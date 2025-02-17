#include "iostream"
#include "string"
#include "vector"
#include "stack"
#include "sstream"
#include "unordered_map"
#include "algorithm"
#include "deque"
#include "list"

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

    cin >> tC;
    cin.ignore();
    list<string>dq;
    while (tC--){
        getline(cin, aux);
        vector<string>v = splitString(aux, ' ');
        if (v[0] == "get"){
            cout<<dq[stoi(v[1])]<<endl;
        }
        else if (v[0] == "push_back"){
            dq.push_back(v[1]);
        }
        else if (v[0] == "push_front"){
            dq.push_front(v[1]);
        }
        else if (v[0] == "push_middle"){
            dq.insert(dq.begin() + (dq.size()+1)/2, v[1]);
        }
        // cout<<dq.size()<<endl;
    }
}
//--------------------EOSOLUTION---------------------------------