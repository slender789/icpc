#include "bits/stdc++.h"
using namespace std;
// map<int, int>memo;
vector<int>vec(60000, -1);

int recurF(int num, int cont){
    int res = 60001;
    if (num==1) return cont + 1;
    if (num==0) return cont;
    
    int sq = (int) sqrt(num);
    if(num==sq*sq) return cont+1;
    
    cont ++;
    for(int i=sq ; i>0 ; i--){
        if(vec[num-i*i] != -1){
            res = min(res, vec[num-i*i]+cont);
        }
        else{
            int ans=recurF(num-i*i, cont);
            res=min(res, ans);
            vec[num-i*i]=ans-cont;
        }
    }
    return res;
}

int main(){
    int m;
    cin>>m;
    cout<<recurF(m, 0);
	return 0;
}
