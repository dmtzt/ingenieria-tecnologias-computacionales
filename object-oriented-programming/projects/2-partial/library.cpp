/* 
 * library.cpp
 *
 * David Alejandro Martinez Tristan
 * 29/04/2019
*/

#define MATERIALS_SIZE 20
#define RESERVATIONS_SIZE 50
#define BOOK_CODE 'B'
#define CD_CODE 'C'
#define SOFTWARE_CODE 'S'
#define END_PROGRAM 0
#define DISPLAY_LIST_MATERIALS 1
#define DISPLAY_LIST_RESERVATIONS 2
#define DISPLAY_RESERVATIONS_MATERIAL 3
#define DISPLAY_RESERVATIONS_DATE 4
#define MAKE_RESERVATION 5
#include <iostream>
#include <fstream>
#include "Material.h"
#include "Book.h"
#include "CD.h"
#include "Software.h"
#include "Reservation.h"

using namespace std;

int requestMaterialID(Material **materials, int &mSize);

bool makeReservation(Material **materials, Reservation** reservations, ofstream &outfile, int& reservationsIndex, int &mSize, int &rSize);

void format();
void loadMaterials(Material **materials, ifstream &infile, int &mSize);
void loadReservations(Reservation **reservations, ifstream &resinfile, int &rSize);
void appendReservation(Reservation &reservation, ofstream &outfile);
void displayListMaterials(Material **materials, int &mSize);
void displayListReservations(Material **materials, Reservation** reservations, int &mSize, int &rSize);
void displayReservationsMaterial(Material **materials, Reservation** reservations, int &mSize, int &rSize);
void displayReservationsDate(Material **materials, Reservation** reservations, int &mSize, int &rSize);

int main(void)
{
    int mSize = 0;
    int rSize = 0;
    int reservationsIndex = 0;
    int option;

    Material* materials[MATERIALS_SIZE];
    Reservation* reservations[RESERVATIONS_SIZE];
    ifstream infile;
    ifstream resinfile;
    ofstream resoutfile;

    infile.open("material.txt");
    resinfile.open("reservations.txt");

    loadMaterials(materials, infile, mSize);
    loadReservations(reservations, resinfile, rSize);

    resinfile.close();

    resoutfile.open("reservations.txt", ofstream::app);

    cout << "Welcome to the library" << endl;
    do
    {
        cout << "Please choose an option:" << endl;
        cout << "0) Finish program" << endl;
        cout << "1) Display the list of materials" << endl;
        cout << "2) Display the list of reservations" << endl;
        cout << "3) Display the reservations of a given material" << endl;
        cout << "4) Display the reservations of a given date" << endl;
        cout << "5) Do a reservation" << endl;
        cin >> option;

        switch (option)
        {
        case DISPLAY_LIST_MATERIALS:
            displayListMaterials(materials, mSize);
            break;
        case DISPLAY_LIST_RESERVATIONS:
            displayListReservations(materials, reservations, mSize, rSize);
            break;
        case DISPLAY_RESERVATIONS_MATERIAL:
            displayReservationsMaterial(materials, reservations, mSize, rSize);
            break;
        case DISPLAY_RESERVATIONS_DATE:
            displayReservationsDate(materials, reservations, mSize, rSize);
            break;
        case MAKE_RESERVATION:
            if (makeReservation(materials, reservations, resoutfile, reservationsIndex, mSize, rSize))
                cout << "Reservation was successful" << endl;
            else
                cout << "Reservation failed" << endl;
            format();
            break;
        default:
            break;
        }
    } while (option != END_PROGRAM);

    cout << "Thanks for visiting the library!" << endl;
    
    infile.close();
    resoutfile.close();

    return 0;
}

void format()
{
    cout << string(25, '-') << endl;
}

void loadMaterials(Material **materials, ifstream &infile, int &mSize)
{
    int materialsIndex = 0;
    int id, numPages, duration;
    
    char code;

    string title, author, operatingSystem;

    while(!infile.eof() && materialsIndex < MATERIALS_SIZE)
    {
        infile >> id >> title >> code;

        switch (code)
        {
        case BOOK_CODE:
            infile >> numPages >> author;
            materials[materialsIndex] = new Book(id, title, numPages, author);
            materialsIndex++;
            break;
        case CD_CODE:
            infile >> duration;
            materials[materialsIndex] = new CD(id, title, duration);
            materialsIndex++;
            break;
        case SOFTWARE_CODE:
            infile >> operatingSystem;
            materials[materialsIndex] = new Software(id, title, operatingSystem);
            materialsIndex++;
            break;
        default:
            break;
        }
    }

    mSize = materialsIndex - 1;
}

