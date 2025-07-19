// https://atcoder.jp/contests/abc415/tasks/abc415_e
// 2025年07月19日 21時59分36秒
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

const ll INF = (ll)2e18 + 9;
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

    int H, W;
    cin >> H >> W;

    vvll A(H, vll(W));
    rep(i, H) rep(j, W) cin >> A[i][j];
    vll food(H + W - 1);
    rep(i, H + W - 1) cin >> food[i];

    vint di = {1, 0};
    vint dj = {0, 1};

    auto judge = [&](ll x) -> bool {
        if (H == 1 && W == 1) {
            return x + A[0][0] >= food[0];
        }

        vvll rem_power(H, vll(W, -INF));
        rem_power[0][0] = x + A[0][0] - food[0];
        if (rem_power[0][0] < 0) return false;

        using P = tuple<ll, ll, ll>;
        queue<P> que;
        que.push({0, 0, rem_power[0][0]});
        while (que.size()) {
            auto [i, j, p] = que.front();
            que.pop();

            rep(d, 2) {
                int ni = i + di[d], nj = j + dj[d];
                if (clamp(ni, 0, H - 1) != ni || clamp(nj, 0, W - 1) != nj) continue;
                ll nxp = rem_power[i][j] + A[ni][nj] - food[ni + nj];
                if (nxp < 0) continue;
                if (rem_power[ni][nj] >= nxp) continue;
                rem_power[ni][nj] = nxp;
                que.push({ni, nj, nxp});
            }
        }

        return rem_power[H - 1][W - 1] >= 0;
    };

    if (judge(0)) {
        cout << 0 << endl;
        return;
    }

    ll ac = INF, wa = 0;
    while (ac - wa > 1) {
        ll wj = (ac + wa) / 2;
        if (judge(wj)) {
            ac = wj;
        } else {
            wa = wj;
        }
    }
    cout << ac << endl;
}
