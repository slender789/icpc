#include "iostream"
#include "string"
#include "vector"
#include "sstream"
#include "map"
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
    int a, b, c;

    map<string, vector<int>> m;
    string aux;
    
    cin >> a;
    while(a--){
        cin >> aux >> c;
        m[aux].push_back(c);
    }

    for(auto&e : m){
        sort(e.second.begin(), e.second.end());
    }

    cin >> b;
    while(b--){
        cin >> aux >> c;
        // sort(m[aux].begin(), m[aux].end());
        cout<<m[aux][c-1]<<endl;
        // cout<<m[aux][0]<<endl;
    }
    return 0;
}
//--------------------EOSOLUTION---------------------------------
