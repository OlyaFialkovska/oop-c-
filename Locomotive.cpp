#include "Locomotive.h"

// Реалізація Locomotive
Locomotive::Locomotive(const std::string& type, int power)
    : type(type), power(power) {}

void Locomotive::displayInfo() const {
    std::cout << "Locomotive - Type: " << type << ", Power: " << power << " kW\n";
}
