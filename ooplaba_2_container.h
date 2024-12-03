#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;

template <typename T>
class Container {
private:
    vector<T> values;

public:
    Container() = default;

    explicit Container(const T* array, size_t size) {
        values.assign(array, array + size);
    }

    void printValues() const {
        cout << "Values: ";
        for (const auto& val : values) {
            cout << val << " ";
        }
        cout << endl;
    }

    void inputValues(size_t count) {
        values.clear();
        cout << "Enter " << count << " values: ";
        for (size_t i = 0; i < count; ++i) {
            T value;
            cin >> value;
            values.push_back(value);
        }
    }

    void printType() const {
        if (typeid(T) == typeid(char)) {
            cout << "Type: char" << endl;
        } else if (typeid(T) == typeid(int)) {
            cout << "Type: int" << endl;
        } else if (typeid(T) == typeid(float)) {
            cout << "Type: float" << endl;
        } else if (typeid(T) == typeid(double)) {
            cout << "Type: double" << endl;
        } else if (typeid(T) == typeid(bool)) {
            cout << "Type: bool" << endl;
        } else {
            cout << "Type: unknown" << endl;
        }
    }

    size_t size() const {
        return values.size();
    }

    void resize(size_t newSize, T defaultValue = T()) {
        values.resize(newSize, defaultValue);
    }

    T getElement(size_t index) const {
        if (index < values.size()) {
            return values[index];
        } else {
            cout << "Error" << endl;
        }
    }

    void setElement(size_t index, const T& value) {
        if (index < values.size()) {
            values[index] = value;
        } else {
            cout << "Error" << endl;
        }
    }
};

#endif // CONTAINER_H
