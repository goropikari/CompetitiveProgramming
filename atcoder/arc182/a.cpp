/*https://atcoder.jp/contests/arc182/tasks/arc182_a*/
/*2025年03月27日 00時39分10秒*/
#include <bits/stdc++.h>
#include <algorithm>
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
// using mint = modint1000000007;
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

    int n, q;
    cin >> n >> q;
    vint P(q), V(q);
    rep(i, q) {
        cin >> P[i] >> V[i];
        P[i]--;
    }

    // kind[i]: i 回目にどの操作を必要があるか
    // -1 左操作
    // 1  右操作
    // 0  どちらでも良い
    vint kind(q);

    auto change = [&](int i, int op) -> bool {
        if (kind[i] == 0) {
            kind[i] = op;
            return true;
        }
        if (kind[i] != op) {
            // 操作が矛盾
            return false;
        }
        return true;
    };

    rep(i, q) {
        rep2(j, i + 1, q) {
            if (V[i] <= V[j])
                continue;
            if (P[i] == P[j]) {
                cout << 0 << endl;
                return;
            }

            bool ok = true;
            if (P[i] < P[j]) {
                // i 番目の操作で左操作
                // j 番目の操作で右操作
                // をしなければならない
                ok = ok && change(i, -1);
                ok = ok && change(j, 1);
            }
            if (P[i] > P[j]) {
                // i 番目の操作で右操作
                // j 番目の操作で左操作
                // をしなければならない
                ok = ok && change(i, 1);
                ok = ok && change(j, -1);
            }
            if (!ok) {
                cout << 0 << endl;
                return;
            }
        }
    }

    mint two = 2;
    ll cnt = 0;
    rep(i, q) cnt += kind[i] == 0;
    cout << two.pow(cnt).val() << endl;
}

