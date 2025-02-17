#include "iostream"
#include "string"
#include "vector"
#include "sstream"
#include "unordered_set"
#include "set"

//assert(x>0) si falla da RTE
using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;

//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	string aux;
    while (cin>>aux){
        // cout<<aux<<endl;
        int l = aux.length();
        int sum = 0;
        for(int i = 0 ; i<l ; i++){
            sum += aux[i] - '0';
        }
        bool cool = sum % l == 0;
        if (!cool) {
            cout<<aux<<": invalid # of balls"<<endl;
            continue;
        } 

        int balls = sum / l;
        int balls2 = balls;
        
        set<int>us;
        int i = 0;
        bool broken = false;
        while(balls != 0 || us.size() != 0){
            set<int>usN;
            for (auto& v : us) {
                if (v==1) continue;
                usN.insert(v-1);
            }
            us = usN;
            int val = aux[i%l] - '0';
            //mientras hayan pelotas por agregar
            if (balls > 0 && val != 0) {
                if (us.find(val) != us.end()){
                    broken = true;
                    break;
                }
                us.insert(val);
                balls--;
            }
            i++;
        }
        if (broken) {
            cout<<aux<<": invalid pattern"<<endl;
        } else {
            cout<<aux<<": valid with "<<balls2<<" balls"<<endl;
        }

    }

}
//--------------------EOSOLUTION---------------------------------
