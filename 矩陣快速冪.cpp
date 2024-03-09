#include<bits/stdc++.h>
using namespace std;

struct mas{
	int data[2][2];
	mas(int a = 0, int b = 0, int c = 0, int d = 0){
		data[0][0] = a, data[0][1] = b, data[1][0] = c, data[1][1] = d;
	}
};

mas multi(mas a, mas b){
	mas temp;
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			for(int k = 0; k < 2; k++){
				temp.data[i][j] += a.data[i][k] * b.data[k][j];
			}
		}
	}
	return temp;
}

mas power(mas a, int n){
	if(n == 1) return a;
	mas temp = power(a, n/2);
	temp = multi(temp, temp);
	if(n&1) return multi(temp, a);
	return temp;
}

signed main(){
	mas base(1, 1, 1, 0);
	int n;
	cin >> n;
	mas ans = power(base, n);
	cout << ans.data[1][0] << endl;
}
