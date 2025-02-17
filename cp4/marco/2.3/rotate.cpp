#include "iostream"
#include "vector"
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
	int l;
    char aux;

	cin >> l;
    vector<vector<char>>vec(l, vector<char>(l, 0));
    vector<vector<char>>vecRot(l, vector<char>(l, 0));

	for (int i = 0 ; i<l ; i++) {
        for (int j = 0 ; j<l ; j++) {
	        cin >> aux;
            vec[i][j] = aux;
        }
	}
	for (int i = 0 ; i<l ; i++) {
        for (int j = 0 ; j<l ; j++) {
            // //rotate counter clock
	        // vecRot[i][j] = vec[l-1-j][i];
            //rotate clock
	        vecRot[i][j] = vec[j][l-1-i];
        }
	}
    for (int i = 0 ; i<l ; i++) {
        for (int j = 0 ; j<l ; j++) {
	        cout << vecRot[i][j] << " ";
        }
        cout << endl;
	}

}
//--------------------EOSOLUTION---------------------------------