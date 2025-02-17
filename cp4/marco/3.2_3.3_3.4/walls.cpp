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
    float l, w, n, r;
    float x, y;
    cin >> l >> w >> n >> r;
    vector<pair<float, float>>v{
        {l/2, 0},
        {-l/2, 0},
        {0, w/2},
        {0, -w/2},
    };
    set<int>unique;
    for(int i = 0; i < n ; i++){
        cin>>x>>y;
        int u = 0;
        // cout<<"for crane "<<i<<endl;
        for(int j = 0; j < 4 ; j++){
            // distance per crane
            float dis = sqrtf((x-v[j].first)*(x-v[j].first) + (y-v[j].second)*(y-v[j].second));
            // cout<<"dis "<<dis<<endl;
            // turn on if it can reach it
            if(dis<=r){
                u |= (1<<j);
            }
        }
        // only push unique combinations
        unique.insert(u);
    }

    vector<int>myV;
    for(auto&e:unique){
        myV.push_back(e);
        // cout<<e<<endl;
    }
    int mi = 100000000;
    // cout<<"will test for states "<<(1<<myV.size())<<endl;
    for(int i = 0; i<(1<<myV.size()) ; i++){
        int num = 0;
        int c = 0;
        // cout<<"will check bits "<<myV.size()<<endl;
        for(int j = 0; j<myV.size() ; j++){
            if(i & (1<<j)){
                num |= myV[j];
                c++;
            }
        }
        if(num == (1<<4)-1){
            // cout<<c<<endl;
            mi = min(mi, c);
            // cout<<c<<endl;
        }
    }
    if (mi == 100000000) {
        cout<<"Impossible";
    } else {
        cout<<mi;
    }
	return 0;
}
//--------------------EOSOLUTION---------------------------------