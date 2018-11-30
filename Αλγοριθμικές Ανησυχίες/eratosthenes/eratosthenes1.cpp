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
    vector<int> tempArray(maxValue - 1);
    for (int i = 0; i < tempArray.size(); ++i) {
        tempArray[i] = i + 2;
    }

    int p = 2;
    int primesFound = 1;

    while (p*p <= maxValue) {
        primes.clear();

        for (int i = 0; i < primesFound; ++i) {
            primes.push_back(tempArray[i]);
        }
        for (int i = primesFound; i < tempArray.size(); ++i) {
            if (tempArray[i] % p != 0) {
                primes.push_back(tempArray[i]);
            }
        }
        p = primes[primesFound++];
        tempArray = primes;
    }
}
