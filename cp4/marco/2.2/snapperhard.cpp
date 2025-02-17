#include "iostream"
#include "string"
#include "vector"
#include "sstream"
#include "unordered_map"
#include "algorithm"
//assert(x>0) si falla da RTE
using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;
//#define DBG(x) ;
//#define RAYA ;
//#define RAYAS ;

//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int tC;

	cin >> tC;
    int i =1;
	while (tC--) {
        int a, b;
        cin>>a>>b;
        int states = (1<<a);
        int myMod = b % states;
        // int num = (1<<a)-1;
        if (myMod != (states-1)) {
            cout<<"Case #"<<i<<": OFF"<<endl;
        }else{
            cout<<"Case #"<<i<<": ON"<<endl;
        }
        i++;
	}

}
//--------------------EOSOLUTION---------------------------------