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
	int tC;
    cin >> tC;

    for(int i = 0 ; i<21 ; i++){
        for(int x = 1 ; x<4 ; x++){
            for(int j = 0 ; j<21 ; j++){
                for(int y = 1 ; y<4 ; y++){
                    for(int k = 0 ; k<21 ; k++){
                        for(int z = 1 ; z<4 ; z++){
                            if((i*x + j*y + k*z) == tC){
                                string prefix;
                                if(i!=0){
                                    if(x==1) prefix = "single ";
                                    if(x==2) prefix = "double ";
                                    if(x==3) prefix = "triple ";
                                    cout<<prefix<<i<<endl;
                                }
                                if(j!=0){
                                    if(y==1) prefix = "single ";
                                    if(y==2) prefix = "double ";
                                    if(y==3) prefix = "triple ";
                                    cout<<prefix<<j<<endl;
                                }
                                if(k!=0){
                                    if(z==1) prefix = "single ";
                                    if(z==2) prefix = "double ";
                                    if(z==3) prefix = "triple ";
                                    cout<<prefix<<k<<endl;
                                }
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<"impossible";
    return 0;
}
//--------------------EOSOLUTION---------------------------------