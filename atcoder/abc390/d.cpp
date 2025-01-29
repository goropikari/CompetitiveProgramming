/*https://atcoder.jp/contests/abc390/tasks/abc390_d*/
/*2025年01月25日 21時18分13秒*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#include <algorithm>
#include <numeric>
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

const ll INF = (ll)2e18 + 9;
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
    puts(x ? "Yes" : "No");
}

void solve();

int main() {
    solve();
    return 0;
}

ll N;
vll A;
set<ll> S;

void solve() {
    cin >> N;
    A = vll(N);
    rep(i, N) cin >> A[i];

    map<ll, ll> mp;
    mp[0] = 1;
    for (ll a : A) {
        map<ll, ll> tmp = mp;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            tmp[it->first + a]++;
        }
        mp = tmp;
    }

    ll tot = accumulate(all(A), 0LL);

    for (auto it = mp.rbegin(); it != mp.rend(); it++) {
        ll t = tot;
        int cnt = 0;
        ll ans = 0;
        ll now = it->first;
        map<ll, ll> memo;
        vll v = {INF};
        while (t && cnt < N) {
            if (v.back() < now)
                break;
            v.push_back(now);
            ans ^= now;
            t -= now;
            cnt++;
            memo[now]++;
            now = t;
        }
        if (v.size() == 1)
            continue;
        if (t != 0)
            continue;
        int ok = 1;
        for (auto mi = memo.begin(); mi != memo.end(); mi++) {
            if (mp[mi->first] < mi->second) {
                ok = 0;
                break;
            }
        }
        if (!ok)
            continue;
        S.insert(ans);
    }

    cout << S.size() << endl;
}
