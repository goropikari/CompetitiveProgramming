// https://atcoder.jp/contests/arc164/tasks/arc164_a
// 2025年07月12日 09時46分02秒
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

    vll tp;
    {
        ll t = 1;
        while (t <= (ll)1e18) {
            tp.push_back(t);
            t *= 3;
        }

        reverse(all(tp));
    }

    auto cal = [&]() -> void {
        ll N, K;
        cin >> N >> K;

        int M = tp.size();
        ll T = N;
        vll cnt(M);
        rep(i, M) {
            ll q = T / tp[i];
            cnt[i] = q;
            T -= q * tp[i];
        }

        ll sum = accumulate(all(cnt), 0ll);
        rep(i, M - 1) {
            if (cnt[i] == 0) continue;
            if (sum <= K) {
                ll x = min(cnt[i], (K - sum) / 2);
                cnt[i] -= x;
                cnt[i + 1] += x * 3;
                sum += x * 2;
            }
        }

        yesno(sum == K);
    };

    int t;
    cin >> t;
    rep(i, t) cal();
}
