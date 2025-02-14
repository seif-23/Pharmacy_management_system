#include "pharmcy.h"
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
using namespace std;

void functions::bestSearch(const string& filename, const string& searchStr, int linsenum)
{

    ifstream file(filename); // Open file with given filename for reading
    string line;             // Declare a string to store each line of text
    // Vector to store line numbers and corresponding lines where the
    // search string is found
    int lineNumber = 1; // Variable to track the current line number

    if (!file.is_open()) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    while (getline(file, line)) { // Read each line from the file
        if (line.find(searchStr) !=
            string::npos) { // Check if the search string is found in the line
            result.lineNumber = lineNumber;
            // Store the current line
            result.followingLines.push_back(line);
            // Store the next five lines
            for (int i = 0; i < linsenum && getline(file, line); ++i) {
                result.followingLines.push_back(line);
            }
            results.push_back(result);
        }
        lineNumber++; // Increment the line number counter
    }

    file.close(); // Close the file after reading

    if (!results.empty()) { // Check if any results were found
        cout << "String \"" << searchStr
            << "\" found. Lines following the match:" << endl;
        for (const auto& result : results) {
            cout << "Line " << result.lineNumber << " and the next lines:" << endl;
            for (const auto& followingLine : result.followingLines) {
                cout << followingLine << endl;
            }
        }
    }
    else {
        cout
            << "String \"" << searchStr << "\" not found in the file."
            << endl; // Display a message indicating the search string was not found
    }
}
void functions::Search(const string& filename, const string& searchStr, int linsenum)

{

    ifstream file(filename); // Open file with given filename for reading
    string line;             // Declare a string to store each line of text
    // Vector to store line numbers and corresponding lines where the
    // search string is found
    int lineNumber = 1; // Variable to track the current line number

    if (!file.is_open()) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    while (getline(file, line)) { // Read each line from the file
        if (line.find(searchStr) !=
            string::npos) { // Check if the search string is found in the line
            result.lineNumber = lineNumber;
            // Store the current line
            result.followingLines.push_back(line);
            // Store the next five lines
            for (int i = 0; i < linsenum && getline(file, line); ++i) {
                result.followingLines.push_back(line);
            }
            results.push_back(result);
        }
        lineNumber++; // Increment the line number counter
    }

    file.close(); // Close the file after reading
}
bool functions::Searchtt(const string& filename, const string& searchStr, int linsenum)

