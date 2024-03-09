#include<bits/stdc++.h>
#define StarburstStream ios_base::sync_with_stdio(0); cin.tie(0);
#define int long long
#define pb push_back
#define pii pair<int, int>
using namespace std;

int mod = 1e9+7;

int pow(int a, int n){
    if(n == 0) return 1;
    int res = pow(a, n/2);
    res *= res;
    res %= mod;
    if(n & 1){
        res *= a;
        res %= mod;
    }
    return res;
}

int get_inv(int a){
    return pow(a, mod-2);
}

signed main(){
    StarburstStream
    int num;
    while(cin >> num){
        cout << get_inv(num) << endl;
    }
}
