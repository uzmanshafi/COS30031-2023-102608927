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

//3. declare a pointer to a variable and demonstrate the setting and reading of the value in the variable using the pointer
void demoPointer()
{
    int a = 3;
    int *ptr = &a;
    cout << "Original Value of a : " << a << endl;
    cout << "Value of a using pointer : " << *ptr << endl;
}

//4. Create a function that uses a for loop to print all odd numbers between 0 and 20 on a single text line of text output, formatted with spaces. Call this from main.
void PrintOddNumbers()
{
    for (int i = 0; i < 20; i++)
    {
        if (i % 2 != 0)
        {
            cout << i << " ";
        }
    }
}


int main()
{
    //1.
    PrintTwoValues(10, 10);

    //2.
    int a = 4;
    int alteredValue = AlterValue(a);
    cout << "Altered Value : " << alteredValue << endl;

    //3. 
    demoPointer();

    //4.
    PrintOddNumbers();

    return 0;
}