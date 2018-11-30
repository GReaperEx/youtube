#include <iostream>
#include <vector>

using namespace std;

void eratoPrimes(vector<int>& primes, int maxValue);

int main()
{
    int input;

    cout << "Print primes up to what value? ";
    cin >> input;

    vector<int> primes;
    eratoPrimes(primes, input);

    auto iter = primes.begin();
    cout << *iter++;
    for (; iter != primes.end(); ++iter) {
        cout << ", " << *iter;
    }
    cout << endl;

    return 0;
}

void eratoPrimes(vector<int>& primes, int maxValue)
{
    vector<bool> tempArray(maxValue - 1, true);

    for (int i = 0; i*i <= tempArray.size(); ++i) {
        if (tempArray[i]) {
            int mult = i + 2;
            for (int j = i + mult; j < tempArray.size(); j += mult) {
                tempArray[j] = false;
            }
        }
    }

    primes.clear();
    for (int i = 0; i < tempArray.size(); ++i) {
        if (tempArray[i]) {
            primes.push_back(i + 2);
        }
    }
}
