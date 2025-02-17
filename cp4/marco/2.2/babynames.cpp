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

vector<string> splitString(string& str, char delim) {
    vector<string>tokens;
    string aux;
    stringstream ss(str);
    while(getline(ss, aux, delim)){
        tokens.push_back(aux);
    }
    return tokens;
}

//--------------------SOLBEGIN---------------------------------
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    string aux;
    map<string, int>m;
    while(getline(cin, aux)){
        auto tokens = splitString(aux, ' ');
        if (tokens[0] == "1"){
            m[tokens[1]] = stoi(tokens[2]);
        }
        else if (tokens[0] == "2"){
            m.erase(tokens[1]);
        }
        else if (tokens[0] == "3"){
            int look = stoi(tokens[3]);
            int count = 0;
            auto l = m.lower_bound(tokens[1]);
            auto u = m.lower_bound(tokens[2]); //non inclusive
            if (u == m.begin() || l == m.end()) {
                cout<<0<<endl;
                continue;
            }
            if (u == l) {
                cout<<1<<endl;
                continue;
            }
            
            // non inclusive with != u
            for(auto i = l ; i!=u ; i++){
                if(look == 0){
                    count++;
                }
                else if(look == 1 && i->second == 1){
                    count++;
                }
                else if(look == 2 && i->second == 2){
                    count++;
                }
            }
            cout<<count<<endl;
        }
        else {
            return 0;
        }
    }
    return 0;
}
//--------------------EOSOLUTION---------------------------------