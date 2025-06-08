// https://atcoder.jp/contests/dp/tasks/dp_r
// 2025年06月06日 21時32分28秒
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
using mint = modint1000000007;
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

struct Matrix {
    vector<vector<mint>> data;

    Matrix(vector<vector<mint>> data) { this->data = data; }

    Matrix operator*(const Matrix& other) {
        int n = data.size();
        int m = other.data[0].size();
        int l = other.data.size();
        vector res(n, vector<mint>(m, 0));
        rep(i, n) rep(j, m) rep(k, l) {
            res[i][j] += data[i][k] * other.data[k][j];
        }
        return Matrix(res);
    }

    Matrix exp(ll k) {
        int n = data.size();
        Matrix res(vector(n, vector<mint>(n, 0)));
        rep(i, n) res.data[i][i] = 1;
        Matrix a = *this;
        while (k > 0) {
            if (k & 1)
                res = res * a;
            a = a * a;
            k >>= 1;
        }
        return res;
    }

    mint get(int i, int j) {
        return data[i][j];
    }
};

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, K;
    cin >> N >> K;
    vector data(N, vector<mint>(N));
    rep(i, N) rep(j, N) {
        ll a;
        cin >> a;
        data[i][j] = a;
    }
    Matrix A(data);
    Matrix x(vector(N, vector<mint>(1, 1)));

    auto ret = A.exp(K) * x;
    mint ans = 0;
    rep(i, N) ans += ret.get(i, 0);
    cout << ans.val() << endl;
}
