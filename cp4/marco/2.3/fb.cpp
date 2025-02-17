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
    for(int i = 0 ; i<sqrt(2018) ; i++){
        for(int j = 0 ; j<sqrt(2018) ; j++){
            if((i*i + j*j) == 2018){
                cout<<i<<" "<<j<<endl;
            }
        }
    }

    return 0;
}
//--------------------EOSOLUTION---------------------------------
