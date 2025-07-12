// https://atcoder.jp/contests/arc165/tasks/arc165_a
// 2025年07月11日 20時56分04秒
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

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int mx = 1e5;
    vll sieve(mx, 1);
    sieve[0] = sieve[1] = 0;
    rep2(i, 2, mx) {
        for (ll j = i + i; j < mx; j += i) {
            sieve[j] = 0;
        }
    }

    auto factor = [&](ll n) -> vector<pair<ll, ll>> {
        vector<pair<ll, ll>> ret;
        rep2(i, 2, mx) {
            if (n % i != 0) continue;
            ll cnt = 0;
            while (n % i == 0) {
                cnt++;
                n /= i;
            }
            ret.push_back({i, cnt});
        }

        if (n != 1) {
            ret.push_back({n, 1});
        }
        return ret;
    };

    auto cal = [&]() -> void {
        ll N;
        cin >> N;

        auto ret = factor(N);
        yesno(ret.size() != 1);
    };

    int t;
    cin >> t;
    rep(i, t) cal();
}
