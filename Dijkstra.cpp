#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define pb push_back
using namespace std;

struct Element{
    int v;
    int w;
};

const int MAXN = 1001;
int INF = 1e9;
int n, m;
int s;
int dis[MAXN];
bool visit[MAXN];
vector<Element>adj[MAXN];
priority_queue<pii, vector<pii>, greater<pii> > pq;

void init(){
    for(int i = 1; i <= m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        Element temp;
        temp.v = b;
        temp.w = w;
        adj[a].pb(temp);
    }

    for(int i = 1; i <= n; i++){
        dis[i] = INF;
    }

    dis[s] = 0;

    pq.push({0, s});
    //first dis
    //second 點
}

void dijkstra(){
    while(pq.size()){
        pii u = pq.top();
        pq.pop();

        if(visit[u.second]) continue;
        visit[u.second] = true;

        for(auto i: adj[u.second]){
            if(dis[i.v] > u.first + i.w){
                dis[i.v] = u.first + i.w;
                pq.push({dis[i.v], i.v});
            }
        }
    }
}

signed main(){
    cin >> n >> m;
    cin >> s;

    init();
    dijkstra();

    for(int i = 1; i <= n; i++){
        cout << dis[i] << endl;
    }
}
