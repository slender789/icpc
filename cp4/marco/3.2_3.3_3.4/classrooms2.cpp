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

//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int n, m;
	int x, y;
	cin >> n >> m;
	vector<Elem>v(n, Elem(0,0));
	for(int i = 0 ; i<n ; i++){
		cin >> x >> y;
		v[i] = Elem(x, y);
	}
	sort(v.begin(), v.end(), [] (Elem& a, Elem& b){
		if(a.end == b.end){
			return a.start < b.start;
		}
		return a.end < b.end;
	});
	// for(auto&e:v){
	// 	cout<<e.start<<" "<<e.end<<endl;
	// }
	// cout<<"====="<<endl;

	int count = 0;
	unordered_set<int>us;
	while(m--){
		int expectedStart = 0;
		int idx = 0;
		while(idx < v.size()){
			// while they start before expected start
			while(v[idx].start < expectedStart || us.find(idx) != us.end()){
				idx++;
				if(idx >= v.size()) break;
			}
			if(idx >= v.size()) break;
			expectedStart = v[idx].end + 1;
			us.insert(idx);
			idx++;
			count++;
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