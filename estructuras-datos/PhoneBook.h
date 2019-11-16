#include <iostream>
#include <map>
#include <queue>

using namespace std;

class PhoneBook
{
private:
    map<int, string> book;
    queue<string> output;
public:
    void addNumberName(int number, string name);
    void delNumber(int number);
    void findNumber(int number);
    void results();
};

void PhoneBook::addNumberName(int number, string name)
{
    book[number] = name;
}

void PhoneBook::findNumber(int number)
{
    if (book[number].empty())
        output.push("not found");
    else
        output.push(book[number]);
}

void PhoneBook::delNumber(int number)
{
    book.erase(number);
}

void PhoneBook::results()
{
    while (!output.empty())
    {
        cout << output.front() << endl;
        output.pop();
    }
}

