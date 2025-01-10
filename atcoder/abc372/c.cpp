/*https://atcoder.jp/contests/abc372/tasks/abc372_c*/
/*2025年01月08日 01時35分45秒*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (int i = (k); i < (n); ++i)
using namespace std;
using ll = long long;
// using P = pair<ll,ll>;
using P = pair<int, int>;
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

ll N, Q;
string S;

bool isabc(int i, char c) {
    if (c == 'A' && i + 2 < N) {
        return S[i] == 'A' && S[i + 1] == 'B' && S[i + 2] == 'C';
    } else if (c == 'B' && i + 1 < N && i - 1 >= 0) {
        return S[i - 1] == 'A' && S[i] == 'B' && S[i + 1] == 'C';
    } else if (c == 'C' && i - 2 >= 0) {
        return S[i - 2] == 'A' && S[i - 1] == 'B' && S[i] == 'C';
    }

    return false;
}

void solve() {
    cin >> N >> Q;
    cin >> S;
    vll X(Q);
    vector<char> C(Q);
    rep(i, Q) {
        cin >> X[i] >> C[i];
        X[i]--;
    }

    set<int> memo;
    rep(i, N - 2) {
        if (S[i] == 'A' && S[i + 1] == 'B' && S[i + 2] == 'C') {
            memo.insert(i);
        }
    }

    rep(i, Q) {
        S[X[i]] = C[i];
        auto it = memo.lower_bound(X[i] - 2);
        if (it != memo.end() && *it <= X[i]) {
            memo.erase(it);
        }
        if (isabc(X[i], C[i])) {
            memo.insert(X[i] - (C[i] - 'A'));
        };
        cout << memo.size() << endl;
    }
}
