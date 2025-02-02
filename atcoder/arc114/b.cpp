/*https://atcoder.jp/contests/arc114/tasks/arc114_b*/
/*2025年02月02日 13時37分58秒*/
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
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
    puts(x ? "Yes" : "No");
}

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ll N;
    cin >> N;
    vll f(N);
    rep(i, N) {
        cin >> f[i];
        f[i]--;
    }

    scc_graph graph(N);
    rep(i, N) {
        graph.add_edge(i, f[i]);
    }

    vvint scc = graph.scc();
    ll cnt = 0;
    for (auto& x : scc) {
        if (x.size() > 1) {
            cnt++;
        } else {
            if (x[0] == f[x[0]])
                cnt++;
        }
    }

    mint ans = ((mint)2).pow(cnt) - 1;
    cout << ans.val() << endl;
}
