/*https://atcoder.jp/contests/abc236/tasks/abc236_d*/
/*2025年02月23日 17時44分09秒*/
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
    vvll a(n * 2, vll(n * 2, 0));
    rep(i, n * 2 - 1) {
        rep2(j, i + 1, n * 2) {
            cin >> a[i][j];
        }
    }

    ll ans = 0;
    auto f = [&](auto f, ll state, ll sum) {
        if (__builtin_popcountll(state) == n * 2) {
            chmax(ans, sum);
            return;
        }

        ll l, r;
        rep(i, n * 2) {
            if (!(state & (1ll << i))) {
                l = i;
                state = state | (1ll << l);
                break;
            }
        }

        rep2(j, l + 1, n * 2) {
            if (!(state & (1ll << j))) {
                r = j;
                f(f, state | (1ll << r), sum ^ a[l][r]);
            }
        }

        state = state ^ (1ll << l);
    };

    f(f, 0, 0);

    cout << ans << endl;
}
