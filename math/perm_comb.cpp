#include <iostream>

// Function to calculate factorial
long long factorial(int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to calculate permutations P(n, r)
long long permutation(int n, int r) {
    return factorial(n) / factorial(n - r);
}

// Function to calculate combinations C(n, r)
long long combination(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

int main() {
    int n = 5;
    int r = 3;
    std::cout << "P(" << n << ", " << r << ") = " << permutation(n, r) << std::endl;
    std::cout << "C(" << n << ", " << r << ") = " << combination(n, r) << std::endl;
    return 0;
}
