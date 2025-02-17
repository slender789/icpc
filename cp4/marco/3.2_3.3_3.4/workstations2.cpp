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
    int n, m;
    int x, y;
    cin>>n>>m;
    vector<pair<int,int>>v(n);
    for(int i = 0 ; i<n ; i++){
        cin>>x>>y;
        v[i] = {x, x+y};
    }
    sort(v.begin(), v.end());
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    int saved = 0;
    minHeap.push(v[0].second);
    for(int i = 1 ; i<v.size() ; i++){
        bool found = false;
        //no encontraras mas pequeño
        if(minHeap.top() > v[i].first){
            minHeap.push(v[i].second);
            continue;
        }
        //mientras que sean menores al limite inferior, borrar
        while(minHeap.size() && (v[i].first - m) > minHeap.top()){
            minHeap.pop();
        }
        if(!minHeap.size()){
            minHeap.push(v[i].second);
            continue;
        }
        //si hay
        saved++;
        minHeap.pop();
        minHeap.push(v[i].second);
    }
    cout<<saved;

    return 0;
}
//--------------------EOSOLUTION---------------------------------