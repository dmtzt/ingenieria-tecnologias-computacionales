/* 
 * project-1.cpp
 *
 * Generates documentation of a C++ file in a HTML file.
 * The features are retrieved if they are inside block comments,
 * and if they begin with the @ character, followed by 
 * a string that represents their type.
 * 
 * David Alejandro Martinez Tristan
 * 30/01/2019
*/
 
// Length of feature types for erasing them and write in file without metadata
#define PROG_NAME_LENGTH 10
#define AUTHOR_LENGTH 8
#define DATE_LENGTH 6
#define FUNC_NAME_LENGTH 10
#define DESC_LENGTH 6
#define PARAM_LENGTH 7
#define RETURN_LENGTH 8

#include <iostream>
#include <fstream>

using namespace std;

string indent(int hierarchy);

int main(void)
{
    int pos;
    ifstream infile;
    ofstream outfile;
    string line;

    // Flag for checking if the line read is inside a block comment
    bool insideComment = false;

    // Input and output files
    infile.open("factorial.cpp");
    outfile.open("docs.html");
    
    // HTML5 file starting point
    outfile << "<!DOCTYPE html>" << endl;
    outfile << "<html>" << endl;
    outfile << "<head>" << endl;

    while(!infile.eof())
    {
        // Read input file line by line
        getline(infile, line);

        // Check if the line is the start of a block comment
        if (line.find("/**") != string::npos)
            insideComment = true;  
        // Otherwise, check if the line is the end of a block comment
        else if (line.find("*/") != string::npos)
            insideComment = false;
            
        // If the line is inside a block comment, proceed to write in HTML file
        if (insideComment)
        {
            // For every feature, identify its type, delete metadata from line and write feature in HTML file
            // Lines inside head and body tags are indented to respect hierarchy
            //Program name
            if (line.find("@progName") != string::npos)
            {
                pos = line.find("@progName");
                line.erase(0, pos + PROG_NAME_LENGTH);
                outfile << indent(1) << "<h2>Program: " << line << "</h2>" << endl;
            }
            // Function name
            else if (line.find("@funcName") != string::npos)
            {
                pos = line.find("@funcName");
                line.erase(0, pos + FUNC_NAME_LENGTH);
                outfile << indent(1) << "<h3>Function: " << line << "</h3>" << endl;
            }
            // Author name
            else if (line.find("@author") != string::npos)
            {
                pos = line.find("@author");
                line.erase(0, pos + AUTHOR_LENGTH);
                outfile << indent(1) << "<strong>Author:</strong> " << line << "<br>" << endl;
            }
            // Date
            else if (line.find("@date") != string::npos)
            {
                pos = line.find("@date");
                line.erase(0, pos + DATE_LENGTH);
                outfile << indent(1) << "<strong>Date:</strong> " << line << "<br>" << endl;
                outfile << "</head>" << endl;
            }
            // Function description
            else if (line.find("@desc") != string::npos)
            {
                pos = line.find("@desc");
                line.erase(0, pos + DESC_LENGTH);
                outfile << indent(1) << "<strong>Description:</strong> " << line << "<br>" << endl;
            }
            // Function parameters
            else if (line.find("@param") != string::npos)
            {
                pos = line.find("@param");
                line.erase(0, pos + PARAM_LENGTH);
                outfile << indent(1) << "<strong>Parameters:</strong> " << line << "<br>" << endl;
            }
            // Function return
            else if (line.find("@return") != string::npos)
            {
                pos = line.find("@return");
                line.erase(0, pos + RETURN_LENGTH);
                outfile << indent(1) << "<strong>Return:</strong> " << line << "<br>" << endl;
            }
        }
    }

    // HTML5 file end
    outfile << "</body>" << endl;
    outfile << "</html>" << endl;

    // Close files
    infile.close();
    outfile.close();

    // Success
    return 0;
}

/*
 * indent
 * 
 * Generates string of tab '\t' characters to be printed as indentation
 * Receives number of tab characters
 * Returns string of specified tab characters
 */
string indent(int hierarchy)
{
    string indentation = "";
    for (int i = 0; i < hierarchy; i++)
        indentation.append("\t");

    return indentation;
}