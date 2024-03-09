#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int MAXN = 1e5+5;
int n, m, p[MAXN], sz[MAXN];

int dsu_find(int x){
    if(x == p[x]) return x;
    return p[x] = dsu_find(p[x]);
}

void dsu_merge(int x, int y){
    int px = dsu_find(x);
    int py = dsu_find(y);
    if(sz[px] < sz[py]) swap(px, py);
    p[py] = px;
    sz[px] += sz[py];
}

bool dsu_same(int x, int y){
    return dsu_find(x) == dsu_find(y);
}

signed main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        p[i] = i;
        sz[i] = 1;
    }
    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
    }
}
