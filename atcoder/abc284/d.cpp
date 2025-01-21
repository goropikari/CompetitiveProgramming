/*https://atcoder.jp/contests/abc284/tasks/abc284_d*/
/*2025年01月21日 09時10分44秒*/
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

vector<bool> prime((ll)5e6, true);

vll cal(ll N) {
    rep2(i, 2, (ll)5e6) {
        if (prime[i] && N % i == 0) {
            N /= i;

            if (N % i == 0) {
                return vll({i, N / i});
            } else {
                ll p, q;
                q = i;
                p = sqrt(N);
                return vll({p, q});
            }
        }
    }
    return vll();
}

void solve() {
    ll T;
    cin >> T;

    prime[0] = prime[1] = false;
    rep2(i, 2, (ll)5e6) {
        if (!prime[i])
            continue;
        for (ll j = i + i; j <= (ll)5e6; j += i) {
            prime[j] = false;
        }
    }

    rep(i, T) {
        ll N;
        cin >> N;
        print(cal(N));
    }
}
