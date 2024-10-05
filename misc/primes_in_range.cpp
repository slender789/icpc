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
    int m, l, u;
    vector<int>primes_v=primes();

    cin>>m;

    while(m){
        cin>>l>>u;

        vector<int>::iterator mi, mx;

        mi=upper_bound(primes_v.begin(), primes_v.end(),l-1);
        mx=upper_bound(primes_v.begin(), primes_v.end(),u);
        
        if (u==1) {
            cout<<0<<endl;
        }
        else{
            cout<<(int)(mx-primes_v.begin())-(int)(mi-primes_v.begin())<<endl;
        }
        m--;
    }
}
