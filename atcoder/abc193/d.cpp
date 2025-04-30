// https://atcoder.jp/contests/abc193/tasks/abc193_d
// 2025年05月01日 01時34分30秒
#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
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

ll intpow(ll x, ll n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1)
            ret *= x;
        x *= x;
        n >>= 1;
    }
    return ret;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll K;
    string S, T;
    cin >> K >> S >> T;

    vll cnt(10, K);
    rep(i, 4) {
        cnt[S[i] - '0']--;
        cnt[T[i] - '0']--;
    }

    auto score = [&](string s) -> ll {
        vll used(10);
        for (char c : s)
            used[c - '0']++;
        ll ans = 0;
        rep2(i, 1, 10) {
            ans += i * intpow(10, used[i]);
        }
        return ans;
    };

    ll ans = 0;
    S[4] = T[4] = '0';
    rep2(i, 1, 10) {
        rep2(j, 1, 10) {
            S.back() = '0' + i;
            T.back() = '0' + j;

            if (score(S) <= score(T))
                continue;

            ans += cnt[i] * (cnt[j] - (i == j));
        }
    }

    ll rem = K * 9 - 8;
    printf("%.9lf\n", (double)ans / (double)(rem * (rem - 1)));
}
