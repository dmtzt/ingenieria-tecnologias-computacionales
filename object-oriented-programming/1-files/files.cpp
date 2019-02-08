// 1- Include file library
#include <fstream>
#include <iostream>

using namespace std;

int main(void)
{
    int n;
    // string name;

    // 2- Set variable of type file
    // ofstream -> write, ifstream -> read
    ifstream textFile;

    // 3- Open file
    textFile.open("numbers.txt");

    // 4- Read/write content
    while(!textFile.eof())
    {
        textFile >> n;
        // getline(textFile, name);
        cout << n << " ";
    }

    // 5- Close file <_ Important to avoid corruption
    textFile.close();

    return 0;
}