// https://atcoder.jp/contests/abc402/tasks/abc402_f
// 2025年04月19日 21時52分30秒
#include <bits/stdc++.h>
#include <atcoder/all>
#include <atcoder/modint>
using namespace atcoder;
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

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    using mint = modint;
    mint::set_mod(M);

    vector<vector<mint>> A(N, vector<mint>(N));
    rep(i, N) rep(j, N) {
        ll a;
        cin >> a;
        A[i][j] = a;
    }

    vector<mint> tenth(50);
    mint ten = 10;
    rep(i, 50) {
        tenth[i] = ten.pow(i);
    }

    rep(i, N) rep(j, N) {
        A[i][j] *= tenth[2 * N - 2 - (i + j)];
    }

    vvll g1(N), g2(N);
    rep(i, 1 << (N - 1)) {
        mint sum = 0;
        int x = 0, y = 0;
        rep(j, N - 1) {
            sum += A[x][y];
            if ((i >> j) & 1)
                x++;
            else
                y++;
        }
        sum += A[x][y];
        g1[x].push_back(sum.val());
    }
    rep(i, 1 << (N - 1)) {
        mint sum = 0;
        int x = N - 1, y = N - 1;
        rep(j, N - 1) {
            sum += A[x][y];
            if ((i >> j) & 1)
                x--;
            else
                y--;
        }
        g2[x].push_back(sum.val());
    }

    for (auto& v : g2)
        sort(all(v));

    ll ans = 0;
    rep(i, N) {
        for (ll x : g1[i]) {
            auto it = lower_bound(all(g2[i]), M - x);
            if (it != g2[i].begin())
                it = prev(it);
            else
                it = prev(g2[i].end());
            chmax(ans, (x + *it) % M);
        }
    }
    cout << ans << endl;
}
