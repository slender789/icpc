#include "iostream"
#include "string"
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
    string num, base;

    cin >> num >> base;

    if (base == "1") {
        cout<<num;
        return 0;
    }

    int zeros = base.length()-1;
    
    string toBuild = "";

    // punto va en medio
	if (num.length() > zeros) {
        int idxBeforePoint = num.length() - zeros - 1;
        string substring1 = num.substr(0, idxBeforePoint+1);
        string substring2 = num.substr(idxBeforePoint+1);
        toBuild +=  substring1;
        toBuild +=  '.';
        toBuild +=  substring2;
    } else {
        toBuild += "0.";
        int upfront = zeros-num.length();
        while (upfront--){
            toBuild += "0";
        }
        toBuild += num;
    }

    while (toBuild[toBuild.length()-1] == '0'){
        toBuild.pop_back();
    }
    while (toBuild[toBuild.length()-1] == '.'){
        toBuild.pop_back();
    }
    cout << toBuild;

}
//--------------------EOSOLUTION---------------------------------