#include "Wagon.h"

// Реалізація FreightWagon
FreightWagon::FreightWagon(double loadCapacity, double cargoWeight, const std::string& cargoType)
    : loadCapacity(loadCapacity), cargoWeight(cargoWeight), cargoType(cargoType) {}

void FreightWagon::displayInfo() const {
    std::cout << "Freight Wagon - Load Capacity: " << loadCapacity
              << " tons, Cargo Weight: " << cargoWeight
              << " tons, Cargo Type: " << cargoType << "\n";
}

// Реалізація PassengerWagon
PassengerWagon::PassengerWagon(int seats, int passengers)
    : seats(seats), passengers(passengers) {}

void PassengerWagon::displayInfo() const {
    std::cout << "Passenger Wagon - Seats: " << seats
              << ", Passengers: " << passengers << "\n";
}
