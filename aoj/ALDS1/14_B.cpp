/*https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B*/
/*2025年03月23日 18時35分28秒*/
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

ll modpow(ll x, ll n, ll mod) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1)
            ret = (ret * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return ret;
}

struct RollingHash {
    vll data;
    const ll p = 1000000009;
    const ll mod = 1000000021;

    RollingHash(vll& v) {
        int n = v.size();
        data.resize(n + 1);
        rep(i, n) {
            data[i + 1] = (data[i] * p % mod) + v[i];
            data[i + 1] %= mod;
        }
    };

    // [l,r) の範囲の hash 値
    ll sub(ll l, ll r) {
        ll m = r - l;
        ll x = data[r] - data[l] * modpow(p, m, mod) % mod;
        x += mod;
        x %= mod;
        return x;
    }
};

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string t, p;
    cin >> t >> p;

    vll vt, vp;
    int n = t.size();
    rep(i, n) {
        vt.push_back(t[i]);
    }
    int m = p.size();
    rep(i, m) {
        vp.push_back(p[i]);
    }

    RollingHash ht(vt), hp(vp);
    rep(i, n - m + 1) {
        if (ht.sub(i, i + m) == hp.sub(0, m)) {
            cout << i << '\n';
        }
    }
}
