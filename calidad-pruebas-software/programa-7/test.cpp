#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


int main(int argc, char const *argv[])
{
    string line;

    getline(cin, line);
      
    // Vector of string to save tokens
    vector<string> tokens;
      
    // stringstream class check1
    stringstream check1(line);
      
    string intermediate;
      
    // Tokenizing w.r.t. space ' '
    while(getline(check1, intermediate, ','))
    {
        tokens.push_back(intermediate);
    }
      
    // Printing the token vector
    for(int i = 0; i < tokens.size(); i++)
        cout << tokens[i] << '\n';
    return 0;
}
