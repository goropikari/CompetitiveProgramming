/*https://atcoder.jp/contests/abc323/tasks/abc323_c*/
/*2024年12月25日 23時18分14秒*/
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

void solve() {
    int N, M;
    cin >> N >> M;
    vll A(M);
    rep(i, M) cin >> A[i];
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    vll score(N);
    ll max_score = -1;
    ll max_id = -1;
    rep(i, N) {
        rep(j, M) if (S[i][j] == 'o') score[i] += A[j];
        score[i] += i + 1;
        if (max_score < score[i]) {
            max_score = score[i];
            max_id = i;
        }
    }

    rep(i, N) {
        if (i == max_id) {
            cout << 0 << endl;
            continue;
        }
        vll rem;
        rep(j, M) if (S[i][j] == 'x') rem.push_back(A[j]);
        sort(rall(rem));
        ll t = score[i];
        rep(k, rem.size()) {
            t += rem[k];
            if (t > max_score) {
                cout << k + 1 << endl;
                break;
            }
        }
    }
}