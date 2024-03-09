#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define pii pair<int, int>
using namespace std;

const int MAXN = 1e6+5;
vector<int>adj[MAXN];
int sz[MAXN];
int center, csize;
int n;

void dfs(int x, int fa){
    int maxsub = 0;
    sz[x] = 1;

    for(int i: adj[x]){
        if(i == fa) continue;
        dfs(i, x);
        maxsub = max(maxsub, sz[i]);
        sz[x] += sz[i];
    }
    maxsub = max(maxsub, n-sz[x]);

    if(maxsub < csize){
        center = x;
        csize = maxsub;
    }
}

signed main(){
    cin >> n;
    for(int i = 1; i <= n-1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    csize = 1e18;
    dfs(0, 0);
    cout << csize << "\n";
}
