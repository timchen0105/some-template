#include<bits/stdc++.h>
#define int long long
#define lowbit(x) (x&(-x))
using namespace std;

const int MAXN = 1000+50;
int arr[MAXN][MAXN], tree[MAXN][MAXN];
int n;

void update(int x, int y, int v){
    for(int i = x; i <= n; i += lowbit(i)){
        for(int j = y; j <= n; j += lowbit(j)){
            tree[i][j] += v;
        }
    }
}

int sum(int x, int y){
    int res = 0;
    for(int i = x; i > 0; i -= lowbit(i)){
        for(int j = y; j > 0; j -= lowbit(j)){
            res += tree[i][j];
        }
    }
    return res;
}

signed main(){
    memset(tree, 0, sizeof(tree));
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> arr[i][j];
            update(i, j, arr[i][j]);
        }
    }

    while(1){
        int w;
        cin >> w;
        if(w == 1){
            int x, y, v;
            cin >> x >> y >> v;
            update(x, y, v);
        }else if(w == 2){
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << sum(x2, y2) - sum(x1-1, y2) - sum(x2, y1-1) + sum(x1-1, y1-1) << endl;
        }
    }
}
