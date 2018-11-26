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
    unsigned long result = 0;

    if (index <= 0) {
        return 0;
    }
    if (index == 1) {
        return 1;
    }

    int calcIndex;
    if (index % 2 == 0) {
        calcIndex = index/2;

        unsigned long fibM0 = fibonacci(calcIndex);
        unsigned long fibM1 = fibonacci(calcIndex - 1);

        result = (2*fibM1 + fibM0)*fibM0;
    } else {
        calcIndex = (index + 1)/2;

        unsigned long fibM0 = fibonacci(calcIndex);
        unsigned long fibM1 = fibonacci(calcIndex - 1);

        result = fibM0*fibM0 + fibM1*fibM1;
    }

    return result;
}


