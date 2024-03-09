#include<bits/stdc++.h>
#define StarburstStream ios_base::sync_with_stdio(0); cin.tie(0);
#define int long long
#define pb push_back
#define pii pair<int, int>
using namespace std;

const int MAXN = 1e5+5;
int n, mod[MAXN], remain[MAXN];

void exgcd(int a, int b, int &x, int &y){
    if(b == 0){
        x = 1;
        y = 0;
    }else{
        exgcd(b, a%b, y, x);
        y -= (a/b) * x;
    }
}

int crt(){
    int M = 1, ans = 0;
    for(int i = 1; i <= n; i++){
        M *= mod[i];
    }

    for(int i = 1; i <= n; i++){
        int Mi = M / mod[i], inv, y;
        exgcd(Mi, mod[i], inv, y);
        ans += ((remain[i] * Mi)%M * inv)%M;
    }
    return (ans%M + M)%M;
}

signed main(){
    StarburstStream
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> mod[i] >> remain[i];
    }
    cout << crt() << "\n";
}
