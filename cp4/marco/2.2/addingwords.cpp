#include "iostream"
#include "string"
#include "vector"
#include "sstream"
#include "unordered_map"
#include "map"
#include "algorithm"
#include "set"
//assert(x>0) si falla da RTE
using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;

vector<string> splitString(string& phrase, char delimiter){
    vector<string>tokens;
    string token;
    stringstream ss(phrase);
    while(getline(ss, token, delimiter)){
        tokens.push_back(token);
    }
    return tokens;
}

//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    string aux;
    map<string,int>m;
    set<string>s;
    while(getline(cin, aux)){
        vector<string>tokens = splitString(aux, ' ');
        // for(auto&e : tokens){
        //     cout<<e<<" ";
        // }
        // cout<<endl;
        if (tokens[0] == "def"){
            m[tokens[1]] = stoi(tokens[2]);
            s.insert(tokens[1]);
        }
        else if (tokens[0] == "calc"){
            aux.erase(aux.begin(), aux.begin()+5);
            int res = 0;
            bool solved = true;
            for (int i = 1 ; i<tokens.size() ; i+= 2){
                
                if(s.find(tokens[i]) == s.end()){
                    solved = false;
                    break;
                }
                if(tokens[i-1] == "-"){
                    res -= m[tokens[i]];
                }
                else if(tokens[i-1] == "+"){
                    res += m[tokens[i]];
                } else {
                    res += m[tokens[i]];
                }
            }
            if (solved){
                bool found = false;
                for(auto&e : m){
                    if(e.second == res){
                        cout<<aux<<" "<<e.first<<endl;
                        found = true;
                        break;
                    }
                }
                if(!found){
                    cout<<aux<<" unknown"<<endl;
                }
            } else {
                cout<<aux<<" unknown"<<endl;
            }
        } else {
            //clear
            m.clear();
            s.clear();
        }     
    }
    

    return 0;
}
//--------------------EOSOLUTION---------------------------------