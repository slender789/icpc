#include "bits/stdc++.h"
//assert(x>0) si falla da RTE
using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;

#define MAX_N 100001

vector<long long int> reconstruct_print(int end, vector<long long int>&heights, long long int p[]) {
  vector<long long int>v;
  int x = end;
  for (; p[x] >= 0; x = p[x]) v.push_back(x);
  v.push_back(x);
  return v;
}

//--------------------SOLBEGIN---------------------------------
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int tc; cin >> tc;
    while(tc--){
        long long w, h;
        int x; cin >> x;
        vector<pair<long long int,long long int>>v(x);
        vector<long long int>heights(x);
        for(int i = 0 ; i<x ; i++){
            cin >> w >> h;
            v[i] = {w, h};
        }
        sort(v.begin(), v.end());
        for(int i = 0 ; i<x ; i++){
            heights[i] = v[i].second;
        }

        int lis = 0, lis_end = 0; 
        long long int L[MAX_N], L_id[MAX_N], P[MAX_N];

        for (int i = 0; i < heights.size(); ++i) {
            int pos = lower_bound(L, L + lis, heights[i]) - L;
            //ws
                // while the previous holds a not shorter height, advance on pos
                while(
                    pos && 
                    L_id[pos - 1] < v.size() &&
                    v[L_id[pos - 1]].first >= v[i].first
                ){
                    pos++;
                }
                if(pos > lis){
                    // cout<<"oh shit \n";
                    P[i] = -1;
                    continue;
                }
            //ws
            L[pos] = heights[i];
            L_id[pos] = i;
            // remember
            P[i] = pos ? L_id[pos - 1] : -1;
            // if record has been bet
            if (pos + 1 > lis) {
                lis = pos + 1;
                lis_end = i;
            }
        }

        set<int>control;
        for(int i = 0 ; i<heights.size() ; i++){
            control.insert(i);
        }
        int cont = 0;
        while(control.size()){
            auto idxToDelete = reconstruct_print(*prev(control.end()), heights, P);
            for(auto&e:idxToDelete){
                control.erase(e);
            }
            cont++;
        }
        cout<<cont<<endl;
    }
}
