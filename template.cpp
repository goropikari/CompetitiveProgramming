// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep2(i,k,n) for (int i = (k); i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
// using P = pair<ll,ll>;


const ll INF = (ll)1e18;
// const int INF = (int)1e9+7;
template<typename T>
void chmin(T &a, T b) { a = min(a, b); }
template<typename T>
void chmax(T &a, T b) { a = max(a, b); }

template<typename T>
void print(vector<T> v) {
    int n = v.size();
    rep(i,n) {
        if (i == 0) cout << v[i];
        else cout << ' ' << v[i];
    }
    cout << endl;
}

void solve() {
}

int main() {
    solve();
    return 0;
}