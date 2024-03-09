#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, k;
	cin >> n >> k;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	while(k--){
		int a;
		bool found = false;
		cin >> a;
		int l = 0, r = n-1, m = (l+r)/2;
		while(l <= r){
		if(arr[m] > a){
			r = m-1;
			m = (l+r)/2;
		}else if(arr[m] < a){
			l = m+1;
			m = (l+r)/2;
		}else{
			cout << m+1 << endl;
			found = true;
			break;
		}
		}
		if(found == false){
			cout << 0 << endl;
		}	
	}
} 
