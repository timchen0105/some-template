#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define pii pair<int, int>
#define StarburstStream ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int MAXN = 1e4+5;
int n, weight, dp[MAXN], v[MAXN], w[MAXN], number[MAXN];

signed main(){
    StarburstStream
    cin >> n >> weight;
    for(int i = 1; i <= n; i++){
        cin >> v[i] >> w[i] >> number[i];
    }
    for(int i = 1; i <= n; i++){
        int num = min(number[i], weight / w[i]);

        for(int k = 1; num > 0; k *= 2){
            if(k > num) k = num;
            num -= k;
            for(int j = weight; j >= w[i] * k; j--){
                dp[j] = max(dp[j], dp[j -  w[i] * k] + v[i] * k);
            }
        }

    }
    cout << dp[weight] << endl;
}
