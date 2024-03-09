#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+50;

vector<int>adj[MAXN];
bool visit[MAXN];
int n;

void adjacency_lists(){
	for(int i = 1; i <= n; i++){
		adj[i].clear();
	}

	int a, b;
	while(cin >> a >> b){
		adj[a].push_back(b);
	}
}

void DFS(int i){
	for(int j = 0; j < adj[i].size(); j++){
		int v = adj[i][j];

		if(!visit[v]){
			visit[v] = true;
			DFS(v);
		}
	}
}

void traversal(){
	for(int i = 1; i <= n; i++){
		visit[i] = false;
	}

	for(int i = 1; i <= n; i++){
		if(!visit[i]){
			visit[i] = true;
			DFS(i);
		}
	}
}

int main(){

}
