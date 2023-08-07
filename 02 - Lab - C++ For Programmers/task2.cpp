#include <iostream>

using namespace std;

// 1. created a function that takes two values and prints them. 
void PrintTwoValues(int a, int b)
{
    cout << "Int 1 : " << a  << " " << "Int 2 : " << b << endl;
}

// 2. created a function that alters a value and returns them.
int AlterValue(int a)
{
    a *= 4;
    return a;
}

int main()
{
    //1.
    PrintTwoValues(10, 10);

    //2.
    int a = 4;
    int alteredValue = AlterValue(a);
    cout << "Altered Value : " << alteredValue << endl;

    return 0;
}