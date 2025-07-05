// https://atcoder.jp/contests/abc413/tasks/abc413_c
// 2025年07月05日 21時02分48秒
#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
// using vmint = vector<mint>;
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

    int Q;
    cin >> Q;

    // cnt, num
    deque<pair<ll, ll>> deq;
    rep(i, Q) {
        int t;
        cin >> t;
        if (t == 1) {
            ll c, x;
            cin >> c >> x;
            deq.push_back({c, x});
        } else {
            ll sum = 0;
            ll k;
            cin >> k;
            while (k) {
                auto [c, x] = deq.front();
                deq.pop_front();
                if (k >= c) {
                    sum += c * x;
                    k -= c;
                } else {  // k < c
                    sum += k * x;
                    c -= k;
                    k = 0;
                    deq.push_front({c, x});
                }
            }
            cout << sum << endl;
        }
    }
}
