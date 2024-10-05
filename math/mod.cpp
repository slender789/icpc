#include <iostream>
#include <vector>
#include <numeric> // For std::accumulate
#include <cmath>   // For std::pow

using namespace std;

const long long MOD = 1000000007;

// Function to perform modular addition
long long sumaMOD(long long a, long long b) {
    return (a + b) % MOD;
}

// Function to perform modular multiplication
long long multMOD(long long a, long long b) {
    return (a * b) % MOD;
}

// Function to perform modular subtraction
long long restaMOD(long long a, long long b) {
    return ((a - b) % MOD + MOD) % MOD;
}

// Function to perform modular division
long long divMOD(long long a, long long b) {
    // Fermat's Little Theorem for finding modular inverse
    // Since MOD is prime, use pow for the modular inverse
    return multMOD(a, static_cast<long long>(pow(b, MOD - 2)));
}

int main() {
    int n;
    cin >> n;

    long long answer = 1;

    // Calculate factorial using modular multiplication
    for (int i = 2; i <= n; i++) {
        answer = multMOD(answer, i);
    }

    // Count the number of trailing zeros
    int cont = 0;
    while (answer % 10 == 0) {
        answer /= 10;
        cont++;
    }

    cout << cont << endl;
    return 0;
}
