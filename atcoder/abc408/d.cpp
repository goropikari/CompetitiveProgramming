// https://atcoder.jp/contests/abc408/tasks/abc408_d
// 2025年05月31日 21時07分21秒
#include <bits/stdc++.h>
#include <atcoder/all>
#include <atcoder/fenwicktree.hpp>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
// modint::set_mod(10);
// using mint = modint;
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
using int128 = int128_t;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
#define repinc(i, n, inc) for (long long int i = (k); i < (n); i += (inc))
#define OUTSIDE(i, j, h, w) (((i) < 0) || ((i) >= (h)) || ((j) < 0) || ((j) >= (w)))
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

vector<pair<char, int>> runLengthEncode(const string& input) {
    vector<pair<char, int>> encoded;
    int size = input.size();
    for (int i = 0; i < size; ++i) {
        int count = 1;
        while (i + 1 < size && input[i] == input[i + 1]) {
            ++i;
            ++count;
        }
        encoded.emplace_back(input[i], count);
    }
    return encoded;
}

template <typename T>
struct Cumsum {
    vector<T> data;

    Cumsum(vector<T> v) {
        int n = v.size();
        data.resize(n + 1);

        data[0] = 1;
        rep(i, n) {
            data[i + 1] = data[i] + v[i];
        }
    }

    // sum of range [l,r)
    ll sum(int l, int r) {
        return data[r] - data[l];
    }
};

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    auto _cal = []() -> void {
        int N;
        string S;
        cin >> N >> S;

        // dp[i][j]: i 番目まで決めて末尾がグループ j に属したときの最小コスト
        vvll dp(N + 1, vll(3, INF));
        rep(i, 3) dp[0][i] = 0;

        rep2(i, 1, N + 1) {
            rep(j, 3) {
                if (j == 0) {
                    chmin(dp[i][0], dp[i - 1][0] + (ll)(S[i - 1] == '1'));
                }
                if (j == 1) {
                    chmin(dp[i][1], min(dp[i - 1][0], dp[i - 1][1]) + (ll)(S[i - 1] == '0'));
                }
                if (j == 2) {
                    chmin(dp[i][2], min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2])) + (ll)(S[i - 1] == '1'));
                }
            }
        }

        ll ans = INF;
        rep(i, 3) chmin(ans, dp[N][i]);
        cout << ans << endl;
    };

    int t;
    cin >> t;
    rep(i, t) _cal();
}
