#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

int mod = 1e9+7;
const int MAXN = 1e4+50;
int J[MAXN], invJ[MAXN];

int fp(int a, int b, int p){
    int res = 1;
    while(b){
        if(b&1) res = (res*a) % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

void build(int n){
    J[0] = J[1] = invJ[0] = invJ[1] = 1;
    for(int i = 2; i <= n; i++) J[i] = J[i-1] * i % mod;
    invJ[n] = fp(J[n], mod - 2, mod);
    for(int i = n-1; i >= 2; i--) invJ[i] = invJ[i+1] * (i+1) % mod;
}

int C(int n, int m){
    if(n == m || m == 0) return 1;
    int res = J[n] * invJ[n-m] % mod * invJ[m] % mod;
    return res;
}

signed main(){
    int n, m;
    cin >> n >> m;
    build(n);
    cout << C(n, m) << endl;
}
