/* 
 * Department.h
 * 
 * Description
 *
 * David Alejandro Martinez Tristan
 * 25/02/2019
*/

#ifndef DEPARTMENT_H
#define DEPARTMENT_H

class Department
{
    private:
        string name, location;
        int id;
        long long int phoneNum;
    public:
        Department();
        Department(string, string, int, long long int);
        string getName();
        string getLocation();
        int getId();
        long long int getPhoneNum();
        void setName(string);
        void setLocation(string);
        void setId(int);
        void setPhoneNum(long long int);
        void toString();
};

Department::Department()
{
    name = "N/A";
    location = "N/A";
    id = -1;
    phoneNum = -1;
}

Department::Department(string name, 
                       string location, 
                       int id, 
                       long long int phoneNum)
{
    this->name = name;
    this->location = location;
    this->id = id;
    this->phoneNum = phoneNum;
}

string Department::Department::getName()
{
    return name;
}

string Department::getLocation()
{
    return location;
}

int Department::getId()
{
    return id;
}

long long int Department::getPhoneNum()
{
    return phoneNum;
}

void Department::setName(string name)
{
    this->name = name;
}

void Department::setLocation(string location)
{
    this->location = location;
}

void Department::setId(int id)
{
    this->id = id;
}

void Department::setPhoneNum(long long int phoneNum)
{
    this->phoneNum = phoneNum;
}

void Department::toString()
{
    cout << name << endl;
    cout << location << endl;
    cout << id << endl;
    cout << phoneNum << endl;
}
#endif