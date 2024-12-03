#include <iostream>
using namespace std;
#include "ooplaba_2_container.h"

int main() {
        int arr[] = {1, 2, 3, 4, 5};
        Container<int> intContainer(arr, 5);
        intContainer.printValues();
        intContainer.printType();

        intContainer.setElement(2, 42);
        intContainer.printValues();

        intContainer.resize(7, 99);
        intContainer.printValues();

        intContainer.inputValues(3);
        intContainer.printValues();
        intContainer.printType();

        float arrFloat[] = {3.14, 2.71, 1.61};
        Container<float> floatContainer(arrFloat, 3);
        floatContainer.printValues();
        floatContainer.printType();

        char arrChar[] = {'A', 'B', 'C'};
        Container<char> charContainer(arrChar, 3);
        charContainer.printValues();
        charContainer.printType();

        double arrDouble[] = {3.1415, 2.7182, 1.4142};
        Container<double> doubleContainer(arrDouble, 3);
        doubleContainer.printValues();
        doubleContainer.printType();

        bool arrBool[] = {true, false, true};
        Container<bool> boolContainer(arrBool, 3);
        boolContainer.printValues();

        boolContainer.setElement(1, true); 
        boolContainer.printValues();

        boolContainer.resize(5, false); 
        boolContainer.printValues();

        boolContainer.printType();
    return 0;
}
