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
    cin >> n >> m;
    vector<pair<int,int>>pos;
    vector<pair<int,int>>neg;
    int x, y;
    for(int i = 0 ; i<n ; i++){
        cin>>x>>y;
        if(x<0){
            neg.push_back({-x, y});
        } else {
            pos.push_back({x, y});
        }
    }

    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());

    int highestIdx = pos.size()-1;
    int tripsCount = 0;
    while(highestIdx >= 0){
        int highestIdxCp = highestIdx;
        int mCp = m;
        //only add trip for highest
        tripsCount += pos[highestIdxCp].first * 2;
        // cout<<"higestIdx so far is "<<highestIdx<<endl;
        
        for(int i = highestIdxCp ; i >= 0 ; i--){
            if(pos[i].second <= mCp){
                // cout<<"idx "<<i<<" was covered"<<endl;
                mCp -= pos[i].second;
                highestIdx = i-1;
                continue;
            }
            if(pos[i].second > mCp){
                // cout<<"idx "<<i<<" was not covered"<<endl;
                pos[i].second -= mCp;
                break;
            }
        }
    }
    // cout<<"-====="<<endl;
    highestIdx = neg.size()-1;
    while(highestIdx >= 0){
        int highestIdxCp = highestIdx;
        int mCp = m;
        //only add trip for highest
        tripsCount += neg[highestIdxCp].first * 2;
        // cout<<"higestIdx so far is "<<highestIdx<<endl;
        
        for(int i = highestIdxCp ; i >= 0 ; i--){
            if(neg[i].second <= mCp){
                // cout<<"idx "<<i<<" was covered"<<endl;
                mCp -= neg[i].second;
                highestIdx = i-1;
                continue;
            }
            if(neg[i].second > mCp){
                // cout<<"idx "<<i<<" was not covered"<<endl;
                neg[i].second -= mCp;
                break;
            }
        }
    }
    cout<<tripsCount;

    return 0;
}
//--------------------EOSOLUTION---------------------------------