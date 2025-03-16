/*https://atcoder.jp/contests/arc140/tasks/arc140_b*/
/*2025年03月15日 03時46分30秒*/
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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<char> s(n);
    rep(i, n) cin >> s[i];

    auto com = runLengthEncode(s);

    // cnt, id
    multiset<int> stock;
    int m = com.size();
    rep(i, m - 2) {
        if (com[i].first == 'A' && com[i + 1].first == 'R' && com[i + 2].first == 'C' && com[i + 1].second == 1) {
            stock.insert(min(com[i].second, com[i + 2].second));
        }
    }

    ll ans = 0;
    int cnt = 1;
    while (stock.size()) {
        if (cnt % 2 == 1) {
            auto f = prev(stock.end());
            auto num = *f;
            stock.erase(f);
            ans++;
            if (num - 1)
                stock.insert(num - 1);
        } else {
            auto l = stock.begin();
            ans++;
            stock.erase(l);
        }
        cnt++;
    }
    cout << ans << endl;
}
