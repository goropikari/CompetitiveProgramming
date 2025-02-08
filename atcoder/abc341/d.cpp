/*https://atcoder.jp/contests/abc341/tasks/abc341_d*/
/*2025年02月07日 00時01分55秒*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
using namespace std;
using ll = long long;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

// const ll INF = (ll)2e18+9;
const int INF = (int)2e9 + 7;

template <typename T>
void chmin(T& a, T b) {
    a = min(a, b);
}
template <typename T>
void chmax(T& a, T b) {
    a = max(a, b);
}

template <typename T>
void print(vector<T> v) {
    int n = v.size();
    rep(i, n) {
        if (i == 0)
            cout << v[i];
        else
            cout << ' ' << v[i];
    }
    cout << endl;
}

void yesno(bool x) {
    puts(x ? "Yes" : "No");
}

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ll N, M, K;
    cin >> N >> M >> K;
    if (N > M)
        swap(N, M);

    ll l = lcm(N, M);

    auto f = [&](ll x) { return x / N + x / M - (x / l) * 2 >= K; };

    ll wa = 0, ac = 1e18;
    while (ac - wa > 1) {
        ll wj = (ac + wa) / 2;
        if (f(wj))
            ac = wj;
        else
            wa = wj;
    }
    cout << ac << endl;
}
