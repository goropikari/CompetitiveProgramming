// https://atcoder.jp/contests/past202005-open/tasks/past202005_d
// 2025年08月29日 22時52分55秒
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

void Yes() {
    yesno(true);
}

void No() {
    yesno(false);
}

// ceil(a/b)
ll ceil(ll a, ll b) {
    return (a + b - 1) / b;
}

// floor(a/b)
ll floor(ll a, ll b) {
    return a / b;
}

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;
    vector<string> S(5);
    rep(i, 5) cin >> S[i];

    vector<string> num(5);
    num[0] = ".###..#..###.###.#.#.###.###.###.###.###.";
    num[1] = ".#.#.##....#...#.#.#.#...#.....#.#.#.#.#.";
    num[2] = ".#.#..#..###.###.###.###.###...#.###.###.";
    num[3] = ".#.#..#..#.....#...#...#.#.#...#.#.#...#.";
    num[4] = ".###.###.###.###...#.###.###...#.###.###.";

    auto find = [&](int x, int i) -> bool {
        bool ok = true;
        rep2(j, i, i + 4) {
            rep(k, 5) {
                if (S[k][j] != num[k][x * 4 + j - i]) {
                    ok = false;
                }
            }
        }
        return ok;
    };

    string ans;
    for (int i = 0; i < N * 4; i += 4) {
        rep(k, 10) {
            if (find(k, i)) {
                ans.push_back('0' + k);
                break;
            }
        }
    }
    cout << ans << endl;
}
