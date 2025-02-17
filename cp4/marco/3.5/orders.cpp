#include "bits/stdc++.h"
//assert(x>0) si falla da RTE
using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;

long long int dp(int amount, int vIdx, vector<int>&v, vector<vector<long long int>>&memo){
    if(amount == 0) {
        return memo[vIdx][amount] = 1;
    }
    if(vIdx >= v.size() || amount < 0) {
        return 0;
    }
    if(memo[vIdx][amount] != -1){
        return memo[vIdx][amount];
    }
    //take coin
    auto op1 = dp(amount-v[vIdx], vIdx, v, memo);
    //dont take
    auto op2 = dp(amount, vIdx+1, v, memo);

    return memo[vIdx][amount] = op1 + op2;
}

void meme(int round, int amount, int vIdx, vector<int>&v, vector<vector<long long int>>&memo){
    if(vIdx >= v.size() || amount < 0) {
        return;
    }
    if((vIdx < (v.size()-1)) && (memo[vIdx+1][amount] == 1)){
        // cout<<"did not choose "<<vIdx<<" in round "<<round<<endl;
        meme(round+1, amount, vIdx+1, v, memo);
    }
    if((vIdx < v.size()) && ((amount-v[vIdx]) >= 0) && (memo[vIdx][amount-v[vIdx]] == 1)){
        // cout<<"did choose "<<vIdx<<" in round "<<round<<endl;
        cout<<vIdx+1<<" ";
        // res.push_back(vIdx+1);
        meme(round+1, amount-v[vIdx], vIdx, v, memo);
    }
}

//--------------------SOLBEGIN---------------------------------
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    int n, m;
    cin >> n;
    vector<int>v(n);
    for(int i = 0 ; i<n ; i++){
        cin>>v[i];
    }
    cin >> m;
    vector<int>acc(m);
    vector<vector<long long int>>memo(n, vector<long long int>(30002, -1));    
    for(int i = 0 ; i<m ; i++){
        cin>>acc[i];
        auto ans = dp(acc[i], 0, v, memo);

        if(ans == 0){
            cout<<"Impossible"<<endl;
        }
        else if(ans > 1){
            cout<<"Ambiguous"<<endl;
        } else {
            meme(1, acc[i], 0, v, memo);
            cout<<endl;
        }
    }
    return 0;
}
