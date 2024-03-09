#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

int n, m; //ек еk
const int MAXN = 1e4+50, MAXM = 1e4+50;
vector<int>adj[MAXN];
int p[MAXM];
bool visit[MAXM];

bool match(int v){
    for(int i = 0; i < adj[v].size(); i++){
        int u = adj[v][i];
        if(!visit[u]){
            visit[u] = true;

            if(p[u] == 0 || match(p[u])){
                p[u] = v;
                return true;
            }
        }
    }
    return false;
}

int hungarian(){
    int cnt = 0;

    for(int i = 1; i <= n; i++){
        memset(visit, 0, sizeof(visit));
        if(match(i)) cnt++;
    }
    return cnt;
}

signed main(){
    int s;
    cin >> n >> m >> s;
    for(int i = 1; i <= s; i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    cout << hungarian() << endl;
}
