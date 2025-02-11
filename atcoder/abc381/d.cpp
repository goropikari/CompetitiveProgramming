/*https://atcoder.jp/contests/abc381/tasks/abc381_d*/
/*2025年02月11日 03時45分44秒*/
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
    ll n;
    cin >> n;
    vll a(n);
    rep(i, n) cin >> a[i];
    a.push_back(INF);

    auto res = runLengthEncode(a);

    vector<pair<ll, int>> cand;
    for (auto [num, cnt] : res) {
        if (cnt <= 2) {
            cand.push_back({num, cnt});
        } else {
            cand.push_back({num, 2});
            cand.push_back({num, 2});
        }
    }

    ll ans = 0;
    ll i = 0, j = 0;
    set<int> memo;
    while (j < cand.size()) {
        auto [num, cnt] = cand[j];
        if (cnt < 2) {
            chmax(ans, (ll)memo.size());
            memo = set<int>();
            j++;
            i = j;
            continue;
        }

        if (memo.count(num)) {
            while (cand[i].first != num) {
                memo.erase(cand[i].first);
                i++;
            }
            i++;
        }
        memo.insert(num);
        chmax(ans, (ll)memo.size());
        j++;
    }
    cout << ans * 2 << endl;
}
