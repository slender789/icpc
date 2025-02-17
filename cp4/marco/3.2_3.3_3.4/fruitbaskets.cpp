#include "bits/stdc++.h"
//assert(x>0) si falla da RTE
using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;
long long int globSum = 0;

void backtrack(int idx, int sum, vector<int>&v, bool chose){
    if(sum >= 200)return;
    if(chose) {
        // cout<<"chose "<<sum<<endl;
        globSum += sum;
    }
    if(v[idx] >= 200 || idx >= v.size())return;
    backtrack(idx+1, sum+v[idx], v, true);
    backtrack(idx+1, sum, v, false);
}

//--------------------SOLBEGIN---------------------------------
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int n;
    cin>>n;
    long long int grandTotal = 0;
    vector<int>v(n);
    for(int i = 0 ; i<n ; i++){
        cin>>v[i];
        grandTotal += v[i];
    }
    sort(v.begin(), v.end());
    backtrack(0, 0, v, false);
    grandTotal *= pow(2, n-1);
    cout<<grandTotal-globSum;
    return 0;
}
//--------------------EOSOLUTION---------------------------------