#include <bits/stdc++.h>
using namespace std;

#define GS 300010
vector<int>graph[GS];
bitset<GS>vis;
int n;

void dfs(int curr){
    if(vis[curr] || curr == n) return;
    vis[curr] = 1;
    for(int h: graph[curr]) if(!vis[h]) dfs(h);
}

int main(){
    int m, ini, fin;
    cin>>n>>m;
    while(m--){
        cin>>ini>>fin;
        graph[ini].push_back(fin);
        graph[fin].push_back(ini);
    }
    dfs(n-1);
    for(int i = 1; i<=n ; i++) cout<<(vis[i]?'B':'A');
    cout<<endl;
}