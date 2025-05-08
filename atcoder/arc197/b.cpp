// https://atcoder.jp/contests/arc197/tasks/arc197_b
// 2025年05月07日 20時37分25秒
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
    cout << (x ? "Yes" : "No") << '\n';
}

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    auto cal = []() -> void {
        int N;
        cin >> N;
        vll A(N);
        rep(i, N) cin >> A[i];

        sort(all(A));
        ll sum = 0;
        ll ans = 0;
        ll k = 0;
        rep(i, N) {
            sum += A[i];
            ll n = i + 1;
            while (k < N && A[k] * n <= sum) {
                // 平均以下の A[k]
                k++;
            }
            chmax(ans, n - k);
        }
        cout << ans << endl;
    };

    int t;
    cin >> t;
    rep(i, t) {
        cal();
    }
}