{

    ifstream file(filename); // Open file with given filename for reading
    string line;             // Declare a string to store each line of text
    // Vector to store line numbers and corresponding lines where the
    // search string is found
    int lineNumber = 1; // Variable to track the current line number

    if (!file.is_open()) {
        cerr << "Error: Unable to open file." << endl;
    }

    while (getline(file, line)) { // Read each line from the file
        if (line.find(searchStr) !=
            string::npos) { // Check if the search string is found in the line
            result.lineNumber = lineNumber;
            // Store the current line
            result.followingLines.push_back(line);
            // Store the next five lines
            for (int i = 0; i < linsenum && getline(file, line); ++i) {
                result.followingLines.push_back(line);
            }
            results.push_back(result);
        }
        lineNumber++; // Increment the line number counter
    }

    file.close(); // Close the file after reading

    if (!results.empty()) { // Check if any results were found

        return true;

    }
    else {
        std::cout
            << "String \"" << searchStr << "\" not found in the file."
            << endl; // Display a message indicating the search string was not found
        return false;
    }
}
string functions::ToLowerS(string nameLower)
{
    string cname;


    for (char c : nameLower) {
        cname += tolower(c);
    }

    return cname;
}
void person::SetName() {
    string N0, N1, N2;
    cout << "Enter the name consisting of first name + his second name + "
        "+ his surname\n";
    cin >> N0 >> N1 >> N2;
    N0 = ToLowerS(N0);
    N1 = ToLowerS(N1);
    N2 = ToLowerS(N2);
    Name0 = N0; Name1 = N1; Name2 = N2;

    if (N0.empty() || N1.empty() || N2.empty()) {
        cout << "All names components must be provided \n";
    }

}
void person::SetAddress() {
    cout << "Enter the address consisting of your state + province + city\n";
    string A, B, C;
    cin >> A >> B >> C;
    A = ToLowerS(A);
     B = ToLowerS(B);
    C = ToLowerS(C);
    if (A.empty() || B.empty() || C.empty())
        cout << "All address components must be provided \n";
    Address0 = A;  Address1 = B; Address2 = C;
}
void person::SetAge() {
    cout << "Enter the age\n";
    int AG;
    while (!(cin >> AG)) {
        cout << "Invalid input. Please enter an integer: ";
        cin.clear(); // Clear error flags
        cin.ignore(numeric_limits<streamsize>::max(),
            '\n'); // Discard invalid input
    }
    bool x = AG > 0 && AG < 99;
    if (x)
        Age = AG;
    else {
        cout << "Sorry, enter an appropriate age (number of years )\n ";

        while (x == 0) {
            cout << "enter valid age \n";
            cin >> AG;
            if (AG > 0 && AG < 99)
                break;

        }
        Age = AG;
    }
}
void person::SetNumber() {
    cout << "Enter the number\n";
    char NU[13];
    bool isValid = false;
    do {
        for (int i = 0; i < 13; i++) {
            cin >> NU[i];
        }

        isValid = NU[0] == '+' && NU[1] == '2' && NU[2] == '0';

        if (isValid) {
            break; // Exit the loop if the number is valid
        }
        else {
            cout << "Please enter a valid Egyptian number starting with +20" << endl;
        }
    } while (!isValid);

    // Once a valid number is entered, copy it to the member variable
    for (int i = 0; i < 13; i++) {
        Number[i] = NU[i];
    }
}
string person::GetFullname() { return cname; }
string person::getname0() { return Name0; }
string person::getname1() { return Name1; }
string person::getname2() { return Name2; }
string person::GetFullAddress() {
    return Address0 + space + Address1 + space + Address2;
}
string person::getaddress0() { return Address0; }
string person::getaddress1() { return Address1; }
string person::getaddress2() { return Address2; }
int person::GetAge() { return Age; }
void person::PrintNumber() {
    for (int i = 0; i < 13; i++) {
        cout << Number[i];
    }
}
const char* person::GetNumber() const { return Number; }
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void functions::editData(const string& filename, const string& searchStr,
    const string& replacementStr) {
    ifstream inputFile(filename); // Open file with given filename for reading
    string line;                  // Declare a string to store each line of text
    vector<string> modifiedLines; // Vector to store modified lines
    while (getline(inputFile, line)) { // Read each line from the file
        size_t pos = 0;
        while ((pos = line.find(searchStr, pos)) !=
            string::npos) { // Find occurrences of searchStr in line
            line.replace(pos, searchStr.length(),
                replacementStr);   // Replace searchStr with replacementStr
            pos += replacementStr.length(); // Move past the replacement
        }
        modifiedLines.push_back(line); // Store the modified line
    }
    inputFile.close(); // Close the input file

    ofstream outputFile(filename); // Open the same file for writing (this will
    // clear its contents)
    for (const string& modifiedLine :
        modifiedLines) { // Write modified lines to the file
        outputFile << modifiedLine << endl;
    }
    outputFile.close(); // Close the output file
    cout << "Your data has been changed successfully." << endl;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////


void person::DisplayData() { // desplay all data
    cout << "the data of employee " << Name0 << " " << Name1 << " " << Name2
        << "is: \n";
    cout << "\nthe name is : " << GetFullname();
    cout << "\nthe address is : " << GetFullAddress();
    cout << "\nthe Age is :" << GetAge();
    cout << "\nthe number is : ";
    PrintNumber();
}

void employee::SetPassword() {
    char pass[6];
    cout << "Please enter a password consisting of only six characters \n";
    for (int q = 0; q < 6; q++) {
        cin >> pass[q];
    }
    for (int q = 0; q < 6; q++) {
        password[q] = pass[q];
    }
}
void employee::SetSallary() {
    double S;
    cout << "enter a sallay :\n";
    while (!(cin >> S)) {
        cout << "Invalid input. Please enter an double number: ";
        cin.clear(); // Clear error flags
        cin.ignore(numeric_limits<streamsize>::max(),
            '\n'); // Discard invalid input
    }
    cin.ignore();
    if (S > 0) {
        sallarry = S;
    }
    else {
        cout << "enter a positive sallary \n";
        cin >> S;
        while (S < 0) {
            cout << "enter a positive sallary \n";
            cin >> S;
            if (S > 0) {
                break;
            }
        }
        sallarry = S;
    }
}
void employee::PrintPassword() {
    cout << "the password is : ";
    for (int q = 0; q < 6; q++) {
        cout << password[q];
    }
    cout << "\n";
}
const char* employee::GetPassword() const { return password; }
double employee::GetSallarry() { return sallarry; }
void employee::displayDataemployee() {
    DisplayData();
    PrintPassword();
    cout << "\nsallarry is: " << GetSallarry();
    //   cout << "\nid is : " << GetId();
}
void employee::appendEmployee(string fileName) {
    string name0 = getname0();
    string name1 = getname1();
    string name2 = getname2();
    string name = name0 + "_" + name1 + "_" + name2;
    string Address = GetFullAddress();
    int Age = GetAge();
    string a = to_string(Age);
    string username = name0 + "_" + name1[0] + "_" + a;
    const char* Number = GetNumber();
    const char* Password = GetPassword();
    double sall = GetSallarry();
    fstream employeef;
    employeef.open(fileName, ios::app);
    if (employeef.is_open()) {
        employeef << "employee Data:\n"
            << username << "\n" << name << "\n"
            << Address << "\n"
            << Age << "\n";
        for (int i = 0; i < 13; i++) {
            employeef << Number[i];
        }
        employeef << "\n" << sall;
        employeef << "\n" << Password;
        employeef << "\n##################################################\n";
        employeef.close();
        cout << "\nYour username is " << username << "\n";
        cout << "\nYour employee has been added successfully.\n";

    }
    else {
        cout << "Sorry, failed to open the file.\n";
    }

}
void employee::editemployee(string filename) {
    employee seif;
    string newname0, newname1, newname2, newname;
    string address, address0, address1, address2;
    string newage;
    string newsalary;
    string number;
    string eAge;
    string eSallery;
    string UserName;
    string strNewsalary;
    cout << "Enter The UserName: " << endl;
    cin >> UserName;
    bool result = seif.Searchtt(filename, UserName, 6);
    if (result) {
        string oldname = seif.result.followingLines.at(1);
        string oldaddress = seif.result.followingLines.at(2);
        string oldage = seif.result.followingLines.at(3);
        string oldnumber = seif.result.followingLines.at(4);
        string olsalarry = seif.result.followingLines.at(5);
        string olpassword = seif.result.followingLines.at(6);

        cout
            << "What data do you want to modify? "
            "\n1-address\n2-phonenmber\n3-sallarry\n4-password\n";
        int x;
        while (!(cin >> x)) {
            cout << "Invalid input. Please enter an integer: ";
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(),
                '\n'); // Discard invalid input
        }
        switch (x) {

        case 1:
            cout << "enter the new address  3 words : \n";
            cin >> address0 >> address1 >> address2;
            address = address0 + "_" + address1 + "_" + address2;
            seif.editData(filename, oldaddress, address);
            break;

        case 2:

            seif.SetNumber();
            seif.editData(filename, oldnumber, seif.GetNumber());
            break;
        case 3:

            seif.SetSallary();
            eSallery = to_string(seif.GetSallarry());
            seif.editData(filename, olsalarry, eSallery);
            break;
        case 4:
            seif.SetPassword();
            seif.editData(filename, olpassword, seif.GetPassword());
            break;
        default:
            break;
        }
    }
    else {
        cout << "Error:UserName Not Found In File." << endl;
    }
}
string employee::employeetype() {
    int type;
    string fileName;
    cout << "Enter the type of employee 1-pharmacist\n2-cashier\n: ";
    while (!(cin >> type)) {
        cout << "Invalid input. Please enter an integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    switch (type)
    {
    case 1: return "Pharmacist.txt";
        break;
    case 2:
        return "Cashier.txt";
        break;
    default:
        cout << "Invalid employee type. Exiting function.\n";
        exit(0);
        break;
    }
}
void Customer::SetGender() {
    cout << "enter the gender :\n1-male\n2-female\n";
    int G;
    cin >> G;
    switch (G) {
    case 1:
        Gender = "male";
        break;
    case 2:
        Gender = "female";
        break;
    default:
        cout << "error enter avalid case.\n";
        break;
    }
}
void Customer::SetDuAmount() {
    cout << "enter the Due amount in customer account :\n";
    float D;
    cin >> D;
    DueAmmount = D;
}
string Customer::GetGender() { return Gender; }
float Customer::GetDueAmmount() { return DueAmmount; }
void Customer::appendcustomer() {

    string name3 = getname0();
    string name4 = getname1();
    string name5 = getname2();
    string namE = name3 + "_" + name4 + "_" + name5;
    string Address3 = getaddress0();
    string Address4 = getaddress1();
    string Address5 = getaddress2();
    int age = GetAge();
    const char* number = GetNumber();
    string gender = GetGender();
    float dueamount = GetDueAmmount();

    fstream customerf;
    customerf.open("customer.txt", ios::app);
    if (customerf.is_open()) {
        customerf << "customer Data:\n"
            << namE << "\n"
            << Address3 << "_" << Address4 << "_" << Address5 << "\n"
            << age << "\n";
        for (int i = 0; i < 13; i++) {
            customerf << number[i];
        }
        customerf << "\n" << gender << "\n" << dueamount;

        customerf << "\n##################################################\n";
    }
    customerf.close();
    cout << "\nYour customer has been added successfully.\n";
}



void Customer::DisplatDatacustomer() {
    DisplayData();
    cout << "\ngender is: " << GetGender();
    cout << "\nDue Amount is: " << GetDueAmmount();
}
void Customer::editcustomer() {
    Customer asseel;
    string address, address0, address1, address2;
    string newgender;
    string number;
    string newamount;
    cout << "Enter the old name: " << endl;
    asseel.SetName();

    bool result = asseel.Searchtt("customer.txt", asseel.GetFullname(), 6);
    if (result) {
        string oldaddress = asseel.result.followingLines.at(1);
        string oldnumber = asseel.result.followingLines.at(3);
        string olgender = asseel.result.followingLines.at(4);
        string olamount = asseel.result.followingLines.at(5);
        Customer p2;
        cout << "What data do you want to modify? "
            "\n1-name\n2-address\n3-age\n4-phonenumber\n5-gender\n6-due "
            "amount\n";
        int x;
        while (!(cin >> x)) {
            cout << "Invalid input. Please enter an integer: ";
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(),
                '\n'); // Discard invalid input
        }
        switch (x) {

        case 1:
            cout << "enter the new address  3 words : \n";
            cin >> address0 >> address1 >> address2;
            address = address0 + "_" + address1 + "_" + address2;
            asseel.editData("customer.txt", oldaddress, address);
            break;


        case 2:
            cout << "enter the new number:\n";
            asseel.SetNumber();
            asseel.editData("customer.txt", oldnumber, asseel.GetNumber());
            break;
        case 3:
            cout << "Enter the new gender:\n";
            asseel.SetGender();
            asseel.editData("customer.txt", olgender, asseel.GetGender());
            break;
        case 4:
            cout << "enter the new due amount:\n";
            asseel.SetDuAmount();
            newamount = to_string(asseel.GetDueAmmount());
            asseel.editData("customer.txt", olamount, newamount);
            break;
        default:
            break;
        }
    }
    else {
        cout << "Error: Full name not found in file." << endl;
    }
}
void product::setName() {
    string n;
    cout << "please enter the name of the product\n";
    cin >> n;
    string lowercaseword;
    for (char ch : n) {
        lowercaseword += tolower(ch);
    }

    name = lowercaseword;
}
void product::setPrice() {
    double p;
    cout << "please enter the price of the product\n";
    while (!(cin >> p)) {
        cout << "Invalid input. Please enter an integer: ";
        cin.clear(); // Clear error flags
        cin.ignore(numeric_limits<streamsize>::max(),
            '\n'); // Discard invalid input
    }
    price = p;
}
void product::setProduction() {
    // Input for day
    int day;
    do {
        cout << "Enter the day (1-31): ";

        while (!(cin >> day)) {
            cout << "Invalid input. Please enter an integer: ";
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(),
                '\n'); // Discard invalid input
        }
    } while (!validateDay(day));

    // Input for month
    int month;
    do {
        cout << "Enter the month (1-12): ";

        while (!(cin >> month)) {
            cout << "Invalid input. Please enter an integer: ";
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(),
                '\n'); // Discard invalid input
        }
    } while (!validateMonth(month));

    // Input for year
    int year;
    do {
        cout << "Enter the year (2024-2034): ";

        while (!(cin >> year)) {
            cout << "Invalid input. Please enter an integer: ";
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(),
                '\n'); // Discard invalid input
        }
        yy = year;
    } while (!validateYear(year));

    int dateArray[] = { day, month, year };
    int length = sizeof(dateArray) / sizeof(dateArray[0]);
    string formattedDate;
    for (int i = 0; i < length; ++i) {
        formattedDate += std::to_string(dateArray[i]);
        if (i < length - 1) {
            formattedDate += '\\';
        }
    }
    for (int i = 0; i < 10; i++) {
        production_Date[i] = formattedDate[i];
    }
}
void product::setExpiration() {
    // Input for day
    int day;
    do {
        cout << "Enter the day (1-31): ";

        while (!(cin >> day)) {
            cout << "Invalid input. Please enter an integer: ";
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(),
                '\n'); // Discard invalid input
        }
    } while (!validateDay(day));

    // Input for month
    int month;
    do {
        cout << "Enter the month (1-12): ";

        while (!(cin >> month)) {
            cout << "Invalid input. Please enter an integer: ";
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(),
                '\n'); // Discard invalid input
        }
    } while (!validateMonth(month));

    // Input for year
    int year;

    do {
        cout << "Enter the year (2024-2034): ";

        while (!(cin >> year)) {
            cout << "Invalid input. Please enter an integer: ";
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(),
                '\n'); // Discard invalid input
        }
    } while (!validateYear(year));

    // Loop until expiration year is not equal to production year
    while (year == yy) {
        cout << "Expiration year cannot be the same as production year. Please "
            "enter a different year."
            << endl;
        cout << "Enter the year (2024-2034): ";
        cin >> year;
        while (!(cin >> year)) {
            cout << "Invalid input. Please enter an integer: ";
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(),
                '\n'); // Discard invalid input
        }
    }

    int dateArray[] = { day, month, year };

    int length = sizeof(dateArray) / sizeof(dateArray[0]);
    string formattedDate;
    for (int i = 0; i < length; ++i) {
        formattedDate += std::to_string(dateArray[i]);
        if (i < length - 1) {
            formattedDate += '\\';
        }
    }
    for (int i = 0; i < 10; i++) {
        expiration_Date[i] = formattedDate[i];
    }
}
void product::setAPI() {
    string a;
    cout << "please enter the API of the product\n";
    cin >> a;
    API = a;
}
void product::setCategory() {
    string c;
    int y = 0;
    product ob;
    cout << "Please enter the product's category\n1 for painkillers\n2 for "
        "vitamens\n3 for antibiotics\n4 for Steroids\n5 for Laxatives\n";
    while (!(cin >> y)) {
        cout << "Invalid input. Please enter an integer: ";
        cin.clear(); // Clear error flags
        cin.ignore(numeric_limits<streamsize>::max(),
            '\n'); // Discard invalid input
    }
    switch (y) {
    case 1:
        c = "painkillers";
        break;
    case 2:
        c = "vitamens";
        break;
    case 3:
        c = "antibiotics";
        break;
    case 4:
        c = "steroids";
        break;
    case 5:
        c = "Laxatives";
        break;
    default:
        c = "unidentified";
    }
    category = c;
}
void product::setForm() {
    string f;

    int x;
    product ob;
    cout << "Please enter the product's form\n1 for tablets\n2 for capsules\n3 "
        "for powders\n4 for injectable\n5 for oral\n";
    while (!(cin >> x)) {
        cout << "Invalid input. Please enter an integer: ";
        cin.clear(); // Clear error flags
        cin.ignore(numeric_limits<streamsize>::max(),
            '\n'); // Discard invalid input
    }
    switch (x) {
    case 1:
        f = "tablets";
        break;
    case 2:
        f = "capsules";
        break;
    case 3:
        f = "powders";
        break;
    case 4:
        f = "injectable";
        break;
    case 5:
        f = "syrup";
        break;
    default:
        f = "unidentified";
    }
    form = f;
}
void product::setQuantity() {
    int q;
    cout << "please enter the quantity of the product\n";
    cin >> q;
    int quantity = q;
}
void product::printname() { cout << name; }
void product::printprice() { cout << price; }
void product::printcategory() { cout << category; }
string product::getName() { return name; }
double product::getPrice() { return price; }
void product::PrintProduction() {
    for (int k = 0; k < 10; k++) {
        cout << production_Date[k];
    }
    cout << "\n";
}
void product::PrintExpiration() {
    for (int l = 0; l < 10; l++) {
        cout << expiration_Date[l];
    }
    cout << "\n";
}
const char* product::GetProduction() const { return production_Date; }
const char* product::GetExpiration() const { return expiration_Date; }
string product::getCategory() { return category; }
string product::getAPI() { return API; }
string product::getForm() { return form; }
int product::getQuantity() { return quantity; }
bool product::check() {
    for (int t = 6; t < 10; t++) {
        if (production_Date[t] == expiration_Date[t])
            return false;
    }
    return true;
}
/////////////////////////////////////////////////////////////
int product::addCart(string medcineName) {
    int price = 0;
    int quan = 0;
    int oldquantiti = 0;
    string eQuan;
    product pp;
    while (!price) {
        cout << "How much do you want to add?\n";
        while (!(cin >> quan)) {
            cout << "Invalid input. Please enter an integer: ";
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(),
                '\n'); // Discard invalid input
        }
        Search("medicines.txt", medcineName, 7);
        oldquantiti = stoi(result.followingLines.at(2));
        if (quan <= 0)
        {
            cout << "Cant do this please check the inventory.";
            return 0;
        }
        else if (oldquantiti >= quan) {
            price = stoi(result.followingLines.at(1)) * quan;
            oldquantiti -= quan;
        }
        else
            cout << "Please enter a number less than  " << oldquantiti << endl;
    }
    eQuan = to_string(oldquantiti);
    pp.editData("medicines.txt", result.followingLines.at(2), eQuan);
    cout << "Added successfully to the cart\n";
    return price;
}
/////////////////////////////////////////////////////////////

