#include "iostream"
#include "string"
#include "vector"
#include "sstream"
#include "unordered_map"
#include "map"
#include "algorithm"
#include "set"
using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;

//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    long long int tc, aux;
    map<long long int, int>m;
    long long int mini = 10000000000;
    cin>>tc;
    for(int i = 0 ; i<tc ; i++){
        cin>>aux;
        if(m[aux]!=0){
            mini = min(mini, (long long int)i-(m[aux]-1));
        }
        m[aux] = i+1;
    }
    if(m.size() == tc){
        cout<<tc;
    } else {
        cout<<mini;
    }


    return 0;
}
//--------------------EOSOLUTION---------------------------------