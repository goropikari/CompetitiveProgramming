/*https://atcoder.jp/contests/abc279/tasks/abc279_d*/
/*2025年01月21日 08時03分44秒*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
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

double A, B;

double f(ll t) {
    return A / sqrt(1.0 + t) + B * t;
}

void solve() {
    cin >> A >> B;

    ll l = 0, r = A / B + 1;
    while (r - l > 2) {
        ll m1 = (l * 2 + r) / 3;
        ll m2 = (l + r * 2) / 3;
        if (f(m1) > f(m2))
            l = m1;
        else
            r = m2;
    }

    double ans = A;
    for (ll i = l; i <= r; i++)
        chmin(ans, f(i));
    printf("%.9lf\n", ans);
}
