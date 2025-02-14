#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct SearchResult {
    int lineNumber;
    vector<string> followingLines;
};
class functions {
public:
    vector<SearchResult> results;
    SearchResult result;
    void editData(const string& filename, const string& searchStr,
        const string& replacementStr);
    struct SearchResult;
    void bestSearch(const string& filename, const string& searchStr, int linsenum);
    void Search(const string& filename, const string& searchSt, int linsenum);
    bool Searchtt(const string& filename, const string& searchStr, int linsenum);
    string ToLowerS(string nameLower);
};
class person :public functions {
private:
    string space = "_";
    string Name0, Name1, Name2;
    string NameLower = Name0 + Name1 + Name2;
    string Address0, Address1, Address2;
    int Age;
    char Number[13];
    string cname;

public:

    void SetName();
    void SetAddress();
    void SetAge();
    void SetNumber();
    string GetFullname();
    string getname0();
    string getname1();
    string getname2();
    string GetFullAddress();
    string getaddress0();
    string getaddress1();
    string getaddress2();
    int GetAge();
    void PrintNumber();
    const char* GetNumber() const;

    void DisplayData();
};
class employee : public person {
private:
    char password[6];
    double sallarry;
    int Id;
    int Age;
    char Number[13];
public:
    void SetPassword();
    void SetSallary();
    void PrintPassword();
    const char* GetPassword() const;
    double GetSallarry();
    void displayDataemployee();
    void appendEmployee(string fileName);
    void editemployee(string filename);
    string employeetype();
};
class Customer : public person {
private:
    string Gender;
    float DiscountRate;
    float DueAmmount;
    float Ammount;

public:
    void SetGender();
    void SetDuAmount();
    string GetGender();
    float GetDueAmmount();
    void appendcustomer();
    void editcustomer();
    void DisplatDatacustomer();
};
class product : public functions {
    string name;
    double price;
    char production_Date[10];
    char expiration_Date[10];
    int yy;
    string API; // effective material
    string category;
    string form;
    int quantity;
public:
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
    string getName();
    double getPrice();
    const char* GetProduction() const;
    const char* GetExpiration() const;
    string getAPI();
    string getCategory();
    string getForm();
    bool check();
    void Dd();
    void appendproduct();
    bool validateDay(int day);
    bool validateMonth(int month);
    bool validateYear(int year);
    void setQuantity();
    int getQuantity();
    int addCart(string medcineName);
    void editproduct();
};
