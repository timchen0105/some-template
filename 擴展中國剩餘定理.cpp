#include<bits/stdc++.h>
#define StarburstStream ios_base::sync_with_stdio(0); cin.tie(0);
#define int long long
#define pb push_back
#define pii pair<int, int>
using namespace std;

const int MAXN = 1e5+5;
int n, mod[MAXN], remain[MAXN];

int mul(int a, int b, int mod){
    int ans = 0;
    while(b){
        if(b&1){
            ans += a;
            ans %= mod;
        }
        a += a;
        a %= mod;
        b >>= 1;
    }
    return ans;
}

int exgcd(int a, int b, int &x, int &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }else{
        int d = exgcd(b, a%b, y, x);
        y -= a/b * x;
        return d;
    }
}

int excrt(){
    int ans = remain[1], M = mod[1], t, y;
    for(int i = 2; i <= n; i++){
        int mi = mod[i], res = ((remain[i] - ans)%mi + mi)%mi;
        int gcd = exgcd(M, mi, t, y);
        if(res % gcd != 0){
            return -1;
        }
        t = mul(t, res / gcd, mi);
        ans += t * M;
        M = mi / gcd * M;
        ans = (ans%M + M)%M;
    }
    return ans;
}

signed main(){
    StarburstStream
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> mod[i] >> remain[i];
    }
    cout << excrt() << "\n";
}
