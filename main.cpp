#include "pharmcy.h"
#include <cctype>
#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
using namespace std;
string getPasswordowner() {
    string password;
    cout << "Enter your password: ";
    cin >> password;
    return password;
}
bool passwordChecker(string filename) {
    bool passwordCorrect = false;
    int attempts = 3;
    employee Employee;
    string UserName;
    string password;
    string UserName0;
    string usint;
    string UserName1;
    cout << "Enter your firstname:" << endl;
    cin >> UserName0;
    cout << "Enter the second char of username :" << endl;
    cin >> UserName1;
    cout << "Enter the  number of username :" << endl;
    cin >> usint;
    UserName = UserName0 + "_" + UserName1 + "_" + usint;
    bool result = Employee.Searchtt(filename, UserName, 6);
    if (result) {
        while (attempts > 0) {
            cout << "Enter your password:" << endl;
            cin >> password;
            string correctPass = Employee.result.followingLines.at(6);
            if (password.length() == 0) {
                cout << "Password cannot be empty. " << endl;
            }
            else if (password.length() != 6) {
                cout << "Password must be 6 characters. " << endl;
            }

            if (correctPass == password) {
                cout << "Password correct. Welcome!" << endl;
                passwordCorrect = true;
                return true;
            }
            else {
                cout << "Incorrect password. Please try again." << endl;
                attempts--;
            }
        }
        if (attempts == 0) {
            cout << "You have exceeded the maximum number of attempts. Exiting..."
                << endl;
            return false;
        }

    }

    else {
        cout << "error no name found in the file !" << endl;
        return false;
    }
}
vector<string> readFile(const string& filename) {
    vector<string> lines;
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            lines.push_back(line);
        }
        file.close();
    }
    else {
        cout << "Unable to open file: " << filename << endl;
    }
    return lines;
}
void cashierMenu() {
    while (true) {
        cout << "\n===== cashier inventory menu =====" << endl;
        cout << "1. add product to transaction cart" << endl;
        cout << "2. display products in inventory" << endl;
        cout << "3. add customer" << endl;
        cout << "4. edit customer" << endl;
        cout << "5. search customer" << endl;
        cout << "6. back to job roles" << endl;

        product p1;
        Customer p2;
        int choice;
        string cname;
        vector<string> dt;
        string name7;
        string name8;
        string name9;
        string name10;
        int n = 0, total = 1;
        vector<int> totalV;

        cout << "enter your choice: ";
        while (!(cin >> choice)) {
            cout << "Invalid input. Please enter an integer: ";
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(),
                '\n'); // Discard invalid input
        }
        cout << endl;

        if (choice == 1) {
        }
        else if (choice > 1) {
            choice++;
        }

        switch (choice) {
        case 1:
            cout << "\nSelect a medicine by entering its number:\n";
            cout << "1. Paracetamol\n";
            cout << "2. Ibuprofen\n";
            cout << "3. Vitamin-C\n";
            cout << "4. Vitamin-D3\n";
            cout << "5. Amoxicillin\n";
            cout << "6. Ciprofloxacin\n";
            cout << "7. Prednisone\n";
            cout << "8. Dexamethasone\n";
            cout << "9. Lactulose\n";
            cout << "10. Bisacodyl\n";
            cout << "Enter your choice (1-10) : ";
            while (!(cin >> choice)) {
                cout << "Invalid input. Please enter an integer: ";
                cin.clear(); // Clear error flags
                cin.ignore(numeric_limits<streamsize>::max(),
                    '\n'); // Discard invalid input
            }

            switch (choice) {
            case 1:
                cout << "You selected Paracetamol.\n";
                totalV.push_back(p1.addCart("paracetamol"));
                n--;
                break;
            case 2:
                cout << "You selected Ibuprofen.\n";
                totalV.push_back(p1.addCart("ibuprofen"));
                n--;
                break;
            case 3:
                cout << "You selected Vitamin C.\n";
                totalV.push_back(p1.addCart("vitamin-c"));
                n--;
                break;
            case 4:
                cout << "You selected Vitamin D3.\n";
                totalV.push_back(p1.addCart("vitamin-d3"));
                n--;
                break;
            case 5:
                cout << "You selected Amoxicillin.\n";
                totalV.push_back(p1.addCart("amoxicillin"));
                n--;
                break;
            case 6:
                cout << "You selected Ciprofloxacin.\n";
                totalV.push_back(p1.addCart("ciprofloxacin"));
                n--;
                break;
            case 7:
                cout << "You selected Prednisone.\n";
                totalV.push_back(p1.addCart("prednisone"));
                n--;
                break;
            case 8:
                cout << "You selected Dexamethasone.\n";
                totalV.push_back(p1.addCart("dexamethasone"));
                n--;
                break;
            case 9:
                cout << "You selected Lactulose.\n";
                totalV.push_back(p1.addCart("lactulose"));
                n--;
                break;
            case 10:
                cout << "You selected Bisacodyl.\n";
                totalV.push_back(p1.addCart("bisacodyl"));
                n--;
                break;
            default:
                cout << "Invalid choice.\n";
                n--;
                return;
            }
        case 2:
            for (int t : totalV)
                total *= t;
            cout << "\nyout total is " << total << endl;
            break;
        case 3:
            dt = readFile("medicines.txt");
            for (const string& line : dt) {
                cout << line << endl;
            }
            break;
        case 4:
            p2.SetName();
            p2.SetAddress();
            p2.SetAge();
            p2.SetNumber();
            p2.SetGender();
            p2.SetDuAmount();
            p2.appendcustomer();
            break;
        case 5:
            p2.editcustomer();
            break;
        case 6:
            cout << "enter the name of the customer:" << endl;
            cin >> name7;
            cin >> name8;
            cin >> name9;
            name10 = name7 + "_" + name8 + "_" + name9;
            for (char c : name10) {
                cname += tolower(c);
            }

            p2.bestSearch("customer.txt", cname, 5);
            break;
        case 7:
            return;
        default:
            cout << "invalid choice. please try again." << endl;
        }
    }
}
void ownerMenu() {
    while (true) {
        cout << "\n===== Owner Inventory Menu =====" << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. Search Employee" << endl;
        cout << "3. Edit Employee" << endl;
        cout << "4. Display Employees" << endl;
        cout << "5. Back to Job Roles" << endl;
        vector<string> data;
        employee e1;
        int choice;
        string name, name0, name1, name2, name3;
        string fileName;
        cout << "Enter your choice: ";
        while (!(cin >> choice)) {
            cout << "Invalid input. Please enter an integer: ";
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(),
                '\n'); // Discard invalid input
        }
        switch (choice) {
        case 1:
            fileName = e1.employeetype();
            e1.SetName();
            e1.SetAddress();
            e1.SetAge();
            e1.SetNumber();
            e1.SetSallary();
            e1.SetPassword();
            e1.appendEmployee(fileName);

            break;
        case 2:
            fileName = e1.employeetype();
            cout << "enter the name of the employee:\n" << endl;
            cin >> name1;
            cin >> name2;
            cin >> name3;
            name0 = name1 + "_" + name2 + "_" + name3;
            for (char c : name0) {
                name += tolower(c);
            }
            e1.bestSearch(fileName, name, 6);

            break;
        case 3:
            fileName = e1.employeetype();
            e1.editemployee(fileName);
            break;
        case 4:
            fileName = e1.employeetype();
            data = readFile(fileName);
            for (const string& line : data) {
                cout << line << endl;
            }
            break;
        case 5:
            return;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}
void pharmacistMenu() {
    while (true) {
        cout << "\n===== Pharmacist Inventory Menu =====" << endl;
        cout << "1. Add Product to Inventory" << endl;
        cout << "2. Search Product in Inventory" << endl;
        cout << "3. Display Products in Inventory" << endl;
        cout << "4. Edit Products in Inventory" << endl;
        cout << "5. Back to Job Roles" << endl;

        int choice;
        product ob5;
        string NAME;
        vector<string> dta;

        cout << "Enter your choice: ";
        while (!(cin >> choice)) {
            cout << "Invalid input. Please enter an integer: ";
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(),
                '\n'); // Discard invalid input
        }
        switch (choice) {
        case 1:
            ob5.setName();
            ob5.setPrice();
            ob5.setQuantity();
            ob5.setProduction();
            ob5.setExpiration();
            ob5.setAPI();
            ob5.setCategory();
            ob5.setForm();

            ob5.appendproduct();
            break;
        case 2:
            cout << "please enter the name of the product you want to search about\n";
            cin >> NAME;
            ob5.bestSearch("medicines.txt", NAME, 8);
            break;
        case 3:
            dta = readFile("medicines.txt");
            for (const string& line : dta) {
                cout << line << endl;
            }
            break;
        case 4:
            ob5.editproduct();
            break;
        case 5:
            return;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(void) {
    int choice = 0;
    string userName;
    const string mainPassword = "d1234";
    string password;
    int attempts = 3;
    while (true) {
        cout << "\n###### Pharmacy Management System ######" << endl;
        cout << "Job Roles:" << endl;
        cout << "1. Owner" << endl;
        cout << "2. Cashier" << endl;
        cout << "3. Pharmacist" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your job role: ";
        while (!(cin >> choice)) {
            cout << "Invalid input. Please enter an integer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        switch (choice) {
        case 1:
            while (attempts > 0) {
                password = getPasswordowner();
                if (password == mainPassword) {
                    cout << "Welcome to the Dealers System\n";
                    ownerMenu();
                    break;
                }
                else {
                    cout << "Password is wrong. Please try again.\n";
                    attempts--;
                }
            }

            if (attempts == 0) {
                cout << "You have exceeded the maximum number of attempts.\n "
                    "Exiting.............\n";
                return 0;
            }
            break;
        case 2:
            if (passwordChecker("Cashier.txt")) {
                cashierMenu();
            }
            else {
                cout << "error Error: Unable to open account! \n";
            }

            break;
        case 3:
            if (passwordChecker("Pharmacist.txt")) {
                pharmacistMenu();
            }
            else {
                cout << "error Error: Unable to open account! \n";
            }

            break;
        case 4:
            exit(0);
        default:
            cout << "Please Enter number between 1 -> 5" << endl;
        }
    }
}

+