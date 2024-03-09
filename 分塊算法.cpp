#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
//區間最小值
const int MAXN = 2e5+50;
int n, q;
int arr[MAXN], block[MAXN], tag[MAXN];
int k;

int query(int l, int r){
    int ans = 1e9;

//    if(tag[l/k]){
//        for(int i = (l/k)*k; i < (l/k + 1)*k; i++){
//            arr[i] += tag[l/k];
//        }
//        tag[l/k] = 0;
//    }
//
//    if(tag[r/k]){
//        for(int  i= (r/k)*k; i > (r/k - 1)*k; i--){
//            arr[i] += tag[r/k];
//        }
//        tag[r/k] = 0;
//    }

    for(int i = l; i <= r; i++){
        if(i/k != l/k) break;
        ans = min(ans, arr[i]);
    }

    for(int i = r; i >= l; i--){
        if(i/k != r/k) break;
        ans = min(ans, arr[i]);
    }

    for(int i = l/k + 1; i <= r/k - 1; i++){
        ans = min(ans, block[i]);
    }

    return ans;
}

void modify(int pos, int val){
    arr[pos] += val;
    block[pos/k] += val;
}

void seg_mod(int l, int r, int val){
    for(int i = l/k + 1; i <= r/k - 1; i++){
        block[i] = min(block[i], val);
        tag[i] = val;
    }
    for(int i = l; i <= r; i++){
        if(i/k != l/k) break;
        arr[i] = val;
    }
    if(l/k == r/k) return;
    for(int i = r; i >= l; i--){
        if(i/k != r/k) break;
        arr[i] = val;
    }
}

signed main(){
    memset(block, 0x3f3f3f3f, sizeof(block));
    cin >> n >> q;
    k = sqrt(n);
    for(int i = 1; i <= n; i++) cin >> arr[i];

    for(int i = 1; i <= n; i++){
        block[i/k] = min(block[i/k], arr[i]);
    }

    while(q--){
        int w;
        cin >> w;
        if(w == 1){
            int k, u;
            cin >> k >> u;
            modify(k, u - arr[k]);
        }else if(w == 2){
            int a, b;
            cin >> a >> b;
            cout << query(a, b) << endl;
        }
    }
}
