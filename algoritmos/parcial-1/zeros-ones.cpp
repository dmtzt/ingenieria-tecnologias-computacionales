#include <iostream>

using namespace std;

int main(void)
{
    int size, pos;
    bool finished;
    string input;
    cin >> size >> input;

    do
    {
        pos = 0;
        finished = true;

        while (pos < input.size())
        {
            if ((input[pos] == '0' && input[pos + 1] == '1') || 
                (input[pos] == '1' && input[pos + 1] == '0'))
            {
                input.erase(pos, 2);
                if (finished)
                    finished = false;
            }
            else
                pos++;
        }     
        
    } while (!finished);

    cout << input.size() << endl;
    return 0;
}