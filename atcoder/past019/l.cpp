// https://atcoder.jp/contests/past19-open/tasks/past19_l
// 2025年03月31日 07時51分22秒
#include <bits/stdc++.h>
#include <algorithm>
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

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vll B(N);
    rep(i, N) cin >> B[i];

    auto f = [&](ll x) -> ll {
        ll ans = 0;
        rep(i, 2) {
            int sw = i;
            ll sum = 0;

            rep(j, N) {
                if (sw == 0) {
                    if (x < B[j]) {
                        sum++;
                        sw = 1 - sw;
                    }
                } else {
                    if (B[j] <= x) {
                        sum++;
                        sw = 1 - sw;
                    }
                }
            }

            chmax(ans, sum);
        }

        return ans;
    };

    vll t = B;
    sort(all(t));
    ll m = t[N / 2];

    ll ans = 0;
    rep2(i, -1, 2) {
        chmax(ans, f(m + i));
    }

    cout << ans << endl;
}
