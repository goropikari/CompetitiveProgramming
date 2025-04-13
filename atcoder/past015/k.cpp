// https://atcoder.jp/contests/past15-open/tasks/past202306_k
// 2025年04月13日 23時48分26秒
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
    cout << (x ? "Yes" : "No") << '\n';
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
    vll P(N);
    rep(i, N) {
        cin >> P[i];
    }

    fenwick_tree<ll> cnts(N + 1), fw(N + 1);
    vint ids(N + 1);
    rep(i, N) {
        cnts.add(i + 1, 1);
        fw.add(i + 1, P[i]);
        ids[P[i]] = i + 1;
    }

    ll ans = 0;
    for (ll i = N; i >= 1; i--) {
        ll cnt = cnts.sum(ids[i] + 1, N + 1);
        cnts.add(ids[i], -1);
        fw.add(ids[i], -i);
        if (cnt == 0)
            continue;
        ans += cnt * i;
        ans += fw.sum(ids[i] + 1, N + 1);
    }
    cout << ans << endl;
}
