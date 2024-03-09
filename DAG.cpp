#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+50;
vector<int>adj[MAXN];
int inDegree[MAXN];
int outDegree[MAXN];
int dp[MAXN];
int visit[MAXN];
vector<int>inDegreeIsZero;

int DFS(int first, int v){
    visit[v] = 1;
    if(dp[v]) return dp[v];
    for(int i = 0; i < adj[v].size(); i++){
        if(!visit[adj[v][i]]){
            return dp[v] = max(dp[v], DFS(v, adj[v][i]) + 1);
        }
    }
    return 1;
}

int main(){
    memset(inDegree, 0, sizeof(inDegree));
    memset(outDegree, 0, sizeof(outDegree));
    memset(dp, 0, sizeof(dp));
    memset(visit, 0, sizeof(visit));
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        inDegree[y]++;
        outDegree[x]++;
    }

    for(int i = 1; i <= n; i++){
        if(inDegree[i] == 0){
            inDegreeIsZero.push_back(i);
        }
    }

    for(int i = 0; i < inDegreeIsZero.size(); i++){
        dp[inDegreeIsZero[i]] = DFS(inDegreeIsZero[i], inDegreeIsZero[i]);
    }

    int big = 0;

    for(int i = 1; i <= n; i++){
        cout << dp[i] << endl;
    }

}
