#include<bits/stdc++.h>
#define lc index << 1
#define rc index << 1 | 1
using namespace std;

const int MAXN = 3e5;
int arr[MAXN];
int tree[MAXN*4];
int tag[MAXN*4];

int n;

void update(int index){
    tree[index] = tree[lc] + tree[rc];
}

void build(int L = 1, int R = n, int index = 1){
    if(L == R){
        tree[index] = arr[L];
        return;
    }
    int M = (L+R) >> 1;
    build(L, M, lc);
    build(M+1, R, rc);
    update(index);
}

void down(int l, int r, int index){
	if(tag[index] != 0){
		int m = (l+r) >> 1;
		tag[lc] = tag[index];
		tag[rc] = tag[index];
		tree[lc] = tag[index] * (m - l + 1);
		tree[rc] = tag[index] * (r - m);
		tag[index] = 0;
	}
}

void segment_modify(int l, int r, int val, int L = 1, int R = n, int index = 1){
	if(l == L && r == R){
		tree[index] = val * (r - l + 1);
		tag[index] = val;
		return;
	}
	down(L, R, index);
	int M = (L+R) >> 1;
	if(r <= M){
        segment_modify(l, r, val, L, M, lc);
    }else if(l > M){
        segment_modify(l, r, val, M+1, R, rc);
    }else{
        segment_modify(l, M, val, L, M, lc);
        segment_modify(M+1, r, val, M+1, R, rc);
    }
    update(index);
}

int query(int l, int r, int L = 1, int R = n, int index = 1){
    if(l == L && r == R){
        return tree[index];
    }
    down(L, R, index);
    int M = (L+R) >> 1;
    if(r <= M){
        return query(l, r, L, M, lc);
    }else if(l > M){
        return query(l, r, M+1, R, rc);
    }else{
        return query(l, M, L, M, lc) + query(M+1, r, M+1, R, rc);
    }
}

int main(){
	memset(tag, 0, sizeof(tag));
	cout << "輸入個數" << endl;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}

	build();

	while(1){
		cout << "輸入指令" << endl;
		cout << "0：跳出迴圈" << endl;
		cout << "1：區間改值" << endl;
		cout << "2：詢問區間和" << endl;
		cout << "3：單點詢問" << endl;
		int a;
		cin >> a;
		if(a == 0){
			break;
		}else if(a == 1){
			int l, r, val;
			cin >> l >> r >> val;
			segment_modify(l, r, val);
		}else if(a == 2){
			int l, r;
			cin >> l >> r;
			cout << query(l, r) << endl;
		}else if(a == 3){
			int index;
			cin >> index;
			cout << tree[index] << endl;
		}else{
			cout << "無效" << endl;
		}
	}
}
