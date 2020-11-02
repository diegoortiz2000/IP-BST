//
// Created by Diego Alberto Ortiz Mariscal A01552000, Diego Mojarro A01638460, Luis Armando Salazar A01114901
// November 01 2020
//

#include "RegisterEntry.h"
#include <iostream>
#include <sstream>

using namespace std;

RegisterEntry::RegisterEntry(const string &textRegistry) {
    // Cycle to split a string by space
    int stringPosition = 0;
    istringstream ss(textRegistry);
    do {
        string word;
        ss >> word;
        if (stringPosition == 3) {
            setIp(ipReader(word));
            std::stringstream ssPort(word);
            string partPort;
            bool ipWoPort = false;
            while (getline(ssPort, partPort, ':')) {
                if (!ipWoPort) {
                    setStringIp(partPort);
                    ipWoPort = true;
                }
            }
        }
        stringPosition++;
    } while (ss);
}

RegisterEntry::RegisterEntry() = default;

unsigned long long RegisterEntry::ipReader(const string &stringIp) {
    std::stringstream ss(stringIp);
    string part;
    unsigned long long ip;
    unsigned long long firstPosIp;
    unsigned long long secondPosIp;
    unsigned long long thirdPosIp;
    unsigned long long fourthPosIp;
    // Cycle to split an ip string by its respective separators
    int ipPos = 0;
    // Split by .
    while (getline(ss, part, '.')) {
        if (ipPos == 0) {
            firstPosIp = stoi(part);
        } else {
            if (ipPos == 1) {
                secondPosIp = stoi(part);
            } else {
                if (ipPos == 2) {
                    thirdPosIp = stoi(part);
                } else {
                    if (ipPos == 3) {
                        // Split by :
                        std::stringstream ssPort(part);
                        string partPort;
                        int ipPortPos = 0;
                        while (getline(ssPort, partPort, ':')) {
                            if (ipPortPos == 0) {
                                fourthPosIp = stoi(partPort);
                            }
                            ipPortPos++;
                        }
                    }
                }
            }
        }
        ipPos++;
    }
    // Operation to convert each respective position of an ip to its decimal equivalent
    ip = ((((firstPosIp * 256 + secondPosIp) * 256 + thirdPosIp) * 256) + fourthPosIp);
    return ip;
}

unsigned long long int RegisterEntry::getIp() const {
    return ip;
}

void RegisterEntry::setIp(unsigned long long int ip) {
    RegisterEntry::ip = ip;
}

const string &RegisterEntry::getStringIp() const {
    return stringIp;
}

void RegisterEntry::setStringIp(const string &stringIp) {
    RegisterEntry::stringIp = stringIp;
}

ostream &operator<<(ostream &os, const RegisterEntry &entry) {
    os << entry.stringIp;
    return os;
}