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

    vector<tuple<ll, ll, ll, ll>> d = {
        {0, 0, -1, 1},   {0, -1, 0, 1},   {0, -1, -1, -1}, {-1, 0, 0, 1},
        {-1, 0, -1, -1}, {-1, -1, 0, -1}, {-1, -1, -1, 1},
    };

    vector<vvll> cumsum(N + 1, vvll(N + 1, vll(N + 1, 0)));
    rep2(i, 1, N + 1) rep2(j, 1, N + 1) rep2(k, 1, N + 1) {
        cumsum[i][j][k] += A[i - 1][j - 1][k - 1];
        for (auto [x, y, z, sign] : d) {
            cumsum[i][j][k] += cumsum[i + x][j + y][k + z] * sign;
        }
    }

    ll Q;
    cin >> Q;
    while (Q--) {
        ll a, x, b, y, c, z;
        cin >> a >> x >> b >> y >> c >> z;
        a--, b--, c--;

        ll ans = 0;
        ans += cumsum[x][y][z];
        ans -= cumsum[x][y][c];
        ans -= cumsum[x][b][z];
        ans += cumsum[x][b][c];
        ans -= cumsum[a][y][z];
        ans += cumsum[a][y][c];
        ans += cumsum[a][b][z];
        ans -= cumsum[a][b][c];
        cout << ans << endl;
    }
}
