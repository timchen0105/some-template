#include<bits/stdc++.h>
#define StarburstStream ios_base::sync_with_stdio(0); cin.tie(0);
#define int long long
#define pb push_back
#define pii pair<int, int>
using namespace std;

int mod = 1e9+7;

int exgcd(int a, int b, int &x, int &y){
    if(b == 0){
        x = 1, y = 0;
        return a;
    }else{
        int d = exgcd(b, a%b, y, x);
        y -= (a/b)*x;
        return d;
    }

}

signed main(){
    StarburstStream
    int a, b, x, y;
    while(cin >> a >> b){
        if(__gcd(a, b) != 1){
            cout << "no" << endl;
            continue;
        }
        exgcd(a, b, x, y);
        cout << x << endl;
    }
}
