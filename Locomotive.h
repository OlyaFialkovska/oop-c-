#ifndef LOCOMOTIVE_H
#define LOCOMOTIVE_H

#include <string>
#include <iostream>

class Locomotive {
private:
    std::string type;
    int power;
public:
    Locomotive(const std::string& type, int power);
    void displayInfo() const;
};

#endif // LOCOMOTIVE_H
