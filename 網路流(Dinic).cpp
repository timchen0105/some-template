#include<bits/stdc++.h>
#define StarburstStream
#define int long long
#define pb push_back
#define pii pair<int, int>
using namespace std;

struct Edge{
    int to, cap, rev;
};
const int MAXN = 205;
int INF = 1e18, n, m, s, t, level[MAXN], iter[MAXN];
vector<Edge> adj[MAXN];

void bfs(){
    memset(level, -1, sizeof(level));
    level[s] = 0;
    queue<int>q;
    q.push(s);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(Edge i: adj[x]){
            if(i.cap > 0 && level[i.to] == -1){
                q.push(i.to);
                level[i.to] = level[x] + 1;
            }
        }
    }
}

int dfs(int x, int flow){
    if(x == t) return flow;
    for(int &j = iter[x]; j < adj[x].size(); j++){
        Edge &i = adj[x][j];
        if(i.cap > 0 && level[i.to] == level[x] + 1){
            int tmp = dfs(i.to, min(i.cap, flow));
            if(tmp > 0){
                i.cap -= tmp;
                adj[i.to][i.rev].cap += tmp;
                return tmp;
            }
        }
    }
    return 0;
}

int flow(){
    int res = 0;
    while(true){
        bfs();
        if(level[t] == -1) break;
        memset(iter, 0, sizeof(iter));
        int tmp = 0;
        while((tmp = dfs(s, INF)) > 0){
            res += tmp;
        }
    }
    return res;
}

signed main(){
    StarburstStream
    cin >> n >> m >> s >> t;
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w, adj[v].size()});
        adj[v].pb({u, 0, adj[u].size() - 1});

        adj[v].pb({u, w, adj[u].size()});
        adj[u].pb({v, 0, adj[v].size() - 1});
    }
    cout << flow() << endl;
}
