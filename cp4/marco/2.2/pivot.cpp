#include "iostream"
#include "string"
#include "map"
#include "vector"
#include "set"
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
	int a, aux;
    vector<int>vec;

    set<int>s1;
    set<int>s2;

    cin>>a;
    while(a--){
        cin>>aux;
        vec.push_back(aux);
    }

    int ma = vec[vec.size()-1];
    s1.insert(vec.size()-1);

    for(int i = vec.size()-2 ; i >= 0 ; i--) {
        int curr = vec[i];
        if(curr<ma) {
            s1.insert(i);
        }
        ma = min(ma, curr); 
    }
    // for(auto s : s1){
    //     cout<<s<<endl;
    // }
    // cout<<endl;

    int mi = vec[0];
    s2.insert(0);
    for(int i = 1 ; i <= vec.size()-1 ; i++) {
        int curr = vec[i];
        if(curr>mi) {
            s2.insert(i);
        }
        mi = max(mi, curr); 
    }

    // for(auto s : s2){
    //     cout<<s<<endl;
    // }
    // cout<<endl;
    
    int cont = 0;
    for(auto s : s1){
        if(s2.find(s)!=s2.end()){
            cont++;
        }
    }
    cout<<cont;
    return 0;

}
//--------------------EOSOLUTION---------------------------------