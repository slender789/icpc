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
    int tC;
    string aux;
    

    cin >> tC;
    cin.ignore();
    while(tC--){
        // cin >> aux;
        getline(cin, aux);
        unordered_map<int, int>m;
        for(auto& e : aux){
            if (e >= 97){
                m[e-32]++;
            } else {
                m[e]++;
            }
        }
        bool broke = false;
        for(int i = 65 ; i <= 90 ; i++){
            if (m[i] == 0 && broke == false){
                broke = true;
                cout<<"missing ";
            }
            if (m[i] == 0){
                // cout<<intToChar(m[i]);
                cout<<char(i+32);
                // cout<<i<<" ";
            }
        }
        if(!broke){
            cout<<"pangram";
        }
        // for (const auto &e : m){
        //     cout<<e.first<<" "<<e.second<<endl;
        // }
        cout<<endl;
    }
    return 0;
}
//--------------------EOSOLUTION---------------------------------
