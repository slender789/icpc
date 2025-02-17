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

// https://open.kattis.com/problems/classy

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
    int tCGlob;
    string aux;
    
    cin >> tCGlob;
    
    for (int i = 0 ; i<tCGlob ; i++){
        cin >> tC;
        vector<pair<string, vector<string>>>vec(tC);
        //stupid
        getline(cin, aux);
        int maxSize = 0;

        for (int i = 0 ; i<tC ; i++){
            getline(cin, aux);
            string name = splitString(aux, ':')[0];
            string c = splitString(aux, ' ')[1];
            vector<string>splitC = splitString(c, '-');
            reverse(splitC.begin(), splitC.end());
            maxSize = max(maxSize, (int)splitC.size());
            vec[i] = pair(name, splitC);
        }

        for(auto &v:vec){
            while(v.second.size() < maxSize){
                v.second.push_back("middle");
            }
        }

        sort(vec.begin(), vec.end(), [](const pair<string, vector<string>>& a, const pair<string, vector<string>>& b) {
            // Add your sorting logic here
            int smallest = min(a.second.size(), b.second.size());
            // cout<<"between "<<a.first<< " and "<<b.first<<" smallest is "<<smallest<<endl;
            for(int i = 0 ; i<smallest ; i++){
                if (a.second[i] == b.second[i]) continue;
                // lower, med, upper
                string ans = a.second[i] < b.second[i] ? "true" : "false";
                // cout<<a.second[i]<< " < "<<b.second[i]<<" ? "<<ans<<endl;
                return a.second[i] < b.second[i];
            }
            /*
                 When comparing classes, once you have reached the lowest level of detail, you should assume that all further classes are the same as the middle level of the previous level of detail. 
                 So upper class and middle-upper class are equivalent, as are middle-middle-lower-middle and lower-middle.
            */
            //middle-middle-upper-lower-middle
            //lower-middle-upper-lower-middle
            return a.first > b.first;
        });

        reverse(vec.begin(), vec.end());
        for(int i = 0 ; i<vec.size() ; i++) {
            cout<<vec[i].first<<endl;
            // for(int j = 0 ; j<vec[i].second.size() ; j++) {
            //     cout<<vec[i].second[j]<<" ";
            // }
            // cout<<endl;
        }
        cout<<"=============================="<<endl;
    }


    return 0;
}
//--------------------EOSOLUTION---------------------------------