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
	string tC;
    cin>>tC;
    vector<string>v;
    for(int i = 1 ; i<tC.size() ; i++){
        for(int j = i+1 ; j<tC.size() ; j++){
            string partA, partB, partC;
            partA = tC.substr(0, i);
            partB = tC.substr(i, j-i);
            partC = tC.substr(j, tC.length()-j);
            reverse(partA.begin(), partA.end());
            reverse(partB.begin(), partB.end());
            reverse(partC.begin(), partC.end());
            v.push_back(partA+partB+partC);
            // cout<<partA<<" "<<partB<<" "<<partC<<endl;
        }
    }
    sort(v.begin(), v.end());
    cout<<*v.begin();
    return 0;
}
//--------------------EOSOLUTION---------------------------------