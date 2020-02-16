#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    int duplicates, index, pos;
    string input;
    cin >> input;
    while (input.size() > 1)
    {
        duplicates = (input.size() - 1) / 2;
        index = (duplicates % 2 == 0) ? input.size() / 2 - 1 : input.size() / 2;
        if (input[index] == input[index + 1])
            input = input.substr(0, index);
        else
        {
            if (input[index + 1] == input[index + 2])
            {
                pos = index + 1;
                input = input.substr(pos, input.size() - pos);
            }
            else
            {
                cout << input[index + 1] << endl;
                return 0;
            }
        }
    }

    cout << input[0] << endl;
    
    return 0;
}