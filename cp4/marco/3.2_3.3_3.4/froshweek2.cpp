#include "bits/stdc++.h"
//assert(x>0) si falla da RTE
using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;

struct Elem {
	int start;
	int end;
	Elem(int start, int end) : start(start), end(end){};
};

bool comp(Elem a, Elem b){
	if(a.end == b.end){
		return a.start < b.start;
	}
	return a.end < b.end;
};
bool comp2(Elem a, Elem b){
	if(a.start == b.start){
		return a.end < b.end;
	}
	return a.start < b.start;
};

//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int tasks, windows;
    cin >> tasks >> windows;
    vector<int>t(tasks);
    vector<int>w(windows);
    for(int i = 0 ; i<tasks ; i++){
        cin >> t[i];
    }
    for(int i = 0 ; i<windows ; i++){
        cin >> w[i];
    }
    sort(t.begin(), t.end());
    sort(w.begin(), w.end());
	
    int firstT = 0;
    int firstW = 0;
    int count = 0;
    while(firstW < windows && firstT < tasks){
        while(t[firstT] > w[firstW]){
            if(firstW >= windows)break;
            firstW++;
        }
        if(firstT >= tasks)break;
        if(firstW >= windows)break;
        firstW++;
        firstT++;
        count++;
    }
    
    cout<<count;    
    return 0;
}
//--------------------EOSOLUTION---------------------------------