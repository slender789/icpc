#include "bits/stdc++.h"
//assert(x>0) si falla da RTE
using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;

vector<int> splitString(string& str, char delim){
	vector<int>tokens;
	string token;
	stringstream ss(str);
	while(getline(ss, token, delim)){
		tokens.push_back(stoi(token));
	}
	return tokens;
}

//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	string l;
	while(getline(cin, l)){
		set<int>s;
		auto tokens = splitString(l, ' ');
		// for(auto&e:tokens){
		// 	cout<<e<<" ";
		// }
		// cout<<endl;
		bool repeated = false;
		for(int i = 0 ; i<tokens.size(); i++) {
			for(int j = i+1 ; j<tokens.size(); j++) {
				int val = abs(tokens[j] - tokens[i]);
				if(s.find(val) != s.end()){
					repeated = true;
					break;
				}
				s.insert(val);
			}
			if (repeated) break;
		}
		if (repeated){
			cout<<"not a ruler"<<endl;
			continue;
		}
		int m = *s.rbegin();
		vector<int>missing;
		for(int i = 1 ; i<m; i++) {
			if (s.find(i) == s.end()) {
				missing.push_back(i);
			}
		}
		if (missing.size() == 0){
			cout<<"perfect"<<endl;
		} else {
			cout<<"missing ";
			for(auto&e : missing){
				cout<<e<<" ";
			}
			cout<<endl;
		}
	}
	return 0;


}
//--------------------EOSOLUTION---------------------------------