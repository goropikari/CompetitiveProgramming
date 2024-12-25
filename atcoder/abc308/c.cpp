/*https://atcoder.jp/contests/abc308/tasks/abc308_c*/
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
    int id;
    ll head, tail;
};

bool operator<(const Point& a, const Point& b) {
    // a.head/(a.head+a.tail) = b.head/(b.head+b.tail)
    // a.head * (b.head+b.tail) = b.head * (a.head+a.tail)
    if (a.head * (b.head + b.tail) == b.head * (a.head + a.tail)) {
        return a.id > b.id;
    }

    return a.head * (b.head + b.tail) < b.head * (a.head + a.tail);
}

void solve() {
    int N;
    cin >> N;
    vector<Point> p(N);
    rep(i, N) {
        ll a, b;
        cin >> a >> b;
        p[i] = {i + 1, a, b};
    }
    sort(rall(p));
    vll ans;
    for (auto [id, a, b] : p)
        ans.push_back(id);
    print(ans);
}
