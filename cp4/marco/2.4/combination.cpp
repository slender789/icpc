#include "bits/stdc++.h"
//assert(x>0) si falla da RTE
using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;

//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    // Combination
    int n = 7, k = 3;
    vector<int> taken(n, 0);
    for (int i = n-k; i < n; ++i) taken[i] = 1;
    do {
        for (int i = 0; i < n; ++i)
            if (taken[i]) printf("%d ", i);
        printf("\n");
    }
    while (next_permutation(taken.begin(), taken.end()));

    cout<<endl;
    
    // // Permutation
    // vector<int> nums(n);
    // for (int i = 0; i < n; ++i) nums[i] = i;  // Initialize nums with 0, 1, ..., n-1
    // do {
    //     // Print only the first k elements of the current permutation
    //     for (int i = 0; i < k; ++i)
    //         printf("%d ", nums[i]);
    //     printf("\n");
    // } while (next_permutation(nums.begin(), nums.end()));
    
    return 0;
}
//--------------------EOSOLUTION---------------------------------