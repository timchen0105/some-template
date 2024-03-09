#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int MAXN = 1e3;
int n, m, root;
vector<int>adj[MAXN];
int tin[MAXN], tout[MAXN], t = 0;
int a[MAXN][30];

void dfs(int x, int px){
    tin[x] = t++;
    a[x][0] = px;

    for(int i = 1; (1 << i) < n/2; i++){
        a[x][i] = a[a[x][i-1]][i-1];
    }

    for(int i = 0; i < adj[x].size(); i++){
        dfs(adj[x][i], x);
    }

    tout[x] = t++;
}

bool ancestor(int x, int y){
    return tin[x] < tin[y] && tout[x] > tout[y];
}

int lca(int x, int y){
    if(x == y) return x;
    if(ancestor(x, y)) return x;
    if(ancestor(y, x)) return y;

    for(int i = 25; i >= 0; i--){
        if(!ancestor(a[x][i], y)){
            x = a[x][i];
        }
    }
    return a[x][0];
}

signed main(){
    cin >> n >> m >> root;
    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
    }
    dfs(root, root);

    int x, y;
    while(1){
        cin >> x >> y;
        cout << lca(x, y) << endl;
    }
}
