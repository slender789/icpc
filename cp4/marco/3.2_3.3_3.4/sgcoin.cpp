#include "bits/stdc++.h"
//assert(x>0) si falla da RTE
using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;

long long H(long long previousHash, string &transaction, long long token) {
  long long v = previousHash;
  for (int i = 0; i < transaction.length(); i++) {
    v = (v * 31 + transaction[i]) % 1000000007;
  }
  return (v * 7 + token) % 1000000007;
}

//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	long long prevHash; cin >> prevHash;
	string lastStr;
	long long lastH;

	for(long long i = 0 ; i<(1<<31-1) ; i++){
		string str = "asdfghj";
		long long curr = H(prevHash, str, i); 
		if (curr % 10000000 == 0) {
			// cout<<curr<<endl;
			cout<<str<<" "<<i<<endl;
			lastH = curr;
			lastStr = str;
			break;
		}
	}
	
	for(long long i = 0 ; i<(1<<31-1) ; i++){
		string str = "asdfghj";
		long long curr = H(lastH, str, i); 
		if (curr % 10000000 == 0) {
			// cout<<curr<<endl;
			cout<<str<<" "<<i<<endl;
			lastH = curr;
			lastStr = str;
			break;
		}
	}


	// long long num = (1LL << 63) - 1;
	// cout<<num;


}
//--------------------EOSOLUTION---------------------------------