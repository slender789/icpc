#include "iostream"
#include "vector"
//assert(x>0) si falla da RTE
using namespace std;
#define endl '\n'
#define DBG(x) cerr<<#x<< "=" << (x) << endl;
#define RAYA cerr<<"======================"<<endl;
#define RAYAS cerr<<"......................"<<endl;
#define RAYAS cerr<<"......................"<<endl;
int INF = 100000000;

bool check(int &mark, int A ,int B, vector<vector<int>>&vec, vector<vector<bool>>&visitadoLocal){
    if (visitadoLocal[A][B]){ 
        return false;
    };
    visitadoLocal[A][B] = true;
    
    if (vec[A][B]==INF){
        vec[A][B] = mark;
        return true;
    }

    bool ans = false;
    bool auxAns = false;
    if (A-1>=0 && A-1 <vec.size()){
        auxAns = check(mark, A-1 ,B, vec, visitadoLocal);
        ans = ans || auxAns;
    }
    if (A+1>=0 && A+1 <vec.size()){
        auxAns = check(mark, A+1 ,B, vec, visitadoLocal);
        ans = ans || auxAns;
    }
    if (B-1>=0 && B-1 <vec[0].size()){
        auxAns = check(mark, A, B-1 ,vec, visitadoLocal);
        ans = ans || auxAns;
    }
    if (B+1>=0 && B+1 <vec[0].size()){
        auxAns = check(mark, A ,B+1, vec, visitadoLocal);
        ans = ans || auxAns;
    }
    return ans;
}

//--------------------SOLBEGIN---------------------------------
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int a, b;
    char aux;
	cin >> a >> b;
    vector<vector<int>>vec(a+2, vector<int>(b+2, 0));

    for(int i = 1 ; i<a+1 ; i++) {
        for(int j = 1 ; j<b+1 ; j++) {
            cin >> aux;
            if (aux == '.') {
                vec[i][j] = 0;
            } else {
                vec[i][j] = INF;
            }
        }
    }

    bool found = true;
    int cont = 1;
    while (found) {
        found = false;
        vector<vector<bool>>visitadoLocal(a+2, vector<bool>(b+2, false));
        found = check(cont, 0 , 0, vec, visitadoLocal);
        if (found) cont++;
    }
    cont--;

    for(int i = 1 ; i<a+1 ; i++) {
        for(int j = 1 ; j<b+1 ; j++) {
            /*
            Output a grid with the ring numbers. 
            If the number of rings is less than 10, use two characters for each grid square; 
            otherwise use three characters for each grid square. 
            Right justify all ring numbers in the grid squares, and use ‘.’ to fill in the remaining characters.
            If a row or column does not contain a ring number it should still be output, filled entirely with ‘.’s.

            */
            if (cont < 10) {
                if (vec[i][j] == 0) {
                    cout<<"..";
                }
                else {
                    cout << "." << vec[i][j];
                }
            }
            else {
                if (vec[i][j] == 0) {
                    cout<<"...";
                }
                else if (vec[i][j] < 10) {
                    cout << ".." << vec[i][j];
                }
                else if (vec[i][j] < 100) {
                    cout << "." << vec[i][j];
                }
                else {
                    cout << vec[i][j];
                }
            }
        }
        cout<<endl;
    }
    // for(int i = 1 ; i<a+1 ; i++) {
    //     for(int j = 1 ; j<b+1 ; j++) {
    //         cout << vec[i][j];
    //     }
    //     cout<<endl;
    // }
}

