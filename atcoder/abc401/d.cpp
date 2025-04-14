// https://atcoder.jp/contests/abc401/tasks/abc401_d
// 2025年04月12日 21時08分29秒
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

vector<pair<char, int>> runLengthEncode(const string& input) {
    vector<pair<char, int>> encoded;
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

    ll N, K;
    string S;
    cin >> N >> K >> S;

    rep(i, N) {
        if (i + 1 < N && S[i] == '?' && S[i + 1] == 'o') {
            S[i] = '.';
        }
        if (i + 1 < N && S[i] == 'o' && S[i + 1] == '?') {
            S[i + 1] = '.';
        }
    }

    int no = 0;
    for (char c : S)
        if (c == 'o')
            no++;
    if (no == K) {
        rep(i, N) if (S[i] == '?') S[i] = '.';
        cout << S << endl;
        return;
    }

    auto ps = runLengthEncode(S);
    int m = 0;
    for (auto [c, num] : ps) {
        if (c == 'o')
            m += num;
        if (c == '?')
            m += (num + 1) / 2;
    }

    if (m > K) {
        cout << S << endl;
        return;
    }

    for (auto [c, num] : ps) {
        if (c != '?') {
            rep(i, num) cout << c;
            continue;
        }

        if (num % 2 == 0) {
            rep(i, num) cout << '?';
        } else {
            rep(i, num) {
                cout << (i % 2 == 0 ? 'o' : '.');
            }
        }
    }
    cout << endl;
}
