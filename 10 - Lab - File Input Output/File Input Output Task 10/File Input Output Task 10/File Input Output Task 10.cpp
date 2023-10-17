#include "Data.h"
#include <iostream>
#include <fstream>

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

    void saveToFile(const Data& data, const string& filename) {
        ofstream file(filename, ios::binary);
        file.write((char*)&data, sizeof(data));
        file.close();
    }

    saveToFile(myData, "test1.bin");

}