void loadReservations(Reservation **reservations, ifstream &resinfile, int& rSize)
{
    int reservationsIndex = 0;
    int materialID, clientID;
    Date date;

    while (!resinfile.eof() && rSize < RESERVATIONS_SIZE)
    {
        resinfile >> date >> materialID >> clientID;
        reservations[reservationsIndex] = new Reservation(materialID, clientID, date);
        reservationsIndex++;
    }

    rSize = reservationsIndex - 1;
    

}

void appendReservation(Reservation &reservation, ofstream &outfile)
{
    int clientID = reservation.getClientID();
    int materialID = reservation.getMaterialID();
    Date date = reservation.getReservationDate();

    outfile << date << " " << materialID << " " << clientID << endl;
}

int requestMaterialID(Material **materials, int &mSize)
{
    int materialID;

    while(true)
    {
        cout << "Please provide material ID: ";
        cin >> materialID;

        for (int i = 0; i < mSize; i++)
        {
            if (materialID == materials[i]->getId())
                return materialID;
        }

        cout << "ID does not exist" << endl;
    }
}

void displayListMaterials(Material **materials, int &mSize)
{
    for (int i = 0; i < mSize; i++)
        materials[i]->toString();

    format();
}

void displayListReservations(Material** materials, Reservation** reservations, int& mSize, int& rSize)
{
    int days, materialID;

    for (int i = 0; i < mSize; i++)
    {
        days = materials[i]->numDaysRented();
        materialID = materials[i]->getId();

        for (int j = 0; j < rSize; j++)
        {
            if (materialID == reservations[j]->getMaterialID())
            { 
                cout << materials[i]->getTitle() << " ";
                reservations[j]->toString();
                cout << " " << reservations[j]->calculateEndReservation(days) << endl;
            }
        }
    }

    format();
}

void displayReservationsMaterial(Material **materials, Reservation** reservations, int& mSize, int& rSize)
{
    int days, materialID;

    materialID = requestMaterialID(materials, mSize);

    for (int i = 0; i < mSize; i++)
    {
        if (materialID == materials[i]->getId())
        {
            days = materials[i]->numDaysRented();

            for (int j = 0; j < rSize; j++)
            {
                if (materialID == reservations[j]->getMaterialID())
                {
                    cout << materials[i]->getTitle() << " ";
                    reservations[j]->toString();
                    cout << " " << reservations[j]->calculateEndReservation(days) << endl;
                }
            }
            break;
        }
    }

    format();
}

void displayReservationsDate(Material **materials, Reservation** reservations, int& mSize, int& rSize)
{
    int clientID, materialID, days;
    string title;
    Date date, reservation, endReservation;
    cin >> date;

    for (int i = 0; i < rSize; i++)
    {
        clientID = reservations[i]->getClientID();
        materialID = reservations[i]->getMaterialID();

        for (int j = 0; j < mSize; j++)
        {
            if (materialID == materials[j]->getId())
            {
                days = materials[j]->numDaysRented();
                title = materials[j]->getTitle();
                reservation = reservations[i]->getReservationDate();
                endReservation = reservations[i]->calculateEndReservation(days);

                if (date >=  reservation && date <= endReservation)
                    cout << clientID << " " << title << endl;
            }
        }
    }

    format();
}

bool makeReservation(Material **materials, Reservation** reservations, ofstream &outfile, int& reservationsIndex, int& mSize, int& rSize)
{
    bool isFound = false;
    int clientID, materialID, days;
    Date currentReservation;
    Date currentEndReservation;
    Date newReservation;
    Date newEndReservation;

    cin >> newReservation >> materialID >> clientID;
    
    for (int i = 0; i < mSize; i++)
    {
        if (materialID == materials[i]->getId())
        {
            isFound = true;
            days = materials[i]->numDaysRented();

            for (int j = 0; j < rSize; j++)
            {
                if (materialID == reservations[j]->getMaterialID())
                {
                    currentReservation = reservations[j]->getReservationDate();
                    currentEndReservation = reservations[j]->calculateEndReservation(days);
                    newEndReservation = newReservation + materials[j]->numDaysRented();

                    if ((newEndReservation >= currentReservation && newEndReservation <= currentEndReservation)
                        || (newReservation >= currentReservation && newReservation <= currentEndReservation))
                    {
                        cout << "Material not available in given date" << endl;
                        format();
                        return false;
                    }
                }
            }
        }
    }

    if (isFound)
    {
        reservations[reservationsIndex] = new Reservation(materialID, clientID, newReservation);
        Reservation reservation(materialID, clientID, newReservation);
        appendReservation(reservation, outfile);
        reservationsIndex++;
        rSize++;
        return true;
    }
    else
    {
        cout << "Material not found" << endl;
        return false;
    } 
}