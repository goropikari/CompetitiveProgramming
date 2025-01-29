/*https://atcoder.jp/contests/abc331/tasks/abc331_e*/
/*2025年01月29日 16時29分42秒*/
// 解説放送見た
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
    int N, M, L;
    cin >> N >> M >> L;

    vll A(N), B(M), C(L), D(L);
    rep(i, N) cin >> A[i];
    rep(i, M) cin >> B[i];
    rep(i, L) {
        cin >> C[i] >> D[i];
        C[i]--, D[i]--;
    }

    vector<unordered_set<int>> memo(N);
    rep(i, L) {
        memo[C[i]].insert(D[i]);
    }

    vector<pair<ll, int>> b;
    rep(i, M) b.push_back({B[i], i});

    sort(rall(b));

    ll ans = 0;
    rep(i, N) {
        rep(j, M) {
            auto [v, idx] = b[j];
            if (memo[i].count(idx))
                continue;
            chmax(ans, A[i] + v);
            break;
        }
    }
    cout << ans << endl;
}
