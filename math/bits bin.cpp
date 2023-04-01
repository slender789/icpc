#include "bits/stdc++.h"
using namespace std;
vector<long long int>s;

// q=(~q); invertir binario

int main(){
    s.push_back(1);
    long long int n=1;    
    while(true){
        long long int len = 0;
        long long int aux=n, aux2=n;
        long long int mirr = 0;
        while(aux2!=0){
            aux2 /= 2;
            len ++;
        }
        for(int i=0 ; i<len ; i++){
            mirr <<= 1;
            mirr = (mirr|(aux & 1));
            aux >>= 1;
        }
        long long int gen = n;
        gen <<= len;
        gen = (gen | mirr);
        s.push_back(gen);
        gen=n;
        gen <<= len+1;
        gen = (gen | mirr);
        s.push_back(gen);
        gen=n;
        gen <<= 1;
        gen = (gen | 1);
        gen <<= len;
        gen = (gen | mirr);
        s.push_back(gen);

        if (gen >= 2147483648) break;

        n++;
    }
    sort(s.begin(), s.end());
    int tC;
    long long int A, B;

    cin >>tC;
    while(tC){
        cin>>A>>B;

        cout<<distance(upper_bound(s.begin(), s.end(), A-1), lower_bound(s.begin(), s.end(), B+1))<<endl;
        

        tC--;
    }

  return 0;
}