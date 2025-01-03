#include "Train.h"

// Реалізація Train
Train::Train(int trainNumber, const std::string& trainType, const Locomotive& locomotive)
    : trainNumber(trainNumber), trainType(trainType), locomotive(locomotive) {}

void Train::addWagon(const std::shared_ptr<Wagon>& wagon) {
    wagons.push_back(wagon);
}

void Train::displayInfo() const {
    std::cout << "Train Number: " << trainNumber << ", Type: " << trainType << "\n";
    locomotive.displayInfo();
    std::cout << "Wagons:\n";
    for (const auto& wagon : wagons) {
        wagon->displayInfo();
    }
}
    