#ifndef COLLECTION_H
#define COLLECTION_H

#include <vector>
#include <iostream>

template<typename T>
class Collection {
private:
    std::vector<T> items;
public:
    void add(const T& item) {
        items.push_back(item);
    }

    void displayAll() const {
        for (const auto& item : items) {
            item.displayInfo();
        }
    }
};

#endif // COLLECTION_H
