#include "bits/stdc++.h"
//assert(x>0) si falla da RTE
using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;

bool areFloatsEqual(long double a, long double b, int decimalPlaces = 5) {
    const long double epsilon = std::pow(10, -decimalPlaces);
    return std::fabs(a - b) < epsilon;
}

long double distanceOnTime(vector<pair<int,int>>&seq, long double t){
    long double acum = 0;
    //first is h, second is time
    for (int i = 0 ; i<seq.size(); i++){
        if(t >= seq[i].second){
            acum += seq[i].first;
        }
        else{
            long double val = t * seq[i].first/seq[i].second;
            acum += val;
            return acum;
        }
        t -= seq[i].second;
    }
    return acum;
}

//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int n, m;
    int x, y;
    cin >> n >> m;
    vector<pair<int,int>>up(n);
    vector<pair<int,int>>down(m);
    int totalD = 0;
    int timeA = 0;
    int timeB = 0;
    int maxTime;
    for (int i = 0 ; i<n; i++){
        cin>>up[i].first;
        cin>>up[i].second;
        totalD += up[i].first;
        timeA += up[i].second;
    }
    for (int i = 0 ; i<m; i++){
        cin>>down[i].first;
        cin>>down[i].second;
        timeB += down[i].second;
    }
    maxTime = max(timeA, timeB);
    long double l = 0;
    long double h = maxTime;
    long double mid;
    // int maxIt = 30;
    while(abs(h-l) > 1e-6){
        mid = (h+l)/2;
        long double distanceA = distanceOnTime(up, mid);
        long double distanceB = distanceOnTime(down, mid);
        if(areFloatsEqual(distanceA + distanceB, totalD)){
            h = mid;
            // maxIt--;
        }
        else if(distanceA + distanceB < totalD){
            l = mid;
        } else {
            h = mid;
        }
    }
    // cout<<fixed<<setprecision(6)<<mid;
    cout << mid;
    return 0;
}
//--------------------EOSOLUTION---------------------------------