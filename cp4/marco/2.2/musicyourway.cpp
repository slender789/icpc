#include "iostream"
#include "string"
#include "vector"
#include "sstream"
#include "unordered_map"
#include "algorithm"
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

//--------------------SOLBEGIN---------------------------------
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int tC;
    string aux;
    
    getline(cin, aux);
    unordered_map<string,int>titlesIdx;
    vector<string>titles = splitString(aux, ' ');
    for(int i = 0 ; i<titles.size() ; i++){
        titlesIdx[titles[i]] = i;
    }

    cin >> tC;
    vector<vector<string>>records(tC);
    
    //stupid
    getline(cin, aux);
    
    for (int i = 0 ; i<tC ; i++){
        getline(cin, aux);
        records[i] = splitString(aux, ' ');
    }
    
    cin >> tC;
    vector<string>toQuery(tC);
    for (int i = 0 ; i<tC ; i++){
        cin >> aux;
        toQuery[i]=aux;
    }

    for(const auto&e : toQuery){
        int titleIdx = titlesIdx[e];
        
        stable_sort(records.begin(), records.end(), [&titleIdx](const vector<string>& a, const vector<string>& b) {
            return a[titleIdx] < b[titleIdx]; 
        });

        // for(const auto&rec : records){
            for(const auto&f : titles){
                cout << f << " ";
            }
            cout << endl;
        // }
        for(const auto&rec : records){
            for(const auto&f : rec){
                cout << f << " ";
            }
            cout << endl;
        }
        cout<<endl;
    }

    return 0;
}
//--------------------EOSOLUTION---------------------------------