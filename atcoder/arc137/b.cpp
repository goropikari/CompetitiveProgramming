// https://atcoder.jp/contests/arc137/tasks/arc137_b
// 2025年05月29日 00時27分03秒
#include <bits/stdc++.h>
#include <atcoder/all>
// using namespace atcoder;
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

template <typename T>
vector<pair<T, int>> runLengthEncode(const vector<T>& input) {
    vector<pair<T, int>> encoded;
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

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vint A(N);
    rep(i, N) cin >> A[i];

    auto ps = runLengthEncode(A);
    if (ps.size() == 1) {
        cout << N + 1 << endl;
        return;
    }

    int m = ps.size();

    int mone = 0, pone = 0;
    bool is_init_one = ps[0].first == 1;
    int s0 = 0, s1 = 1;
    if (is_init_one) swap(s0, s1);
    int sum0 = 0;
    for (int i = s0; i < m; i += 2) {
        sum0 += ps[i].second;
        chmax(pone, sum0);
        if (i + 1 < m) {
            sum0 -= ps[i + 1].second;
            if (sum0 < 0) sum0 = 0;
        }
    }
    int sum1 = 0;
    for (int i = s1; i < m; i += 2) {
        sum1 += ps[i].second;
        chmax(mone, sum1);
        if (i + 1 < m) {
            sum1 -= ps[i + 1].second;
            if (sum1 < 0) sum1 = 0;
        }
    }

    int cnt_one = accumulate(all(A), 0);
    int r = cnt_one + pone;
    int l = cnt_one - mone;
    cout << r - l + 1 << endl;
}
