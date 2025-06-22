// https://atcoder.jp/contests/abc411/tasks/abc411_e
// 2025年06月22日 19時18分22秒
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
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
#define repinc(i, n, inc) for (long long int i = (k); i < (n); i += (inc))
#define OUTSIDE(i, j, h, w) (((i) < 0) || ((i) >= (h)) || ((j) < 0) || ((j) >= (w)))
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

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vvll dice(N);
    set<ll> cands;
    rep(i, N) {
        rep(j, 6) {
            ll a;
            cin >> a;
            cands.insert(a);
            dice[i].push_back(a);
        }
        sort(all(dice[i]));
    }
    sort(all(dice));

    // 最大値が m となる確率
    // m 以下の確率 - (m 未満の確率)
    mint ans = 0;
    mint tot = mint(6).pow(N);
    for (auto it = cands.rbegin(); it != cands.rend(); it++) {
        ll m = *it;
        mint leq_cnt = 1, le_cnt = 1;
        int ok = 1;
        rep(i, N) {
            auto it_leq = upper_bound(all(dice[i]), m);
            auto it_le = lower_bound(all(dice[i]), m);
            leq_cnt *= distance(dice[i].begin(), it_leq);
            le_cnt *= distance(dice[i].begin(), it_le);
            if (leq_cnt == 0) {
                ok = 0;
                break;
            }
        }
        if (!ok) break;
        ans += (leq_cnt - le_cnt) / tot * m;
    }
    cout << ans.val() << endl;
}
