//
// Created by Diego Alberto Ortiz Mariscal A01552000, Diego Mojarro A01638460, Luis Armando Salazar A01114901
// November 01 2020
//

#ifndef INC_1_3_REGISTERENTRY_H
#define INC_1_3_REGISTERENTRY_H

#include <iostream>
#include <string>

using namespace std;

class RegisterEntry {
private:
    // Ip in decimal form
    unsigned long long ip;
    // String that contains the ip
    string stringIp;
public:
    // Constructor that receives a string containing a registry entry in format MMM DD HH:MM:SS IP Message
    // initializes the strings textRegistry Month, day, time, ip, ip port and textRegistry
    // O(1)
    explicit RegisterEntry(const string &textRegistry);

    // Default constructor
    // O(1)
    RegisterEntry();

    // Method that converts an ip from a string to its decimal form as an unsigned long long integer
    // O(n)
    static unsigned long long ipReader(const string &stringIp);

    // Getters and setters
    // O(1)

    unsigned long long int getIp() const;

    void setIp(unsigned long long int ip);

    const string &getStringIp() const;

    void setStringIp(const string &stringIp);

    // Stream output operator to display the text registry
    // O(1)
    friend ostream &operator<<(ostream &os, const RegisterEntry &entry);
};


#endif //INC_1_3_REGISTERENTRY_H
