#include "bits/stdc++.h"
//assert(x>0) si falla da RTE
using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;

struct Elem {
	int start;
	int end;
	Elem(int start, int end) : start(start), end(end){};
};

bool comp(Elem a, Elem b){
	if(a.end == b.end){
		return a.start < b.start;
	}
	return a.end < b.end;
};
bool comp2(Elem a, Elem b){
	if(a.start == b.start){
		return a.end < b.end;
	}
	return a.start < b.start;
};

//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int n, m;
	int x, y;
	cin >> n >> m;
	vector<Elem>v;
	for(int i = 0 ; i<n ; i++){
		cin >> x >> y;
		v.push_back(Elem(x, y));
	}
	sort(v.begin(), v.end(), comp);
	// for(auto&e:v){
	// 	cout<<e.start<<" "<<e.end<<endl;
	// }
	// cout<<"====="<<endl;

	int count = 0;
	unordered_set<int>us;
	while(m--){
		auto it = v.begin();
		int start = 0;
		while(it!=v.end()){
			it = lower_bound(v.begin(), v.end(), Elem(start, start), comp2);
			if(it==v.end()) break;
			while(us.find(it-v.begin()) != us.end()){
				it++;
				if(it==v.end()) break;
			}
			if(it!=v.end()){
				us.insert(it-v.begin());
				count++;
				start = it->end+1;
			};
		};
		// for(auto&e:us){
		// 	cout<<e<<endl;
		// }
		// cout<<"====="<<endl;
	}
	cout<<count<<endl;
	return 0;
}
//--------------------EOSOLUTION---------------------------------