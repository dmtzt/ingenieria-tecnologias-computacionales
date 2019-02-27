/* 
 * Employee.h
 * 
 * Description
 *
 * David Alejandro Martinez Tristan
 * 25/02/2019
*/

#include <iostream>
#include <string>

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Department.h"
#include "Invoice.h"

using namespace std;

class Employee
{
    private:
        int id, age;
        string firstName, lastName;
        Invoice invoice;
        Department department;
    public:
        Employee();
        Employee(int, int, string, string, Invoice, Department);
        int getId();
        int getAge();
        string getFirstName();
        string getLastName();
        Invoice getInvoice();
        Department getDepartment();
        void setId(int);
        void setAge(int);
        void setFirstName(string);
        void setLastName(string);
        void setInvoice(Invoice);
        void setDepartment(Department);
        bool compareDepartment(Employee);
        void toString();
};

Employee::Employee(int id, 
                   int age, 
                   string firstName, 
                   string lastName, 
                   Invoice invoice, 
                   Department department)
{
    this->id = id;
    this->age = age;
    this->firstName = firstName;
    this->lastName = lastName;
    this->invoice = invoice;
    this->department =department;
}

int Employee::getId()
{
    return id;
}

int Employee::getAge()
{
    return age;
}

string Employee::getFirstName()
{
    return firstName;
}

string Employee::getLastName()
{
    return lastName;
}
Invoice Employee::getInvoice()
{
    return invoice;
}

Department Employee::getDepartment()
{
    return department;
}

void Employee::setId(int id)
{
    this->id = id;
}
void Employee::setAge(int age)
{
    this->age = age;
}

void Employee::setFirstName(string firstName)
{
    this->firstName =firstName;
}

void Employee::setLastName(string lastName)
{
    this->lastName = lastName;
}

void Employee::setInvoice(Invoice invoice)
{
    this->invoice = invoice;
}

void Employee::setDepartment(Department department)
{
    this->department = department;
}

bool Employee::compareDepartment(Employee employee)
{
    if (id != employee.getId)
        return false;

    return true;
}

void toString()
{

}

#endif