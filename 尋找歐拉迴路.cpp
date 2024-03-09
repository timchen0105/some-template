#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define pb push_back
#define AC ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int MAXN = 1e5+5;
int visit[MAXN];
vector<int>adj[MAXN], ans;
set<pii>s;
int n, m, cnt = 0;

void dfs(int x){
    visit[x] = true;
    for(int i: adj[x]){
        if(s.find({i, x}) != s.end()){
            s.erase(s.find({i, x}));
            s.erase(s.find({x, i}));
            dfs(i);
        }
    }
    ans.pb(x);
}

signed main(){
    AC
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
        s.insert({a, b});
        s.insert({b, a});
    }

    for(int i = 1; i <= n; i++){
        cnt += (adj[i].size() % 2);
    }

    if(cnt == 0){
        dfs(1);
        for(int i = 1; i <= n; i++){
            if(visit[i] == false){
                cout << "IMPOSSIBLE" << endl;
                exit(0);
            }
        }

        for(int i: ans){
            cout << i << " ";
        }
    }else{
        cout << "IMPOSSIBLE" << endl;
    }
}
