/*https://atcoder.jp/contests/abc399/tasks/abc399_d*/
/*2025年03月29日 21時09分05秒*/
#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
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
    cout << (x ? "Yes" : "No") << '\n';
}

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    auto cal = []() -> void {
        int N;
        cin >> N;
        vll A(N * 2 + 2);
        rep(i, N * 2) {
            cin >> A[i + 1];
        }
        A[0] = -INF;
        A[N * 2 + 1] = INF;

        vvint ids(N + 1);
        for (int i = 1; i <= N * 2; i++) {
            ids[A[i]].push_back(i);
        }

        set<pair<int, int>> ans;
        for (int a = 1; a <= N; a++) {
            int lid = ids[a][0];
            int rid = ids[a][1];

            // 数字 i が隣接している
            if (lid + 1 == rid)
                continue;

            for (int d1 : {-1, 1}) {
                for (int d2 : {-1, 1}) {
                    if (A[lid + d1] != A[rid + d2])
                        continue;

                    int b = A[lid + d1];

                    if (d1 == 1 && d2 == -1) {
                        // 同じ場所の数字を参照しているとき
                        // 1 2 1 における 2 の場所を見ている
                        if (lid + 2 == rid)
                            continue;

                        // 2 1 1 2 で 2 を調べているときのケースを飛ばす
                        if (lid + 3 == rid)
                            continue;
                    }

                    ans.insert(minmax(a, b));
                }
            }
        }

        cout << ans.size() << endl;
    };

    int t;
    cin >> t;
    rep(i, t) {
        cal();
    }
}
