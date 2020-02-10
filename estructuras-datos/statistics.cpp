#include <ctime>
#include <iostream>
#include <fstream>
#define START_TIME 0
#define END_TIME 1
#define END_PROGRAM -1

using namespace std;

void init(bool* isActive);
void printHeader(bool* isActive);
string formatTime(int s);

int main(void)
{
    int index = 1;
    int total = 0;
    int records[10][2];
    bool isActive[10];
    int option;
    ofstream outfile;
    clock_t start;

    init(isActive);
    outfile.open("Tiempos.txt", ios::app);
    start = clock();
    do
    {
        printHeader(isActive);
        cout << "Previous total: " << formatTime(total) << endl;
        cout << "Current time: " << formatTime((clock() / CLOCKS_PER_SEC)) << " ";
        cout << "Current record: " << index << endl;
        cout << "Option: ";
        cin >> option;
        option--;
        
        if (option >= 0 && option <= 9)
        {
            if (!isActive[option])
            {
                records[option][START_TIME] = (clock() - start) / CLOCKS_PER_SEC;
                isActive[option] = true;
            }
            else
            {
                records[option][END_TIME] = (clock() - start) / CLOCKS_PER_SEC;
                total = records[option][END_TIME] - records[option][START_TIME];
                outfile << index << "," << total << "," << formatTime(total) << endl;
                isActive[option] = false;
                index++;
            }
        }
    } while (option != END_PROGRAM);

    cout << "Program ended" << endl;
    outfile.close();
}

void init(bool* isActive)
{
    for (int i = 0; i < 10; i++)
        isActive[i] = false;
    
}

void printHeader(bool* isActive)
{
    for (int i = 0; i < 20; i++)
        cout << "_";
    
    cout << endl;
    
    for (int i = 0; i < 10; i++)
        cout << (i + 1) << " ";
    
    cout << endl;

    for (int i = 0; i < 10; i++)
    {
        if (isActive[i])
            cout << "* ";
        else
            cout << "- ";
    }
    
    cout << endl;
}

string formatTime(int s)
{
    int m = s / 60;
    s %= 60;

    string time = to_string(m) + ":" + to_string(s);
    return time;
}