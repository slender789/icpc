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
    int n, m;
    cin >> n >> m;
    vector<long long int>sizes(n);
    vector<long long int>paints(m);
    for (int i = 0 ; i<n; i++){
        cin>>sizes[i];
    }
    sort(sizes.begin(), sizes.end());
    long long int tot = 0;
    for (int i = 0 ; i<m; i++){
        cin>>paints[i];
        tot += paints[i];
    }
    long long int comp = 0;
    for (int i = 0 ; i<m; i++){
        auto it = lower_bound(sizes.begin(), sizes.end(), paints[i]);
        comp += *it - paints[i];
        // cout<<"for "<<paints[i]<<" "<<*it<<endl;
    }
    cout<<comp;
}
//--------------------EOSOLUTION---------------------------------