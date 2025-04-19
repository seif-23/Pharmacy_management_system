#ifndef PERSON_H
#define PERSON_H

#include <string>
#include "Functions.h"

class Person : public Functions
{
protected:
    std::string Name0, Name1, Name2;
    std::string Address0, Address1, Address2;
    int Age;
    char Number[13];
    const std::string space = "_";

public:
    Person() = default;
    virtual ~Person() = default;

    void SetName();
    void SetAddress();
    void SetAge();
    void SetNumber();
    std::string GetFullname();
    std::string getname0();
    std::string getname1();
    std::string getname2();
    std::string GetFullAddress();
    std::string getaddress0();
    std::string getaddress1();
    std::string getaddress2();
    int GetAge();
    void PrintNumber();
    const char *GetNumber() const;
};

#endif // PERSON_H