// https://atcoder.jp/contests/joi2008ho/tasks/joi2008ho_a
// Mon 23 Feb 2026 10:46:52 AM JST
#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
// using vmint = vector<mint>;
// modint::set_mod(10);
// using mint = modint;
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
// using int128 = int128_t;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
#define pb push_back
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

template <typename T>
void vprint(vector<T> v) {
    for (auto x : v) cout << x << '\n';
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

struct Stone {
    int color, num;
};

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<Stone> stones;
    rep(i, N) {
        int s;
        cin >> s;
        if (stones.empty()) {
            stones.push_back({s, 1});
        } else if (i % 2 == 0) {
            if (stones.back().color == s) {
                stones.back().num++;
            } else {
                stones.push_back({s, 1});
            }
        } else {
            if (stones.back().color == s) {
                stones.back().num++;
            } else {
                auto b = stones.back();
                stones.pop_back();
                b.num++;
                b.color ^= 1;
                if (stones.size() && stones.back().color == b.color) {
                    stones.back().num += b.num;
                } else {
                    stones.push_back(b);
                }
            }
        }
    }

    ll ans = 0;
    for (auto [c, num] : stones) {
        if (c == 0) ans += num;
    }
    cout << ans << endl;
}
