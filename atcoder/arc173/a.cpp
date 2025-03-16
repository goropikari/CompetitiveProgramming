/*https://atcoder.jp/contests/arc173/tasks/arc173_a*/
/*2025年03月16日 17時23分14秒*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
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
    puts(x ? "Yes" : "No");
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

    auto f = [](auto f, ll x) -> ll {
        string s = to_string(x);
        int n = s.size();

        if (n == 1)
            return x;

        ll ans = 0;
        // n 桁未満の neq number の数
        rep2(i, 1, n) {
            ans += intpow(9, i);
        }

        // leading number が s[0] 未満場合の数
        ans += (ll)((s[0] - '0') - 1) * intpow(9, n - 1);

        // (s[0] - '0') * intpow(10,n-1) 以上、x 未満の neq number の個数
        // s[0] ~ s[i-1] までの数字は s と同じで、i 番目の文字が s[i] 未満の数字のうち neq number になる個数
        rep2(i, 1, n) {
            ans += (ll)(s[i] - '0') * intpow(9, n - i - 1);
            if (s[i - 1] == s[i]) {
                break;
            }
            if (s[i - 1] < s[i]) {
                ans -= intpow(9, n - i - 1);
            }
        }

        // 現在見ている数が neq number ならば +1 する
        int ok = 1;
        rep2(i, 1, n) {
            if (s[i - 1] == s[i])
                ok = 0;
        }
        if (ok)
            ans++;

        return ans;
    };

    auto cal = [f](ll k) -> ll {
        ll ac = INF, wa = 0;
        while (abs(ac - wa) > 1) {
            ll wj = (ac + wa) / 2;
            ll v = f(f, wj);
            if (v >= k) {
                ac = wj;
            } else {
                wa = wj;
            }
        }
        return ac;
    };

    int t;
    cin >> t;
    rep(_, t) {
        ll k;
        cin >> k;
        cout << cal(k) << endl;
    }
}
