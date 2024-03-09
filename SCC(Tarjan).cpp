#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int MAXN = 1e4+50;
vector<int>adj[MAXN];
int visit[MAXN];
int low[MAXN];
int scc[MAXN];
bool in_st[MAXN];
stack<int>st;
int t = 1;
int n, m;
int scc_id = 1;

void dfs(int p, int i){
    visit[i] = low[i] = t++;
    st.push(i);
    in_st[i] = true;

    for(int j = 0; j < adj[i].size(); j++){
        int u = adj[i][j];
        if(!visit[u]){
            dfs(i, u);
            low[i] = min(low[i], low[u]);
        }else if(in_st[u]){
            low[i] = min(low[i], visit[u]);
        }
    }

    if(visit[i] == low[i]){
        int j;
        do{
            j = st.top(); st.pop();
            scc[j] = scc_id;
            in_st[j] = false;
        }while(i != j);
        scc_id++;
    }
}

signed main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
    }
    for(int i = 1; i <= n; i++){
        if(!visit[i]){
            dfs(i, i);
        }
    }
}
