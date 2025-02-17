#include "iostream"
#include "string"
#include "vector"
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

vector<string> splitString(const string& str, const string& delimiter) {
    vector<string> tokens;
    size_t start = 0; // Start position of the substring
    size_t end;       // End position where the delimiter is found

    while ((end = str.find(delimiter, start)) != string::npos) {
        // Extract the substring from start to the position of the delimiter
        tokens.push_back(str.substr(start, end - start));
        // Move the start position past the delimiter
        start = end + delimiter.length();
    }
    // Add the last substring after the last delimiter
    tokens.push_back(str.substr(start));

    return tokens;
}

string mixStrings(vector<string>&ans) {
    string fina = "";
    for(int i = 0 ; i<ans.size()-1 ; i++){
        fina += ans[i] + ", ";
    }
    fina += ans[ans.size()-1];
    return fina;
}

//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	string line, aux;
    int tC, w;
    getline(cin, line);
    cin >> tC;
    w = tC;
    
    vector<vector<string>>vec;

    // ignore
    getline(cin, aux);
    while(tC--){
        getline(cin, aux);
        vec.push_back(splitString(aux, ", "));
    }
    int size = vec[0].size();

    int mi = 10e8;
    vector<string>hola;
    // avanzar por cada caso
    for (int i = 0 ; i<w ; i++){
        int maxChanges = 0;
        for (int k = 0 ; k<w ; k++){
            if (i==k) continue;
            int changes = 0;
            //por cada palabra
            for (int j = 0 ; j<size ; j++){
                //a comparar con cada otro caso 
                if (vec[i][j] != vec[k][j]){
                    changes++;
                }
            }
            maxChanges = max(maxChanges, changes);
        }
        if (maxChanges == mi) hola.push_back(mixStrings(vec[i]));
        if (maxChanges < mi) {
            hola.clear();
            hola.push_back(mixStrings(vec[i]));
            mi = maxChanges;
        };
    }

    for(auto s : hola){
        cout<<s<<endl;
    }
}
//--------------------EOSOLUTION---------------------------------