/*https://atcoder.jp/contests/abc277/tasks/abc277_d*/
/*2025年02月02日 17時16分45秒*/
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#include <bits/stdc++.h>
#include <numeric>
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
    ll N, M;
    cin >> N >> M;
    vll A(N);
    rep(i, N) cin >> A[i];

    sort(all(A));

    ll tot = accumulate(all(A), 0LL);
    ll ans = tot;

    vector<pair<ll, int>> r = runLengthEncode(A);
    vector<pair<ll, int>> cyc = r;
    cyc.insert(cyc.end(), all(r));
    int rsz = r.size();
    int i = 0, j = 0;
    while (i < rsz) {
        ll sum = 0;
        do {
            sum += cyc[j].first * cyc[j].second;
            j++;
        } while (j - i < rsz && j < 2 * rsz &&
                 (cyc[j - 1].first + 1) % M == cyc[j].first);
        chmin(ans, tot - sum);
        i = j;
    }
    cout << ans << endl;
}
