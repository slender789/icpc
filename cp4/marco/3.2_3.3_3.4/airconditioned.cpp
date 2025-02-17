#include "bits/stdc++.h"
//assert(x>0) si falla da RTE
using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;

struct Elem{
    int s;
    int e;
    int mid;
    Elem(int s, int e):s{s}, e(e), mid(e-s) {};
};

bool comp(Elem&a, Elem&b){
    return a.s < b.s;
}

//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int n; cin >> n;
    int x, y;
    vector<Elem>v(n, Elem(0, 0));
    for(int i = 0 ; i<n ; i++){
        cin >> x >> y;
        v[i] = Elem(x, y);
    }

    sort(v.begin(), v.end(), comp);
    // for(auto&e : v){
    //     cout<<e.s<<" "<<e.e<<endl;
    // }
    // cout<<"====="<<endl;

    int count = 0;
    int rooms = 0;
    unordered_set<int>us;
    while(count<n){
        int idx = 0;
        while(us.find(idx) != us.end()){
            idx++;
        }
        if(idx >= n) break;
        us.insert(idx);
        // cout<<"starting at "<<idx<<endl;
        int start, end;
        start = v[idx].s;
        end = v[idx].e;
        //go to next
        idx++;
        while(idx < n){
            if(v[idx].s >= start && v[idx].s <= end){
                // cout<<"fits"<<endl;
                if(us.find(idx) == us.end()){
                    us.insert(idx);
                    // cout<<idx<<" ";
                    count++;
                }
                start = max(start, v[idx].s);
                end = min(end, v[idx].e);
            }
            idx++;
        }
        // cout<<endl;
        rooms++;
        // cout<<"---"<<endl;
    }

    cout<<rooms;


    return 0;
}
//--------------------EOSOLUTION---------------------------------