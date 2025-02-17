#include "bits/stdc++.h"
//assert(x>0) si falla da RTE
using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;

vector<int> solve(int n){
	vector<int>v(n);
	v[1] = 1;
	int next = 2;
	int idx = 1;
	int rate = 3;
	while(next <= v.size()){
		int count = rate;
		while(count){
			if(idx >= v.size()) idx = 0;
			if(v[idx] == 0) count--;
			if (count == 0) v[idx] = next;
			idx++;
		}
		next++;
		rate++;
	}
	return v;
}

//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int tC, aux;

	cin >> tC;
	while (tC--) {
		cin>>aux;
		if(aux == 1){
			cout<<1;
		} else{
			for(auto&e: solve(aux)){
				cout<<e<<" ";
			}
		}
		cout<<endl;
	}
}
//--------------------EOSOLUTION---------------------------------