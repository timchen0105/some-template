#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int MAXN = 1e3;
int n, m, root;
vector<int>adj[MAXN];
int lca[MAXN][MAXN];
bool visit[MAXN];
int p[MAXN];

void init(){
    for(int i = 1; i <= n; i++){
        p[i] = i;
        visit[i] = false;
    }

    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
    }
}

int find(int x){
    return x == p[x] ? x : (p[x] = find(p[x]));
}

void dfs(int x){
    if(visit[x]) return;
    visit[x] = true;

    for(int y = 1; y <= n; y++){
        if(visit[y]){
            lca[x][y] = lca[y][x] = find(y);
        }
    }

    for(int i = 0; i < adj[x].size(); i++){
        dfs(adj[x][i]);
        p[adj[x][i]] = x;
    }
}

signed main(){
    cin >> n >> m >> root;
    init();
    dfs(root);

    while(1){
        int x, y;
        cin >> x >> y;
        cout << lca[x][y] << endl;
    }
}
