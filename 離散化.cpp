#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;
int arr[MAXN];
int temp[MAXN];

signed main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        temp[i] = arr[i];
    }
    sort(temp+1, temp+1+n);
    int len = unique(temp+1, temp+1+n)-temp-1;
    for(int i = 1; i <= n; i++){
        arr[i] = lower_bound(temp+1, temp+1+len, arr[i])-temp;
    }
    for(int i = 1; i <= n; i++){
        cout << arr[i] << " ";
    }
}
