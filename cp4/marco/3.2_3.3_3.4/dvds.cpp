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
        int n, aux;
        int lookFor = 1;
        int count = 0;
        cin >> n;
        for(int i = 0; i < n ; i++){
            cin >> aux;
            if(aux == lookFor){
                lookFor++;
                count++;
            }
        }
        cout<<n-count<<endl;
    }

    return 0;
}
//--------------------EOSOLUTION---------------------------------