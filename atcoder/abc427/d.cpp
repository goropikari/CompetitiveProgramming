// https://atcoder.jp/contests/abc427/tasks/abc427_d
// Mon 13 Oct 2025 07:01:29 AM JST
#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
// using vmint = vector<mint>;
// modint::set_mod(10);
// using mint = modint;
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
using int128 = int128_t;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
using ll = long long;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

// const ll INF = (ll)2e18+9;
// const int INF = (int)2e9 + 7;

template <typename T>
void chmin(T& a, T b) { a = min(a, b); }
template <typename T>
void chmax(T& a, T b) { a = max(a, b); }

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

void yesno(bool x) { cout << (x ? "Yes" : "No") << '\n'; }

void Yes() { yesno(true); }

void No() { yesno(false); }

// ceil(a/b)
ll ceil(ll a, ll b) { return (a + b - 1) / b; }

// floor(a/b)
ll floor(ll a, ll b) { return a / b; }

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    auto cal = []() -> void {
        ll N, M, K;
        string S;
        cin >> N >> M >> K >> S;

        vvint graph(N);
        rep(i, M) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            graph[u].push_back(v);
        }

        vector result(N, vint(K * 2 + 1, 0));
        vector visited(N, vint(K * 2 + 1, 0));
        rep(i, N) {
            result[i][0] = S[i] == 'A';
            visited[i][0] = 1;
        }

        auto f = [&](auto f, int n, int r) -> int {
            if (visited[n][r]) return result[n][r];
            visited[n][r] = 1;
            int na = 0, nb = 0;
            for (int nx : graph[n]) {
                if (f(f, nx, r - 1))
                    na++;
                else
                    nb++;
            }

            if (na == 0) {
                return result[n][r] = 0;
            }
            if (nb == 0) {
                return result[n][r] = 1;
            }
            if (r % 2 == 0 && na > 0) {
                return result[n][r] = 1;
            }

            return result[n][r] = 0;
        };

        int ret = f(f, 0, K * 2);
        cout << (ret ? "Alice" : "Bob") << endl;
    };

    int t;
    cin >> t;
    rep(i, t) cal();
}
