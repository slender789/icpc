#include "bits/stdc++.h"
//assert(x>0) si falla da RTE
using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;
#define limite 1000001

//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int n;
    cin>>n;
    vector<long long int>v(n);
    for(int i = 0 ; i<n ; i++){
        cin>>v[i];
    }
    
    long long int latest = v[n-1];
    long long int sum = 0;
    for(int i = n-2 ; i>=0 ; i--){
        if(v[i]<latest){
            latest = v[i];
            continue;
        }
        if(latest == 0){
            cout<<1;
            return 0;
        }
        sum += v[i]-(latest-1);
        latest = latest -1;
    }
    cout<<sum;
    return 0;
}
//--------------------EOSOLUTION---------------------------------