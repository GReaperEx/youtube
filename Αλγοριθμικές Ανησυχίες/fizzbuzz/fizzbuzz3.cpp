#include <iostream>
#include <string>

using namespace std;

int main()
{
    for (int i = 1; i <= 100; ++i) {
        string toOutput = "";

        if (i % 3 == 0) {
            toOutput += "fizz";
        }
        if (i % 5 == 0) {
            toOutput += "buzz";
        }

        if (toOutput == "") {
            toOutput = to_string(i);
        }

        cout << toOutput << endl;
    }

    return 0;
}
