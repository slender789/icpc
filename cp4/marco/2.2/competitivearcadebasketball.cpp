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
    int a, b, c, au;
    cin >> a >> b >> c;

    map<string, int> m;
    set<string> ignore;
    
    string aux;
    while(a--){
        cin >> aux;
        m[aux] = 0;
    }
    
    bool won = false;
    while(c--){
        cin >> aux >> au;
        if (ignore.find(aux) != ignore.end()) continue;
        m[aux] += au;
        if (m[aux] >= b) {
            cout<<aux<< " wins!"<<endl;
            won = true;
            ignore.insert(aux);
        }
    }
    if (!won){
        cout<<"No winner!";
    }






    return 0;
}
//--------------------EOSOLUTION---------------------------------
