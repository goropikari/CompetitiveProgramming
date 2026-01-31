// http://localhost:5173/problem/count_points_in_triangle
// Sat 31 Jan 2026 06:38:16 AM JST
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
    ll x, y;

    Point operator-(const Point& other) {
        return Point{x - other.x, y - other.y};
    }

    ll cross(const Point& other) {
        return x * other.y - other.x * y;
    }

    ll pos(const Point& other) {
        ll v = cross(other);
        if (v > 0) v = 1;
        if (v < 0) v = -1;
        return v;
    }
};

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;
    vector<Point> A(N);
    rep(i, N) {
        ll x, y;
        cin >> x >> y;
        A[i] = {x, y};
    }

    ll M;
    cin >> M;
    vector<Point> B(M);
    rep(i, M) {
        ll x, y;
        cin >> x >> y;
        B[i] = {x, y};
    }

    int Q;
    cin >> Q;
    while (Q--) {
        ll a, b, c;
        cin >> a >> b >> c;
        Point ab = A[b] - A[a];
        Point bc = A[c] - A[b];
        Point ca = A[a] - A[c];

        if (ab.cross(ca) == 0) {
            cout << 0 << endl;
            continue;
        }

        ll ans = 0;
        rep(t, M) {
            Point at = B[t] - A[a];
            Point bt = B[t] - A[b];
            Point ct = B[t] - A[c];

            ll sum = 0;
            sum += ab.pos(at);
            sum += bc.pos(bt);
            sum += ca.pos(ct);
            if (abs(sum) == 3) ans++;
        }
        cout << ans << '\n';
    }
}
