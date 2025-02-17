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

int greedy (int amount, vector<int>&v, vector<int>&memo){
    if (amount == 0) return 1;
    if (memo[amount] != -1){
        return memo[amount];
    }
    auto lb = lower_bound(v.begin(), v.end(), amount);
    if (lb == v.end()){
        lb--;
    }
    if (*lb > amount){
        lb--;
    }
    // amount -= *lb;
    return memo[amount] = greedy(amount - *lb, v, memo)+1;
}

int dp (int amount, vector<int>&v, vector<int>&memo){
    if (amount == 0) return 1;
    if (amount < 0) return 1000000;

    if(memo[amount]!=-1){
        return memo[amount];
    }

    int ans = 1000000;
    for(auto&e : v){
        //                                      +1 para incluir restada
        ans = min(ans, dp(amount-e, v, memo) + 1);
    }
    return memo[amount] = ans;
}

//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int n;
    // int sum = 0;
    cin >> n;
    vector<int>v(n);
    for(int i = 0 ; i<n ; i++){
        cin>>v[i];
        // sum += v[i];
    }
    sort(v.begin(), v.end());
    int largest = v[n-1] + v[n-2];

    vector<int>memo1(largest+1, -1);
    vector<int>memo(largest+1, -1);
    
    for(int i = largest ; i>0 ; i--){
        // cout<<"i "<<i<<" ";
        // cout<<greedy(i, v, memo1)-1<<" ";
        // cout<<dp(i, v, memo)-1<<endl;
        if(greedy(i, v, memo1)-1 != (dp(i, v, memo)-1)){
            cout<<"non-canonical"<<endl;
            return 0;
        }
    }
    cout<<"canonical"<<endl;
    return 0;
}
//--------------------EOSOLUTION---------------------------------