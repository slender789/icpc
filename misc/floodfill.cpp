#include <bits/stdc++.h>
using namespace std;
#define max 100

int mapa[max][max];
bool visited[max][max];
stack<pair<int, int>> adj;
 
void addEdge(int r, int c, int maxR, int maxC){
    if(0<=r+1 && r+1<maxR && !visited[r+1][c]){
        adj.push({r+1, c});
    }
    if(0<=r-1 && r-1<maxR && !visited[r-1][c]){
        adj.push({r-1, c});
    }
    if(0<=c+1 && c+1<maxC && !visited[r][c+1]){
        adj.push({r, c+1});
    }
    if(0<=c-1 && c-1<maxC && !visited[r][c-1]){
        adj.push({r, c-1});
    }
}

int main(){
    int row;
    int col;
    cin>>row>>col;
    
    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            cin>>mapa[i][j];
            if(mapa[i][j]==1) visited[i][j]=true;
            else visited[i][j]=false;
        }
    }

    int contador = 0;
    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            if (mapa[i][j]==0 and !visited[i][j]){
                adj.push({i,j});
                while(adj.size() != 0){
                    int topR=adj.top().first;
                    int topC=adj.top().second;
                    adj.pop();
                    addEdge(topR, topC, row, col);
                    visited[topR][topC]=true;
                }
                contador++;
            }
        }
    }
    
    cout<<contador;

    return 0;
}