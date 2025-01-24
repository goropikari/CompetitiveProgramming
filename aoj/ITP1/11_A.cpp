// https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/11/ITP1_11_A
/*2025年01月22日 02時23分25秒*/
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

struct Die {
    vint data;
    map<char, vint> mp = {
        {'N', vint({4, 0, 2, 3, 5, 1})},
        {'S', vint({1, 5, 2, 3, 0, 4})},
        {'E', vint({2, 1, 5, 0, 4, 3})},
        {'W', vint({3, 1, 0, 5, 4, 2})},
    };

    Die(vint v) { this->data = v; }

    void roll(char c) {
        vint v = this->data;
        rep(i, 6) {
            v[mp[c][i]] = data[i];
        }
        this->data = v;
    }
};

void solve() {
    vint v;
    rep(i, 6) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    string S;
    cin >> S;

    Die d(v);
    for (char c : S) {
        d.roll(c);
    }
    cout << d.data[0] << endl;
}
