/*https://atcoder.jp/contests/abc394/tasks/abc394_c*/
/*2025年02月22日 21時04分15秒*/
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

template <typename T>
vector<pair<T, int>> runLengthEncode(const vector<T>& input) {
    vector<pair<T, int>> encoded;
    int size = input.size();
    for (int i = 0; i < size; ++i) {
        int count = 1;
        while (i + 1 < size && input[i] == input[i + 1]) {
            ++i;
            ++count;
        }
        encoded.emplace_back(input[i], count);
    }
    return encoded;
}

void solve() {
    string S;
    cin >> S;

    vector<char> v;
    for (char c : S)
        v.push_back(c);

    vector<pair<char, int>> ans;
    auto comp = runLengthEncode(v);
    int n = comp.size();
    rep(i, n) {
        auto [c1, cnt1] = comp[i];
        char c2 = '-';
        int cnt2 = 0;
        if (i + 1 < n) {
            c2 = comp[i + 1].first;
            cnt2 = comp[i + 1].second;
        }
        if (c1 == 'W' && c2 == 'A') {
            ans.push_back({'A', 1});
            ans.push_back({'C', cnt1});
            comp[i + 1].second--;
        } else {
            ans.push_back({comp[i]});
        }
    }

    for (auto [c, cnt] : ans) {
        rep(i, cnt) cout << c;
    }
    cout << endl;
}
