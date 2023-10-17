#include "Data.h"
#include <iostream>

int main() {
    Data myData;
    myData.character = 'A';
    myData.integer = 123;
    myData.floatingPoint = 123.45;

    void printData(const Data & data) {
        cout << "Char: " << data.character << endl;
        cout << "Int: " << data.integer << endl;
        cout << "Float: " << data.floatingPoint << endl;
    }

    printData(myData);

}

