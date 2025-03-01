/*https://atcoder.jp/contests/abc347/tasks/abc347_e*/
/*2025年03月01日 04時00分54秒*/
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
    int n, q;
    cin >> n >> q;

    vint x(q);
    vvint ids(n);
    vint freq(n);
    vint cnts;
    int sum = 0;
    rep(i, q) {
        cin >> x[i];
        x[i]--;
        ids[x[i]].push_back(i);

        if (freq[x[i]]) {
            sum--;
        } else {
            sum++;
        }
        freq[x[i]] = 1 - freq[x[i]];
        cnts.push_back(sum);
    }

    vll cumsum(q + 1, 0);
    rep(i, q) cumsum[i + 1] = cumsum[i] + cnts[i];

    vll ans(n);
    rep(i, n) {
        vint v = ids[i];
        if (v.size() == 0)
            continue;
        if (v.size() % 2 == 1) {
            v.push_back(q);
        }

        int m = v.size();
        for (int j = 0; j < m; j += 2) {
            ans[i] += cumsum[v[j + 1]] - cumsum[v[j]];
        }
    }
    print(ans);
}
