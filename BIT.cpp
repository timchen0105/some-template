#include<bits/stdc++.h>
#define lowbit(x) (x&(-x))
#define int long long
using namespace std;

const int MAXN = 2e5+50;
int arr[MAXN];
int tree[MAXN];
int n;

void update(int k, int v){
	for(int i = k; i <= n; i += lowbit(i)){
		tree[i] += v;
	}
}

int sum(int x){
	int he = 0;
	for(int i = x; i > 0; i -= lowbit(i)){
		he += tree[i];
	}
	return he;
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	memset(tree, 0, sizeof(tree));
	int q;
	cin >> n >> q;

	for(int i = 1; i <= n; i++){
		cin >> arr[i];
		update(i, arr[i]);
	}

	while(q--){
		int w;
        cin >> w;
        if(w == 1){
            int k, v;
            cin >> k >> v;
            update(k, v-arr[k]);
            arr[k] = v;
        }else if(w == 2){
            int l, r;
            cin >> l >> r;
            cout << sum(r) - sum(l-1) << endl;
        }
	}
}
