// https://atcoder.jp/contests/abc405/tasks/abc405_e
// 2025年05月10日 21時26分22秒
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
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

    ll A, B, C, D;
    cin >> A >> B >> C >> D;

    ll tot = A + B + C + D;

    vector<mint> fac(tot + 1), invfac(tot + 1);
    fac[0] = invfac[0] = 1;
    rep2(i, 1, tot + 1) {
        fac[i] = fac[i - 1] * i;
    }
    rep2(i, 1, tot + 1) {
        invfac[i] = fac[i].inv();
    }

    auto comb = [&](ll n, ll r) -> mint {
        return fac[n] * invfac[n - r] * invfac[r];
    };

    mint ans = 0;
    for (ll k = A; k <= A + B; k++) {
        ll left_orange = k - A;
        ll right_orange = B - left_orange;
        ans += comb(k - 1, A - 1) * comb(right_orange + C + D, C);
    }
    // rep(k, C + 1) {
    //     ans += comb(A + B + k, B) * comb(D - 1 + C - k, C - k);
    // }
    cout << ans.val() << endl;
}
