// https://atcoder.jp/contests/tdpc/tasks/tdpc_dice
// 2025年07月23日 00時04分58秒
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

    ll N, D;
    cin >> N >> D;

    if (D == 1) {
        cout << 1 << endl;
        return;
    }

    {
        ll g = gcd(D, 30);
        if (g == 1) {
            cout << 0 << endl;
            return;
        }
    }

    ll nfive = 0;
    while (D % 5 == 0) {
        nfive++;
        D /= 5;
    }

    rep(n4, 31) {
        rep(n6, 28) {
            ll t = D;
            vll num(7);
            num[5] = nfive;
            rep(i, n4) t /= 4;
            rep(i, n6) t /= 6;
            if (t == 0) continue;

            while (t % 2 == 0) {
                t /= 2;
                num[2]++;
            }
            while (t % 3 == 0) {
                t /= 3;
                num[3]++;
            }

            ll sum = accumulate(all(num), 0ll);
        }
    }
}
