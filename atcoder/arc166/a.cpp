// https://atcoder.jp/contests/arc166/tasks/arc166_a
// 2025年05月09日 19時53分18秒
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

    auto check = [](string X, string Y) -> bool {
        int n = X.size();
        int xa = 0, ya = 0;
        for (char c : X) {
            if (c == 'A')
                xa++;
        }
        for (char c : Y) {
            if (c == 'A')
                ya++;
        }

        if (xa > ya)
            return false;

        int rema = ya - xa;
        rep(i, n) {
            if (X[i] == 'C') {
                if (rema) {
                    X[i] = 'A';
                    rema--;
                } else {
                    X[i] = 'B';
                }
            }
        }

        set<int> xbpos;
        rep(i, n) {
            if (X[i] == 'B')
                xbpos.insert(i);
        }

        rep(i, n) {
            if (X[i] == Y[i])
                continue;
            if (X[i] == 'B' && Y[i] == 'A')
                return false;
            if (X[i] == 'A' && Y[i] == 'B') {
                auto it = xbpos.lower_bound(i);
                if (it == xbpos.end())
                    return false;
                swap(X[i], X[*it]);
                xbpos.erase(it);
            }
        }

        return true;
    };

    auto cal = [&]() -> void {
        int N;
        string X, Y;
        cin >> N >> X >> Y;

        if (X == Y) {
            yesno(true);
            return;
        }

        // sentinel
        X.push_back('C');
        Y.push_back('C');

        N++;
        int start = 0;
        rep(i, N) {
            if (Y[i] == 'C' && X[i] != 'C') {
                yesno(false);
                return;
            }

            if (X[i] == 'C' && Y[i] == 'C') {
                int len = i - start;
                if (!check(X.substr(start, len), Y.substr(start, len))) {
                    yesno(false);
                    return;
                };
                start = i + 1;

                continue;
            }
        }
        yesno(true);
    };

    int t;
    cin >> t;
    rep(i, t) {
        cal();
    }
}
