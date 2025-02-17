#include "bits/stdc++.h"
//assert(x>0) si falla da RTE
using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;

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

//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int tc;
    while(true){
        cin>>tc;
        if(tc == 0) break;
        vector<int>A(tc);
        vector<int>memo(tc, -1);
        vector<int>rem(tc, -1);
        for(int i = 0 ; i<tc ; i++){
            cin >> A[i];
        }
        int maxLis = 1;
        // int maxIdx = 0;
        vector<int>maxIdxs;
        for(int i = tc-1 ; i>=0 ; i--){
            int op = Lis(i, A, memo, rem);
            if(op > maxLis){
                maxIdxs.clear();
                maxIdxs.push_back(i);
                // maxIdx = i;
            }
            else if(op == maxLis){
                maxIdxs.push_back(i);
                // maxIdx = i;
            }
            maxLis = max(maxLis, op);
        }
        cout<<maxLis<<" ";

        // for(int i = 0 ; i<tc ; i++){
        //     cout << A[i] << " ";
        // }
        // cout<<endl;
        // for(int i = 0 ; i<tc ; i++){
        //     cout << rem[i] << " ";
        // }
        // cout<<endl;
        vector<vector<int>>ress;
        for(auto&e:maxIdxs){
            vector<int>res;
            int aux = e;
            // cout<<A[e]<<" ";
            res.push_back(A[e]);
            while(rem[aux]>=0){
                res.push_back(A[rem[aux]]);
                // cout<<A[rem[aux]]<<" ";
                aux = rem[aux];
            }
            reverse(res.begin(), res.end());
            ress.push_back(res);
        }
        sort(ress.begin(), ress.end());
        for(auto&e:ress[0]){
            cout<<e<<" ";
        }
        cout<<endl;
        // cout<<endl;
    }
}
//--------------------EOSOLUTION---------------------------------