// https://atcoder.jp/contests/abc294/tasks/abc294_e
// 2025年06月05日 20時10分01秒
#include <bits/stdc++.h>
#include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
// modint::set_mod(10);
// using mint = modint;
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

void Yes() {
    yesno(true);
}

void No() {
    yesno(false);
}

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll L, N1, N2;
    cin >> L >> N1 >> N2;
    deque<pair<ll, ll>> i1, i2;
    rep(i, N1) {
        ll v, l;
        cin >> v >> l;
        i1.emplace_back(v, l);
    }
    rep(i, N2) {
        ll v, l;
        cin >> v >> l;
        i2.emplace_back(v, l);
    }

    ll ans = 0;
    ll now = 1;
    ll cnt1 = 0, cnt2 = 0;
    while (i1.size() && i2.size()) {
        auto [v1, l1] = i1.front();
        auto [v2, l2] = i2.front();

        if (v1 == v2) {
            ans += min(cnt1 + l1, cnt2 + l2) - now + 1;
        }

        now = min(cnt1 + l1, cnt2 + l2) + 1;
        if (cnt1 + l1 < cnt2 + l2) {
            cnt1 += l1;
            i1.pop_front();
        } else if (cnt1 + l1 > cnt2 + l2) {
            cnt2 += l2;
            i2.pop_front();
        } else {
            cnt1 += l1, cnt2 += l2;
            i1.pop_front();
            i2.pop_front();
        }
    }
    cout << ans << endl;
}
