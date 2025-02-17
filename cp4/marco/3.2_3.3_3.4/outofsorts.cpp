#include "bits/stdc++.h"
//assert(x>0) si falla da RTE
using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;

int binSearch(vector<long long int>&v, long long int obj){
    int l = 0;
    int h = v.size()-1;
    
    while(h>=l){
        int mid = (h+l)/2;
        if (v[mid] == obj){
            return mid;
        }
        if(v[mid]>obj) h = mid-1;
        if(v[mid]<obj) l = mid+1;
    }
    return -1;
}

//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    long long int n, m, a, c, x0;
    cin >> n >> m >> a >> c >> x0;
    vector<long long int>v(n);
    for(int i = 0 ; i<n ; i++){
        if(i==0){
            v[0] = (a*x0 + c) % m;
        } else {
            v[i] = (a*v[i-1] + c) % m;
        }
    }
    vector<long long int>vs = v;
    sort(vs.begin(), vs.end());
    int s = 0;
    for(int i = 0 ; i<n ; i++){
        // if(binSearch(v, vs[i]) == i){
        if(binSearch(v, vs[i]) != -1){
            s++;
        }
    }

    /*
    6   1
    1   2
    4   4
    7   6
    2   7
    */

    cout<<s;
    return 0;
}
//--------------------EOSOLUTION---------------------------------