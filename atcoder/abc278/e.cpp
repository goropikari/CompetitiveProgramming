/*https://atcoder.jp/contests/abc278/tasks/abc278_e*/
/*2025年02月04日 00時39分09秒*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#include <unordered_set>
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
    ll H, W, N, h, w;
    cin >> H >> W >> N >> h >> w;
    vvll A(H + 1, vll(W + 1, 0));
    rep(i, H) rep(j, W) cin >> A[i + 1][j + 1];

    int sz = 301;
    vvll rows(H + 1, vll(sz, 0)), cols(W + 1, vll(sz, 0));
    rep(i, H) {
        rep(j, W) {
            rows[i + 1][A[i + 1][j + 1]]++;
            cols[j + 1][A[i + 1][j + 1]]++;
        }
    }

    rep(i, H) {
        rep(j, sz) {
            rows[i + 1][j] += rows[i][j];
        }
    }
    rep(i, W) {
        rep(j, sz) {
            cols[i + 1][j] += cols[i][j];
        }
    }

    for (int i = 1; i <= H - h + 1; i++) {
        for (int j = 1; j <= W - w + 1; j++) {
            ll cnt = 0;
            rep(k, sz) {
                bool t = false;
                t = t || cols[j - 1][k] > 0;
                t = t || (cols[W][k] - cols[j + w - 1][k] > 0);
                t = t || rows[i - 1][k] > 0;
                t = t || (rows[H][k] - rows[i + h - 1][k]) > 0;
                cnt += t;
            }

            if (j != 1)
                cout << ' ';
            cout << cnt;
        }
        cout << endl;
    }
}
