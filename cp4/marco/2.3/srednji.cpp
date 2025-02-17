#include "iostream"
#include "string"
#include "vector"
#include "sstream"
#include "unordered_map"
#include "map"
#include "algorithm"
#include "set"
using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;

//--------------------SOLBEGIN---------------------------------
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int tc, look, aux;
    cin>>tc>>look;
    vector<int>m(tc);
    vector<int>lr(tc);
    vector<int>rl(tc);
    int idx;
    for(int i = 0 ; i<tc ; i++){
        cin>>aux;
        m[i]=aux;
        if (aux == look) idx = i;
    }    
    lr[0] = m[0] > look ? 1 : -1;
    for(int i = 1; i<tc ; i++){
        if(lr[i-1] == -1 && m[i] > look){
            lr[i] = 0;
        }
        else if(lr[i-1] == -1 && m[i] <= look){
            lr[i] = -1; //permanece menor
        }
        else if(lr[i-1] == 1 && m[i] <= look){
            lr[i] = 0;
        }
        else if(lr[i-1] == 1 && m[i] > look){
            lr[i] = 1; //permanece mayor
        }
        else {
            lr[i] = m[i] > look ? 1 : -1; //permanece mayor
        }
    }
    rl[rl.size()-1] = m[rl.size()-1] > look ? 1 : -1;
    for(int i = rl.size()-2; i>=0 ; i--){
        if(rl[i+1] == -1 && m[i] > look){
            rl[i] = 0;
        }
        else if(rl[i+1] == -1 && m[i] <= look){
            rl[i] = -1; //permanece menor
        }
        else if(rl[i+1] == 1 && m[i] <= look){
            rl[i] = 0;
        }
        else if(rl[i+1] == 1 && m[i] > look){
            rl[i] = 1; //permanece mayor
        }
        else {
            rl[i] = m[i] > look ? 1 : -1; //permanece mayor
        }
    }
    for(auto& e : lr){
        cout <<e<< " ";
    }
    cout<<endl;
    for(auto& e : rl){
        cout <<e<< " ";
    }
    cout<<endl;
    int sum = 1;
    int li = idx - 1;
    int ri = idx + 1;
    while(li >= 0 || ri < tc){
        cout<<"li "<<li<<" ri "<<ri<<endl;
        if((li>=0 && lr[li] == 0) && (ri<tc && rl[ri] == 0)){
            cout<<"ch1"<<endl;
            sum += 3; //two individuals and both together
            li-=2;
            ri+=2;
            continue;
        }
        if((li>=0 && lr[li] == 0)){
            cout<<"ch2"<<endl;
            sum += 1;
            li-=2;
            continue;
        }
        if((ri<tc && rl[ri] == 0)){
            cout<<"ch3"<<endl;
            sum += 1;
            ri+=2;
            continue;
        }
        if((li>=0 && lr[li] == 1) && (ri<tc && rl[ri] == -1)){
            cout<<"ch4"<<endl;
            sum += 1;
            li--;
            ri++;
            continue;
        }
        if((li>=0 && lr[li] == -1) && (ri<tc && rl[ri] == 1)){
            cout<<"ch5"<<endl;
            sum += 1;
            li--;
            ri++;
            continue;
        }
        li--;
        ri++;
        // break;
    }
    cout<<sum;
    return 0;
}
//--------------------EOSOLUTION---------------------------------