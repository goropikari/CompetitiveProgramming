// http://localhost:5173/problem/sort_points_by_argument
// Sat 31 Jan 2026 05:46:42 AM JST
#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
// using vmint = vector<mint>;
// modint::set_mod(10);
// using mint = modint;
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
// using int128 = int128_t;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
using ll = long long;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

// const ll INF = (ll)2e18 + 9;
const int INF = (int)2e9 + 7;

template <typename T>
void chmin(T& a, T b) { a = min(a, b); }
template <typename T>
void chmax(T& a, T b) { a = max(a, b); }

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

void yesno(bool x) { cout << (x ? "Yes" : "No") << '\n'; }

void Yes() { yesno(true); }

void No() { yesno(false); }

// ceil(a/b)
ll ceil(ll a, ll b) { return (a + b - 1) / b; }

// floor(a/b)
ll floor(ll a, ll b) { return a / b; }

void solve();

int main() {
    solve();
    return 0;
}

struct Point {
    long long x, y;

    // 外積
    long long cross(const Point& other) const {
        return x * other.y - y * other.x;
    }

    int pos() const {
        if (y < 0) return -1;
        if (x >= 0 && y == 0) return 0;
        return 1;
    }

    bool operator<(const Point& other) const {
        int h1 = pos();
        int h2 = other.pos();
        if (h1 != h2) return h1 < h2;
        return cross(other) > 0;
    }
};

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;
    vector<Point> pts(N);
    rep(i, N) {
        ll x, y;
        cin >> x >> y;
        pts[i] = {x, y};
    }

    sort(all(pts));

    for (auto [x, y] : pts) {
        cout << x << ' ' << y << '\n';
    }
}
