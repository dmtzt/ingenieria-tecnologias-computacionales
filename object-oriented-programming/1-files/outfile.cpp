#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    // We are putting data to the OUTPUT file
    ofstream outfile;

    // If it doesn't exist, the compiler will create it
    // The second parameter is the mode the file will be opened
    // ofstream::app is to append data to the already existing data
    outfile.open("outfile.txt", ofstream::app);

    // Loop to write 10 numbers
    for (int i = 21; i <= 30; i++)
        outfile << i << endl;

    // Close file
    outfile.close();

    return 0;
}