#include<bits/stdc++.h>
using namespace std;

int power(int a, int b){
	if(b == 0) return 1;
	if(b % 2 == 1) return a * power(a, b-1);
	int temp = power(a, b/2);
	return temp * temp;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(true){
		int a, b;
		cin >> a >> b;
		//cout << power(a, b) << endl;

		int res = 1, base = a;
		while(b != 0){
            if(b % 2 == 1) res *= base;
            base *= base;
            b /= 2;
		}
		cout << res << endl;
	}
}
