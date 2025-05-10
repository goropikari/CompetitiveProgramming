/*https://atcoder.jp/contests/abc366/tasks/abc366_d*/
/*2025年01月25日 13時12分17秒*/
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

template <typename T>
struct Cumsum3d {
    vector<vector<vector<T>>> data;

    Cumsum3d(vector<vector<vector<T>>> v) {
        assert(v.size() != 0);
        assert(v[0].size() != 0);
        assert(v[0][0].size() != 0);

        int n = v.size();
        int m = v[0].size();
        int l = v[0][0].size();

        data = vector(n + 1, vector(m + 1, vector<T>(l + 1)));

        vector<tuple<ll, ll, ll, ll>> d = {
            {0, 0, -1, 1},
            {0, -1, 0, 1},
            {0, -1, -1, -1},
            {-1, 0, 0, 1},
            {-1, 0, -1, -1},
            {-1, -1, 0, -1},
            {-1, -1, -1, 1},
        };

        rep2(i, 1, n + 1) rep2(j, 1, m + 1) rep2(k, 1, l + 1) {
            data[i][j][k] += v[i - 1][j - 1][k - 1];
            for (auto [x, y, z, sign] : d) {
                data[i][j][k] += data[i + x][j + y][k + z] * sign;
            }
        }
    }

    T sum(int si, int sj, int sk, int fi, int fj, int fk) {
        ll ans = 0;
        ans += data[fi][fj][fk];
        ans -= data[fi][fj][sk];
        ans -= data[fi][sj][fk];
        ans += data[fi][sj][sk];
        ans -= data[si][fj][fk];
        ans += data[si][fj][sk];
        ans += data[si][sj][fk];
        ans -= data[si][sj][sk];
        return ans;
    }
};

void solve() {
    ll N;
    cin >> N;

    vector<vvll> A(N, vvll(N, vll(N, 0)));
    rep(i, N) {
        rep(j, N) {
            rep(k, N) {
                cin >> A[i][j][k];
            }
        }
    }

    Cumsum3d cumsum(A);

    ll Q;
    cin >> Q;
    while (Q--) {
        ll a, x, b, y, c, z;
        cin >> a >> x >> b >> y >> c >> z;
        a--, b--, c--;

        cout << cumsum.sum(a, b, c, x, y, z) << endl;
    }
}
