/*https://atcoder.jp/contests/abc216/tasks/abc216_e*/
/*2025年03月12日 03時11分17秒*/
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

ll sum(ll x) {
    return x * (x + 1) / 2;
}

ll cal(ll l, ll r) {
    return sum(r) - sum(l);
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k;
    cin >> n >> k;
    vll a(n);
    rep(i, n) cin >> a[i];

    map<ll, ll> mp;
    for (ll x : a)
        mp[x]++;

    ll ans = 0;
    while (mp.rbegin() != mp.rend() && k) {
        auto it = mp.rbegin();
        auto nit = next(it);

        ll v1 = it->first;
        ll n1 = it->second;
        ll v2 = 0;
        if (nit != mp.rend())
            v2 = nit->first;

        if ((v1 - v2) * n1 <= k) {
            k -= (v1 - v2) * n1;
            ans += cal(v2, v1) * n1;
            mp.erase(v1);
            if (v2)
                mp[v2] += n1;
        } else {
            ll q = k / n1;
            ll r = k % n1;
            ans += cal(v1 - q, v1) * n1;
            v1 -= q;
            ans += v1 * r;
            k = 0;
        }
    }
    cout << ans << endl;
}

