/* 
 * project-1.cpp
 * 
 * 
 *
 * David Alejandro Martinez Tristan
 * 30/01/2019
*/

#include <iostream>
#include <fstream>

using namespace std;

string indent(int hierarchy);

int main(void)
{
    ifstream infile;
    ofstream outfile;
    string substr;

    bool commentInit = false;

    infile.open("factorial.cpp");
    outfile.open("documentation.html");
    
    outfile << "<!DOCTYPE html>" << endl;
    outfile << "<html>" << endl;
    outfile << << "\n" << "<head>" << endl;

    while(!infile.eof())
    {
        infile >> substr;

        if (substr.compare("/**"))
            commentInit = true;
        if (substr.compare("@progName"))
        {
            infile >> substr;

            outfile << indent(2) << "<header>" << endl;
            outfile << indent(3) << "<title>" << substr << "</title>" << endl;
            outfile << indent(2) << "</header>" << endl; 
            outfile << indent(1) << "</head>" << endl;
            outfile << indent(1) << "<body>" << endl;
            outfile << indent(2) << "<h1>Program: " << substr << "</h1>" << endl; 
        }
        else if (substr.compare("@author"))
        {
            infile >> substr;

            outfile <<< "<br>" << endl;
            outfile << indent(2) << "<strong>Author:</strong>" << endl;
        }
        else if (substr.compare("@date"))
        {

        }
        else if (substr.compare("@funcName"))
        {

        }
        else if (substr.compare("@desc"))
        {

        }
        else if (substr.compare("@param"))
        {

        }
        else if (substr.compare("@return"))
        {

        }
        else
        {
            outfile << substr << " ";
        }
    }

    outfile << "</body>" << endl;
    outfile << "</html>" << endl;

    infile.close();
    outfile.close();

    return 0;
}

string indent(int hierarchy)
{
    string indentation = "";
    for (int i = 0; i < hierarchy; i++)
        indentation.append("\n");

    return indentation;
}
