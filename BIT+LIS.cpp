#include<bits/stdc++.h>
#define lowbit(x) x&-x
#define int long long
using namespace std;

const int MAXN = 1e5+5;
int arr[MAXN];
int temp[MAXN];
int lis[MAXN];
int tree[MAXN];
int n;

void update(int pos, int val){
    for(int i = pos; i <= n; i += lowbit(i)){
        tree[i] = max(tree[i], val);
    }
}

int ask(int x){
    int res = 0;
    for(int i = x; i > 0; i -= lowbit(i)){
        res = max(res, tree[i]);
    }
    return res;
}

signed main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
		cin >> arr[i];
		temp[i] = arr[i];
	}
	sort(temp+1, temp+1+n);
    for(int i = 1; i <= n; i++){
        arr[i] = lower_bound(temp+1, temp+1+n, arr[i])-temp;
    }
	for(int i = 1; i <= n; i++){
        lis[i] = ask(arr[i]-1) + 1;
        update(arr[i], lis[i]);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
        ans = max(ans, lis[i]);
	}
	cout << ans << endl;

	for(int i = 1; i <= n; i++){
        cout << lis[i] << " ";
	}
}
