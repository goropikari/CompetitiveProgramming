/*https://atcoder.jp/contests/abc352/tasks/abc352_e*/
/*2025年01月29日 11時39分40秒*/
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
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
    ll N, M;
    cin >> N >> M;

    vvll A(M);
    vll C(M);
    rep(i, M) {
        ll k, c;
        cin >> k >> c;
        C[i] = c;
        rep(j, k) {
            ll a;
            cin >> a;
            a--;
            A[i].push_back(a);
        }
    }

    vector<pair<ll, int>> cs;
    rep(i, M) {
        cs.push_back({C[i], i});
    }

    sort(all(cs));

    dsu uf(N);
    ll ans = 0;
    for (auto [c, i] : cs) {
        int k = A[i].size();
        rep2(j, 1, k) {
            int a = A[i][0], b = A[i][j];
            if (uf.same(a, b))
                continue;
            uf.merge(a, b);
            ans += c;
        }
    }

    if (uf.groups().size() != 1)
        ans = -1;
    cout << ans << endl;
}
