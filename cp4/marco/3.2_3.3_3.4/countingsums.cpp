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
	int count = 1;
	int n, q, aux;
	while(cin>>n){
		vector<int>v(n);
		vector<int>allDiff;
		for(int i =0 ; i<n ; i++){
			cin>>v[i];
		}
		for(int i = 0 ; i<n ; i++){
			for(int j = i+1 ; j<n ; j++){
				allDiff.push_back(v[i]+v[j]);
			}
		}
		sort(allDiff.begin(), allDiff.end());
		// for(auto&e:allDiff){
		// 	cout<<e<<endl;
		// }
		// cout<<"---"<<endl;
		cin>>q;
		cout<<"Case "<<count<<":"<<endl;
		for(int i =0 ; i<q ; i++){
			cin>>aux;
			auto lb = lower_bound(allDiff.begin(), allDiff.end(), aux);
			auto ub = lower_bound(allDiff.begin(), allDiff.end(), aux);
			if (ub == allDiff.end()) ub--;
			while (ub > allDiff.begin() && *ub >= aux) {
				ub--;
			}
			int l;
			int u;
			if(lb == allDiff.end()) {l = (1<<31-1);} else {l = *lb;}; 
			if(ub >= allDiff.end()) {u = (1<<31-1);} else {u = *ub;}; 
			if(abs(l-aux) < abs(u-aux)){
				cout<<"Closest sum to "<<aux<<" is "<<l<<"."<<endl;
			} else {
				cout<<"Closest sum to "<<aux<<" is "<<u<<"."<<endl;
			}
		}
		count++;
	}

	return 0;


}
//--------------------EOSOLUTION---------------------------------