#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // Assignment and Dereferencing

    int a;
    int b;

    cout << "Enter a number: ";
    cin >> a;

    cout << "Enter another number: ";
    cin >> b;

    int* ptr_a = &a;
    int* ptr_b = &b;

    cout << "Value of a: " << *ptr_a << endl;
    cout << "Value of b: " << *ptr_b << endl;

    cout << endl;


    // Maximum in an Array

    int numbers[] = {15, 8, 42, 27, 91, 34};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    int* max_ptr = numbers;

    for (int* ptr = numbers; ptr < numbers + size; ptr++)
    {
        if (*ptr > *max_ptr)
        {
            max_ptr = ptr;
        }
    }

    cout << "Largest number in the array: " << *max_ptr << endl;

    cout << endl;


    // Length of a C-Style String

    char word[] = "Harper";

    char* ptr = word;
    int length = 0;

    while (*ptr != '\0')
    {
        length++;
        ptr++;
    }

    cout << "Length of the string: " << length << endl;

    cout << endl;


    // Reverse a C-Style String

    char text[] = "Computer";

    char* start = text;
    char* end = text;

    while (*end != '\0')
    {
        end++;
    }

    end--;

    cout << "Reversed string: ";

    while (end >= start)
    {
        cout << *end;
        end--;
    }

    cout << endl;
    cout << endl;


    // Midpoint in a Vector

    vector<int> values = {10, 20, 30, 40, 50, 60};

    int* left = &values[0];
    int* right = &values[values.size() - 1];

    while (left + 1 < right)
    {
        left++;
        right--;
    }

    cout << "Midpoint value: " << *left << endl;

    return 0;
}