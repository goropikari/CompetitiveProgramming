/*https://atcoder.jp/contests/abc347/tasks/abc347_d*/
/*2025年01月31日 02時45分35秒*/
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

void solve() {
    ll a, b, C;
    cin >> a >> b >> C;

    // int rev = 0;
    // if (a > b) {
    //     swap(a, b);
    //     rev = 1;
    // }

    ll c = __builtin_popcountll(C);
    if (c < abs(a - b) || a + b < c || (a + b) % 2 != c % 2) {
        cout << -1 << endl;
        return;
    }

    ll x = 0;
    ll overrap = (a + b - c) / 2;
    a -= overrap;
    rep(i, 60) {
        if (a && (C & (1LL << i))) {
            x ^= 1LL << i;
            a--;
        }
    }
    rep(i, 60) {
        if (overrap && !(C & (1LL << i))) {
            x ^= 1LL << i;
            overrap--;
        }
    }
    if (a || overrap) {
        cout << -1 << endl;
        return;
    }

    ll y = x ^ C;
    // if (rev) {
    //     swap(x, y);
    // }
    cout << x << ' ' << y << endl;
}
