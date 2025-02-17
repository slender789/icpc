#include "bits/stdc++.h"
//assert(x>0) si falla da RTE
using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;
#define ll long long
#define INF 100000000000000000

ll int feasible(ll int g, ll int b, ll int dn){
    ll int sum = g + b + dn;
    ll int minimal = (sum / 2) + 1;
    if(g+dn >= minimal){
        return max(minimal - g, 0LL);
    } else {
        return -1;
    }
}

void dp(ll int idx, ll int del, vector<vector<ll int>>&table, vector<vector<ll int>>&v){
    ll int benef = v[idx-1][0];
    ll int cost = v[idx-1][1];
    
    if (del <= benef){
        table[idx][del] = min(table[idx-1][del], cost);
        return;
    }
    //asumimos que el previo
    ll int ans = table[idx-1][del]; 
    if((del - benef) >= 0){
        // a ver si escogiendo sale menos
        ans = min (ans, table[idx-1][del - benef] + cost);
    }
    table[idx][del] = ans;
}

//--------------------SOLBEGIN---------------------------------
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    ll int n; cin >> n;
    vector<vector<ll int>>v;
    ll int d, g, b, dn;
    ll int lostDel = 0;
    ll int wonDel = 0;
    ll int totDel = 0;
    for(int i = 0 ; i<n ; i++){
        cin >> d >> g >> b >> dn;
        totDel += d;
        ll int feas = feasible(g,b,dn);
        if (feas > 0) {
            // benefit, cost
            v.push_back({d,feas});
        }
        else if (feas < 0) {
            lostDel += d;
        } else {
            wonDel += d;
        }
    }
    ll int minDel = (totDel/2)+1;
    // cout<<"minDel "<<minDel<<endl;
    // cout<<"lostDel "<<lostDel<<endl;
    // cout<<"wonDel "<<wonDel<<endl;
    // cout<<"totDel "<<totDel<<endl;
    
    if(lostDel >= minDel){
        cout<<"impossible";
        return 0;
    }
    if(wonDel >= minDel){
        cout<<"0";
        return 0;
    }

    // for(auto&e:v){
    //     cout<<e[0]<<" "<<e[1]<<endl;
    // }
    vector<vector<ll int>>table(v.size()+1, vector<ll int>(2017, INF));
    for(ll int i = 1 ; i <= v.size() ; i++){
        for(ll int j = 0 ; j <= 2016 ; j++){
            dp(i, j, table, v);
        }
    }
    
    ll int need = minDel - wonDel;
    // cout<<"need "<<need<<endl;
    ll int myMin = INF;
    for(ll int i = 1 ; i <= v.size() ; i++){
        for(int j = need ; j <= 2016 ; j++){
            myMin = min(table[i][j], myMin);
            // if(table[i][j] == INF){
            //     cout << "inf ";
            // } else {
            //     cout << " " << table[i][j] << " ";
            // }
        }
        // cout<<endl;
    }
    if (myMin == INF) {
        cout<<"impossible";
    }
    cout<<myMin;        
    return 0;
}
