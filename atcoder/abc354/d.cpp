/*https://atcoder.jp/contests/abc354/tasks/abc354_d*/
/*2025年02月22日 16時56分23秒*/
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
    puts(x ? "Yes" : "No");
}

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    ll h = d - b, w = c - a;
    vll cnt(4, 0);
    {
        ll ta = abs(a), tb = abs(b);
        ta %= 4;
        tb %= 2;
        if (a < 0)
            ta = (4 - ta) % 4;
        if (b < 0)
            tb = (2 - tb) % 2;
        if (ta == 0) {
            cnt[0] += h / 2;
            cnt[3] += h / 2;
            if (tb == 0)
                cnt[0] += h % 2;
            else
                cnt[3] += h % 2;
        }
        if (ta == 1) {
            cnt[0] += h / 2;
            cnt[1] += h / 2;
            if (tb == 0)
                cnt[1] += h % 2;
            else
                cnt[0] += h % 2;
        }
        if (ta == 2) {
            cnt[1] += h / 2;
            cnt[2] += h / 2;
            if (tb == 0)
                cnt[2] += h % 2;
            else
                cnt[1] += h % 2;
        }
        if (ta == 3) {
            cnt[2] += h / 2;
            cnt[3] += h / 2;
            if (tb == 0)
                cnt[3] += h % 2;
            else
                cnt[2] += h % 2;
        }
    }

    vll area = {2, 1, 0, 1, 2, 1, 0, 1};
    ll ans = 0;
    rep(i, 4) {
        ans += cnt[i] * (w / 4 * 4);
        ll m = w % 4;
        rep2(j, i, i + m) {
            ans += area[j] * cnt[i];
        }
    }
    cout << ans << endl;
}
