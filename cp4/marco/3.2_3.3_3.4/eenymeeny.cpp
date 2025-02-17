#include "bits/stdc++.h"
//assert(x>0) si falla da RTE
using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;
#define limite 1000001

vector<string> splitLine(string& str, char delim){
    vector<string>v;
    string aux;
    stringstream ss(str);
    while(getline(ss, aux, delim)){
        v.push_back(aux);
    }
    return v;
}

//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    string aux;
    int n;
    getline(cin, aux);
    // cin.ignore();
    cin.clear();
    cin>>n;

    // cout<<aux<<endl;
    // cout<<n<<endl;

    vector<string>teamA;
    vector<string>teamB;
    unordered_set<int>chosen;
    auto v = splitLine(aux, ' ');
    int jumps = v.size();

    vector<string>kids(n);
    for(int i = 0 ; i<n ; i++){
        cin>>kids[i];
    }
    int last = 0;
    bool f = true;
    for(int i = 0 ; i<n ; i++){
        int c = jumps;
        while(c){
            if(chosen.find(last) == chosen.end()){
                c--;
            }
            last = (last + 1)%n;
        }
        last == 0 ? last = n-1 : last--;
        if(f) teamA.push_back(kids[last]);
        if(!f) teamB.push_back(kids[last]);
        f = !f;
        chosen.insert(last);
        last = (last + 1)%n;
    }
    cout<<teamA.size()<<endl;
    for(auto&e : teamA){
        cout<<e<<endl;
    }
    cout<<teamB.size()<<endl;
    for(auto&e : teamB){
        cout<<e<<endl;
    }
    
    return 0;
}
//--------------------EOSOLUTION---------------------------------