void product::Dd() { // Display data
    cout << "name Is: " << name << endl;
    cout << "price Is: " << price << endl;
    cout << "production Date is: ";
    PrintProduction();
    cout << "expiration Date is: ";
    PrintExpiration();
    cout << "product's API is: " << API << endl;
    cout << "category Is: " << category << endl;
    cout << "product's Form is: " << form << endl;
}
void product::appendproduct() {
    string name = getName();
    double price = getPrice();
    string API = getAPI();
    string category = getCategory();
    string form = getForm();
    const char* PDate = GetProduction();
    const char* ExpDate = GetExpiration();
    int quantity = getQuantity();

    fstream medicinef;
    medicinef.open("medicines.txt", ios::app);
    if (medicinef.is_open()) {
        medicinef << "medicine Data:\n"
            << name << "\n"
            << price << "\n"
            << quantity << "\n"
            << API << "\n"
            << category << "\n"
            << form << "\n";
        for (int i = 0; i < 10; i++) {
            medicinef << PDate[i];
        }
        medicinef << "\nexpiration Date: ";
        for (int q = 0; q < 10; q++) {
            medicinef << ExpDate[q];
        }
        medicinef << "\n##################################################\n";
    }
    medicinef.close();
    cout << "\nYour product has been added successfully.\n";
}

