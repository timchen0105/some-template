#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define AC ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int MAXN = 1e4+50;
vector<int>adj[MAXN], ap;
int depth[MAXN], low[MAXN];
int t = 1;
int n, m;

void dfs(int i, int pa){
    depth[i] = low[i] = t;
    t++;
    int child_count = 0;
    bool is_ap = false;

    for(int u: adj[i]){
        if(u == pa) continue;
        if(!depth[u]){
            dfs(u, i);
            child_count++;
            if(depth[i] <= low[u]) is_ap = true;
            low[i] = min(low[i], low[u]);
        }
        low[i] = min(low[i], depth[u]);
    }
    if(i == pa && child_count < 2) is_ap = false;
    if(is_ap) ap.pb(i);
    return;
}

signed main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(int i = 1; i <= n; i++){
        if(!depth[i]){
            dfs(i, i);
        }
    }
    for(int i: ap){
        cout << i << endl;
    }
}
