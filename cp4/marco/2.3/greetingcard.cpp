#include "bits/stdc++.h"

//assert(x>0) si falla da RTE
using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;

//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    long long int a, b, tc;
    cin >> tc;
    vector<pair<long long int,long long int>>v;
    set<pair<long long int,long long int>>us;
    while(tc--){
        cin >> a >> b;
        v.push_back(pair(a, b));
        us.insert(pair(a, b));
    }
    vector<pair<int,int>>toLook{
        {0, 2018}, {0, -2018}, {1118, 1680}, {-1118, 1680}, {1118, -1680}, {-1118, -1680}, 
    };
    long long int sum = 0;
    for(long long int i = 0; i <v.size() ; i++){
        for(auto& e : toLook){
            if(us.find(pair(v[i].first+e.first, v[i].second+e.second)) != us.end()){
                sum++;        
            }
            if(us.find(pair(v[i].first+e.second, v[i].second+e.first)) != us.end()){
                sum++;        
            }
        }
    }

    cout<<sum/2;

    return 0;
}
//--------------------EOSOLUTION---------------------------------
