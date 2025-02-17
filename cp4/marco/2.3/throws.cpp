#include "iostream"
#include "string"
#include "vector"
#include "stack"
#include "sstream"
#include "unordered_map"
//assert(x>0) si falla da RTE
using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;
//#define DBG(x) ;
//#define RAYA ;
//#define RAYAS ;

vector<string> splitString(const string& str, char delimiter) {
    vector<string> tokens;
    string token;
    stringstream ss(str);
    while(getline(ss, token, delimiter)){
        tokens.push_back(token);
    }
    return tokens;
}

// val, steps
pair<int, int> turnInto(int val, int steps, int size){
    int res = val + steps;
    // cout<<"res "<<res<<endl;
    if (res>=0) {
        res = res % size;
        return pair(res, res-val);
    } else {
        res = res % size;
        // cout<<"new res "<<res<<endl;
        res = (res + size) % size;
        // cout<<"new res "<<res<<endl;
        return pair(res, res - val); 
    }
}

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	string line, aux;
    int tC, size;
    
    cin >> size >> tC;
    cin.ignore();

    getline(cin, aux);
    vector<string>vec = splitString(aux, ' ');

    // for(const auto& e : vec){
    //     cout<<e<<endl;
    // }

    stack<int>seq;
    int curr = 0;
    int i = 0;
    while(i<vec.size()){
        // cout<<"curr: "<<curr<<endl;
        if(vec[i] == "undo"){
            int w = stoi(vec[i+1]);
            // cout<<"will undo "<<w<<endl;
            while(w--){
                int steps = seq.top();
                seq.pop();
                // cout<<"was curr "<<curr<<" with steps "<<steps<<endl;
                pair<int, int>p = turnInto(curr, -steps, size);
                curr = p.first;
                // cout<<"curr is "<<curr<<endl;
            }
            i += 2;
        } else {
            // cout<<"will add "<<stoi(vec[i])<<endl;
            pair<int, int>p = turnInto(curr, stoi(vec[i]), size);
            curr = p.first;
            // cout<<"curr is "<<curr<<endl;
            // cout<<"will push steps "<<p.second<<endl;
            seq.push(p.second);
            i++;
        }
        // cout<<endl;
    }
    cout<<curr;

    // pair<int, int>p = turnInto(4, -9, 5);
    // cout<<"new:"<<p.first<<" steps:"<<p.second<<endl;
    // p = turnInto(0, 1, 5);
    // cout<<"new:"<<p.first<<" steps:"<<p.second<<endl;
    // p = turnInto(0, 2, 5);
    // cout<<"new:"<<p.first<<" steps:"<<p.second<<endl;
    // p = turnInto(0, 3, 5);
    // cout<<"new:"<<p.first<<" steps:"<<p.second<<endl;
    // p = turnInto(0, 4, 5);
    // cout<<"new:"<<p.first<<" steps:"<<p.second<<endl;
    // p = turnInto(0, 5, 5);
    // cout<<"new:"<<p.first<<" steps:"<<p.second<<endl;
    
    
    // cout<<endl;
    
    
    // p = turnInto(3, 1, 5);
    // cout<<"new:"<<p.first<<" steps:"<<p.second<<endl;
    // p = turnInto(p.first, -p.second, 5);
    // cout<<"recover new:"<<p.first<<" steps:"<<p.second<<endl;
    
    // p = turnInto(3, 2, 5);
    // cout<<"new:"<<p.first<<" steps:"<<p.second<<endl;
    // p = turnInto(p.first, -p.second, 5);
    // cout<<"recover new:"<<p.first<<" steps:"<<p.second<<endl;
    
    // p = turnInto(3, 3, 5);
    // cout<<"new:"<<p.first<<" steps:"<<p.second<<endl;
    // p = turnInto(p.first, -p.second, 5);
    // cout<<"recover new:"<<p.first<<" steps:"<<p.second<<endl;
    
    // p = turnInto(3, 4, 5);
    // cout<<"new:"<<p.first<<" steps:"<<p.second<<endl;
    // p = turnInto(p.first, -p.second, 5);
    // cout<<"recover new:"<<p.first<<" steps:"<<p.second<<endl;
    
    // p = turnInto(3, 5, 5);
    // cout<<"new:"<<p.first<<" steps:"<<p.second<<endl;
    // p = turnInto(p.first, -p.second, 5);
    // cout<<"recover new:"<<p.first<<" steps:"<<p.second<<endl;
    
    // p = turnInto(3, 6, 5);
    // cout<<"new:"<<p.first<<" steps:"<<p.second<<endl;
    // p = turnInto(p.first, -p.second, 5);
    // cout<<"recover new:"<<p.first<<" steps:"<<p.second<<endl;
    
    // p = turnInto(3, 7, 5);
    // cout<<"new:"<<p.first<<" steps:"<<p.second<<endl;
    // p = turnInto(p.first, -p.second, 5);
    // cout<<"recover new:"<<p.first<<" steps:"<<p.second<<endl;


}
//--------------------EOSOLUTION---------------------------------