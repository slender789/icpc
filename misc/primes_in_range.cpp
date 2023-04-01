#include <bits/stdc++.h>
#define max 1000000
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