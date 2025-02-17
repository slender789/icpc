#include "iostream"
#include "string"
#include "vector"
#include "sstream"
#include "unordered_map"
#include "set"
#include "queue"

using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;

//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int tC, x, y;
    set<int>s;
    cin>>tC;
    while(tC--){
        cin>>x>>y;
        for(int i = x ; i<= y ; i++){
            s.insert(i);
        }
    }
    cout<<s.size();
    return 0;
}
//--------------------EOSOLUTION---------------------------------
