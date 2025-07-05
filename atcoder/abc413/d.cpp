// https://atcoder.jp/contests/abc413/tasks/abc413_d
// 2025年07月05日 21時12分23秒
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

    auto cal = []() -> void {
        int N;
        cin >> N;
        vll A(N);
        rep(i, N) cin >> A[i];
        vector<pair<ll, ll>> ps;
        rep(i, N) {
            ps.push_back({abs(A[i]), A[i]});
        }
        sort(all(ps));

        if (N <= 2) {
            Yes();
            return;
        }

        {
            int m = 0, p = 0;
            set<ll> stock;

            for (auto [a, x] : ps) {
                stock.insert(a);
                if (x < 0)
                    m++;
                else
                    p++;
            }

            if (stock.size() == 1) {
                if (min(m, p) == N / 2 || max(m, p) == N) {
                    Yes();
                    return;
                }
            }
        }

        bool ok = true;
        rep2(i, 1, N - 1) {
            ll y = ps[i].second;
            ll x = ps[i - 1].second;
            ll z = ps[i + 1].second;
            if (y * y != x * z) ok = false;
        }
        yesno(ok);
    };

    int t;
    cin >> t;
    rep(i, t) cal();
}
