// https://atcoder.jp/contests/past19-open/tasks/past19_j
// 2025年03月30日 19時03分09秒
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

    int N;
    cin >> N;
    vll A(N * 3);
    rep(i, N * 3) cin >> A[i];

    ll ans = INF;

    auto get = [](int x, int j) -> int {
        return (x >> j) & 1;
    };

    auto dfs = [&](auto dfs, int used, vll stock) -> void {
        if ((int)stock.size() == N) {
            ll mx = *max_element(all(stock));
            ll mi = *min_element(all(stock));
            chmin(ans, mx - mi);
            return;
        }
        int i = 0;
        rep(j, N * 3) {
            if (get(used, j) == 0) {
                i = j;
                break;
            }
        }

        rep2(j, i + 1, N * 3) {
            rep2(k, j + 1, N * 3) {
                if (get(used, j) == 0 && get(used, k) == 0) {
                    stock.push_back(A[i] + A[j] + A[k]);
                    dfs(dfs, used | (1 << i) | (1 << j) | (1 << k), stock);
                    stock.pop_back();
                }
            }
        }
    };

    dfs(dfs, 0, vll());
    cout << ans << endl;
}
