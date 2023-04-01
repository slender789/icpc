#include <bits/stdc++.h>

using namespace std;

int main() {
  int m;
  cin>>m;
  while(m){  
    int n,t,st,por_completar;
    vector<int>vec;

    // n es el numero de veces que se tiró el dado de 6 caras
    // t es el total sumado
    // st es el semitotal menos el último valor
    // calculamos posible secuencia
    
    cin>>n>>t>>st;
    int lim=t-st;
    t=st;
    n=n-1;
    vec.push_back(lim);

    for(int i=lim ; i>0 ; i--){
        if((i*n)<=t){
            por_completar=t-(i*n);
            while(n){
                vec.push_back(i);
                n--;
            }
            break;
        }
    }
    
    for(int i=0 ; i<vec.size() ; i++){
        while(vec[i]<lim && por_completar){
            vec[i]+=1;
            por_completar--;         
        }   
        cout<<vec[i]<<" ";
    }

    cout<<endl;
    vec.clear();
    m--;
    }
}