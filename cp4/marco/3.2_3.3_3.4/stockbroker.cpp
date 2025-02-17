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
    bool lookForDec = true;
    int n; cin >> n;
    int aux;
    int prev;
    vector<int>v;
    cin >> prev; // Read the first element

    for (int i = 1; i < n; i++) {
        cin >> aux;

        if (lookForDec) {
            if (aux > prev) {
                v.push_back(prev); // Local minimum
                lookForDec = false;
            }
        } else {
            if (aux < prev) {
                v.push_back(prev); // Local maximum
                lookForDec = true;
            }
        }
        prev = aux; // Update prev for next iteration
    }

    // Handle the last element
    if (!v.empty() && ((lookForDec && aux < v.back()) || (!lookForDec && aux > v.back()))) {
        v.push_back(aux);
    }

    if(v.size()%2 != 0){
        v.pop_back();
    }
    if(v.size()<=1){
        cout<<100;
        return 0;
    }
    // for(auto&e:v){
    //     cout<<e<<endl;
    // }
    // cout<<endl;
    long long int stack = 100;
    long long int act = 0;
    for(long long int i = 0 ; i<v.size() ; i+=2){
        long long int buy = v[i];
        act += stack / buy;
        if (act > 100000) act = 100000;
        stack -= act*buy;
        long long int sell = v[i+1];
        stack += act * sell;
        act = 0;
    }
    cout<<stack;
    return 0;
}
//--------------------EOSOLUTION---------------------------------