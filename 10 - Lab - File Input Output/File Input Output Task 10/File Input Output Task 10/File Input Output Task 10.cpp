

// PART A
//#include "Data.h"
//#include <iostream>
//#include <fstream>
//using namespace std;
//
//void printData(const Data & data) {
//    cout << "Char: " << data.character << endl;
//    cout << "Int: " << data.integer << endl;
//    cout << "Float: " << data.floatingPoint << endl;
//}
//
//void saveToFile(const Data& data, const string& filename) {
//    ofstream file(filename, ios::binary);
//    file.write((char*)&data, sizeof(data));
//    file.close();
//}
//
//void loadFromFile(Data& data, const string& filename) {
//    ifstream file(filename, ios::binary);
//    file.read((char*)&data, sizeof(data));
//    file.close();
//}
//
//int main() {
//    Data myData;
//    myData.character = 'A';
//    myData.integer = 123;
//    myData.floatingPoint = 123.45;
//
//    saveToFile(myData, "test1.bin");
//    loadFromFile(myData, "test1.bin");
//    printData(myData);
//}
