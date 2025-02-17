#include "iostream"
#include "string"
#include "vector"
#include "sstream"
//assert(x>0) si falla da RTE
using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;

int newDir(int& i, int& j, int& dir, vector<vector<char>>&vec){
    if (vec[i][j]=='*' || vec[i][j]=='.') return dir;
    if(vec[i][j]=='/'){
        // moving to top, then r
        if (dir==0) return 3;
        // moving down, then l
        if (dir==1) return 2;
        // moving to left, then d
        if (dir==2) return 1;
        // moving to right, then u
        if (dir==3) return 0;
    } else {
        // moving to top, then l
        if (dir==0) return 2;
        // moving down, then r
        if (dir==1) return 3;
        // moving to left, then u
        if (dir==2) return 0;
        // moving to right, then d
        if (dir==3) return 1;
    }
}

pair<int,int> myMove(int i, int j, int& dir, vector<vector<char>>vec){
    vector<pair<int, int>>pairs = {{-1,0},{1,0},{0,-1},{0,1}};
    i += pairs[dir].first;
    j += pairs[dir].second;
    return pair(i, j);
}

//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int a = 1;int b = 1;int startI = 0;int startJ = 0;int dir = 8;
    //0-top
    //1-down
    //2-left
    //3-right
    int myCont = 1;

	while (cin >> a >> b) {
        if (a == 0 || b == 0) return 0;
        vector<vector<char>>vec(b, vector<char>(a));
        for (int i = 0 ; i < b ; i++){
            for (int j = 0 ; j < a ; j++){
                cin>>vec[i][j];
                if ('*' == vec[i][j]){
                    startI = i;
                    startJ = j;

                    if (j==0) dir = 3;
                    if (i==0) dir = 1;
                    if (j==(b-1)) dir = 2;
                    if (i==(a-1)) dir = 0;
                }
            }
        }

        // cout<<dir<<endl;

        while(vec[startI][startJ]!='x'){
            dir = newDir(startI, startJ, dir, vec);
            auto p = myMove(startI, startJ, dir, vec);
            startI = p.first;
            startJ = p.second;
        }
        vec[startI][startJ] = '&';

        cout<<"HOUSE "<<myCont<<endl;
        myCont++;
        for (int i = 0 ; i < b ; i++){
            for (int j = 0 ; j < a ; j++){
                cout<<vec[i][j];
            }
            cout<<endl;
        }
	}

}
//--------------------EOSOLUTION---------------------------------
