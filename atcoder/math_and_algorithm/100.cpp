// https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_bv
/*2025年01月19日 15時25分52秒*/
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

struct Matrix {
    vector<vector<double>> data;

    Matrix(double x, double y, double z) {
        data = vector<vector<double>>(3);
        data = {
            {1 - x, y, 0},
            {0, 1 - y, z},
            {x, 0, 1 - z},
        };
    }

    Matrix(vector<vector<double>> mat) { this->data = mat; }

    Matrix(ll n) {
        this->data = vector<vector<double>>(n, vector<double>(n, 0));
    }

    Matrix operator*(const Matrix& q) {
        vector<vector<double>> T = this->data, Q = q.data;
        int n = T.size();
        int m = T[0].size();
        int l = Q[0].size();
        vector<vector<double>> ret(n, vector<double>(l, 0));
        rep(i, n) rep(j, l) rep(k, m) {
            ret[i][j] += T[i][k] * Q[k][j];
        }

        return Matrix(ret);
    }

    Matrix exp(ll n) {
        Matrix b = *this;
        Matrix ans = Matrix(b.data.size());
        rep(i, ans.data.size()) ans.data[i][i] = 1;
        while (n) {
            if (n & 1) {
                ans = ans * b;
            }
            b = b * b;
            n /= 2;
        }

        return ans;
    }
};

void solve() {
    ll Q;
    cin >> Q;
    rep(_, Q) {
        double x, y, z;
        ll t;
        cin >> x >> y >> z >> t;

        Matrix A = Matrix(x, y, z);
        Matrix v = Matrix(vector<vector<double>>({{1}, {1}, {1}}));

        // Matrix ans = A.exp(1) * v;
        Matrix ans = A.exp(t) * v;
        rep(i, 3) {
            if (i != 0)
                cout << ' ';
            printf("%.10lf", ans.data[i][0]);
        }
        cout << endl;
    }
}
