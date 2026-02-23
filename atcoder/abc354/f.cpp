// https://atcoder.jp/contests/abc354/tasks/abc354_f
// Sat 21 Feb 2026 01:56:11 AM JST
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

const ll INF = (ll)2e18 + 9;
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
        ll N;
        cin >> N;
        vll A(N);
        rep(i, N) cin >> A[i];

        vll last(N), head(N);
        vll lislast(N, INF), lishead(N, INF);
        rep(i, N) {
            {
                auto it = lower_bound(all(lislast), A[i]);
                *it = A[i];
                last[i] = it - lislast.begin() + 1;
            }
            {
                ll a = A[N - i - 1];
                auto it = lower_bound(all(lishead), -a);
                *it = -a;
                head[N - i - 1] = it - lishead.begin() + 1;
            }
        }

        ll maxlen = lower_bound(all(lislast), INF) - lislast.begin();

        vll ans;
        rep(i, N) {
            if (last[i] + head[i] - 1 == maxlen) ans.push_back(i + 1);
        }
        cout << ans.size() << endl;
        print(ans);
    };

    int t;
    cin >> t;
    rep(i, t) cal();
}
