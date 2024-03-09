#include<bits/stdc++.h>
#define pb push_back
using namespace std;

struct Element{
    int u;
    int v;
    int w;
};

const int MAXN = 1e5+1;
int n, m, s;
Element edge[MAXN];
int dis[MAXN];

void init(){
    dis[s] = 0;
    for(int i = 1; i <= m; i++){
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
        if(edge[i].u == s){
            dis[edge[i].v] = edge[i].w;
        }
    }
}

void relax(int u, int v, int w){
    dis[v] = min(dis[v], dis[u] + w);
}

bool bellman_ford(){
    for(int i = 1; i <= n-1; i++){
        for(int j = 1; j <= m; j++){
            relax(edge[j].u, edge[j].v, edge[j].w);
        }
    }

    bool flag = true;

    for(int i = 1; i <= m; i++){
        if(dis[edge[i].v] > dis[edge[i].u] + edge[i].w) flag = false;
    }

    return flag;
}

signed main(){
    memset(dis, 0x3f, sizeof(dis));
    cin >> n >> m >> s;
    init();
    if(bellman_ford()){
        for(int i = 1; i <= n; i++){
            cout << dis[i] << endl;
        }
    }
}
