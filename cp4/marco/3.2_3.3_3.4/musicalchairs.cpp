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
    int n;
    cin>>n;
  vector<long long int>v(n);
  vector<long long int>idxs(n);
  for(int i = 0 ; i<n ; i++){
        cin>>v[i];
        idxs[i] = i;
    }

    int idx = 0;
    while(v.size() > 1){
        idx = (idx+v[idx]-1)%v.size();
        idxs.erase(idxs.begin()+idx);
        auto next_to = v.erase(v.begin()+idx);
        if(next_to == v.end()){
            idx = 0;
        } else {
            idx = next_to - v.begin();
        }
    }
    cout<<idxs[0]+1;

    return 0;

}
//--------------------EOSOLUTION---------------------------------