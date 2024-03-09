#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e3+1;
int INF = 1e9;
int dis[MAXN][MAXN];
int n, m;
int from, to;

void init(){

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j){
                dis[i][j] = 0;
            }else{
                dis[i][j] = INF;
            }
        }
    }

    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        dis[u][v] = w;
    }
}

void floyd_warshall(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
            }
        }
    }
}

signed main(){
    cin >> n >> m;
    init();
    floyd_warshall();
    cin >> from >> to;
    cout << dis[from][to] << endl;
}
