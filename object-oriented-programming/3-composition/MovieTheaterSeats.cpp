/* 
 * MovieTheaterSeats.cpp
 *
 * David Alejandro Martinez Tristan
 * 07/03/2019
*/

#include <iostream>
#include "MovieTheaterSeat.h"
#define RESERVE_SEAT 1
#define LOOK_SEAT_INFO 2
#define DISPLAY_SEATS 3
#define END_PROGRAM 4
#define SEATS_SIZE 5

using namespace std;

void setRowCol(int& row, int& col);
void reserveSeat(int row, int col, MovieTheaterSeat seats[][SEATS_SIZE]);
void lookSeatInfo(int row, int col, MovieTheaterSeat seats[][SEATS_SIZE]);
void displaySeats(MovieTheaterSeat seats[][SEATS_SIZE]);

int main(void)
{
    int row, col, option;
    MovieTheaterSeat seats[SEATS_SIZE][SEATS_SIZE];

    cout << "Welcome to the cinema!" << endl;
    do
    {
        cout << "1- Reserve seat" << endl;
        cout << "2- Look for seat information" << endl;
        cout << "3- Display theater seats" << endl;
        cout << "4- Terminate program" << endl;
        cin >> option;

        switch (option)
        {
            case RESERVE_SEAT:
            {
                setRowCol(row, col);
                reserveSeat(row, col, seats);
                break;
            }
            case LOOK_SEAT_INFO:
            {
                setRowCol(row, col);
                lookSeatInfo(row, col, seats);
                break;
            }
            case DISPLAY_SEATS:
            {
                displaySeats(seats);
                break;
            }
            case END_PROGRAM:
                break;
            default:
            {
                cout << "Option not valid" << endl;
                break;
            }
        }
    } while (option != END_PROGRAM);
    
    return 0;
}

void setRowCol(int& row, int& col)
{
    cout << "Please give row [1,5]: ";
    cin >> row;
    row--;
    cout << "Please give seat [1,5]: ";
    cin >> col;
    col--;
}

void reserveSeat(int row, int col, MovieTheaterSeat seats[][SEATS_SIZE])
{
    if (seats[row][col].getReserved())
    {
        cout << "Seat is already reserved" << endl;
        return;
    }

    string name;

    cout << "Please give name for reservation: ";
    cin.ignore();
    getline(cin, name);
    
    seats[row][col].setName(name);
    seats[row][col].setReserved(true);
    cout << endl;
}

void lookSeatInfo(int row, int col, MovieTheaterSeat seats[][SEATS_SIZE])
{
    seats[row][col].toString();
    cout << endl;
}

void displaySeats(MovieTheaterSeat seats[][SEATS_SIZE])
{
    for (int i = 0; i < SEATS_SIZE; i++)
    {
        for (int j = 0; j < SEATS_SIZE; j++)
        {
            if (seats[i][j].getReserved())
                cout << "* ";
            else
                cout << "_ ";
        }
        cout << endl;
    }
    cout << endl;
}