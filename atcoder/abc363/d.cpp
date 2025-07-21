// https://atcoder.jp/contests/abc363/tasks/abc363_d
// 2025年07月21日 13時56分41秒
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

ll intpow(ll x, ll n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1)
            ret *= x;
        x *= x;
        n >>= 1;
    }
    return ret;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;

    if (N == 1) {
        cout << 0 << endl;
        return;
    }

    N -= 2;

    // 2k-1, 2k 桁の回文数の種類数 9 * 10^(k-1)
    int m = 38;
    vll nkind(m);
    rep2(k, 1, m / 2) {
        nkind[2 * k - 1] = 9ll * intpow(10, k - 1);
        nkind[2 * k] = 9ll * intpow(10, k - 1);
    }

    vll offset(m);
    rep2(k, 1, m / 2) {
        offset[2 * k - 1] = intpow(10, k - 1);
        offset[2 * k] = intpow(10, k - 1);
    }

    int d = 0;
    rep2(k, 1, m) {
        if (N - nkind[k] < 0) {
            d = k;
            break;
        }
        N -= nkind[k];
    }

    ll pre = offset[d] + N;
    string s = to_string(pre);
    string rev = s;
    if (d % 2 == 1) rev.pop_back();
    reverse(all(rev));
    s += rev;
    cout << s << endl;
}
