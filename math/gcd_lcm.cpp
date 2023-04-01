#include "bits/stdc++.h"
using namespace std;

unsigned long long int trailing_zeroes(unsigned long long int n) {
	unsigned long long int bits = 0, x = n;
	if (x) {
		while ((x & 1) == 0) {
			++bits;
			x >>= 1;
		}
	}
	return bits;
}
//Euclidean algorithm by division
//most efficient i've found thus far
//TC := O(log(a+b))
//a>=b
unsigned long long int gcd(unsigned long long int a, unsigned long long int b) {
    if (!a || !b)
        return a | b;
	unsigned long long int shift = trailing_zeroes(a | b);
    a >>= trailing_zeroes(a);
    do {
        b >>= trailing_zeroes(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}
//a>=b
unsigned long long int lcm(unsigned long long int a, unsigned long long int b) {
	if (a + b == 0) {
		return 0;
	}
	//will probably overflow because of a*b lol
	return (a / gcd(a, b)) * b;
}

int main(){
    int a=1;
    cin>>a;
    while(a!=0){
        int cont=0;
        for(int i=0 ; i<a ; i++){
            if(gcd(i,a)==1){
                cont++;
            }
        }
        cout<<cont<<endl;
        cin>>a;
    }   
    return 0;
}