void product::editproduct() {
    product pp;
    string name;
    string price;
    char production_Date[10];
    char expiration_Date[10];
    string API; // effective material
    string category;
    string form;
    int qua;
    string oldname;
    string oldprice;
    string oldProductionDate;
    string oldExpirationDate;
    string oldapi;
    string oldcatogery;
    string oldform;
    string oldquantiti;

    string eQuan, ePrice;

    cout << "Enter the  name: " << endl;
    pp.setName();
    bool result = pp.Searchtt("medicines.txt", pp.getName(), 7);
    if (result) {
        oldname = oldname = pp.result.followingLines[0];
        oldprice = pp.result.followingLines[1];
        oldquantiti = pp.result.followingLines[2];
        oldapi = pp.result.followingLines[3];
        oldcatogery = pp.result.followingLines[4];
        oldform = pp.result.followingLines[5];

        cout << "What data do you want to modify? "
            "\n1-name\n2-price\n3-quantity \n4-api\n5-catogery\n6-form\n";
        int x;
        while (!(cin >> x)) {
            cout << "Invalid input. Please enter an integer: ";
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(),
                '\n'); // Discard invalid input
        }
        switch (x) {
        case 1:
            pp.setName();
            pp.editData("medicines.txt", oldname, pp.getName());
            break;
        case 2:
            pp.setPrice();
            ePrice = to_string(pp.getPrice());
            pp.editData("medicines.txt", oldquantiti, ePrice);
            break;
        case 3:
            pp.setQuantity();
            eQuan = to_string(pp.getQuantity());
            pp.editData("medicines.txt", oldquantiti, eQuan);
            break;
        case 4:
            pp.setAPI();
            pp.editData("medicines.txt", oldapi, pp.getAPI());
            break;
        case 5:
            pp.setCategory();
            pp.editData("medicines.txt", oldcatogery, pp.getCategory());
            break;
        case 6:
            pp.setForm();
            pp.editData("medicines.txt", oldform, pp.getForm());
            break;

        default:
            break;
        }
    }
    else {
        cout << "Error: Full name not found in file." << endl;
    }
}
bool product::validateDay(int day) { return (day > 0 && day <= 31); }
bool product::validateMonth(int month) { return (month > 0 && month <= 12); }
bool product::validateYear(int year) { return (year >= 2024 && year <= 2034); }


