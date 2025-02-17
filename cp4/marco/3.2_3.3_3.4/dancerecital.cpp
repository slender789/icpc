#include "bits/stdc++.h"
//assert(x>0) si falla da RTE
using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;
//#define DBG(x) ;
//#define RAYA ;
//#define RAYAS ;

int calcMatches(string&a, string&b){
    unordered_map<char,int>frec;
    int count = 0;
    for (int i = 0 ; i<a.size() ; i++) {
        frec[a[i]]++;
    }
    for (int i = 0 ; i<b.size() ; i++) {
        frec[b[i]]++;
    }
    for(auto&e : frec){
        if(e.second>1)count++;
    }
    return count;
}

//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int tC;

	cin >> tC;
    string aux;
	vector<int>v(tC); for (int i = 0 ; i<tC ; i++) v[i] = i;
	
    vector<vector<int>>pairToMatches(tC, vector<int>(tC));
	// map<pair<int,int>, int>pairToMatches(tC);
	unordered_map<int, string>indexToWord(tC);
    for (int i = 0 ; i<tC ; i++) {
        cin>>aux;
        indexToWord[i] = aux;
        // cout<<"indexToWord "<<aux<<endl;
	}
    
    for (int i = 0 ; i<tC-1 ; i++) {
        for (int j = i+1 ; j<tC ; j++) {
            int val = calcMatches(indexToWord[i], indexToWord[j]);
            pairToMatches[i][j] = val;
            // cout<<"pairToMatches "<<i<<" "<<j<<" "<<val<<endl;
        }
	}

    int count = 26*26*26;
    do {
        int sum = 0;
        for(int i = 0 ; i<tC-1 ; i++){
            int idxA = v[i];
            int idxB = v[i+1];
            if (idxA > idxB) swap(idxA, idxB);
            sum += pairToMatches[idxA][idxB];
        }
        count = min(count, sum);
    } while (next_permutation(v.begin(), v.end()));

    cout<<count;
    return 0;

}
//--------------------EOSOLUTION---------------------------------