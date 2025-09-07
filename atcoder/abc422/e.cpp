// https://atcoder.jp/contests/abc422/tasks/abc422_e
// 2025年09月07日 23時34分27秒
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

// ceil(a/b)
ll ceil(ll a, ll b) {
    return (a + b - 1) / b;
}

// floor(a/b)
ll floor(ll a, ll b) {
    return a / b;
}

void solve();

int main() {
    solve();
    return 0;
}

struct Point {
    ll x, y;
};

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;
    vector<Point> pts;
    rep(i, N) {
        ll x, y;
        cin >> x >> y;
        pts.push_back({x, y});
    }

    auto f = [](Point p, Point q) -> tuple<ll, ll, ll> {
        ll a = q.y - p.y;
        ll b = p.x - q.x;
        ll c = -p.x * q.y + q.x * p.y;

        return {a, b, c};
    };

    mt19937_64 rng(12345);
    ll m = 100;
    rep(_, m) {
        uint64_t p, q;
        do {
            p = rng() % N;
            q = rng() % N;
        } while (p == q);
        auto [a, b, c] = f(pts[p], pts[q]);

        ll cnt = 0;
        rep(i, N) {
            auto [x, y] = pts[i];
            if (a * x + b * y + c == 0) cnt++;
        }
        if (cnt * 2 > N) {
            Yes();
            cout << a << ' ' << b << ' ' << c << endl;
            return;
        }
    }

    No();
}
