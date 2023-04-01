#include <bits/stdc++.h>
#define max 3000
using namespace std;
 
vector<int> primes(){
    bitset<max>bits;
    bits[0]=bits[1]=1;
    int raiz=(static_cast<int>(sqrt(max)))+1;
    vector<int> primes_vec;
    for(int i=2 ; i<=raiz ; i++){
        if(bits[i]==1) continue;
        int aux=i*i;
        while(aux <= max){
            bits[aux] = 1;
            aux=aux+i;
        }
 
    }
    for (int i=2 ; i<bits.size() ; i++) {
        if(bits[i]==0){ 
            primes_vec.push_back(i);
        }
    }
    return primes_vec;
}
 
int main() {
    int n;
    vector<int>primes_v=primes();
    
    cin>>n;
    int count=0;
    
    while(n){
        vector<int>factors;
        set<int>factorsSet;
        int m = n;
        for(int x : primes_v){
            while(m%x==0){
                factors.push_back(x);
                m /= x;
            }
        }

        for(int x : factors){
            factorsSet.insert(x);

        }

        if(factorsSet.size()==2){
            count++;
        }
        n--;
    }
    cout<<count;
  
}