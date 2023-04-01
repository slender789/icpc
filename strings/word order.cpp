#include "bits/stdc++.h"
//assert(x>0) si falla da RTE
using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    set<string>s;
    int m;
    cin>>m;
    while(m){
        string aux;
        cin>>aux;
        s.insert(aux);
        m--;
    }

    int mx=0;

    while(s.size()){
        string sample = *(s.begin());
        s.erase(sample);
        for(int i=0 ; i<(sample.length()-1) ; i++){
            sample += sample[0];
            sample.erase(0, 1);
            
            if(s.find(sample)!=s.end()){
                s.erase(s.find(sample));
            }
        }
        mx++;
    }
    
    cout<<mx<<endl;
	return 0;
}	
