#include "iostream"
#include "string"
#include "vector"
#include "stack"
#include "sstream"
#include "unordered_map"
#include "algorithm"
#include "deque"
#include "list"

//assert(x>0) si falla da RTE
using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int size, aux;

    cin >> size;
    int maxL = 0;
    vector<int>nums;
    vector<int>maxLeft;
    vector<int>maxRight;
    while (size--){
        cin >> aux;
        maxL = max(maxL, aux);
        nums.push_back(aux);
        maxLeft.push_back(maxL);
    }
    int maxR = 0;
    for(int i = nums.size()-1 ; i>=0 ; i--){
        maxR = max(maxR, nums[i]);
        maxRight.push_back(maxR);
    }
    reverse(maxRight.begin(), maxRight.end());

    int maxJ = 0;
    for(int i = 1 ; i<nums.size()-1 ; i++){
        if (maxLeft[i-1] < nums[i] || maxRight[i+1] < nums[i]) continue;
        int minf = min(maxLeft[i-1], maxRight[i+1]);
        maxJ = max(maxJ, minf-nums[i]);
    }
    cout<<maxJ;

}
//--------------------EOSOLUTION---------------------------------