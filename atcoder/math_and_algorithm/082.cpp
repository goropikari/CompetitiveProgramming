// https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_bn
/*2025年01月16日 01時11分35秒*/
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

struct Time {
    ll l, r;

    bool operator<(const Time& other) {
        if (this->r != other.r)
            return this->r < other.r;
        return this->l < other.l;
    }
};

void solve() {
    ll N;
    cin >> N;

    vector<Time> ts;
    rep(i, N) {
        int l, r;
        cin >> l >> r;
        ts.push_back({l, r});
    }

    sort(all(ts));
    ll ans = 0;
    ll now = -1;
    for (auto [l, r] : ts) {
        if (now > l)
            continue;
        ans++;
        now = r;
    }
    cout << ans << endl;
}
