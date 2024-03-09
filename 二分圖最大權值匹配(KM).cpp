#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int MAXN = 305;
const int INF = 1e9;

struct Element{
    int b, w;
};

vector<Element>adj[MAXN];
int lx[MAXN], ly[MAXN];
bool visitx[MAXN], visity[MAXN];
int p[MAXN];
int slack[MAXN];
int n;

void init(){
    fill(lx+1, lx+1+n, 0);
    fill(ly+1, ly+1+n, 0);
    fill(p+1, p+1+n, 0);
    for(int i = 1; i <= n; i++){
        adj[i].clear();
    }
}

bool match(int v){
    cout << "a";
    visity[v] = true;

    for(int i = 0; i < adj[v].size(); i++){
        Element u = adj[v][i];

        if(!visitx[u.b]){
            int delta = lx[u.b] + ly[u.b] - u.w;

            if(delta == 0){
                visitx[u.b] = true;

                if(p[u.b] == 0 || match(p[u.b])){
                    p[u.b] = v;
                    return true;
                }
            }else{
                slack[u.b] = min(slack[u.b], delta);
            }
        }
    }

    return false;
}

int km(){
    init();
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < adj[i].size(); j++){
            ly[i] = max(ly[i], adj[i][j].w);
        }
    }

    for(int i = 1; i <= n; i++){
        fill(slack+1, slack+1+n, INF);

        while(1){
            memset(visitx, 0, sizeof(visitx));
            memset(visity, 0, sizeof(visity));

            if(match(i)) break;

            int d = INF;
            for(int j = 1; j <= n; j++){
                if(!visitx[j]) d = min(d, slack[j]);
            }

            for(int j = 1; j <= n; j++){
                if(visity[j]) ly[j] -= d;
                if(visitx[j]){
                    lx[j] += d;
                }else{
                    slack[j] -= d;
                }
            }
        }
    }

    int res = 0;
    for(int i = 1; i <= n; i++){
        res += adj[p[i]][i].w;
    }
    return res;
}

signed main(){
    int nn, m;
    cin >> nn >> m;
    n = nn*2;
    for(int i = 1; i <= m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        Element temp;
        temp.b = b;
        temp.w = w;
        adj[a].pb(temp);
        temp.b = a;
        adj[b].pb(temp);
    }
    cout << km() << endl;
}
