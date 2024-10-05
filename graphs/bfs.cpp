#include<vector>
#include<bitset>
#include<queue>
#include<stack>

using namespace std;
#define GS 400040

vector<int> graph[GS];
bitset <GS> vis;
//anchura O(V+E)
void dfs(int curr) {
	queue<int> fringe;
	fringe.push(curr);
	while (fringe.size()) {
		curr = fringe.front(); fringe.pop();
		if (!vis[curr]) {
			vis[curr] = 1;
			for (int h : graph[curr]) fringe.push(h);
		}
	}
}