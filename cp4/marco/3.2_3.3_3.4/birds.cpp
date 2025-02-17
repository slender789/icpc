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
    int l, d,  present;
    cin >> l >> d >> present;
    vector<int>v(present);
    for (int i = 0 ; i<present ; i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    int count = 0;
    if (present > 0){
        count += (v[0]-6)/d;
        // if((v[0]-6 % d) == 0) count += 1;

        for (int i = 1 ; i<present ; i++){
            count += (v[i]-v[i-1])/(d);
            count -= 1;
        }

        count += ((l-6)-v[v.size()-1])/d;
        // if((((l-6)-v[v.size()-1]) % d) == 0) count += 1;
        cout<<count;
    }else{
        count += ((l-6)-6)/(d);
        count += 1;
        cout<<count;

    }

	return 0;
}
//--------------------EOSOLUTION---------------------------------