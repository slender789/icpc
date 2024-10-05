#include <iostream>
#include <vector>
#include <bitset>
#include <set>
#include <cmath>

using namespace std;

// Constant to define the maximum limit for prime calculation
const int MAX = 3000;

// Function to generate a list of prime numbers using the Sieve of Eratosthenes
vector<int> primes() {
    bitset<MAX> bits;
    bits[0] = bits[1] = 1; // Mark 0 and 1 as non-prime
    int sqrt_max = static_cast<int>(sqrt(MAX)) + 1;
    vector<int> primes_vec;

    // Sieve of Eratosthenes
    for (int i = 2; i <= sqrt_max; i++) {
        if (bits[i]) continue; // Skip if i is marked as non-prime
        for (int j = i * i; j < MAX; j += i) {
            bits[j] = 1; // Mark multiples of i as non-prime
        }
    }

    // Collecting prime numbers
    for (int i = 2; i < bits.size(); i++) {
        if (!bits[i]) {
            primes_vec.push_back(i); // Add prime number to the vector
        }
    }
    return primes_vec;
}

int main() {
    int n;
    vector<int> primes_v = primes(); // Generate list of primes

    cin >> n; // Input number
    int count = 0; // Count of numbers with exactly two distinct prime factors

    // Loop through all numbers from n down to 1
    while (n > 0) {
        vector<int> factors; // To store factors of the current number
        set<int> factorsSet; // To store unique factors
        int m = n; // Copy of n for factorization

        // Factorization using the list of prime numbers
        for (int x : primes_v) {
            while (m % x == 0) {
                factors.push_back(x); // Store factor
                m /= x; // Reduce m by the factor
            }
        }

        // Insert factors into the set for uniqueness
        for (int x : factors) {
            factorsSet.insert(x);
        }

        // Check if the number has exactly two distinct prime factors
        if (factorsSet.size() == 2) {
            count++;
        }
        n--; // Decrement n to check the next number
    }
    
    cout << count; // Output the count
    return 0;
}
