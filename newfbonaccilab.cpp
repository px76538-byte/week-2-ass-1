#include <iostream>
using namespace std;

int recursiveCalls = 0;

int fibonacciRecursive(int n)
{
    recursiveCalls++;

    if (n == 1 || n == 2)
    {
        return 1;
    }
    else
    {
        return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
    }
}

int fibonacciLoop(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }

    int first = 1;
    int second = 1;
    int answer = 0;
    int loopCount = 0;

    for (int i = 3; i <= n; i++)
    {
        answer = first + second;
        first = second;
        second = answer;
        loopCount++;
    }

    cout << "Loop iterations: " << loopCount << endl;

    return answer;
}

int main()
{
    int n = 10;

    cout << "Recursive Fibonacci of " << n << ": "
         << fibonacciRecursive(n) << endl;

    cout << "Recursive function calls: " << recursiveCalls << endl;

    cout << "Loop Fibonacci of " << n << ": "
         << fibonacciLoop(n) << endl;

    cout << endl;

    cout << "Answer 1: The recursive function is called "
         << recursiveCalls << " times." << endl;

    cout << "Answer 2: The recursive version is inefficient because it repeats "
         << "the same calculations many times." << endl;

    cout << "Answer 3: The loop runs 8 times when n is 10." << endl;

    return 0;
}