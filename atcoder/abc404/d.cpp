// https://atcoder.jp/contests/abc404/tasks/abc404_d
// 2025年05月03日 21時16分32秒
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

ll intpow(ll x, ll n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1)
            ret *= x;
        x *= x;
        n >>= 1;
    }
    return ret;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    vll costs(N);
    rep(i, N) cin >> costs[i];

    // animals[i]: 動物園 i で見ることのできる動物
    vvint animals(N);

    rep(i, M) {
        int k;
        cin >> k;
        rep(j, k) {
            int a;
            cin >> a;
            a--;
            animals[a].push_back(i);
        }
    }

    ll ans = INF;
    rep(i, intpow(3, N)) {
        ll t = i;
        vint watch(M);
        ll sum = 0;
        rep(j, N) {
            int cnt = t % 3;
            t /= 3;
            sum += costs[j] * cnt;
            rep(k, cnt) {
                for (int x : animals[j])
                    watch[x]++;
            }
        }

        int ok = 1;
        for (int x : watch) {
            if (x < 2)
                ok = 0;
        }

        if (ok)
            chmin(ans, sum);
    }
    cout << ans << endl;
}
