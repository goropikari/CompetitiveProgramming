/*https://atcoder.jp/contests/abc283/tasks/abc283_d*/
/*2025年01月21日 08時51分55秒*/
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
    string S;
    cin >> S;
    vector<set<char>> box;
    box.push_back({});

    rep(i, S.size()) {
        if (S[i] == '(') {
            box.push_back({});
        } else if (S[i] == ')') {
            box.pop_back();
        } else {
            for (ll j = box.size() - 1; j >= max(0LL, (ll)box.size() - 27);
                 j--) {
                if (box[j].count(S[i])) {
                    yesno(false);
                    return;
                }
            }
            box.back().insert(S[i]);
        }
    }
    yesno(true);
}
