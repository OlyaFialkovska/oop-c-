#ifndef WAGON_H
#define WAGON_H

#include <string>
#include <iostream>

// Базовий клас Wagon
class Wagon {
public:
    virtual void displayInfo() const = 0; // Чисто віртуальний метод
    virtual ~Wagon() = default;
};

// Вантажний вагон
class FreightWagon : public Wagon {
private:
    double loadCapacity;
    double cargoWeight;
    std::string cargoType;
public:
    FreightWagon(double loadCapacity, double cargoWeight, const std::string& cargoType);
    void displayInfo() const override;
};

// Пасажирський вагон
class PassengerWagon : public Wagon {
private:
    int seats;
    int passengers;
public:
    PassengerWagon(int seats, int passengers);
    void displayInfo() const override;
};

#endif // WAGON_H
