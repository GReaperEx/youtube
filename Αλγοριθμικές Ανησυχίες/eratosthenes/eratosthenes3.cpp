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
    primes.clear();
    primes.push_back(2);

    for (int i = 3; i <= maxValue; i += 2) {
        bool isPrime = true;

        for (int p : primes) {
            if (p*p > i) {
                break;
            }
            if (i % p == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            primes.push_back(i);
        }
    }
}

