#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define pii pair<int, int>
using namespace std;

const int MAXN = 1e5+5;
int arr[MAXN], dif[MAXN];
int n;

signed main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    arr[0] = 0;
    for(int i = 1; i <= n; i++){
        dif[i] = arr[i] - arr[i-1];
    }
}
