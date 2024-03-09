#include<bits/stdc++.h>
#define AC ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int MAXN = 2e5+50;
int arr[MAXN], dp[MAXN];

int main(){
    AC
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
		dp[i] = 1;
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j < i; j++){
			if(arr[j] < arr[i]) dp[i] = max(dp[j] + 1, dp[i]);
		}
	}

	int ans = 0;
	for(int i = 1; i <= n; i++){
		ans = max(ans, dp[i]);
	}

	cout << ans << endl;
}
