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
    int tc; cin >> tc;
    while(tc--){
        int l, a;
        cin >> l >>a;
        vector<int>v(a);
        for(int i = 0 ; i<a ; i++){
            cin>>v[i];
        }
        sort(v.begin(), v.end());
        int ma = 0;
        int mi = 0;
        for(int i = 0 ; i<a ; i++){
            ma = max(max(abs(v[i]-0), abs(l-v[i])), ma);
            mi = max(min(abs(v[i]-0), abs(l-v[i])), mi);
        }
        cout<<mi<<" "<<ma<<endl;
    }

    return 0;
}
//--------------------EOSOLUTION---------------------------------