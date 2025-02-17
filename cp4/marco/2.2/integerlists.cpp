#include "iostream"
#include "string"
#include "vector"
#include "stack"
#include "sstream"
#include "unordered_map"
#include "algorithm"
#include "deque"

//assert(x>0) si falla da RTE
using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;

vector<string> splitString(string& str, char delimiter){
    vector<string>tokens;
    string token;
    stringstream ss(str);
    while(getline(ss, token, delimiter)){
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	string line, aux;
    int tC;
    string steps;
    string nums;
    int n;

    cin >> tC;
    while (tC--){
        cin>>steps>>n>>nums;
        nums.erase(nums.begin());
        nums.erase(nums.end()-1);
        vector <string> vec = splitString(nums, ',');
        deque<string>dq;
        for(auto& e : vec){
            dq.push_back(e);
            // cout<<e<<endl;
        }

        bool broken = false;
        bool reversed = false;

        for(int i = 0 ; i<steps.size() ; i++){
            if(steps[i] == 'R') {
                reversed = ! reversed;
            } else {
                if(dq.size() == 0){
                    broken = true;
                    // cout<<"broken"<<endl;
                    break;
                } else {
                    if (!reversed) {
                        // cout<<dq.front()<<endl;
                        dq.pop_front();
                    } else {
                        // cout<<dq.back()<<endl;
                        dq.pop_back();
                    }
                }
            }
        }

        if(broken){
            cout<<"error"<<endl;
        }else{
            if(dq.size()==0){
                cout<<"[]"<<endl;
            }
            else if (!reversed){
                cout<<'[';
                while(dq.size()>1){
                    cout<<dq.front()<<',';
                    dq.pop_front();
                }
                cout<<dq.front();
                cout<<']'<<endl;
            } else {
                cout<<'[';
                while(dq.size()>1){
                    cout<<dq.back()<<',';
                    dq.pop_back();
                }
                cout<<dq.back();
                cout<<']'<<endl;
            }
            // cout<<dq.back()<<endl;
            // cout<<"dqsize"<<dq.size()<<endl;
            // cout<<"dqfront"<<dq.front()<<endl;
        }

    }
}
//--------------------EOSOLUTION---------------------------------