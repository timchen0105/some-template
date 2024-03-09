#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;

struct Node{
    int lc, rc, sum;
};

const int MAXN = 1e5+5;
int arr[MAXN];
Node tree[MAXN*4];
int sz = 0;
int root;

int build(){
    sz++;
    tree[sz].lc = 0, tree[sz].rc = 0, tree[sz].sum = 0;
    return sz;
}

void modify(int pos, int val, int L, int R, int index){
    if(L == R){
        tree[index].sum += val;
        return;
    }
    int M = (L+R) >> 1;

    if(pos <= M){
        if(tree[index].lc == 0){
            tree[index].lc = build();
        }

        modify(pos, val, L, M, tree[index].lc);
    }else{
        if(tree[index].rc == 0){
            tree[index].rc = build();
        }

        modify(pos, val, M+1, R, tree[index].rc);
    }
    tree[index].sum = tree[index].lc + tree[index].rc;
}

int query(int l, int r, int L, int R, int index){
    if(l == L && r == R){
        return tree[index].sum;
    }
    int M = (L+R) >> 1;

    if(r <= M){
        return query(l, r, L, M, tree[index].lc);
    }else if(l > M){
        return query(l, r, M+1, R, tree[index].rc);
    }else{
        return query(l, M, L, M, tree[index].lc) + query(M+1, r, M+1, R, tree[index].rc);
    }
}

signed main(){
    root = build();
}
