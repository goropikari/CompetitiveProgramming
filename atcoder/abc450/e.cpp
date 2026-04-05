// https://atcoder.jp/contests/abc450/tasks/abc450_e
// Wed 01 Apr 2026 11:17:30 PM JST
#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
// using vmint = vector<mint>;
// modint::set_mod(10);
// using mint = modint;
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
// using int128 = int128_t;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
#define pb push_back
using ll = long long;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

const ll INF = (ll)2e18 + 9;
// const int INF = (int)2e9 + 7;

template <typename T>
bool chmin(T& a, T b) {
    bool change = a > b;
    a = min(a, b);
    return change;
}
template <typename T>
bool chmax(T& a, T b) {
    bool change = a < b;
    a = max(a, b);
    return change;
}

template <typename T>
void print(vector<T> v, char delim = ' ') {
    int n = v.size();
    rep(i, n) {
        if (i == 0)
            cout << v[i];
        else
            cout << delim << v[i];
    }
    cout << endl;
}

template <typename T>
void vprint(vector<T> v) {
    for (auto x : v) cout << x << '\n';
}

void yesno(bool x) { cout << (x ? "Yes" : "No") << '\n'; }

void Yes() { yesno(true); }

void No() { yesno(false); }

// ceil(a/b)
ll ceil(ll a, ll b) { return (a + b - 1) / b; }

// floor(a/b)
ll floor(ll a, ll b) { return a / b; }

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string X, Y;
    cin >> X >> Y;

    int xsz = X.size(), ysz = Y.size();

    vll len(100);
    len[1] = xsz, len[2] = ysz;
    int cnt = 0;
    rep2(i, 3, 100) {
        len[i] = len[i - 1] + len[i - 2];
        cnt = i;
        if (len[i] > (ll)2e18 + 5) break;
    }

    vvll xcnt(26, vll(xsz + 1));
    vvll ycnt(26, vll(ysz + 1));
    rep(i, xsz) {
        xcnt[X[i] - 'a'][i + 1] = 1;
    }
    rep(i, ysz) {
        ycnt[Y[i] - 'a'][i + 1] = 1;
    }

    rep(i, 26) {
        rep(j, xsz) {
            xcnt[i][j + 1] += xcnt[i][j];
        }
        rep(j, ysz) {
            ycnt[i][j + 1] += ycnt[i][j];
        }
    }

    vvll S(26, vll(100));
    rep(i, 26) S[i][1] += xcnt[i][xsz];
    rep(i, 26) S[i][2] += ycnt[i][ysz];

    rep(i, 26) rep2(k, 3, cnt) {
        S[i][k] += S[i][k - 1] + S[i][k - 2];
    }

    auto dfs = [&](auto dfs, int id, ll r, int c) -> ll {
        if (id == 1) return xcnt[c][r];
        if (id == 2) return ycnt[c][r];

        if (r <= len[id - 1]) return dfs(dfs, id - 1, r, c);

        return S[c][id - 1] + dfs(dfs, id - 2, r - len[id - 1], c);
    };

    int Q;
    cin >> Q;
    while (Q--) {
        ll l, r;
        char C;
        cin >> l >> r >> C;

        int c = C - 'a';
        int id = 0;
        while (len[id] < r) id++;
        cout << dfs(dfs, id, r, c) - dfs(dfs, id, l - 1, c) << '\n';
    }
}
