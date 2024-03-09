#include<bits/stdc++.h>
#define StarburstStream ios_base::sync_with_stdio(0); cin.tie(0);
#define int long long
#define pb push_back
#define pii pair<int, int>
using namespace std;

const int MAXN = 1e5+5;
set<int>adj[MAXN];
int sz[MAXN], p[MAXN];
int N;

int dfs(int x, int pa){
    sz[x] = 1;
    for(int i: adj[x]){
        if(i != pa){
            sz[x] += dfs(i, x);
        }
    }
    return sz[x];
}

int centroid(int x, int pa, int n){
    for(int i: adj[x]){
        if(i != pa && sz[i] > n/2){
            return centroid(i, x, n);
        }
    }
    return x;
}

void build(int x, int pa){
    int n = dfs(x, pa);
    int c = centroid(x, pa, n);

    p[c] = pa;

    vector<int> tmp(adj[c].begin(), adj[c].end());
    for(int i: tmp){
        adj[c].erase(i);
        adj[i].erase(c);
        build(i, c);
    }
}

signed main(){
    StarburstStream
    cin >> N;
    for(int i = 1; i <= N; i++){
        int x, y;
        cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
    }
}
