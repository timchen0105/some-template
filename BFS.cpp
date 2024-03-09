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

void BFS(){
	queue<int>q;

	for(int i = 1; i <= n; i++){
		visit[i] = false;
	}

	for(int k = 1; k <= n; k++){
		if(!visit[k]){
			q.push(k);
			visit[k] = true;

			while(!q.empty()){
				int i = q.front();
				q.pop();

				for(int j = 0; j < adj[i].size(); j++){
					int v = adj[i][j];

					if(!visit[v]){
						q.push(v);
						visit[v] = true;
					}
				}
			}
		}
	}
}

int main(){

}
