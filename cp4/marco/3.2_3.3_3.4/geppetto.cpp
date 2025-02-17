#include "bits/stdc++.h"
//assert(x>0) si falla da RTE
using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;

bool hasBitSet(int num, int mask){
    return (num & mask) == mask;
}

//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int n, m, aux1, aux2;
    cin>>n>>m;
    vector<int>masks(m);
    int counter = 0;
    for(int i = 0 ; i<m ; i++){
        cin >> aux1 >> aux2;
        masks[i] = (1<<aux1-1) | (1<<aux2-1);
    }

    for(int i = 0 ; i<(1<<n) ; i++){
        bool has = false;
        for(auto&p : masks){
            if(hasBitSet(i, p)) {has = true; break;};
        }
        if (!has) counter++;
    }
    cout<<counter;
	return 0;
}
//--------------------EOSOLUTION---------------------------------