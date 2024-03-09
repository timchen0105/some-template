#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define pii pair<int, int>
using namespace std;

const int MAXN = 1e4+5;
vector<int>adj[MAXN];
bool in_st[MAXN];
int depth[MAXN], low[MAXN], scc[MAXN];
stack<int>st;
int t = 1;
int n, m;
int scc_id = 1;

void dfs(int i, int pa){
    depth[i] = low[i] = t;
    t++;
    st.push(i);
    in_st[i] = true;

    for(int u: adj[i]){
        if(!depth[u]){
            dfs(u, i);
            low[i] = min(low[i], low[u]);
        }else if(in_st[i]){
            low[i] = min(low[i], depth[u]);
        }
    }

    if(depth[i] == low[i]){
        int x;
        do{
            x = st.top(); st.pop();
            scc[x] = scc_id;
            in_st[x] = false;
        }while(x != i);
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
        while(!st.empty()){
            st.pop();
        }
        if(!depth[i]){
            dfs(i, i);
        }
    }

    for(int i = 1; i <= n; i++){
        cout << scc[i] << endl;
    }
}
