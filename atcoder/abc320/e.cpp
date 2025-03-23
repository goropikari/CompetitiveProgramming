/*https://atcoder.jp/contests/abc320/tasks/abc320_e*/
/*2025年03月23日 19時07分13秒*/
// #include <atcoder/all>
// using namespace atcoder;
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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vll ans(n);
    priority_queue<int, vint, greater<int>> people;

    // time, id
    using P = pair<ll, int>;
    priority_queue<P, vector<P>, greater<P>> tpq;

    rep(i, n) people.push(i);
    rep(i, m) {
        ll t, w, s;
        cin >> t >> w >> s;
        while (tpq.size() && tpq.top().first <= t) {
            auto [t, id] = tpq.top();
            tpq.pop();
            people.push(id);
        }

        if (people.size() == 0)
            continue;

        auto p = people.top();
        people.pop();
        ans[p] += w;
        tpq.push({t + s, p});
    }

    for (ll x : ans)
        cout << x << '\n';
}
