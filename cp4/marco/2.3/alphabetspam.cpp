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

//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    string aux;
    unordered_map<float, float>m;

    cin >> aux;
    for(auto& e : aux){
        if(e >= 65 && e <= 90){
            m[0]++;
        }
        else if(e >= 97 && e <= 122){
            m[1]++;
        }
        else if(e == 95){
            m[2]++;
        }
        else {
            m[3]++;
        }
    }
    float ans2 = m[2]/aux.length();
    cout<<ans2<<endl;
    float ans1 = m[1]/aux.length();
    cout<<ans1<<endl;
    float ans0 = m[0]/aux.length();
    cout<<ans0<<endl;
    float ans3 = m[3]/aux.length();
    cout<<ans3<<endl;
    return 0;
}
//--------------------EOSOLUTION---------------------------------
