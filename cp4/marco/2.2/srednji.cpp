#include "iostream"
#include "string"
#include "vector"
#include "sstream"
#include "unordered_map"
#include "map"
#include "algorithm"
#include "set"
using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;

bool check(vector<int>&vec, int start, int end, int look) {
    end++;
    if (start < vec.size() && end <= vec.size() && start <= end) {
        vector<int> subvec(vec.begin() + start, vec.begin() + end);
        sort(subvec.begin(), subvec.end());
        // for(auto& e : subvec){
        //     cout<<e<<" ";
        // }
        // cout<<endl;
        // cout<<"checking idx "<<(subvec.size()-1)/2<<endl;
        if(subvec[(subvec.size()-1)/2] == look){
            return true;
        } else{
            return false;
        }
    } else {
        cout << "Invalid indices!" << endl;
        return false;
    }
}

//--------------------SOLBEGIN---------------------------------
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int tc, look, aux;
    vector<int>m;
    cin>>tc>>look;
    for(int i = 0 ; i<tc ; i++){
        cin>>aux;
        if (aux == look) m.push_back(i);
    }
    int sum = m.size();
    for(auto&e : m){
        int i = e-1;
        int j = e+1;
        while(i >= 0 && j <tc && ((m[i] <= look && m[j] >= look) || (m[j] <= look && m[i] >= look)) ){
            i -= 1;
            j += 1;
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
//--------------------EOSOLUTION---------------------------------