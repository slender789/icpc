#include "iostream"
#include "string"
#include "vector"
#include "sstream"
#include "unordered_set"
#include "set"
#include "queue"

//assert(x>0) si falla da RTE
using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;

//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int tc;
    cin >> tc;
    set<string>s;
    vector<string>v;
    while(tc--){
        string aux;
        cin >> aux;
        v.push_back(aux);
    }
    s.insert(v[0]);
    for(int i = 1; i <v.size() ; i++){
        if(v[i-1][v[i-1].size()-1] == v[i][0] && s.find(v[i]) == s.end()){
            
        } else {
            int n = (i % 2 == 0) ? 1 : 2;
            cout<<"Player "<< n <<" lost";
            return 0;
        }
        s.insert(v[i]);
    }

    cout<<"Fair Game";
    return 0;
}
//--------------------EOSOLUTION---------------------------------
