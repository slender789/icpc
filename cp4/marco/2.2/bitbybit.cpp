#include "iostream"
#include "string"
#include "vector"
#include "sstream"
#include "unordered_map"
#include "algorithm"
//assert(x>0) si falla da RTE
using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;
//#define DBG(x) ;
//#define RAYA ;
//#define RAYAS ;

vector<string> splitString(string& phrase, char delimiter){
    vector<string>tokens;
    string token;
    stringstream ss(phrase);
    while(getline(ss, token, delimiter)){
        tokens.push_back(token);
    }
    return tokens;
}

void turnBitOn(long long int& n, int idx){
    n |= (1<<idx);
}
void turnBitOff(long long int& n, int idx){
    n &= ~(1<<idx);
}
bool isBitOn(long long int& n, int idx){
    return (n & (1<<idx));
}

//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    string aux;
    // long long int n = (1<<32)-1;
    // cout << n;

    int tC;
    while(cin>>tC){
        if (!tC) return 0;
        cin.ignore();
        // long long int nonVisited = (1<<32)-1;
        long long int visited = 0;
        long long int value = 0;
        while(tC--){
            getline(cin, aux);
            vector<string>tokens = splitString(aux, ' ');
            // for(const auto& e : tokens){
            //     cout<<e<<" ";
            // }
            if (tokens[0] == "SET"){
                turnBitOn(value, stoi(tokens[1]));
                turnBitOn(visited, stoi(tokens[1]));
            }
            if (tokens[0] == "CLEAR"){
                turnBitOff(value, stoi(tokens[1]));
                turnBitOn(visited, stoi(tokens[1]));
            }
            if (tokens[0] == "AND"){
                int i = stoi(tokens[1]);
                int j = stoi(tokens[2]);
                bool iVis = isBitOn(visited, i);
                bool jVis = isBitOn(visited, j);
                bool iVal = isBitOn(value, i);
                bool jVal = isBitOn(value, j);
                // cout<<"and"<<endl;
                // cout<<"iVis "<<iVis<<endl;
                // cout<<"jVis "<<jVis<<endl;
                // cout<<"iVal "<<iVal<<endl;
                // cout<<"jVal "<<jVal<<endl;
                // both visited
                if (iVis && jVis) {
                    if (iVal && jVal) {
                        // turn on
                        turnBitOn(value, i);
                    } else {
                        // turn off
                        turnBitOff(value, i);
                    }
                    // mark as visited
                    turnBitOn(visited, i);
                }
                // either is 0
                else if ((iVis && !iVal)||(jVis && !jVal)) {
                    // turn on
                    turnBitOff(value, i);
                    // mark as visited
                    turnBitOn(visited, i);
                } else {
                    // i has not been visited yet
                    turnBitOff(visited, i);
                }
            }
            if (tokens[0] == "OR"){
                int i = stoi(tokens[1]);
                int j = stoi(tokens[2]);
                bool iVis = isBitOn(visited, i);
                bool jVis = isBitOn(visited, j);
                bool iVal = isBitOn(value, i);
                bool jVal = isBitOn(value, j);
                // cout<<"or"<<endl;
                // cout<<"iVis "<<iVis<<endl;
                // cout<<"jVis "<<jVis<<endl;
                // cout<<"iVal "<<iVal<<endl;
                // cout<<"jVal "<<jVal<<endl;
                // both visited
                if (iVis && jVis) {
                    if (iVal || jVal) {
                        // turn on
                        turnBitOn(value, i);
                    } else {
                        // turn off
                        turnBitOff(value, i);
                    }
                    // mark as visited
                    turnBitOn(visited, i);
                }
                // either is 1
                else if ((iVis && iVal)||(jVis && jVal)) {
                    // turn on
                    turnBitOn(value, i);
                    // mark as visited
                    turnBitOn(visited, i);
                } else {
                    // i has not been visited yet
                    turnBitOff(visited, i);
                }
            }
            // cout<<endl;
        }
        for(int i = 31 ; i >= 0 ; i--){
            if (isBitOn(visited, i)) {
                if (isBitOn(value, i)){
                    cout<<1;
                } else {
                    cout<<0;
                }
            } else {
                cout<<'?';
            }
        }
        cout<<endl;
    }
    

    return 0;
}
//--------------------EOSOLUTION---------------------------------