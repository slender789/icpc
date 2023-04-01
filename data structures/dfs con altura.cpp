#include "bits/stdc++.h"
using namespace std;
#define endl "\n"
#define GS 10

int altura[GS];
vector<int> grafo[GS];

void dfs(int padre){
	int curr;
	int visited[GS]={0};
	queue<int>cola;
	cola.push(padre);
    int cont_altura=0;
    altura[padre]=cont_altura;  
    
	while(cola.size() != 0){
		curr=cola.front();
		cout<<curr<<" "<<altura[curr]<<endl;
		cola.pop();
		for(int hijo : grafo[curr]){
			if(visited[hijo]==0){
				cola.push(hijo);
				visited[hijo]=1;
				altura[hijo]=altura[curr]+1;
			}
		}
	}
}

void dfs2(int padre){
	int curr;
	int visited[GS]={0};
	stack<int>pila;
	
	pila.push(padre);

	while(pila.size() != 0){
		curr=pila.top();
		cout<<curr<<endl;
		pila.pop();
		for(int hijo : grafo[curr]){
			if(visited[hijo]==0){
				pila.push(hijo);
				visited[hijo]=1;
			}
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
	
	int nodos, vertices, inicio, fin;
	cin>>nodos>>vertices;
	
	while(vertices--){
		cin>>inicio>>fin;
		grafo[inicio].push_back(fin);
	}
		
	dfs(0);	
	return 0;
}