#include <iostream>
#include <sstream>
#include <string>
#include "PhoneBook.h"

using namespace std;

int main(void)
{
    PhoneBook phoneBook;
    string data, word, query, name;
    int n, count, number;

    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        getline(cin, data);
        stringstream ss;
        ss << data;
        count = 0;

        while (ss >> word)
        {
            if (count == 0)
                query = word;
            else if (count == 1)
                number = stoi(word);
            else if (count == 2)
                name = word;

            count++;
        }

        if (query.compare("add") == 0)
            phoneBook.addNumberName(number, name);
        else if (query.compare("find") == 0)
            phoneBook.findNumber(number);
        else if (query.compare("del") == 0)
            phoneBook.delNumber(number);
    }

    phoneBook.results();
    return 0;   
}