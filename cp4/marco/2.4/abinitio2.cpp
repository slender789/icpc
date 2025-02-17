#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

// long long int expp(long long int n, long long int e){
//     if(e==0) return 1;
//     long long int res = n;
//     // for(int i = 0; i < e-1 ; i++){
//     //     res *= n;
//     //     res %= mod;
//     // }
//     if (e%2 == 0){
//         return powl()
//     }
//     return res;
// }

long long modular_exponentiation(long long base, long long exp, long long m) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

void printMat(vector<vector<int>>&v){
    cout<<endl;
    for(int x = 0; x < v.size() ; x++){
        for(int y = 0 ; y < v[x].size() ; y++){
            cout<<v[x][y]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main(){
    int V, E, Q, aux1, aux2;
    int transposes = 0;
    int inversiones = 0;
    cin>>V>>E>>Q;
    vector<vector<int>>vec(V, vector<int>(V, 0));
    for(int i = 0 ; i < E ; i++){
        cin >> aux1 >> aux2;
    }
    int op;
    for(int i = 0 ; i < Q ; i++){
        cin >> op;
        if(op == 1){
            for(int x = 0 ; x<vec.size() ; x++){
                (inversiones % 2 == 0) ? vec[x].push_back(0) : vec[x].push_back(1);
            }
            (inversiones % 2 == 0) ? vec.push_back(vector<int>(vec.size()+1, 0)) : vec.push_back(vector<int>(vec.size()+1, 1));
        }
        else if(op == 2){
            cin >> aux1 >> aux2;
            if (transposes % 2 == 1) swap(aux1, aux2);
            (inversiones % 2 == 0) ? vec[aux1][aux2] = 1 : vec[aux1][aux2] = 0;
        }
        else if(op == 3){
            cin >> aux1;
            for(int x = 0 ; x<vec.size() ; x++){
                if (inversiones % 2 == 0) {vec[x][aux1] = 0;vec[aux1][x] = 0;} else {vec[x][aux1] = 1;vec[aux1][x] = 1;};
            }
        }
        else if(op == 4){
            cin >> aux1 >> aux2;
            if (transposes % 2 == 1) swap(aux1, aux2);
            (inversiones % 2 == 0) ? vec[aux1][aux2] = 0 : vec[aux1][aux2] = 1;
        }
        else if(op == 5){
            transposes++;
        }
        else if(op == 6){
            inversiones++;
        }
        // printMat(vec);
    }

    //before final
    if (inversiones % 2 == 1){
        for(int x = 0; x < vec.size() ; x++){
            for(int y = 0 ; y < vec.size() ; y++){
                if (x!=y) vec[x][y] == 1 ? vec[x][y] = 0 : vec[x][y] = 1;
            }
        }
    };
    if (transposes % 2 == 1){
        vector<vector<int>>vecAux(vec.size(), vector<int>(vec.size(), 0));
        for(int x = 0; x < vec.size() ; x++){
            for(int y = 0 ; y < vec.size() ; y++){
                vecAux[y][x] = vec[x][y];
            }
        }
        vec = vecAux;
    };

    cout<<vec.size()<<endl;
    for(int w = 0 ; w<vec.size() ; w++){
        long long int ex = 0;
        long long int res = 0;
        for(int x = 0 ; x<vec.size() ; x++){
            assert(vec.size() == vec[w].size());
            if(x!=w && vec[w][x] == 1){
                // res += ((x*expp(7, ex))%mod);
                // res%=mod;
                res += ((x * modular_exponentiation(7, ex, mod)) % mod);
                res %= mod;
                ex++;
            }
        }
        cout<<ex<<" "<<res<<endl;
    }
    return 0;
}