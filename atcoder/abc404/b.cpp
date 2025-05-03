// https://atcoder.jp/contests/abc404/tasks/abc404_b
// 2025年05月03日 21時01分56秒
#include <bits/stdc++.h>
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

template <typename T>
vector<vector<T>> rotr90(vector<vector<T>>& mat) {
    vector<vector<T>> newmat = mat;
    int N = mat.size();
    rep(i, N) {
        rep(j, N) {
            // newmat[j][N - 1 - i] = mat[i][j];
            newmat[i][j] = mat[N - j - 1][i];
        }
    }
    return newmat;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector S(N, vector<char>(N)), T(N, vector<char>(N));
    rep(i, N) rep(j, N) cin >> S[i][j];
    rep(i, N) rep(j, N) cin >> T[i][j];

    ll ans = INF;
    rep(k, 4) {
        if (k)
            S = rotr90(S);
        ll cnt = k;
        rep(i, N) rep(j, N) {
            if (S[i][j] != T[i][j])
                cnt++;
        }
        chmin(ans, cnt);
    }
    cout << ans << endl;
}
