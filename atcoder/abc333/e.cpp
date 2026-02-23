// https://atcoder.jp/contests/abc333/tasks/abc333_e
// Mon 23 Feb 2026 04:08:38 PM JST
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

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    using P = pair<int, int>;
    vector<P> queries(N);
    rep(i, N) {
        int t, x;
        cin >> t >> x;
        x--;
        queries[i] = {t, x};
    }

    // ポーションをすべて拾ってモンスターをすべてのモンスターを倒すことができるか確認
    {
        vint his(N);
        for (auto [t, x] : queries) {
            if (t == 1) {
                his[x]++;
            } else {
                his[x]--;
                if (his[x] < 0) {
                    cout << -1 << endl;
                    return;
                }
            }
        }
    }

    // 無駄にポーションを持ちたくないので、モンスターが出現するタイミングと近いポーションを拾うのが最適なので後ろから調べてどのポーションを拾うかを決定する
    vint must_use(N), monster(N);
    for (int i = N - 1; i >= 0; i--) {
        auto [t, x] = queries[i];
        if (t == 1) {
            if (monster[x]) {
                must_use[i] = 1;
                monster[x]--;
            }
        } else {
            monster[x]++;
        }
    }

    // 拾うポーションを決めた状態でシミュレーションして最大保持数を調べる
    ll sum = 0, ans = 0;
    vint portion(N);
    vint track;
    rep(i, N) {
        auto [t, x] = queries[i];
        if (t == 1) {
            int u = 0;
            if (must_use[i]) {
                sum++;
                chmax(ans, sum);
                u = 1;
            }
            track.push_back(u);
        } else {
            sum--;
        }
    }

    cout << ans << endl;
    print(track);
}
