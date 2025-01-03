#include <iostream>
#include <memory>
#include "Train.h"
#include "Wagon.h"

int main() {
    Locomotive locomotive("Diesel", 3000);

    Train train(12345, "Mixed", locomotive);

    train.addWagon(std::make_shared<FreightWagon>(50.0, 30.0, "Coal"));
    train.addWagon(std::make_shared<PassengerWagon>(100, 80));

    train.displayInfo();

    return 0;
}
