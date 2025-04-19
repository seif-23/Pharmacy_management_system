#ifndef MENU_H
#define MENU_H

#include <string>

class Menu
{
public:
    static void cashierMenu();
    static void ownerMenu();
    static void pharmacistMenu();
    static std::string getPasswordowner();
    static bool passwordChecker(std::string filename);
};

#endif // MENU_H