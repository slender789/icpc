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

//Radix Sort in custom base to avoid TLE

//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    long long int tC;    
    cin >> tC;
    while(tC--){
        long long int n;long long int a;long long int b;long long int c;long long int x;long long int y;long long int aux;
        cin >> n >> a >> b >> c >> x >> y;
        vector<long long int>generated(n);
        generated[0] = a;
        for(long long int i = 1 ; i<n ; i++){
            generated[i] = (generated[i-1]*b+a)%c;
        }
        for(const auto& e : generated){
            cout<<e<<" ";
        }
        cout<<endl;
        sort(generated.begin(), generated.end());
        for(const auto& e : generated){
            cout<<e<<" ";
        }
        cout<<endl;
        long long int v = 0;
        for(long long int i = 0 ; i<n ; i++){
            v = (v * x + generated[i]) % y;
        }
        cout<<v<<endl;
    }

    return 0;
}
//--------------------EOSOLUTION---------------------------------