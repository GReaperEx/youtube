#include <iostream>

using namespace std;

unsigned long fibonacci(int index);

int main()
{
    int index;

    cout << "Which fibonacci number do you want? ";
    cin >> index;

    cout << "fibonacci(" << index << ") = " << fibonacci(index) << endl;

    return 0;
}

unsigned long fibonacci(int index)
{
    if (index <= 0) {
        return 0;
    }
    if (index == 1) {
        return 1;
    }
    return fibonacci(index - 1) + fibonacci(index - 2);
}
