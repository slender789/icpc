#include "bits/stdc++.h"
//assert(x>0) si falla da RTE
using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;
#define limite 1000001

vector<pair<long long int,long long int>> factors(long long int n){
    vector<pair<long long int,long long int>> v;
    for(long long int i = 1 ; i<=sqrtl(n) ; i++){
        if(n%i == 0){
            v.push_back({i, n/i});
        }
    }
    return v;
}

//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    long long int n;
    cin>>n;
    auto pairs = factors(n);
    for(auto&e : pairs){
        // a, b
        // cout<<e.first<<" "<<e.second<<endl;
        long long int a = e.first;
        long long int b = e.second;
        if(abs(a-b)%2==0 && abs(a+b)%2==0){
            long long int i = (a-b)/2;
            long long int j = (a+b)/2;
            cout<<abs(i)<<" "<<abs(j);
            return 0;
        }
    }
    cout<<"impossible";
    return 0;
}
//--------------------EOSOLUTION---------------------------------