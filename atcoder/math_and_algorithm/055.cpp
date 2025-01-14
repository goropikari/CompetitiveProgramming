// https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_au
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
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

ll MOD = ((ll)1e9 + 7);

struct Matrix {
    vvll data;

    Matrix(vvll data) { this->data = data; }

    Matrix operator*(const Matrix& other) {
        int n = data.size();
        int m = other.data[0].size();
        int l = other.data.size();
        vvll res(n, vll(m, 0));
        rep(i, n) rep(j, m) rep(k, l) {
            res[i][j] += data[i][k] * other.data[k][j];
            res[i][j] %= MOD;
        }
        return Matrix(res);
    }

    Matrix exp(ll k) {
        int n = data.size();
        Matrix res(vvll(n, vll(n, 0)));
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
};

void solve() {
    ll N;
    cin >> N;

    // (a_{n+1}, a_n) = A^{n-1} * (a_2, a_1)
    Matrix A = Matrix({{2, 1}, {1, 0}});
    Matrix res = A.exp(N - 1) * Matrix({{1}, {1}});
    cout << res.data[1][0] << endl;
}
