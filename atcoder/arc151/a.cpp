// https://atcoder.jp/contests/arc151/tasks/arc151_a
// 2025年08月01日 21時07分48秒
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

    int N;
    cin >> N;
    string S, T;
    cin >> S >> T;

    string U = string(N, '0');
    reverse(all(S));
    reverse(all(T));

    ll sd = 0, td = 0;
    rep(i, N) {
        sd += S[i] != U[i];
        td += T[i] != U[i];
    }
    if (sd == td) {
        cout << U << endl;
        return;
    }

    int ok = 0;
    rep(i, N) {
        ll tmps = sd, tmpt = td;
        if (S[i] == '1')
            tmps--;
        else
            tmps++;
        if (T[i] == '1')
            tmpt--;
        else
            tmpt++;

        if (abs(tmps - tmpt) < abs(sd - td)) {
            U[i] = '1';
            sd = tmps;
            td = tmpt;
        }

        if (sd == td) {
            ok = 1;
            break;
        }
    }

    reverse(all(U));
    string ans = U;
    if (!ok)
        ans = "-1";
    cout << ans << endl;
}
