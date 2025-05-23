// https://atcoder.jp/contests/abc338/tasks/abc338_e
// 2025年05月24日 00時32分16秒
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
using int128 = int128_t;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
#define repinc(i, n, inc) for (long long int i = (k); i < (n); i += (inc))
#define OUTSIDE(i, j, h, w) (((i) < 0) || ((i) >= (h)) || ((j) < 0) || ((j) >= (w)))
using namespace std;
using ll = long long;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

// const ll INF = (ll)2e18+9;
// const int INF = (int)2e9 + 7;

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

    int N;
    cin >> N;

    vector<pair<int, int>> ps;
    rep(i, N) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (a > b)
            swap(a, b);
        ps.emplace_back(a, b);
    }

    sort(all(ps), [](auto a, auto b) -> bool {
        return a.second < b.second;
    });

    auto op = [](ll a, ll b) -> ll { return a + b; };
    auto e = []() -> ll { return 0ll; };

    segtree<ll, op, e> seg(N * 2);
    rep(i, N) {
        seg.set(ps[i].first, 1);
    }

    bool ans = false;
    for (auto [a, b] : ps) {
        int sum = seg.prod(a + 1, b);
        if (sum > 0)
            ans = true;
        seg.set(a, -1);
        seg.set(b, 1);
    }
    yesno(ans);
}
