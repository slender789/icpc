#include <bits/stdc++.h>
#include <bits/extc++.h> // For PBDS
using namespace std;
using namespace __gnu_pbds;

typedef tree<
    string, null_type, 
    less<string>, 
    rb_tree_tag, 
    tree_order_statistics_node_update
> ost;

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
    ost treeM;
    ost treeW;
    string aux;
    // map<string, int>m;
    while(getline(cin, aux)){
        auto tokens = splitString(aux, ' ');
        if (tokens[0] == "1"){
            int sex = stoi(tokens[2]);
            sex == 1 ? treeM.insert(tokens[1]) : treeW.insert(tokens[1]); 
            // m[tokens[1]] = stoi(tokens[2]);
            // tree.insert(pair(tokens[1], stoi(tokens[2])));
        }
        else if (tokens[0] == "2"){
            auto possIdx = treeM.order_of_key(tokens[1]);
            if(*treeM.find_by_order(possIdx) == tokens[1]){
                treeM.erase(treeM.find_by_order(possIdx));
            }
            possIdx = treeW.order_of_key(tokens[1]);
            if(*treeW.find_by_order(possIdx) == tokens[1]){
                treeW.erase(treeW.find_by_order(possIdx));
            }
        }
        else if (tokens[0] == "3"){
            int look = stoi(tokens[3]);
            int count = 0;
            auto lM = treeM.order_of_key(tokens[1]);
            auto uM = treeM.order_of_key(tokens[2]); //non inclusive
            auto lW = treeW.order_of_key(tokens[1]);
            auto uW = treeW.order_of_key(tokens[2]); //non inclusive
            
            if(look == 1){
                cout<<(uM - lM)<<endl;
            }
            else if(2 == look){
                cout<<(uW - lW)<<endl;
            } else {
                cout<<(uM - lM) + (uW - lW)<<endl;
            }
        }
        else {
            return 0;
        }
    }
    return 0;
}
//--------------------EOSOLUTION---------------------------------


/*
#include "bits/stdc++.h"

using namespace std;
#define endl '\n'

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    vector<int> men(300,0);
    vector<int> wom(300,0);
    map<string,int> genderCache;

    int t; 
    while(cin>>t){
        if(t == 0) break;
        if(t == 1){
            string nom; cin>>nom;
            int gen; cin>>gen;
            if(gen == 1) men[nom[0]]++;
            else         wom[nom[0]]++;
            genderCache[nom] = gen;

        }

        if(t == 2){
            string nom; cin>>nom;
            int gen = genderCache[nom];
            if(gen == 1) men[nom[0]]--;
            else         wom[nom[0]]--;
        }

        if(t == 3){
            int l,r; cin>>l>>r;
            int gen; cin>>gen;
            
            int res = 0;
            for(int i = l; i<r; i++){
                if(gen == 1 || gen == 0) res+= men[i];
                if(gen == 2 || gen == 0) res+= wom[i];
            }

            cout<<res<<endl;
        }
    }
}

 */
         