// https://atcoder.jp/contests/past19-open/tasks/past19_h
// 2025年03月30日 18時42分09秒
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

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, S;
    cin >> N >> S;
    vll A(N);
    rep(i, N) cin >> A[i];
    sort(all(A));

    rep(i, 1 << (N - 1)) {
        do {
            vll sum;
            ll st = A[0];
            rep(j, N - 1) {
                if ((i >> j) & 1) {
                    st *= A[j + 1];
                } else {
                    sum.push_back(st);
                    st = A[j + 1];
                }
            }
            sum.push_back(st);
            if (accumulate(all(sum), 0ll) == S) {
                yesno(true);
                rep(j, N - 1) {
                    cout << A[j];
                    if ((i >> j) & 1)
                        cout << 'x';
                    else
                        cout << '+';
                }
                cout << A[N - 1] << endl;
                return;
            }
        } while (next_permutation(all(A)));
    }

    yesno(false);
}
