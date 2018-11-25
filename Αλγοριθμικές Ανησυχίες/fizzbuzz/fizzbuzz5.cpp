#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    map<int, string> buzzfizz = {
        { 3, "fizz" }, { 5, "buzz" }
    };

    for (int i = 1; i <= 100; ++i) {
        string toOutput = "";
        for (auto iter = buzzfizz.begin(); iter != buzzfizz.end(); ++iter) {
            if (i % iter->first == 0) {
                toOutput += iter->second;
            }
        }

        if (toOutput == "") {
            toOutput = to_string(i);
        }
        cout << toOutput << endl;
    }

    return 0;
}
