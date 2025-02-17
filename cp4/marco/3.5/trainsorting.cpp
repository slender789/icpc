#include "bits/stdc++.h"
//assert(x>0) si falla da RTE
using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;

#define MAX_N 100001

int Lis(int i, vector<int>&A, vector<int>&memo, vector<int>&rem){
    if(i==0) return 1;
    if(memo[i]!=-1) return memo[i];
    int ans = 1;
    for(int j = 0 ; j<i ; j++){
        if(A[j] < A[i]){
            int op = Lis(j, A, memo, rem)+1;
            if (op > ans || (op == ans && A[j]<A[rem[i]])){
                rem[i] = j;
            }
            ans = max(ans, op);
        }
    }
    memo[i] = ans;
    return ans;
}

int Lds(int i, vector<int>&A, vector<int>&memo, vector<int>&rem){
    if(i==0) return 1;
    if(memo[i]!=-1) return memo[i];
    int ans = 1;
    for(int j = 0 ; j<i ; j++){
        if(A[j] > A[i]){
            int op = Lds(j, A, memo, rem)+1;
            if (op < ans || (op == ans && A[j]>A[rem[i]])){
                rem[i] = j;
            }
            ans = max(ans, op);
        }
    }
    memo[i] = ans;
    return ans;
}

//--------------------SOLBEGIN---------------------------------
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int x; cin >> x;
    vector<int>A(x);
    for(int i = 0 ; i<x ; i++){
        cin >> A[i];
    }

    vector<int>memo(x, -1);
    vector<int>rem(x, -1);
    vector<int>memo_inv(x, -1);
    vector<int>rem_inv(x, -1);

    int maxSum = 0;
    int maxIdx = 0;

    for(int i = 0 ; i<x ; i++){
        int op = Lis(i, A, memo, rem);
        int op2 = Lds(i, A, memo_inv, rem_inv);
        if((op+op2-1) >= maxSum){
            maxIdx = i;
        }
        maxSum = max(maxSum, (op+op2-1));
    }
    // cout<<maxIdx<<endl;
    int maxRes=0;
    maxRes = max(maxRes, memo[maxIdx]);
    maxRes = max(maxRes, memo_inv[maxIdx]);
    cout<<maxRes<<endl;

    return 0;
}
