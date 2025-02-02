/*https://atcoder.jp/contests/abc308/tasks/abc308_e*/
/*2025年02月01日 02時01分46秒*/
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
    ll N;
    cin >> N;
    vll A(N);
    rep(i, N) cin >> A[i];

    string S;
    cin >> S;

    vector<vvll> cumsum(100, vvll(3, vll(N + 1, 0)));
    rep(i, N) {
        cumsum[S[i]][A[i]][i + 1] = 1;
    }
    for (char c : {'M', 'E', 'X'}) {
        rep(i, N) {
            rep(j, 3) {
                cumsum[c][j][i + 1] += cumsum[c][j][i];
            }
        }
    }

    ll ans = 0;
    rep2(j, 1, N) {
        if (S[j] == 'E') {
            rep(i, 3) {
                rep(k, 3) {
                    set<ll> s;
                    s.insert(i);
                    s.insert(A[j]);
                    s.insert(k);

                    ll mul = 0;
                    while (true) {
                        if (!s.count(mul))
                            break;
                        mul++;
                    }

                    ans += mul * (cumsum['M'][i][j] - cumsum['M'][i][0]) *
                           (cumsum['X'][k][N] - cumsum['X'][k][j + 1]);
                }
            }
        }
    }

    cout << ans << endl;
}
