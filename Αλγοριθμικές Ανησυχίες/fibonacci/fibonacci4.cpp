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

class mat2
{
public:
    unsigned long data[2][2];

    mat2(unsigned long m11, unsigned long m12, unsigned long m21, unsigned long m22) {
        data[0][0] = m11;
        data[0][1] = m12;
        data[1][0] = m21;
        data[1][1] = m22;
    }

    const mat2 operator* (const mat2& other) const {
        return mat2(data[0][0]*other.data[0][0] + data[0][1]*other.data[1][0],
                    data[0][0]*other.data[0][1] + data[0][1]*other.data[1][1],
                    data[1][0]*other.data[0][0] + data[1][1]*other.data[1][0],
                    data[1][0]*other.data[0][1] + data[1][1]*other.data[1][1]);
    }

    const mat2 pow(int exponent) const {
        if (exponent <= 0) {
            return mat2(1, 0, 0, 1);
        }
        if (exponent == 1) {
            return *this;
        }

        if (exponent % 2 == 0) {
            return (*this * *this).pow(exponent/2);
        }
        return (*this * *this).pow(exponent/2) * *this;
    }
};

unsigned long fibonacci(int index)
{
    if (index <= 0) {
        return 0;
    }
    if (index == 1) {
        return 1;
    }

    mat2 fibMatrix = mat2(1, 1, 1, 0).pow(index);

    return fibMatrix.data[0][1];
}

