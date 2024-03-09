#include<bits/stdc++.h>
#define StarburstStream ios_base::sync_with_stdio(0); cin.tie(0);
#define int long long
#define pb push_back
#define pii pair<int, int>
using namespace std;

const int MAXN = 1e5+5;
int LeastPrimeDivisor[MAXN];
vector<int> pr;

void LinearSieve(){
    for(int i = 2; i < MAXN; i++){
        if(!LeastPrimeDivisor[i]){
            pr.pb(i);
            LeastPrimeDivisor[i] = i;
        }
        for(int p: pr){
            if(i * p >= MAXN){
                break;
            }
            LeastPrimeDivisor[i*p] = p;
            if(i % p == 0) break;
        }
    }
}

signed main(){
    StarburstStream
    LinearSieve();
}
