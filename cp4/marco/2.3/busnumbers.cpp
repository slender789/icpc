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

// Convert integer to char
char intToChar(int num) {
    return num + '0';  // Convert digit to character
}

//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int tC, tc, aux;
    vector<int>v;
    cin>>tC;
    tc = tC;
    while(tC--){
        cin>>aux;
        v.push_back(aux);
    }
    sort(v.begin(), v.end());

    // for(auto e : v){
    //     cout<<e<<endl;
    // }

    int i = 0;
    while(i < tc){
        int cont = 0;
        while(i+1 < tc && (v[i+1]- v[i] == 1)){
            cont++;
            i++;
        }
        // cout<<"cont "<<cont<<" i "<<i<<endl;
        // none
        if(cont == 0){
            cout<<v[i]<<" ";
        }
        // only 2
        else if(cont == 1){
            cout<<v[i-1]<<" "<<v[i]<<" ";
        }
        // lots
        else {
            cout<<v[i-cont]<<"-"<<v[i]<<" ";
        }
        i++;
        // cout<<endl;
    }

    return 0;
}
//--------------------EOSOLUTION---------------------------------
