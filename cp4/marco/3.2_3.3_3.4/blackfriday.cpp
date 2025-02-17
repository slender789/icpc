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

	int tc, aux; cin >>tc;
	map<int,int>m;
	map<int,int>valToIdx;
	for(int i = 0 ; i<tc ; i ++){
		cin>>aux;
		valToIdx[aux]=i;
		m[aux]++;
	}
	// for(auto&e:m){
	// 	cout<<e.first<<" "<<e.second<<endl;
	// }
	// cout<<endl;
	// for(auto&e:valToIdx){
	// 	cout<<e.first<<" "<<e.second<<endl;
	// }
	// cout<<endl;
	for(auto i = m.rbegin() ; i!=m.rend() ; i++){
		if( i->second == 1 ){
			cout<<valToIdx[i->first]+1;
			return 0;
		}
	}
	cout<<"none";
	return 0;


}
//--------------------EOSOLUTION---------------------------------