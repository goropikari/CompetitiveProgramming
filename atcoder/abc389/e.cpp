/*https://atcoder.jp/contests/abc389/tasks/abc389_e*/
/*2025年01月18日 21時53分36秒*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (int i = (k); i < (n); ++i)
using namespace std;
using ll = long long;
// using P = pair<ll,ll>;
// using P = pair<int, int>;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

// const ll INF = (ll)2e18+9;
const int INF = (int)2e9 + 7;
// const ll MOD = (ll)1e9+9;
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

ll N, M;
vll P;
ll tot, num;

// x 円未満の商品をすべて買うことができるか
bool judge(ll x) {
    tot = num = 0;
    rep(i, N) {
        // (2k-1)Pi < x
        // <-> (2k-1)Pi <= x-1
        ll k = ((x - 1) / P[i] + 1) / 2;
        if (k == 0)
            continue;
        if (M / k / k / P[i] == 0) {
            // M を超えるので ng
            return false;
        }
        tot += k * k * P[i];
        num += k;
        if (tot > M)
            return false;
    }
    return true;
}

void solve() {
    cin >> N >> M;
    P = vll(N);
    rep(i, N) cin >> P[i];

    // judge(x) が true を返す最大の x を探索
    ll ac = 0, wa = M + 1;
    while (abs(ac - wa) > 1) {
        ll x = (ac + wa) / 2;
        if (judge(x))
            ac = x;
        else
            wa = x;
    }

    // 二部探索終了時に ac 側で終わったのか wa 側で終わったかによって
    // tot, num の値が変わるので改めて ac の値で計算
    judge(ac);
    num += (M - tot) / ac;
    cout << num << endl;
}
