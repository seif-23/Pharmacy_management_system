#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "Person.h"

class Employee : public Person
{
private:
    double salary;
    std::string password;

public:
    Employee() = default;
    ~Employee() = default;

    void SetPassword();
    void SetSallary();
    void PrintPassword();
    double GetSallarry();
    void displayDataemployee();
    void appendEmployee(std::string fileName);
    void editemployee(std::string filename);
    std::string employeetype();
};

#endif // EMPLOYEE_H