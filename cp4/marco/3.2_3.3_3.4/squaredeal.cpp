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
    int a, b;
    cin>>a>>b;
    pair<int,int>p1{a,b};
    cin>>a>>b;
    pair<int,int>p2{a,b};
    cin>>a>>b;
    pair<int,int>p3{a,b};
    vector<pair<int,int>>pairs{p1,p2,p3};
    vector<int>cases{0,1,2};
    for(int i = 0 ; i<(1<<4) ; i++){
        sort(cases.begin(), cases.end());
        do{
            bool bit1On = i & (1<<1);
            bool bit2On = i & (1<<2);
            bool bit3On = i & (1<<3);
            int a = pairs[cases[0]].first;
            int b = pairs[cases[0]].second;
            if (bit1On) swap(a,b);
            int c = pairs[cases[1]].first;
            int d = pairs[cases[1]].second;
            if (bit2On) swap(c,d);
            int e = pairs[cases[2]].first;
            int f = pairs[cases[2]].second;
            if (bit3On) swap(e,f);
            // cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<endl;
            if ((a + c == b + f) && (b + f == e) && (e == d + f)){
                cout<<"YES";
                return 0;
            }   
            if((b + d + f == a) && (a == c) && (c == e)){
                cout<<"YES";
                return 0;
            }   


        } while(next_permutation(cases.begin(), cases.end()));
    }
    cout<<"NO";
	return 0;
}
//--------------------EOSOLUTION---------------------------------