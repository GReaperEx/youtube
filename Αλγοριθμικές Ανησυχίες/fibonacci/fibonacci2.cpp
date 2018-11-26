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
    unsigned long prevNum, curNum;

    prevNum = 0;
    curNum = 1;

    if (index <= 0) {
        return 0;
    }
    if (index == 1) {
        return 1;
    }

    for (int i = 2; i <= index; ++i) {
        unsigned long temp = prevNum + curNum;
        prevNum = curNum;
        curNum = temp;
    }

    return curNum;
}

