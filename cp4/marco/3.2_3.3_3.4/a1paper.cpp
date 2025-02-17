#include "bits/stdc++.h"
//assert(x>0) si falla da RTE
using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;

long double searchy(int idx, long double lookFor, vector<long double>&available, vector<long double>&biggestSide){
    // if(idx >= n) {cout<<"returned -1 at idx "<<idx<<endl;return -1;}
    int n = available.size();
    if(idx >= n) return -1;
    if(idx == n-1) {
        if(available[idx]>=lookFor){
            // cout<<"found pair at leaf "<<idx<<endl;
            available[idx]-=lookFor;
            return (lookFor / 2) * biggestSide[idx];
        }
        // cout<<"none found at leaf "<<idx<<endl;
        return -1;
    }

    if(available[idx]>=lookFor){
        // cout<<"found pair at leaf "<<idx<<endl;
        available[idx]-=lookFor;
        return (lookFor / 2) * biggestSide[idx];
    }

    int miss = lookFor - available[idx];
    //for each piece, look for 2 halfs
    miss *= 2;
    long double val1 = searchy(idx+1, miss, available, biggestSide);

    if(val1 == -1) return -1;
    return val1+biggestSide[idx];
}

//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    int n;
    cin >> n;
    n--;
    vector<long double>available(n);
    vector<long double>biggestSide(n);
    long double largest = powl(2, (-3.0/4));
    for(int i = 0 ; i<n ; i++){
        cin>>available[i];
        if (i!=0) {
            largest *= powl(2, (-1.0/2));
        }
        biggestSide[i] = largest;
    }

    // for(auto&e : available){
    //     cout<<e<<endl;
    // }
    // cout<<"==="<<endl;
    // for(auto&e : biggestSide){
    //     // cout<<e<<endl;
    //     cout<<fixed<<setprecision(15)<<e<<endl;
    // }
    // cout<<"==="<<endl;

    long double ans = searchy(0, 2, available, biggestSide);
    if(ans<0){
        cout<<"impossible";
    } else {
        cout<<fixed<<setprecision(6)<<ans;
    }
    return 0;
}
//--------------------EOSOLUTION---------------------------------