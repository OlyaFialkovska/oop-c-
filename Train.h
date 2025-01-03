#ifndef TRAIN_H
#define TRAIN_H

#include <vector>
#include <memory>
#include "Wagon.h"
#include "Locomotive.h"

class Train {
private:
    int trainNumber;
    std::string trainType;
    Locomotive locomotive;
    std::vector<std::shared_ptr<Wagon>> wagons;
public:
    Train(int trainNumber, const std::string& trainType, const Locomotive& locomotive);
    void addWagon(const std::shared_ptr<Wagon>& wagon);
    void displayInfo() const;
};

#endif // TRAIN_H
