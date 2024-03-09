#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define AC ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int MAXN = 1e4+50;
vector<int>adj[MAXN];
int depth[MAXN], low[MAXN];
stack<int>st;
vector<vector<int> >bcc;
int t = 1;
int n, m;

void dfs(int i, int pa){
    depth[i] = low[i] = t;
    t++;
    st.push(i);

    for(int u: adj[i]){
        if(u == pa) continue;
        if(!depth[u]){
            dfs(u, i);
            low[i] = min(low[i], low[u]);
            if(low[u] >= depth[i]){
                int x;
                bcc.pb({});
                do{
                    x = st.top(); st.pop();
                    bcc.back().pb(x);
                }while(x != i);
                st.push(i);
            }
        }
        low[i] = min(low[i], depth[u]);
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
    for(auto i: bcc){
        for(auto j: i){
            cout << j << " ";
        }
        cout << endl;
    }
}
