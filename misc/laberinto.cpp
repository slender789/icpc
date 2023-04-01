#include <bits/stdc++.h>
using namespace std;
#define max 1002
 
char mapa[max][max];
bool visited[max][max];
queue<pair<pair<int, int>, int>> adj;
char fatherMove[max][max];
int nivel = 0;
string mov="";
 
int addEdge(int r, int c, int maxR, int maxC, int nivel){
    if (mapa[r][c]=='B'){
        return 1;
    }
    if(visited[r][c]) return 0;
    if(0<=r+1 && r+1<maxR && !visited[r+1][c]){
        adj.push({{r+1, c}, nivel + 1});
        fatherMove[r+1][c]='D';
    }
    if(0<=r-1 && r-1<maxR && !visited[r-1][c]){
        adj.push({{r-1, c}, nivel + 1});
        fatherMove[r-1][c]='U';
    }
    if(0<=c+1 && c+1<maxC && !visited[r][c+1]){
        adj.push({{r, c+1}, nivel + 1});
        fatherMove[r][c+1]='R';
    }
    if(0<=c-1 && c-1<maxC && !visited[r][c-1]){
        adj.push({{r, c-1}, nivel + 1});
        fatherMove[r][c-1]='L';
    }
    return 0;
}
 
void moves(int r, int c){
    if (mapa[r][c] == 'A'){
        return;
    }
    mov += fatherMove[r][c];

    if(fatherMove[r][c] == 'U'){
        moves(r+1, c);
    }
    else if(fatherMove[r][c] == 'D'){
        moves(r-1, c);
    }
    else if(fatherMove[r][c] == 'R'){
        moves(r, c-1);
    }
    else if(fatherMove[r][c] == 'L'){
        moves(r, c+1);
    }
}
 
int main(){
    int row;
    int col;
    cin>>row>>col;
    
    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            cin>>mapa[i][j];
            if(mapa[i][j]=='#') visited[i][j]=true;
            else visited[i][j]=false;
            fatherMove[i][j]='X';
        }
    }
 
    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            if (mapa[i][j]=='A'){
                adj.push({{i,j}, 0});
                while(adj.size() != 0){
                    int topR=adj.front().first.first;
                    int topC=adj.front().first.second;
                    int level=adj.front().second;
                    adj.pop();
                    if (addEdge(topR, topC, row, col, level)==1){
                        moves(topR, topC);
                        cout<<"YES"<<endl;
                        cout<<level<<endl;
                        reverse(mov.begin(),mov.end());
                        cout<<mov;
                        return 0;
                    }
                    visited[topR][topC]=true;
                }
                cout<<"NO";
                return 0;
            }
 
        }
    }
}