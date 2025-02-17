#include "bits/stdc++.h"
//assert(x>0) si falla da RTE
using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;

int getMostSignificantBit(int num) {
    if (num == 0) return 0; // Handle edge case for 0
    int msbPosition = 31 - __builtin_clz(num); // For 32-bit integers
    return msbPosition;
}

int truncNum(int num){
  int idx = getMostSignificantBit(num);
  while(idx>7){
    num &= ~(1<<(idx));
    idx = getMostSignificantBit(num);
  }
  return num;
}

//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    int n, aux;
    cin>>n;
    
    while(n--){
        cin>>aux;
        for(int i = 0 ; i<256 ; i++){
            int trunced = truncNum((i<<1));
            if((i^trunced) == aux){
                cout<<i<<" ";
                break;
            }
        }
    }
	return 0;


}
//--------------------EOSOLUTION---------------------------------