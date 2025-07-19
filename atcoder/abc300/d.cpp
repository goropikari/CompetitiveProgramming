// https://atcoder.jp/contests/abc300/tasks/abc300_d
// 2025年07月16日 21時01分49秒
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

    int m = (int)1e6 + 5;
    vint isp(m, 1);
    isp[0] = isp[1] = 0;
    rep2(i, 2, m) {
        for (ll j = i + i; j < m; j += i) {
            isp[j] = 0;
        }
    }

    vll primes;
    rep(i, m) if (isp[i]) primes.push_back(i);

    using ull = unsigned long long int;

    auto kth_root = [](ull x, int k) -> ull {
        assert(k != 0);
        if (x == 1 || k == 1) return x;
        ull l = 0, r = x;
        while (r - l > 1) {
            ull m = (r - l) / 2 + l;
            ull t = x;
            rep(i, k) t /= m;
            if (1 > t) {
                r = m;
            } else {
                l = m;
            }
        }
        return l;
    };

    // 平方根
    auto isqrt = [&](ull x) -> ull {
        return kth_root(x, 2);
    };

    ll N;
    cin >> N;

    ll ans = 0;

    rep(i, m) {
        ll a = primes[i];
        if (a * a * a * a * a > N) break;
        rep2(j, i + 1, m) {
            ll b = primes[j];
            if (b * b * b > N / a / a) break;
            ll csq_upper = N / (a * a * b);
            ll c = isqrt(csq_upper);
            if (b < c) {
                auto lit = lower_bound(all(primes), b);
                auto rit = prev(upper_bound(all(primes), c));
                ans += rit - lit;
            }
        }
    }

    cout << ans << endl;
}
