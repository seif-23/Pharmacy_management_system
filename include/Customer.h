#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "Person.h"

class Customer : public Person
{
private:
    std::string gender;
    float dueAmount;

public:
    Customer() = default;
    ~Customer() = default;

    void SetGender();
    void SetDuAmount();
    std::string GetGender();
    float GetDueAmmount();
    void appendcustomer();
    void editcustomer();
    void DisplatDatacustomer();
};

#endif // CUSTOMER_H