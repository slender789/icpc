#include "bits/stdc++.h"
//assert(x>0) si falla da RTE
using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;

#define MAX_N 2002

int dp(int idx, int leftWeight, vector<pair<int,int>>&v, vector<vector<int>>&memo){
    bitset<2001>bsLocal = 0;
    if(idx >= v.size()) return 0;
    if(leftWeight == 0) return 0;
    if(memo[idx][leftWeight] != -1){
        return memo[idx][leftWeight];
    }
    int ans = 0;
    // si se pasa
    if(leftWeight < v[idx].second){
        ans = dp(idx+1, leftWeight, v, memo);
    } else {
        auto op1 = dp(idx+1, leftWeight, v, memo); 
        auto op2 = dp(idx+1, leftWeight - v[idx].second, v, memo);
        // between not choosing it and choosing it
        ans = max(op1, op2 + v[idx].first);
    }
    memo[idx][leftWeight] = ans;
    return ans;
}

void scale(int idx, int cap, vector<pair<int,int>>&v, vector<vector<int>>&memo, set<int>&res){
    if(idx == v.size()-1){
        if(memo[idx][cap] == v[idx].first){
            res.insert(idx);
        }
        return;
    }
    //not chosen
    if(memo[idx+1][cap] == memo[idx][cap]){
        scale(idx+1, cap, v, memo, res);
    }
    //chosen
    else if((cap - v[idx].second) && 
        (memo[idx][cap] - v[idx].first) == memo[idx+1][cap - v[idx].second]){
        scale(idx+1, cap - v[idx].second, v, memo, res);
        res.insert(idx);
    } else if (memo[idx][cap] == v[idx].first) {
        res.insert(idx);
    }
}

//--------------------SOLBEGIN---------------------------------
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    int cap, items;
    while(cin>>cap){
        cin>>items;
        vector<pair<int,int>>v(items);
        vector<vector<int>>memo(
            items, vector<int>(cap+1, -1));
        for (int i = 0 ; i<items ; i++){
            //value and weight
            cin>>v[i].first>>v[i].second;
        }
        dp(0, cap, v, memo);
        
        set<int>res;
        scale(0, cap, v, memo, res);
        cout<<res.size()<<endl;
        for(auto&e:res){
            cout<<e<<" ";
        }
        cout<<endl;
        // for(int i = 0 ; i<items ; i++){
        //     for(int j = 0 ; j<=cap ; j++){
        //         if (memo[i][j] < 0){
        //             cout<<memo[i][j]<<" ";
        //         } else {
        //             cout<<"+"<<memo[i][j]<<" ";
        //         }
        //     }
        //     cout<<endl;
        // }
    }
    return 0;
}
