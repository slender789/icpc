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
    string inc;
    cin>>inc;
    stack<int>s;
    vector<pair<int,int>>pairs;
    int count = 0;
    for(int i = 0 ; i < inc.size() ; i++){
        if(inc[i] == '(') s.push(i);
        if(inc[i] == ')') {
            pairs.push_back({s.top(), i});
            s.pop();
            count++;
        }
    }
    set<string>sols;
    for(int i = 1 ; i <= (1<<count)-1 ; i++){
        vector<int>coords;
        for(int j = 0 ; j < count ; j++){
            if ((i & (1<<j)) == (1<<j)){
                coords.push_back(pairs[j].first);
                coords.push_back(pairs[j].second);
            }
        }
        sort(coords.rbegin(), coords.rend());
        string local = inc;
        for(auto&e:coords){
            local.erase(local.begin()+e);
        }        
        sols.insert(local);
    }
    for(auto&e:sols){
        cout<<e<<endl;
    }        
	return 0;
}
//--------------------EOSOLUTION---------------------------------