#include "bits/stdc++.h"
//assert(x>0) si falla da RTE
using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;

//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int d, s;
    cin >> d >> s;
    // cout<<d<<endl;
    // cout<<s<<endl;
    long double ans = s+1;
    long double l = 0;
    long double r = 10000000000;
    long double m;
    while(abs(ans - s) > 1e-8){
    // for(int i = 0 ; i<30 ; i++){
        m = (l+r)/2;
        ans = m*(cosh((d/(2*m))))-m;
        // cout<<ans<<endl;
        if(ans == s) break;
        if(ans<s){
            // cout<<"looking for lower range to increase ans"<<endl;
            r = m;
        } else {
            // cout<<"looking for higher range to decrease ans"<<endl;
            l = m;
        }
    }
    // cout<<m<<endl;
    long double w = 2*m*sinhl((d/(2*m))); 
    cout<<fixed<<setprecision(5)<<w;
    // ans = mycosh(2);
    // cout<<ans<<endl;
    // cout<<cosh(2)<<endl;
    return 0;
}
//--------------------EOSOLUTION---------------------------------