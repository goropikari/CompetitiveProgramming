// https://atcoder.jp/contests/abc354/tasks/abc354_e
// 2025年07月21日 14時54分22秒
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

    ll N;
    cin >> N;

    vll A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];

    vector<bool> fixed(1 << N), win(1 << N);

    // 使われたカードの状態が state のときに手番が来たときに勝てるか
    auto dfs = [&](auto dfs, int state = 0) -> bool {
        if (fixed[state]) return win[state];
        vector<bool> ret;
        // 表
        rep(i, N) rep2(j, i + 1, N) {
            if (!(state >> i & 1) && !(state >> j & 1) && A[i] == A[j]) {
                bool x = dfs(dfs, state | (1 << i) | (1 << j));
                ret.push_back(x);
            }
        }

        // 裏
        rep(i, N) rep2(j, i + 1, N) {
            if (!(state >> i & 1) && !(state >> j & 1) && B[i] == B[j]) {
                bool x = dfs(dfs, state | (1 << i) | (1 << j));
                ret.push_back(x);
            }
        }

        fixed[state] = true;
        for (bool x : ret) {
            if (!x) return win[state] = true;
        }
        return win[state] = false;
    };

    string ans = "Aoki";
    if (dfs(dfs)) ans = "Takahashi";
    cout << ans << endl;
}
