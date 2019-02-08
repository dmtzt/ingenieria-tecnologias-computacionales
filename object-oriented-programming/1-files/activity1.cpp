/* 
 * A01610267_Activity1.cpp
 * 
 * Reads a series of numbers from a file,
 * adds the corresponding commas and stores
 * the formated numbers in a new file.
 *
 * David Alejandro Martinez Tristan
 * 23/01/2019
*/

#include <fstream>
#include <string>

using namespace std;

int main(void)
{
    // Input and output files
    ifstream infile;
    ofstream outfile;
    // Temporary number
    string number;
    int pos;

    // Open files
    infile.open("LongNumbers.txt");
    outfile.open("NumbersWithCommas.txt");

    // While EOF has not been reached
    while(!infile.eof())
    {
        // Read next line
        getline(infile, number);
        // Start formating from the 3rd digit
        pos = number.size() - 3;

        // While the end of the number has not been reached
        while (pos > 0)
        {
            // Insert comma
            number.insert(pos, ",");
            // Skip the next 3 digits
            pos -= 3;
        }

        // Write formated number to output file
        outfile << number << endl;
    }

    // Close files
    infile.close();
    outfile.close();

    return 0;
}