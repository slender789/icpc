#include "bits/stdc++.h"
//assert(x>0) si falla da RTE
using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;

pair<int,int> dp (int amount, vector<int>&v, vector<pair<int,int>>&memo){
    if (amount <= 0) return {amount, 1};
    if(memo[amount] != make_pair(-1,-1)){
        return memo[amount];
    }

    vector<pair<int,int>>res;
    for(auto&e : v){
        res.push_back(dp(amount-e, v, memo));
    }
    sort(res.begin(), res.end(), [](pair<int,int>&a, pair<int,int>&b){
        if (a.first==b.first){
            return a.second>b.second;
        }
        return a.first<b.first;
    });
    auto r = res.back();
    r.second += 1; //agregar la moneda actual
    return memo[amount] = r;
}

//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int tc;
    int amount, n;
    cin>>tc;
    while(tc--){
        cin >> amount >> n;
        vector<int>v(n);
        for(int i = 0 ; i<n ; i++){
            cin >> v[i];
        }
        vector<pair<int,int>>memo(amount+1, {-1,-1});
        auto res = dp(amount, v, memo);
        cout<<amount+(-res.first)<<" "<<res.second-1<<endl;
    }
    return 0;
}
//--------------------EOSOLUTION---------------------------------