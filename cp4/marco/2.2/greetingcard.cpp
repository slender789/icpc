#include "iostream"
#include "string"
#include "vector"
#include "sstream"
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
    int a, b, tc;
    cin >> tc;
    vector<pair<int,int>>v;
    while(tc--){
        cin >> a >> b;
        v.push_back(pair(a, b));
    }
    int sum = 0;
    for(int i = 0; i <v.size() ; i++){
        for(int j = i+1; j <v.size() ; j++){
            int x = v[i].first - v[j].first;
            int y = v[i].second - v[j].second;
            x *= x;
            y *= y;
            int res = sqrt(x+y);
            if(res == 2018 && res*res == (x+y)){
                sum++;
            }
        }
    }

    cout<<sum;

    return 0;
}
//--------------------EOSOLUTION---------------------------------
