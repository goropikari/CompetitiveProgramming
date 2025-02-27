/*https://atcoder.jp/contests/abc269/tasks/abc269_e*/
/*2025年02月25日 04時24分02秒*/
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
    ll n;
    cin >> n;

    ll row = -1;
    {
        ll l = 1, r = n + 1;
        while (r - l > 1) {
            ll mid = (l + r) / 2;
            cout << "? " << l << ' ' << mid - 1 << ' ' << 1 << ' ' << n << endl;
            cout << flush;

            int t;
            cin >> t;
            if (t == -1) {
                return;
            }
            if (mid - l == t) {
                l = mid;
            } else {
                r = mid;
            }
        }
        row = l;
    }

    ll col = -1;
    {
        ll l = 1, r = n + 1;
        while (r - l > 1) {
            ll mid = (l + r) / 2;
            cout << "? " << 1 << ' ' << n << ' ' << l << ' ' << mid - 1 << endl;
            cout << flush;

            int t;
            cin >> t;
            if (t == -1) {
                return;
            }
            if (mid - l == t) {
                l = mid;
            } else {
                r = mid;
            }
        }
        col = l;
    }

    cout << "! " << row << ' ' << col << endl;
    cout << flush;
}
