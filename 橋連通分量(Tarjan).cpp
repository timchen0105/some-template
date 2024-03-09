#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define AC ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int MAXN = 1e4+50;
vector<int>adj[MAXN];
int depth[MAXN], low[MAXN];
int t = 1;
stack<int>st;
int bcc[MAXN];
int n, m;
int bcc_id = 1;

void dfs(int i, int pa){
    depth[i] = low[i] = t;
    t++;
    st.push(i);

    for(int u: adj[i]){
        if(u == pa) continue;
        if(!depth[u]){
            dfs(u, i);
            low[i] = min(low[i], low[u]);
        }
        low[i] = min(low[i], depth[u]);
    }
    if(depth[i] == low[i]){
        int x;
        do{
            x = st.top(); st.pop();
            bcc[x] = bcc_id;
        }while(x != i);
        bcc_id++;
    }
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
            while(!st.empty()){
                st.pop();
            }
            dfs(i, i);
        }
    }
    for(int i = 1; i <= n; i++){
        cout << bcc[i] << endl;
    }
}
