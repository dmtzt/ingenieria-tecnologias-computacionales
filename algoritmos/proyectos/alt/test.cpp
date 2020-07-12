#include <iostream>
#include <map>

using namespace std;

int main(void)
{
    map<char, int> m;

    m['A'] = 0;
    m['B'] = 0;
    m['C'] = 0;
    m['D'] = 0;

    // if (m.count(2) > 0)
    //     cout << "Found" << endl;
    // else
    //     cout << "Not found" << endl;

    map<char, int>::iterator it;

    for (it =m.begin(); it != m.end(); it++)
    {
        cout << it->first << " ";
    }
    
}
