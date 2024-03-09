#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define pii pair<int, int>
#define StarburstStream ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int MAXN = 1e4+5;
int n, weight, dp[MAXN], v[MAXN], w[MAXN];

signed main(){
    StarburstStream
    cin >> n >> weight;
    for(int i = 1; i <= n; i++){
        cin >> v[i] >> w[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = w[i]; j <= weight; j++){
            dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
        }
    }
    cout << dp[weight] << endl;
}
