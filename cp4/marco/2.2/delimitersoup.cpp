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

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	string line, aux;
    int tC, size;

    unordered_map<char, char>m;
    m['['] = ']';
    m['('] = ')';
    m[']'] = '[';
    m[')'] = '(';
    m['}'] = '{';
    m['{'] = '}';

    stack<char>s;
    
    cin >> tC;
    cin.ignore();

    getline(cin, aux);
    for (int i = 0; i<aux.size() ; i++){
        if (aux[i]==' ') continue;

        if (aux[i]=='[' || aux[i]=='(' || aux[i]=='{'){
            s.push(aux[i]);
        }else{
            if (s.size() == 0){
                cout<<aux[i]<<" "<<i<<endl;
                return 0;
            }
            int t = s.top();
            if (m[t] != aux[i]) {
                cout<<aux[i]<<" "<<i<<endl;
                return 0;
            }
            s.pop();
        }
    }
    cout<<"ok so far";
}
//--------------------EOSOLUTION---------------------------------