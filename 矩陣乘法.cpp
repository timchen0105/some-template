#include<bits/stdc++.h>
using namespace std;

const int MAXM = 100, MAXN = 100, MAXP = 100;
int m, n, p;
int a[MAXM][MAXN], b[MAXN][MAXP], multi[MAXM][MAXP];

signed main(){
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= p; j++){
			multi[i][j] = 0;
		}
	}

	cin >> m >> n;
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}

	cin >> n >> p;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= p; j++){
			cin >> b[i][j];
		}
	}

	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= p; j++){
			for(int k = 1; k <= n; k++){
				multi[i][j] += a[i][k] * b[k][j];
			}
		}
	}

	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= p; j++){
			cout << multi[i][j] << " ";
		}
		cout << endl;
	}
}
