// https://atcoder.jp/contests/arc175/tasks/arc175_a
// 2025年07月03日 20時22分15秒
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
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
#define repinc(i, n, inc) for (long long int i = (k); i < (n); i += (inc))
#define OUTSIDE(i, j, h, w) (((i) < 0) || ((i) >= (h)) || ((j) < 0) || ((j) >= (w)))
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

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;
    vll P(N);
    rep(i, N) {
        cin >> P[i];
        P[i]--;
    }
    string S;
    cin >> S;

    auto calL = [&]() -> mint {
        mint ret = 1;
        vint used(N);

        rep(i, N) {
            int now = P[i];
            int r = (P[i] + 1) % N;
            if (!used[r] && S[now] == 'R') {
                ret = 0;
            }
            if (used[r] && S[now] == '?') {
                ret *= 2;
            }
            used[now] = 1;
        }
        return ret;
    };

    auto calR = [&]() -> mint {
        mint ret = 1;
        vint used(N);

        rep(i, N) {
            int now = P[i];
            int l = P[i], r = (P[i] + 1) % N;
            if (!used[l] && S[now] == 'L') {
                ret = 0;
            }
            if (used[l] && S[now] == '?') {
                ret *= 2;
            }
            used[r] = 1;
        }
        return ret;
    };

    mint ans = calL() + calR();
    cout << ans.val() << endl;
}
