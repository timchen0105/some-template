#include<bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int exgcd(int a, int b, int &x, int &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    int d = exgcd(b, a%b, y, x);
    y -= (a/b) * x;
    return d;
}

signed main(){
    int a, b, c, x, y;
    cin >> a >> b >> c;
    int gcd = exgcd(a, b, x, y);
    if(c % gcd){
        cout << -1 << "\n";
    }else{
        cout << x * c / gcd << " " << y * c / gcd << "\n";
    }
}
