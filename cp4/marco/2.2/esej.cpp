#include "iostream"
#include "string"
#include "vector"
#include "sstream"
#include "unordered_set"
#include "set"
#include "queue"

//assert(x>0) si falla da RTE
using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;

vector<string> permute(string str, int words){
	sort(str.begin(), str.end());

    vector<string>tokens;
	// Keep printing next permutation while there
	// is next permutation
	do {
		tokens.push_back(str);
	} while (next_permutation(str.begin(), str.end()), tokens.size()<words);
    return tokens;
}

//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int a, b, b2;
    cin >> a >> b;

    string alph;
    for(int i = 97; i<97+15 ; i++){
        alph += char(i);
    }

    // cout<<alph;

    auto tokens = permute(alph, a);
    for(auto&e : tokens){
        cout<<e<<" ";
    }

    return 0;
}
//--------------------EOSOLUTION---------------------------------
