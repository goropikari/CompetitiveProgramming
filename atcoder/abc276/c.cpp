/*https://atcoder.jp/contests/abc276/tasks/abc276_c*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#include <algorithm>
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

bool lessv(vint& a, vint& b) {
    int N = a.size();
    rep(i, N) {
        if (a[i] == b[i])
            continue;
        return a[i] < b[i];
    }
    return false;
}

void solve() {
    int N;
    cin >> N;
    vint P(N);
    rep(i, N) cin >> P[i];

    vint ans(N, 0);
    rep(i, N - 1) {
        set<int> S;
        rep(j, N) S.insert(j + 1);

        vint tmp;
        rep(k, i) {
            tmp.push_back(P[k]);
            S.erase(P[k]);
        }

        auto it = S.lower_bound(P[i]);
        if (it == S.begin())
            continue;
        --it;
        tmp.push_back(*it);
        S.erase(it);

        for (auto it = S.rbegin(); it != S.rend(); it++) {
            tmp.push_back(*it);
        }
        if (lessv(ans, tmp))
            ans = tmp;
    }

    print(ans);
}
