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
    int terrains, circ, square;
    cin >> terrains >> circ >> square;
    vector<double>terr(terrains);
    vector<double>houses(circ+square);
    double aux;
    for(int i = 0 ; i<terrains ; i++){
        cin>>aux;
        terr[i] = aux*2;
    }
    for(int i = 0 ; i<circ ; i++){
        cin>>aux;
        houses[i] = aux*2;
    }
    for(int i = 0+circ ; i<square+circ ; i++){
        cin>>aux;
        houses[i] = aux * sqrt(2);
    }

    sort(terr.begin(), terr.end());
    sort(houses.begin(), houses.end());

    // for(auto&e : terr){
    //     cout<<e<<endl;
    // }
    // cout<<"=="<<endl;
    // for(auto&e : houses){
    //     cout<<e<<endl;
    // }
    // cout<<"=="<<endl;

    int t = 0;
    int h = 0;
    int count = 0;

    while(t<terrains && h < circ+square){
        while(houses[h] >= terr[t]){
            t++;
            if(t>=terrains)break;
        }
        if(t>=terrains)break;
        t++;
        h++;
        count++;   
    }
    cout<<count;

    return 0;
}
//--------------------EOSOLUTION---------------------------------