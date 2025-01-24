/*https://atcoder.jp/contests/abc305/tasks/abc305_d*/
/*2025年01月23日 02時10分29秒*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#include <algorithm>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
using namespace std;
using ll = long long;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

// const ll INF = (ll)2e18+9;
const int INF = (int)2e9 + 7;

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

void solve() {
    int N;
    cin >> N;
    vll A(N);
    rep(i, N) cin >> A[i];

    int q;
    cin >> q;
    vll L(q), R(q);
    rep(i, q) cin >> L[i] >> R[i];

    vector<pair<ll, ll>> v;
    rep(i, q) v.push_back({L[i], R[i]});

    int hn = (N + 1) / 2;
    vll down, up, t;
    rep2(i, 1, hn) {
        down.push_back(A[2 * i - 1]);
        up.push_back(A[2 * i]);
        t.push_back(up.back() - down.back());
    }
    down.push_back(INF);
    up.push_back(INF);

    // print(down);
    // print(up);
    // print(t);

    vll cumsum(hn + 1, 0);
    rep2(i, 1, hn + 1) {
        cumsum[i] = up[i - 1] - down[i - 1];
        cumsum[i] += cumsum[i - 1];
    }
    // print(cumsum);

    for (auto [l, r] : v) {
        auto ri = lower_bound(all(up), r) - up.begin();
        auto li = lower_bound(all(up), l) - up.begin();

        ll ans = cumsum[ri + 1] - cumsum[li];
        ans -= t[ri];
        if (down[ri] <= r) {
            ans += r - down[ri];
        }
        if (down[li] <= l) {
            ans -= t[li];
            ans += up[li] - l;
        }
        cout << ans << endl;
    }
}
