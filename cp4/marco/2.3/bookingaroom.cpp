#include "iostream"
#include "string"
#include "vector"
#include "sstream"
#include "unordered_map"
#include "set"
#include "queue"

//65 - 90 upper
//97 - 122 lower
// 95 _
// else symbols

//assert(x>0) si falla da RTE
using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;

// Convert integer to char
char intToChar(int num) {
    return num + '0';  // Convert digit to character
}

//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int x, y, aux;
    set<int>m;
    cin >> x >> y;

    while(y--){
        cin>>aux;
        m.insert(aux);
    }

    for(int i = 1 ; i <= x ; i++){
        if(m.find(i) == m.end()){
            cout<<i;
            return 0;
        }
    }
    cout<<"too late";
    return 0;
}
//--------------------EOSOLUTION---------------------------------
