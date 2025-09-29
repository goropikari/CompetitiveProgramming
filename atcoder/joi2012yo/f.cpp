// https://atcoder.jp/contests/joi2012yo/tasks/joi2012yo_f
// 2025年09月18日 20時11分49秒
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
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

    modint::set_mod(10000);
    using mint = modint;

    auto f = [&](string X, ll MOD) -> mint {
        int N = X.size();

        // dp[is_less][prev number][dir][mod]
        // dir: 0 不定, 1 up, 2 down
        vector dp(2, vector(10, vector(3, vector<mint>(MOD))));
        dp[0][0][0][0] = 1;

        rep(i, N) {
            int t = X[i] - '0';
            vector dpn(2, vector(10, vector(3, vector<mint>(MOD))));

            rep(d, 10) rep(is_less, 2) rep(prev_number, 10) rep(dir, 3) rep(mod, MOD) {
                if (!is_less && d > t) continue;
                if (dir == 1 && prev_number <= d) continue;
                if (dir == 2 && prev_number >= d) continue;
                if (dir == 0 && d != 0 && prev_number == d) continue;

                int is_less_n = is_less || d < t;
                int dir_n = 0;
                if (dir == 0 && prev_number == 0) {
                    dir_n = 0;
                } else if (prev_number < d) {
                    dir_n = 1;
                } else if (prev_number > d) {
                    dir_n = 2;
                }

                int mod_n = (mod * 10 + d) % MOD;

                dpn[is_less_n][d][dir_n][mod_n] += dp[is_less][prev_number][dir][mod];
            }

            swap(dp, dpn);
        }

        mint ans = 0;
        rep(is_less, 2) rep(d, 10) rep(dir, 3) {
            ans += dp[is_less][d][dir][0];
        }

        // cout << ans << endl;

        return ans;
    };

    string A, B;
    ll M;
    cin >> A >> B >> M;

    ll zigzag = 0;
    {
        ll m = (A[0] - '0') % M;
        rep2(i, 1, (ll)A.size()) {
            m *= 10;
            m += A[i] - '0';
            m %= M;
        }

        int ok = 1;
        rep(i, (ll)A.size() - 1) {
            if (A[i] == A[i + 1]) {
                ok = 0;
                break;
            }
        }
        rep2(i, 1, (ll)A.size() - 1) {
            if (A[i - 1] < A[i] && A[i] < A[i + 1]) ok = 0;
            if (A[i - 1] > A[i] && A[i] > A[i + 1]) ok = 0;
        }
        zigzag = m == 0 && ok;
    }

    mint ans = f(B, M) - f(A, M) + zigzag;
    cout << ans.val() << endl;
}
