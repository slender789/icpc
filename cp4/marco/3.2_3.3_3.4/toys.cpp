#include "bits/stdc++.h"
//assert(x>0) si falla da RTE
using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;

/*
For other cases, let F(n,k) denotes the position of the survivor for a circle of size n
and with k skipping rule and we number the people from 0, 1, . . . , n-1 (we will later
add +1 to the final answer to match the format of the original problem description).
After the k-th person is killed, the circle shrinks by one to size n-1 and the position
of the survivor is now F (n-1, k) + k (mod n). This is captured with equation 
    F (n, k) = (F (n-1, k) + k)%n. The base case is when n = 1 where we have
    F (1, k) = 0. This recurrence has a time complexity of O(n).
*/

int josephus(int n, int k){
    if(n==1)return 0;
    return (josephus(n-1, k) + k)%n;
}

//--------------------SOLBEGIN---------------------------------
int main() {
  ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    long long int t, k;
    cin >> t >> k;
    cout<<josephus(t, k);
    return 0;

}
//--------------------EOSOLUTION---------------------------------