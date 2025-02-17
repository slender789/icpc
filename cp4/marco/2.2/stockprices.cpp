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

//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int tCg;
    int tC;
    string aux;
    cin>>tCg;
    while (tCg--){
        cin >> tC;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap_ask;
        priority_queue<pair<int, int>> max_heap_bid;
        string op;
        int x, y;
        int lastp = 0;
        while(tC--){
            cin>>op>>x>>aux>>aux>>y;
            // cout<<op<<" "<<x<<" "<<y<<endl;
            if (op == "sell"){
                min_heap_ask.push(pair(y, x));
            }
            if (op == "buy"){
                max_heap_bid.push(pair(y, x));
            }

            if (min_heap_ask.size() != 0 && max_heap_bid.size() != 0) {
                pair<int,int> bidT = max_heap_bid.top(); 
                pair<int,int> askT = min_heap_ask.top(); 
                if (bidT.first >= askT.first) {
                    min_heap_ask.pop();
                    max_heap_bid.pop();
                    lastp = askT.first;
                    // diff between offer and demand
                    int diff = bidT.second - askT.second;
                    if (diff > 0){
                        max_heap_bid.push(pair(bidT.first, diff));
                    } else if (diff < 0) {
                        min_heap_ask.push(pair(askT.first, -diff));
                    }
                }
            }
            min_heap_ask.size() == 0 ? cout << "- " : cout << min_heap_ask.top().first << " "; 
            max_heap_bid.size() == 0 ? cout << "- " : cout << max_heap_bid.top().first << " "; 
            lastp == 0 ? cout << "-\n" : cout << lastp << endl; 
        }
    }

}
//--------------------EOSOLUTION---------------------------------
