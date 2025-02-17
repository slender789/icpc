#include "iostream"
#include "string"
#include "map"
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
	int a;
    string str1, str2;
    map<char,int> um1, um2;

    cin >> a >> str1 >> str2;

    int same = 0;
    int almostSame = 0;
    
    for (int i = 0 ; i < str1.length() ; i++) {
        if (str1[i] == str2[i]) {
            same++;
        } else {
            um1[str1[i]]++;
            um2[str2[i]]++;
        }
    }
    for(auto p : um1) {
        almostSame += min(um1[p.first], um2[p.first]);
    }
    cout << same << " " << almostSame;

    return 0;

}
//--------------------EOSOLUTION---------------------------------