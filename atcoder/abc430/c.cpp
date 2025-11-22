// https://atcoder.jp/contests/abc430/tasks/abc430_c
// Sat 01 Nov 2025 09:07:54 PM JST
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
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
void chmin(T& a, T b) { a = min(a, b); }
template <typename T>
void chmax(T& a, T b) { a = max(a, b); }

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

void yesno(bool x) { cout << (x ? "Yes" : "No") << '\n'; }

void Yes() { yesno(true); }

void No() { yesno(false); }

// ceil(a/b)
ll ceil(ll a, ll b) { return (a + b - 1) / b; }

// floor(a/b)
ll floor(ll a, ll b) { return a / b; }

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

ll bone(string S, ll A) {
    ll ans = 0;
    auto ps = runLengthEncode(S);
    for (auto [c, num] : ps) {
        if (c == 'b') continue;
        if (num >= A) ans += (num - A + 1) * (num - A + 2) / 2;
    }
    return ans;
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, A, B;
    cin >> N >> A >> B;
    string S;
    cin >> S;

    vll cumsuma(N + 1), cumsumb(N + 1);
    {
        vll tmpa(N), tmpb(N);
        rep(i, N) {
            if (S[i] == 'a')
                tmpa[i]++;
            else
                tmpb[i]++;
        }

        rep(i, N) {
            cumsuma[i + 1] = cumsuma[i] + tmpa[i];
            cumsumb[i + 1] = cumsumb[i] + tmpb[i];
        }
    }

    ll ans = 0;
    rep(i, N) {
        ll numa = cumsuma[i];
        auto lit = lower_bound(all(cumsuma), numa + A);
        if (lit == cumsuma.end()) continue;
        int l = lit - cumsuma.begin();
        ll numb = cumsumb[l] - cumsumb[i];
        if (numb >= B) continue;

        auto rit = lower_bound(all(cumsumb), cumsumb[l] + (B - numb));
        ll id = rit - cumsumb.begin();
        ans += id - l;
    }
    cout << ans << endl;
    // print(cumsuma);
    // print(cumsumb);
}
