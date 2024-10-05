#include <iostream>
#include <algorithm> // For std::swap
#include <numeric>   // For std::gcd (C++17)

using namespace std;

// Function to count the number of trailing zeroes in the binary representation of n
unsigned long long int trailing_zeroes(unsigned long long int n) {
    unsigned long long int bits = 0;
    while (n && (n & 1) == 0) {
        ++bits;
        n >>= 1;
    }
    return bits;
}

// Efficient GCD calculation using the Euclidean algorithm
unsigned long long int gcd(unsigned long long int a, unsigned long long int b) {
    if (a == 0 || b == 0) {
        return a | b; // Return non-zero value
    }
    
    unsigned long long int shift = trailing_zeroes(a | b);
    a >>= trailing_zeroes(a); // Remove factors of 2 from a
    
    do {
        b >>= trailing_zeroes(b); // Remove factors of 2 from b
        if (a > b) {
            swap(a, b);
        }
        b -= a; // Subtract a from b
    } while (b != 0);

    return a << shift; // Restore factors of 2
}

// LCM calculation using GCD
unsigned long long int lcm(unsigned long long int a, unsigned long long int b) {
    if (a == 0 && b == 0) {
        return 0; // LCM of 0 and 0 is undefined
    }
    return (a / gcd(a, b)) * b; // Calculate LCM
}

// Function to count the number of integers less than a that are coprime to a
unsigned long long int countCoprimes(unsigned long long int a) {
    unsigned long long int count = 0;
    for (unsigned long long int i = 1; i < a; i++) {
        if (gcd(i, a) == 1) {
            count++;
        }
    }
    return count;
}

int main() {
    unsigned long long int a;
    cin >> a;

    while (a != 0) {
        unsigned long long int coprimeCount = countCoprimes(a);
        cout << coprimeCount << endl;
        cin >> a;
    }

    return 0;
}
