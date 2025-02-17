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
    int x, y;
    cin>>n>>m;
    vector<pair<int,int>>v(n);
    for(int i = 0 ; i<n ; i++){
        cin>>x>>y;
        v[i] = {x, y+x};
    }
    // sort(v.begin(), v.end());
    // for(auto&e : v){
    //     cout<<e.first<<" "<<e.second<<endl;
    // }

    int acom = n;
    unordered_set<int>us;
    int cl = 0;
    while(acom){
        int currSt = 0;
        bool firstGo = true;
        for(int i = 0 ; i < n ; i++){
            if(abs(v[i].first - currSt) >= m &&!firstGo){
                // cout<<"broke with i = "<<i<<endl;
                break;
            };
            if(v[i].first >= currSt && us.find(i)==us.end()){
                // cout<<"chose i = "<<i<<endl;
                firstGo = false;
                currSt = v[i].second;
                us.insert(i);
                acom--;
            }
        }
        // cout<<"======"<<endl;
        cl++;
    }

    cout<<cl;

    return 0;
}
//--------------------EOSOLUTION---------------------------------