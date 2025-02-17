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
    int h, w, rak;
    cin >> h >> w >> rak;
    vector<vector<int>>A(h, vector<int>(w));
    vector<vector<char>>cop(h, vector<char>(w));
    char aux;
    for (int i = 0; i < h; ++i){
        for (int j = 0; j < w; ++j) {
            cin>>aux;
            cop[i][j] = aux;
            aux == '*' ? A[i][j] = 1 : A[i][j] = 0;
            if (i > 0) A[i][j] += A[i-1][j];
            if (j > 0) A[i][j] += A[i][j-1];
            if (i > 0 && j > 0) A[i][j] -= A[i-1][j-1];// avoid double count
        }
    }
    int I = 0, J = 0;
    int maxSubRect = -1;
    for (int i = 1; i < h; ++i){
        for (int j = 1; j < w; ++j) {
            int k = i+(rak-1-2);
            //-1 to avoid testing over the last row/col
            if (k >= (h-1) || k<0) continue;
            int l = j+(rak-1-2);
            if (l >= (w-1) || l<0) continue;

            int subRect = A[k][l];
            subRect -= A[i-1][l];
            subRect -= A[k][j-1];
            subRect += A[i-1][j-1]; // O(1)
            
            if(subRect > maxSubRect){
                maxSubRect = max(maxSubRect, subRect); // the answer is here
                I = i-1;
                J = j-1;
            }
            // cout<<" i "<<i<<" k "<<k<<" j "<<j<<" l "<<l<<" subRect "<<subRect<<endl;
        }
    }
    // cout<<I<<endl;
    // cout<<J<<endl;
    cout<<maxSubRect<<endl;
    for(int i = I+1 ; i<(I+rak) ; i++){
        cop[i][J] = '|';
        cop[i][J+(rak-1)] = '|';
    }
    for(int j = J+1 ; j<(J+rak) ; j++){
        cop[I][j] = '-';
        cop[I+(rak-1)][j] = '-';
    }
    cop[I][J] = '+'; 
    cop[I+(rak-1)][J] = '+'; 
    cop[I][J+(rak-1)] = '+'; 
    cop[I+(rak-1)][J+(rak-1)] = '+'; 

    for (int i = 0; i < h; ++i){
        for (int j = 0; j < w; ++j) {
            cout<<cop[i][j];
        }
        cout<<endl;
    }




}
//--------------------EOSOLUTION---------------------------------