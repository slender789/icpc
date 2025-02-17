#include <bits/stdc++.h>
using namespace std;
#define inf 10000000
#define mod 1000000007
typedef vector<int> vi;

long long int expp(long long int n, long long int e){
    if(e==0) return 1;
    long long int res = n;
    for(int i = 0; i < e-1 ; i++){
        res *= n;
        res %= mod;
    }
    return res;
}

int main(){
    int V, E, Q, aux1, aux2;
    cin>>V>>E>>Q;
    vector<set<int>>vec(V, set<int>());
    for(int i = 0 ; i < E ; i++){
        cin >> aux1 >> aux2;
        vec[aux1].insert(aux2);
    }
    int op;
    for(int i = 0 ; i < Q ; i++){
        cin >> op;
        if(op == 1){
            vec.push_back(set<int>());
            // V++;
        }
        else if(op == 2){
            cin >> aux1 >> aux2;
            vec[aux1].insert(aux2);        
        }
        else if(op == 3){
            cin >> aux1;
            vec[aux1].clear();
            for(auto&i : vec){
                i.erase(aux1);
            }
        }
        else if(op == 4){
            cin >> aux1 >> aux2;
            vec[aux1].erase(aux2);       
        }
        else if(op == 5){
            set<pair<int,int>>sp;
            for(int x = 0; x < vec.size() ; x++){
                for(auto&j : vec[x]){
                    sp.insert({j, x});
                }
            }
            vector<set<int>>auxVec(vec.size(), set<int>());
            for(auto&e : sp){
                auxVec[e.first].insert(e.second);
            }
            vec = auxVec;
        }
        else if(op == 6){
            for(int x = 0; x < vec.size() ; x++){
                set<int>auxSet;
                for(int y = 0 ; y < vec.size() ; y++){
                    if(vec[x].find(y) == vec[x].end() && y != x){
                        auxSet.insert(y);
                    }
                }
                vec[x] = auxSet;
            }
        }
    }

    cout<<vec.size()<<endl;
    for(auto&e : vec){
        cout<<e.size()<<" ";
        long long int ex = 0;
        long long int res = 0;
        for(auto&f : e){
            res += (f*expp(7, ex))%mod;
            ex++;
        }
        cout<<res<<endl;
    }
    return 0;
}