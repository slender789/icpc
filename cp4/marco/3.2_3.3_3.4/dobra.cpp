#include "bits/stdc++.h"
//assert(x>0) si falla da RTE
using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;

bool check(string& str, int idx, char proposed, unordered_set<char>&vowels, unordered_set<char>&consonants){
    bool isVowel = vowels.find(proposed) != vowels.end(); 
    if(isVowel){
        if(idx > 1){
            if(vowels.find(str[idx-2]) != vowels.end() && vowels.find(str[idx-1]) != vowels.end()){
                return false;
            }
        }
        if(idx > 0 && idx < str.size()-1){
            if(vowels.find(str[idx-1]) != vowels.end() && vowels.find(str[idx+1]) != vowels.end()){
                return false;
            }
        }
        if(idx < str.size()-2){
            if(vowels.find(str[idx+1]) != vowels.end() && vowels.find(str[idx+2]) != vowels.end()){
                return false;
            }
        }
    } else {
        if(idx > 1){
            if(consonants.find(str[idx-2]) != consonants.end() && consonants.find(str[idx-1]) != consonants.end()){
                return false;
            }
        }
        if(idx > 0 && idx < str.size()-1){
            if(consonants.find(str[idx-1]) != consonants.end() && consonants.find(str[idx+1]) != consonants.end()){
                return false;
            }
        }
        if(idx < str.size()-2){
            if(consonants.find(str[idx+1]) != consonants.end() && consonants.find(str[idx+2]) != consonants.end()){
                return false;
            }
        }
    }
    return true;
}

long long int backtrack(int idx, vector<int>&missing, string str, vector<char>&all, unordered_set<char>&vowels, unordered_set<char>&consonants, bool isLHere){
    long long int sum = 0;
    // once we've covered all
    if(idx >= missing.size()){
        // cout<<"worked "<<str<<endl;
        // if(isLHere){cout<<"worked "<<str<<endl;return 1;};
        if(isLHere)return 1;
        return 0;
    };
    for(auto&e : all){
        if(check(str, missing[idx], e, vowels, consonants)){
            str[missing[idx]] = e;
            // cout<<"passed "<<str<<endl;
            bool wasL = isLHere;
            if (e == 'L') isLHere = true;
            long long int pot;
            if(e=='A')pot=5; 
            if(e=='C')pot=20; 
            if(e=='L')pot=1; 
            sum += pot * backtrack(idx+1, missing, str, all, vowels, consonants, isLHere);
            wasL ? isLHere = true : isLHere = false; 
        }
    }
    return sum;
}


//--------------------SOLBEGIN---------------------------------
int main() {
  ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    unordered_set<char>vowels{'A', 'E', 'I', 'O', 'U'};
    unordered_set<char>consonants;
    vector<char>all{'A', 'C', 'L'};
    for(int i = 65 ; i<=90 ; i++){
        if(vowels.find(char(i)) != vowels.end())continue;
        consonants.insert(char(i));
    }

    string inc;
    cin>>inc;
    vector<int>missing;
    bool isLHere = false;
    for(int i = 0 ; i<inc.size() ; i++){
        if(inc[i] == '_'){
            missing.push_back(i);
        }
        if(inc[i] == 'L') isLHere = true; 
    }

    // cout<<missing[0]<<endl;
    // cout<<missing.size()<<endl;
    // if(isLHere)cout<<"L from the start"<<endl;
    cout<<backtrack(0, missing, inc, all, vowels, consonants, isLHere);

    // cout<<endl;
    // for(auto&e : consonants){
    //     cout<<e<<endl;
    // }
    return 0;
}
//--------------------EOSOLUTION---------------------------------