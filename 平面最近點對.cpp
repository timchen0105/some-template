#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define pii pair<int, int>
#define StarburstStream ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int MAXN = 2e5+5;
int n, ans = 1e20;
pii dot[MAXN];

bool cmp(pii a, pii b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first < b.first;
}

struct cmp_s{
    bool operator()(const pii &a, const pii &b) const {
        return a.second < b.second;
    }
};

inline void upd_ans(pii a, pii b){
    int res = (a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second);
    ans = min(ans, res);
}

multiset<pii, cmp_s> s;

signed main(){
    StarburstStream
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> dot[i].first >> dot[i].second;
    }
    sort(dot+1, dot+1+n, cmp);
    int l = 1;
    for(int i = 1; i <= n; i++){
        while(l < i && dot[i].first - dot[l].first >= ans){
            s.erase(s.find(dot[l]));
            l++;
        }
        for(auto it = s.lower_bound({dot[i].first, dot[i].second - ans}); it != s.end() && it->second - dot[i].second < ans; it++){
            upd_ans(*it, dot[i]);
        }
        s.insert(dot[i]);
    }
    cout << ans << endl;
}
