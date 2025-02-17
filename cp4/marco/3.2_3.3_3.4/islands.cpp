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

    int n, aux;
    cin>>n;
    
    for (int i = 1 ; i<=n ; i++){
        vector<int>v(12);
        cin>>aux;
        for (int i = 0 ; i<12 ; i++){
            cin>>v[i];
        }
        int count = 0;
        for (int i = 1 ; i<12 ; i++){
            for (int j = i ; j<12 ; j++){
                int l = v[i-1];
                int u = v[j+1];
                
                bool worked = true; 
                for (int k = i ; k<=j ; k++){
                    if(!(v[k] > l && v[k] > u )){
                        worked = false;
                        break;
                    }
                }
                if(worked){
                if(worked){
                    // cout<<"Worked for "<<i<<" "<<j<<endl;
                    count++;
                } else {
                    // cout<<"Did not work for "<<i<<" "<<j<<endl;
                }
            }
        }
        cout<<i<<" "<<count<<endl;
    }

	return 0;


}
//--------------------EOSOLUTION---------------------------------