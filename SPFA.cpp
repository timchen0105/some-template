#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

struct Element{
    int v;
    int w;
};

const int MAXN = 1e5+1;
int INF = 1e18;
int n, m, s;
int dis[MAXN];
bool visit[MAXN];
int num[MAXN];
vector<Element>adj[MAXN];

void init(){
    dis[s] = 0;
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        Element temp;
        temp.v = v;
        temp.w = w;
        adj[u].pb(temp);
    }
}

bool SPFA(){

    queue<int>q;
    q.push(s);
    visit[s] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        visit[u] = false;
        for(auto i : adj[u]){
            if(dis[i.v] > dis[u] + i.w){
                num[i.v]++;
                if(num[i.v] > n-1) return false;
                dis[i.v] = dis[u] + i.w;
                if(!visit[i.v]){
                    q.push(i.v);
                    visit[i.v] = true;
                }
            }
        }
    }
    return true;
}

signed main(){
    for(int i = 1; i <= n; i++){
        dis[i] = INF;
    }
    memset(num, 0, sizeof(num));
    cin >> n >> m >> s;
    init();
    if(SPFA()){
        for(int i = 1; i <= n; i++){
            cout << dis[i] << endl;
        }
    }
}

//5 7 1
//1 2 3
//1 4 7
//1 3 5
//2 3 9
//3 4 1
//3 1 8
//2 5 4
