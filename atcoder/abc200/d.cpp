// https://atcoder.jp/contests/abc200/tasks/abc200_d
// 2025年06月27日 19時04分47秒
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
// using vmint = vector<mint>;
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
using int128 = int128_t;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
#define repinc(i, n, inc) for (long long int i = (k); i < (n); i += (inc))
#define OUTSIDE(i, j, h, w) (((i) < 0) || ((i) >= (h)) || ((j) < 0) || ((j) >= (w)))
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
    vll A(N + 1);
    rep(i, N) {
        cin >> A[i + 1];
        A[i + 1] %= 200;
    }

    // dp[x][r]: x 個使って余りが r となる場合の数
    vvll dp(N + 1, vll(200));
    dp[0][0] = 1;

    rep2(i, 1, N + 1) {
        vvll dpn(N + 1, vll(200));
        rep(x, i) {
            rep(r, 200) {
                dpn[x][r] += dp[x][r];
                chmin(dpn[x][r], 2ll);  // 2個あれば十分なので頭を抑える

                ll nr = (r + A[i]) % 200;
                dpn[x + 1][nr] += dp[x][r];
                chmin(dpn[x + 1][nr], 2ll);  // 2個あれば十分なので頭を抑える
            }
        }
        swap(dp, dpn);
    }

    ll rem = -1;
    rep(r, 200) {
        ll num = 0;
        rep2(x, 1, N + 1) {
            num += dp[x][r];
        }
        if (num >= 2) {
            rem = r;
            break;
        }
    }
    if (rem < 0) {
        No();
        return;
    }

    vvint ans;
    auto dfs = [&](auto dfs, int now, int num, ll r, vint ids) -> void {
        if (ans.size() == 2) return;
        if (now == 0) {
            if (num == 0 && r == 0) ans.push_back(ids);
            return;
        }

        ll nr = (r - A[now] + (ll)1e9) % 200;
        if (num - 1 >= 0 && dp[num - 1][nr]) {
            ids.push_back(now);
            dfs(dfs, now - 1, num - 1, nr, ids);
            ids.pop_back();
        }
        dfs(dfs, now - 1, num, r, ids);
    };

    rep2(num, 1, N + 1) {
        if (dp[num][rem])
            dfs(dfs, N, num, rem, vint());
    }

    Yes();
    for (auto v : ans) {
        reverse(all(v));
        cout << v.size() << ' ';
        print(v);
    }
}
