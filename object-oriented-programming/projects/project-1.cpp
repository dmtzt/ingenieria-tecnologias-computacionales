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
    outfile << indent(1) << "<head>" << endl;

    while(!infile.eof())
    {
        infile >> substr;

        if (substr.compare("/**"))
            commentInit = true;
        else if (substr.compare("*/"))
            commentInit = false;

        if (commentInit)
        {   
            infile >> substr;

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

                outfile << "<br>" << endl;
                outfile << indent(2) << "<strong>Author: </strong>" << endl;
            }
            else if (substr.compare("@date"))
            {
                infile >> substr;

                outfile << "<br>" << endl;
                outfile << indent(2) << "<strong>Date: </strong>" << endl;
            }
            else if (substr.compare("@funcName"))
            {
                outfile << "<br>" << endl;
                outfile << indent(2) << "<strong>Function: </strong>" << endl;
            }
            else if (substr.compare("@desc"))
            {
                outfile << "<br>" << endl;
                outfile << indent(2) << "<strong>Description: </strong>" << endl;
            }
            else if (substr.compare("@param"))
            {
                outfile << "<br>" << endl;
                outfile << indent(2) << "<strong>Parameter: </strong>" << endl;
            }
            else if (substr.compare("@return"))
            {
                outfile << "<br>" << endl;
                outfile << indent(2) << "<strong>Return: </strong>" << endl;
            }
            else
            {
                outfile << substr << " ";
            }
        }
        else
            infile.ignore(256, '\n');
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
        indentation.append("\t");

    return indentation;
}
