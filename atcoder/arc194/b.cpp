/*https://atcoder.jp/contests/arc194/tasks/arc194_b*/
/*2025年03月27日 20時33分02秒*/
#include <bits/stdc++.h>
#include <atcoder/all>
#include <atcoder/fenwicktree.hpp>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;
    vint P(N + 1);
    rep(i, N) cin >> P[i + 1];

    vint id(N + 1);
    rep(i, N) {
        id[P[i + 1]] = i + 1;
    }

    auto cal = [](ll n) -> ll {
        return n * (n + 1) / 2;
    };

    fenwick_tree<int> fw(N + 1);

    set<int> memo;
    ll ans = 0;
    for (int j = N; j >= 1; j--) {
        int i = id[j] - fw.sum(0, id[j]);
        ans += cal(j - 1) - cal(i - 1);
        fw.add(id[j], 1);
    }
    cout << ans << endl;
}
