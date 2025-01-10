/*https://atcoder.jp/contests/abc371/tasks/abc371_c*/
/*2025年01月08日 01時19分57秒*/
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

const ll INF = (ll)2e18 + 9;
// const int INF = (int)2e9 + 7;
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

void solve() {
    int N;
    cin >> N;
    int mg;
    cin >> mg;
    vvint G(N, vint(N, 0));
    rep(i, mg) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u][v] = 1;
        G[v][u] = 1;
    }

    int mh;
    cin >> mh;
    vvint H(N, vint(N, 0));

    rep(i, mh) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        H[u][v] = 1;
        H[v][u] = 1;
    }

    vvll A(N, vll(N, 0));
    rep(i, N) {
        rep2(j, i + 1, N) {
            cin >> A[i][j];
        }
    }

    vint v(N, 0);
    iota(all(v), 0);

    ll ans = INF;
    do {
        ll sum = 0;
        rep(i, N) {
            rep2(j, i + 1, N) {
                if (H[i][j] != G[v[i]][v[j]]) {
                    sum += A[i][j];
                }
            }
        }
        chmin(ans, sum);
    } while (next_permutation(all(v)));

    cout << ans << endl;
}
