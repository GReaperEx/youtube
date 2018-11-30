#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

void eratoPrimes1(vector<int>& primes, int maxValue);
void eratoPrimes2(vector<int>& primes, int maxValue);
void eratoPrimes3(vector<int>& primes, int maxValue);

int main()
{
    vector<int> primes;

    void (*eratoPrimes[])(vector<int>&, int) = {
        eratoPrimes1, eratoPrimes2, eratoPrimes3
    };

    for (int j = 10000; j <= 1000000; j += 10000) {
        for (int i = 0; i < 3; ++i) {
            auto t1 = chrono::high_resolution_clock::now();
            for (int k = 0; k < 10; ++k) {
                eratoPrimes[i](primes, j);
            }
            auto t2 = chrono::high_resolution_clock::now();

            cout << chrono::duration_cast<chrono::duration<double>>(t2 - t1).count()*100 << ' ';
        }
        cout << endl;
    }

    return 0;
}

void eratoPrimes1(vector<int>& primes, int maxValue)
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

void eratoPrimes2(vector<int>& primes, int maxValue)
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

void eratoPrimes3(vector<int>& primes, int maxValue)
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
