// https://atcoder.jp/contests/abc450/tasks/abc450_e
// Sat 21 Mar 2026 09:59:08 PM JST
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

    // xcnt[i][c]: X の [0, i) の範囲にある文字 c の個数
    // ycnt[i][c]: Y の [0, i) の範囲にある文字 c の個数
    ll xsz = X.size(), ysz = Y.size();
    vvll xcnt(xsz + 1, vll(26)), ycnt(ysz + 1, vll(26));
    rep(i, xsz) {
        int c = X[i] - 'a';
        xcnt[i + 1][c]++;
    }
    rep(c, 26) rep(i, xsz) xcnt[i + 1][c] += xcnt[i][c];
    rep(i, ysz) {
        int c = Y[i] - 'a';
        ycnt[i + 1][c]++;
    }
    rep(c, 26) rep(i, ysz) ycnt[i + 1][c] += ycnt[i][c];

    // len[k]: S_k の長さ
    vll len(100);
    int cnt = 3;
    {
        len[1] = xsz;
        len[2] = ysz;
        ll b = ysz, a = xsz;
        while (b + a <= (ll)2e18 + 5) {
            ll c = b + a;
            a = b;
            b = c;
            len[cnt] = c;
            cnt++;
        }
    }

    // scnt[k][c]: S_k に含まれる文字 c の個数
    vvll scnt(cnt + 1, vll(26));
    rep(i, 26) scnt[1][i] = xcnt[xsz][i];
    rep(i, 26) scnt[2][i] = ycnt[ysz][i];
    rep2(k, 3, cnt + 1) {
        rep(c, 26) {
            scnt[k][c] = scnt[k - 1][c] + scnt[k - 2][c];
        }
    }

    // dfs(index, r, c): S_k の [0, r) の範囲にある文字 c の個数
    auto dfs = [&](auto dfs, ll index, ll r, ll c) -> ll {
        if (index == 0) return 0;
        if (index == 1) return xcnt[r][c];
        if (index == 2) return ycnt[r][c];

        ll fr = len[index - 1];
        if (r <= fr) {
            return dfs(dfs, index - 1, r, c);
        }

        return scnt[index - 1][c] + dfs(dfs, index - 2, r - fr, c);
    };

    auto cal = [&]() -> void {
        ll L, R;
        char C;
        cin >> L >> R >> C;

        int si = 0;
        while (len[si] < R) si++;
        ll c = C - 'a';
        cout << dfs(dfs, si, R, c) - dfs(dfs, si, L - 1, c) << endl;
    };

    ll Q;
    cin >> Q;
    while (Q--) {
        cal();
    }
}
