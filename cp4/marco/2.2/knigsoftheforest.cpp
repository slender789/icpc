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
    int n, k, yearUs, strUs, yearAux, strAux;
    cin >> n >> k;
    cin >> yearUs >> strUs;

    int w = n + k -2;
    vector<pair<int,int>> pairs;
    pairs.push_back(pair(yearUs, strUs));
    
    while(w--){
        cin >> yearAux >> strAux;
        pairs.push_back(pair(yearAux, strAux));
    }
    sort(pairs.begin(), pairs.end());
    w = n + k - 2;

    // for(auto& e : pairs){
    //     cout<<e.first<<" "<<e.second<<endl;
    // }

    priority_queue<int>pq;
    //first round
    for(int i = 0 ; i < n ; i++){
        // cout<<"pushing "<<pairs[i].first<<" "<<pairs[i].second<<endl;
        pq.push(pairs[i].second);
    }
    if (pq.top() == strUs) {
        cout<<"2011";
        return 0;
    }
    pq.pop();

    // next rounds
    for(int i = n ; i <= w ; i++){
        // cout<<"pushing "<<pairs[i].first<<" "<<pairs[i].second<<endl;
        pq.push(pairs[i].second);
        if (pq.top() == strUs) {
            cout<<pairs[i].first;
            return 0;
        }
        pq.pop();
    }

    cout<<"unknown";
    return 0;
}
//--------------------EOSOLUTION---------------------------------
