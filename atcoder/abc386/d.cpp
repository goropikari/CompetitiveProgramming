/*https://atcoder.jp/contests/abc386/tasks/abc386_d*/
/*2024年12月28日 21時51分22秒*/
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

void sort_map(map<ll, vll>& mp) {
    for (auto it = mp.begin(); it != mp.end(); it++) {
        sort(all(it->second));
    }
}

struct Point {
    ll x, y;
    char c;
};

bool operator<(const Point& a, const Point& b) {
    if (a.x != b.x)
        return a.x < b.x;
    return a.y < b.y;
}

void solve() {
    ll N, M;
    cin >> N >> M;

    vector<Point> pt;
    rep(i, M) {
        ll x, y;
        char c;
        cin >> x >> y >> c;
        pt.push_back({x, y, c});
    }
    sort(all(pt));

    ll miny = INF;
    bool ok = true;
    for (auto [x, y, c] : pt) {
        if (c == 'W') {
            chmin(miny, y);
        } else {
            if (y >= miny) {
                ok = false;
                break;
            };
        }
    }
    yesno(ok);
}
