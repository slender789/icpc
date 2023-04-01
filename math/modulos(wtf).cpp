#include "bits/stdc++.h"
using namespace std;

int MOD=1000000007;

long long int sumaMOD(long long int a, long long int b){
    return (a+b) % MOD;
} 
long long int multMOD(long long int a, long long int b){
    return (long long ) a*b % MOD;
}
long long int restaMOD(long long int a, long long int b){
    return ((a-b) % MOD + MOD) % MOD;
}
long long int divMOD(long long int a, long long int b){
    // P es un numero primo relativo a b
    // return a * power(b, P-2) % P;
    // algoritmo extendido de euclides
    return a * pow(b, P-2) % P;
}

int main(){
	int n;
	cin>>n;

    int long long answer = 1;    

    for(n ; n>1 ; n--){
        answer=(answer*n) % 1000000000; 
    }

    int cont=0;
    while(answer%10 == 0){
        answer = answer / 10;
        cont++;
    }

	cout<<cont;
    return 0;
}