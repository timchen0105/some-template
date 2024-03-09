#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define pb push_back
using namespace std;

const int MAXN = 1e4+5;
vector<int>adj[MAXN];
int n, m;
int cnt = 0;

signed main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    for(int i = 1; i <= n; i++){
        cnt += (adj[i].size() % 2);
    }

    if(cnt == 2){
        cout << "¼Ú©Ô¸ô®|";
    }else if(cnt == 0){
        cout << "¼Ú©Ô°j¸ô";
    }else{
        cout << "NO";
    }
}
