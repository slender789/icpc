#include "bits/stdc++.h"
//assert(x>0) si falla da RTE
using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;
#define limite 1000001

set<int>sieve(int n){
    set<int>nums;
    bitset<limite>bs;
    
    for(int i = 2 ; i <= sqrt(n) ; i++){
        for(int j = i*i ; j <= n ; j+=i){
            bs[j] = 1;
        }
    }
    for(int i = 2 ; i <= n ; i++){
        if (!bs[i]) {
            nums.insert(i);
        }
    }
    return nums;
}

//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    //entran n y e
    int tc;
    cin >> tc;
    while(tc--){
        int n, e;
        cin >> n >> e;

        auto primes = sieve(n);
        int p, q;
        for(auto&elem : primes){
            if(n%elem == 0 && n/elem != 1 && primes.find(n/elem) != primes.end()){
                p = elem;
                q = n/elem;
                break;
            }
        }

        // cout<<p<<" "<<q<<endl;

        for(long long int i = 1; i < pow(2,63) ; i+=(p-1)*(q-1)){
            if(i % e == 0){
                cout<<i/e<<endl;
                break;
            }
        }
    }
    return 0;
}
//--------------------EOSOLUTION---------------------------------