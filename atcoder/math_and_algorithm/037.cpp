// https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_ah
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (int i = (k); i < (n); ++i)
using namespace std;
using ll = long long;
// using P = pair<ll,ll>;
using P = pair<int, int>;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

// const ll INF = (ll)2e18+9;
const int INF = (int)2e9 + 7;
// const ll MOD = (ll)1e9+9;
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

struct Point {
    long long int x, y;

    Point operator+(const Point& other) const {
        return {x + other.x, y + other.y};
    }

    Point operator-(const Point& other) const {
        return {x - other.x, y - other.y};
    }

    Point operator*(const Point& other) const {
        return {x * other.x, y * other.y};
    }

    Point operator-() const { return {-x, -y}; }

    long long int inner(const Point& other) const {
        return x * other.x + y * other.y;
    }

    long long int cross(const Point& other) const {
        return x * other.y - y * other.x;
    }
};

void solve() {
    vector<Point> pts(4);
    rep(i, 4) {
        ll x, y;
        cin >> x >> y;
        pts[i] = {x, y};
    }

    Point a = pts[0], b = pts[1], c = pts[2], d = pts[3];
    if (a.x > b.x)
        swap(a, b);
    else if (a.x == b.x && a.y > b.y)
        swap(a, b);
    if (c.x > d.x)
        swap(c, d);
    else if (c.x == d.x && c.y > d.y)
        swap(c, d);
    Point ab = b - a;
    Point ac = c - a;
    Point ad = d - a;
    Point cd = d - c;
    Point ca = -ac;
    Point cb = b - c;

    ll abac = ab.cross(ac);
    ll abad = ab.cross(ad);
    ll cdca = cd.cross(ca);
    ll cdcb = cd.cross(cb);

    if (abac == 0 && abad == 0 && cdca == 0 && cdcb == 0) {
        // if ((clamp(c.x, a.x, b.x) == c.x && clamp(c.y, a.y, b.y) == c.y) ||
        //     (clamp(d.x, a.x, b.x) == d.x && clamp(d.y, a.y, b.y) == d.y)) {
        //     yesno(true);
        //     return;
        // }
        // if ((clamp(a.x, c.x, d.x) == a.x && clamp(a.y, c.y, d.y) == a.y) ||
        //     (clamp(b.x, c.x, d.x) == b.x && clamp(b.y, c.y, d.y) == b.y)) {
        //     yesno(true);
        //     return;
        // }
        // yesno(false);
        // return;

        if ((clamp(c.x, a.x, b.x) == c.x &&
             clamp(c.y, min(a.y, b.y), max(a.y, b.y)) == c.y) ||
            (clamp(d.x, a.x, b.x) == d.x &&
             clamp(d.y, min(a.y, b.y), max(a.y, b.y)) == d.y)) {
            yesno(true);
            return;
        }
        if ((clamp(a.x, c.x, d.x) == a.x &&
             clamp(a.y, min(c.y, d.y), max(c.y, d.y)) == a.y) ||
            (clamp(b.x, c.x, d.x) == b.x &&
             clamp(b.y, min(c.y, d.y), max(c.y, d.y)) == b.y)) {
            yesno(true);
            return;
        }
        yesno(false);
        return;

        // yesno(!(b.x < c.x || d.x < a.x || d.y < a.y || b.y < c.y));
        // return;

        // pair<ll, ll> A, B, C, D;
        // A = {a.x, a.y};
        // B = {b.x, b.y};
        // C = {c.x, c.y};
        // D = {d.x, d.y};
        // yesno(max(A, C) <= min(B, D));
        return;
    }

    // yesno((abac * abad <= 0 && cdca * cdcb <= 0));
    int ok1 = 0, ok2 = 0;
    ok1 = ok1 || (abac <= 0 && abad >= 0);
    ok1 = ok1 || (abac >= 0 && abad <= 0);
    ok2 = ok2 || (cdca <= 0 && cdcb >= 0);
    ok2 = ok2 || (cdca >= 0 && cdcb <= 0);
    yesno(ok1 && ok2);
}
