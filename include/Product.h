#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include "Functions.h"

class Product : public Functions
{
private:
    std::string name;
    double price;
    int quantity;
    std::string productionDate;
    std::string expirationDate;
    std::string api;
    std::string category;
    std::string form;

public:
    Product() = default;
    ~Product() = default;

    void printname();
    void printprice();
    void printcategory();
    void setName();
    void setPrice();
    void setProduction();
    void setExpiration();
    void setAPI();
    void setCategory();
    void setForm();
    void PrintExpiration();
    void PrintProduction();
    std::string getName();
    double getPrice();
    std::string getAPI();
    std::string getCategory();
    std::string getForm();
    bool check();
    void Dd();
    void appendproduct();
    bool validateDay(int day);
    bool validateMonth(int month);
    bool validateYear(int year);
    void setQuantity();
    int getQuantity();
    int addCart(std::string medcineName);
    void editproduct();
};

#endif // PRODUCT_H