//--------------------EOSOLUTION---------------------------------
/*
4 4 
TTTT
TTTT
TTTT
TTTT
.1.1.1.1
.1.2.2.1
.1.2.2.1
.1.1.1.1


6 11
...T.......
.TTT.......
TTTTTTTTT..
TTTTTTTTTTT
TTTTTTTTTTT
TTTTTTTTTTT

.......1..............
...1.1.1..............
.1.2.2.2.1.1.1.1.1....
.1.2.3.3.2.2.2.2.2.1.1
.1.2.2.2.2.2.2.2.2.2.1
.1.1.1.1.1.1.1.1.1.1.1


.......1....
...1.1.1....
.1.2.2.2.1..
.1.2.3.3.2.1
.1.2.2.2.2.1
.1.1.1.1.1.1

25 25
TTTTTTTTTTTTTTTTTTTTTTTTT
TTTTTTTTTTTTTTTTTTTTTTTTT
TTTTTTTTTTTTTTTTTTTTTTTTT
TTTTTTTTTTTTTTTTTTTTTTTTT
TTTTTTTTTTTTTTTTTTTTTTTTT
TTTTTTTTTTTTTTTTTTTTTTTTT
TTTTTTTTTTTTTTTTTTTTTTTTT
TTTTTTTTTTTTTTTTTTTTTTTTT
TTTTTTTTTTTTTTTTTTTTTTTTT
TTTTTTTTTTTTTTTTTTTTTTTTT
TTTTTTTTTTTTTTTTTTTTTTTTT
TTTTTTTTTTTTTTTTTTTTTTTTT
TTTTTTTTTTTTTTTTTTTTTTTTT
TTTTTTTTTTTTTTTTTTTTTTTTT
TTTTTTTTTTTTTTTTTTTTTTTTT
TTTTTTTTTTTTTTTTTTTTTTTTT
TTTTTTTTTTTTTTTTTTTTTTTTT
TTTTTTTTTTTTTTTTTTTTTTTTT
TTTTTTTTTTTTTTTTTTTTTTTTT
TTTTTTTTTTTTTTTTTTTTTTTTT
TTTTTTTTTTTTTTTTTTTTTTTTT
TTTTTTTTTTTTTTTTTTTTTTTTT
TTTTTTTTTTTTTTTTTTTTTTTTT
TTTTTTTTTTTTTTTTTTTTTTTTT
TTTTTTTTTTTTTTTTTTTTTTTTT

..1..1..1..1..1..1..1..1..1..1..1..1..1..1..1..1..1..1..1..1..1..1..1..1..1
..1..2..2..2..2..2..2..2..2..2..2..2..2..2..2..2..2..2..2..2..2..2..2..2..1
..1..2..3..3..3..3..3..3..3..3..3..3..3..3..3..3..3..3..3..3..3..3..3..2..1
..1..2..3..4..4..4..4..4..4..4..4..4..4..4..4..4..4..4..4..4..4..4..3..2..1
..1..2..3..4..5..5..5..5..5..5..5..5..5..5..5..5..5..5..5..5..5..4..3..2..1
..1..2..3..4..5..6..6..6..6..6..6..6..6..6..6..6..6..6..6..6..5..4..3..2..1
..1..2..3..4..5..6..7..7..7..7..7..7..7..7..7..7..7..7..7..6..5..4..3..2..1
..1..2..3..4..5..6..7..8..8..8..8..8..8..8..8..8..8..8..7..6..5..4..3..2..1
..1..2..3..4..5..6..7..8..9..9..9..9..9..9..9..9..9..8..7..6..5..4..3..2..1
..1..2..3..4..5..6..7..8..9.10.10.10.10.10.10.10..9..8..7..6..5..4..3..2..1
..1..2..3..4..5..6..7..8..9.10.11.11.11.11.11.10..9..8..7..6..5..4..3..2..1
..1..2..3..4..5..6..7..8..9.10.11.12.12.12.11.10..9..8..7..6..5..4..3..2..1
..1..2..3..4..5..6..7..8..9.10.11.12.13.12.11.10..9..8..7..6..5..4..3..2..1
..1..2..3..4..5..6..7..8..9.10.11.12.12.12.11.10..9..8..7..6..5..4..3..2..1
..1..2..3..4..5..6..7..8..9.10.11.11.11.11.11.10..9..8..7..6..5..4..3..2..1
..1..2..3..4..5..6..7..8..9.10.10.10.10.10.10.10..9..8..7..6..5..4..3..2..1
..1..2..3..4..5..6..7..8..9..9..9..9..9..9..9..9..9..8..7..6..5..4..3..2..1
..1..2..3..4..5..6..7..8..8..8..8..8..8..8..8..8..8..8..7..6..5..4..3..2..1
..1..2..3..4..5..6..7..7..7..7..7..7..7..7..7..7..7..7..7..6..5..4..3..2..1
..1..2..3..4..5..6..6..6..6..6..6..6..6..6..6..6..6..6..6..6..5..4..3..2..1
..1..2..3..4..5..5..5..5..5..5..5..5..5..5..5..5..5..5..5..5..5..4..3..2..1
..1..2..3..4..4..4..4..4..4..4..4..4..4..4..4..4..4..4..4..4..4..4..3..2..1
..1..2..3..3..3..3..3..3..3..3..3..3..3..3..3..3..3..3..3..3..3..3..3..2..1
..1..2..2..2..2..2..2..2..2..2..2..2..2..2..2..2..2..2..2..2..2..2..2..2..1
..1..1..1..1..1..1..1..1..1..1..1..1..1..1..1..1..1..1..1..1..1..1..1..1..1

*/