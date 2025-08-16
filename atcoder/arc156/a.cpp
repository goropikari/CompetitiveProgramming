// https://atcoder.jp/contests/arc156/tasks/arc156_a
// 2025年08月03日 19時29分53秒
#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
// using vmint = vector<mint>;
// modint::set_mod(10);
// using mint = modint;
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
using int128 = int128_t;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i, n) for (long long int i = 0; i < (n); ++i)
#define rep2(i, k, n) for (long long int i = (k); i < (n); ++i)
using ll = long long;
using vint = vector<int>;
using vll = vector<ll>;
using vvint = vector<vector<int>>;
using vvll = vector<vector<ll>>;

// const ll INF = (ll)2e18+9;
// const int INF = (int)2e9 + 7;

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

void Yes() {
    yesno(true);
}

void No() {
    yesno(false);
}

// ceil(a/b)
ll ceil(ll a, ll b) {
    return (a + b - 1) / b;
}

// floor(a/b)
ll floor(ll a, ll b) {
    return a / b;
}

void solve();

int main() {
    solve();
    return 0;
}

vector<pair<char, long long int>> runLengthEncode(const string& input) {
    vector<pair<char, long long int>> encoded;
    int size = input.size();
    for (int i = 0; i < size; ++i) {
        long long int count = 1;
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

    auto cal = []() -> void {
        int N;
        string S;
        cin >> N >> S;

        int num1 = 0;
        rep(i, N) {
            if (S[i] == '1') num1++;
        }
        if (num1 % 2 == 1) {
            cout << -1 << endl;
            return;
        }

        int even = 0, odd = 0;
        auto ps = runLengthEncode(S);
        for (auto [c, num] : ps) {
            if (c == '0') continue;
            if (num % 2 == 0)
                even++;
            else
                odd++;
        }

        ll ans = -1;
        if (even % 2 == 0 && odd % 2 == 0) {
            ans = num1 / 2;
        }
        cout << ans << endl;
    };

    int t;
    cin >> t;
    rep(i, t) cal();
}
