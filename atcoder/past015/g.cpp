// https://atcoder.jp/contests/past15-open/tasks/past202306_g
// 2025年04月13日 02時01分34秒
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

    int N, M;
    cin >> N >> M;
    vvint as(M), bs(M);
    rep(i, M) {
        int k;
        cin >> k;
        rep(j, k) {
            int a, b;
            cin >> a >> b;
            a--;
            as[i].push_back(a);
            bs[i].push_back(b);
        }
    }

    rep(t, 1 << N) {
        vint xs;
        rep(i, N) {
            xs.push_back((t >> i) & 1);
        }

        int cnt = 0;
        rep(i, M) {
            int ok = 0;
            int ki = as[i].size();
            rep(j, ki) {
                if (xs[as[i][j]] == bs[i][j])
                    ok = 1;
            }
            if (ok)
                cnt++;
        }

        if (cnt == M) {
            yesno(true);
            return;
        }
    }
    yesno(false);
}
