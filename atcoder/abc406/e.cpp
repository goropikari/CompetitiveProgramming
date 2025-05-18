// https://atcoder.jp/contests/abc406/tasks/abc406_e
// 2025年05月17日 21時41分09秒
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
// using mint = modint1000000007;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
#define OUTSIDE(i, j, h, w) (((i) < 0) || ((i) >= (h)) || ((j) < 0) || ((j) >= (w)))
using namespace std;
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

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int mx = 65;
    vector<mint> fac(mx), invfac(mx);
    fac[0] = invfac[0] = 1;
    rep2(i, 1, mx) {
        fac[i] = fac[i - 1] * i;
    }
    rep2(i, 1, mx) {
        invfac[i] = fac[i].inv();
    }

    auto choose = [&](int n, int k) -> mint {
        if (n < 0 || k < 0 || n < k)
            return 0;
        return fac[n] * invfac[n - k] * invfac[k];
    };

    auto f = [&](ll i, ll K) -> mint {
        // 2^i 未満の popcount K の数の総和
        mint tot = (1ll << i) - 1;
        return tot * choose(i - 1, K - 1);
    };

    auto cal = [&]() -> void {
        ll N, K;
        cin >> N >> K;

        vint ids;
        rep(i, 61) if ((N >> i) & 1) ids.push_back(i);
        reverse(all(ids));

        mint ans = 0;
        if (__builtin_popcountll(N) == K)
            ans += N;

        int m = ids.size();
        rep(i, m) {
            // kill ids[i] th bit
            ans += f(ids[i], K - i);

            // ids[i] th bit alive
            rep2(j, i + 1, m) {
                // kill ids[j] bit
                ans += choose(ids[j], K - j) * (1ll << ids[i]);
            }
        }
        cout << ans.val() << endl;
    };

    int t;
    cin >> t;
    rep(_, t) {
        cal();
    }
}
