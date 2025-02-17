#include "bits/stdc++.h"
//assert(x>0) si falla da RTE
using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;
//#define DBG(x) ;
//#define RAYA ;
//#define RAYAS ;

//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int tC, m;

	cin >> tC >> m;
	vector<int>v(tC);
    for (int i = 0; i<tC ; i++) {
        cin>>v[i];
        v[i]-=m;
	}
    
    int maxi = 0;
    int sumi = 0;
    for (int i ; i<tC ; i++) {
        sumi += v[i];
        maxi = max(maxi, sumi);
        if (sumi < 0) sumi = 0;
	}
    cout<<maxi;



}
//--------------------EOSOLUTION---------------------------------