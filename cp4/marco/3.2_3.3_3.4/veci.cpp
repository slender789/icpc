#include "bits/stdc++.h"
//assert(x>0) si falla da RTE
using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;
//#define DBG(x) ;
//#define RAYA ;
//#define RAYAS ;

//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int n, n2;cin>>n;
    n2 = n;
    vector<int>v;
    vector<int>vals;
    while(n){
        v.push_back(n%10);
        n/=10;
    }
    sort(v.begin(), v.end());
    do{
        int val = 0;
        int p = 1;
        for(int i = 0; i<v.size() ; i++){
            val += p*v[i];
            p *= 10;
        }
        vals.push_back(val);
    }while(next_permutation(v.begin(), v.end()));
    sort(vals.begin(), vals.end());
    auto ub = upper_bound(vals.begin(), vals.end(), n2);
    if (ub == vals.end()){
        cout << 0;
    } else {
        cout<<*ub;
    }
    return 0;

}
//--------------------EOSOLUTION---------------------------------