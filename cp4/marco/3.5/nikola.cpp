#include "bits/stdc++.h"
//assert(x>0) si falla da RTE
using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;
#define INF 1000000

int meme = INF;

void dp(int cost, int box, int lastStep, vector<int>&costs, vector<vector<int>>&memo){
    if(box == (costs.size()-1)){
        meme = min(meme, cost);
    }
    if(memo[box][lastStep] != -1){
        return;
    }
    memo[box][lastStep] = 1;
    // int op1 = INF;
    // int op2 = INF;
    int backJump = box - lastStep;
    if((backJump >= 0) && (lastStep != 0)){
        dp(cost + costs[backJump], backJump, lastStep, costs, memo);
    }
    int nextJump = box + lastStep + 1;
    if(nextJump < costs.size()){
        dp(cost + costs[nextJump], nextJump, lastStep+1, costs, memo);
    }
}


//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int n;
    cin >> n;
    vector<int>v(n);
    vector<vector<int>>memo(n, vector<int>(n, -1));
    for(int i = 0 ; i<n ; i++){
        cin>>v[i];
    }
    dp(0, 0, 0, v, memo);
    cout<<meme;
    return 0;
}
//--------------------EOSOLUTION---------------------------------