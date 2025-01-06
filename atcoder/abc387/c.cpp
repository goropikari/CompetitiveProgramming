/*https://atcoder.jp/contests/abc387/tasks/abc387_c*/
/*2025年01月05日 21時10分00秒*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#include <string>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (int i = (k); i < (n); ++i)
using namespace std;
using ll = long long;
// using P = pair<ll,ll>;
using P = pair<int, int>;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

// const ll INF = (ll)2e18+9;
const int INF = (int)2e9 + 7;
// const ll MOD = (ll)1e9+9;
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

ll L, R;
vvll keta(20, vll(10, 0));

ll cal(ll x) {
    string x_str = to_string(x);
    ll n = x_str.size();
    ll sum = 0;

    // n 桁未満の snake number の個数
    rep2(k, 1, n) {
        rep2(l, 1, 10) sum += keta[k][l];
    }

    // n 桁の先頭の桁が `leading_number` 未満の snake number の個数
    ll leading_number = x_str[0] - '0';
    rep2(i, 1, leading_number) {
        sum += keta[n][i];
    }

    // x 以下の最大の snake number を生成する
    int ok = 0;
    string t_str = x_str;
    rep2(i, 1, n) {
        if (ok) {
            t_str[i] = '0' + (leading_number - 1);
        } else if (t_str[i] - '0' >= leading_number) {
            ok = 1;
            t_str[i] = '0' + (leading_number - 1);
        }
    }

    // i-1 桁までは同じな snake number の数
    x_str = t_str;
    rep2(i, 1, n) {
        ll num = x_str[i] - '0';
        sum += num * pow(leading_number, n - (i + 1));
    }

    bool is_snake = true;
    rep2(i, 1, n) {
        if ((x_str[i] - '0') >= leading_number)
            is_snake = false;
    }
    if (is_snake)
        sum++;

    return sum;
}

void solve() {
    cin >> L >> R;
    rep2(k, 1, 20) {
        rep2(ln, 1, 10) {
            keta[k][ln] = pow((ll)ln, (ll)(k - 1));
        }
    }
    cout << cal(R) - cal(L - 1) << endl;
}
