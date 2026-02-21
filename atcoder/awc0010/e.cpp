// https://atcoder.jp/contests/awc0010/tasks/awc0010_e
// Fri 20 Feb 2026 08:36:14 PM JST
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
void chmin(T& a, T b) { a = min(a, b); }
template <typename T>
void chmax(T& a, T b) { a = max(a, b); }

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

    ll N, K;
    cin >> N >> K;
    vint cids(N);
    iota(all(cids), 0ll);

    vvll C(N, vll(N));
    rep(i, N) rep(j, N) cin >> C[i][j];

    auto judge = [&](vint ids) -> ll {
        ll ret = 0;
        vint used(N);
        rep(i, N) {
            if (used[i]) continue;
            ret++;
            int now = ids[i];
            used[i] = 1;
            while (!used[now]) {
                used[now] = 1;
                now = ids[now];
            }
        }

        return N - ret;
    };

    ll ans = 0;
    do {
        if (judge(cids) > K) continue;

        ll sum = 0;
        rep(i, N) {
            int j = (i + 1) % N;
            sum += C[cids[i]][cids[j]];
        }
        chmax(ans, sum);
    } while (next_permutation(all(cids)));

    cout << ans << endl;
}
