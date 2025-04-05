// https://atcoder.jp/contests/abc400/tasks/abc400_e
// 2025年04月05日 22時11分16秒
#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
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
    cout << (x ? "Yes" : "No") << '\n';
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

    ll mx = (int)1e6 + 5;
    // numprime[i]: 数字 i の素因数の数
    vll numprime(mx, 0);
    rep2(i, 2, mx) {
        if (numprime[i] == 0) {
            for (ll j = i; j < mx; j += i) {
                numprime[j]++;
            }
        }
    }

    vll n400;
    rep(i, mx) {
        if (numprime[i] == 2) {
            n400.push_back(i * i);
        }
    }

    auto cal = [&](ll x) -> void {
        ll ans = *prev(upper_bound(all(n400), x));
        cout << ans << endl;
    };

    int n;
    cin >> n;
    rep(i, n) {
        ll x;
        cin >> x;
        cal(x);
    }
}
