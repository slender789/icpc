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
    int tc;
    while(true){
        cin>>tc;
        if(tc == 0) break;
        long double x, y;
        vector<pair<long double, long double>>v(tc);
        vector<long double>acumSum(tc);
        for(int i = 0 ; i<tc ; i++){
            cin >> v[i].first >> v[i].second;
            if(i!=0){
                acumSum[i] = v[i].second + acumSum[i-1];
            } else {
                acumSum[i] = v[i].second;
            }
        }
        int I=0, J=0;
        long double maxProf = 0;
        long double minRange = 15000;
        for(int i = 0 ; i<tc ; i++){
            for(int j = i ; j<tc ; j++){
                long double sum = acumSum[j];
                if(i != 0){
                    sum -= acumSum[i-1];
                }
                // for(int xd = 0 ; xd<(v[j].first - v[i].first + 1) ; xd++){
                //     sum -= 0.08;
                // }
                long double range = v[j].first - v[i].first + 1;
                sum -= (0.08 * range);
                if (sum > maxProf){
                    I = i;
                    J = j;
                    minRange = range;
                } else if (sum == maxProf && range < minRange) {
                    I = i;
                    J = j;
                    minRange = range;
                    // minRange = min(minRange, range);
                } else if (sum == maxProf && range == minRange) {
                    I = I < i ? I : i;
                    J = J < j ? J : j;
                }
                maxProf = max(maxProf, sum);
            }
        }
        if (maxProf <= 0){
            cout<<"no profit\n";
        } else {
            
            cout<<fixed<<setprecision(2)<<maxProf<<" ";
            cout<<fixed<<setprecision(0)<<v[I].first<<" "<<v[J].first<<endl;
        }
        // long double maxProf = 0;
        // long double sum = 0;
        // int first = 0;
        // int last = 0;
        // int begin = 0;
        // for(int i = 0 ; i<tc ; i++){
        //     sum += v[i].second;
        //     if(i != 0){
        //         sum -= (0.08 * (v[i].first - v[i-1].first));
        //     }
        //     if(sum > maxProf){
        //         last = i;
        //         first = begin;
        //     }
        //     maxProf = max(maxProf, sum);
        //     if(sum < 0){
        //         begin = i;
        //         sum = 0;
        //     }
        // }
        // cout << "first " <<first<< " last " <<last<< " maxProf " <<maxProf<<endl;


    }
}
//--------------------EOSOLUTION---------------------------------