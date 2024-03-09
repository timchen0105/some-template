#include<bits/stdc++.h>
#define StarburstStream ios_base::sync_with_stdio(0); cin.tie(0);
#define int long long
#define pb push_back
#define pii pair<int, int>
using namespace std;

const int MAXN = 1e5+5;

using namespace std;
int n;
vector<int>adj[MAXN];

struct Node{
    int pa, deep, sz, hson, top, id;
}node[MAXN];
int tot = 1, num[MAXN];

int prepare(int x, int pa, int d){
    int maxsub = 0;
    node[x].pa = pa;
    node[x].deep = d;
    node[x].sz = 1;
    node[x].hson = -1;

    for(int i: adj[x]){
        if(i != pa){
            int sub = prepare(i, x, d+1);
            node[x].sz += sub;
            if(sub > maxsub){
                maxsub = sub;
                node[x].hson = i;
            }
        }
    }

    return node[x].sz;
}

void decomposition(int x, int pa, int top){
    node[x].top = top;
    node[x].id = tot;
    num[tot] = x;
    tot++;
    if(node[x].hson != -1){
        decomposition(node[x].hson, x, top);
        for(int i: adj[x]){
            if(i != pa && i != node[x].hson){
                decomposition(i, x, i);
            }
        }
    }
}

signed main(){
    cin >> n;
    for(int i = 1; i <= n-1; i++){
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    prepare(1, 1, 0);
    decomposition(1, 1, 1);
}
