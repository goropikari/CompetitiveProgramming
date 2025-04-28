// https://atcoder.jp/contests/abc403/tasks/abc403_f
// 2025年04月28日 16時32分39秒
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

    int N;
    cin >> N;

    int mx = 2005;
    vll exprsz(mx, INF), termsz(mx, INF);
    vector<string> expr(mx), term(mx);
    string ones = "1";
    rep(i, 4) {
        int one = stoi(ones);
        expr[one] = term[one] = ones;
        exprsz[one] = termsz[one] = i + 1;
        ones.push_back('1');
    }

    rep2(i, 2, N + 1) {
        rep2(j, 1, i) {
            string plus = expr[j] + "+" + expr[i - j];
            int plussz = plus.size();
            if (exprsz[i] > plussz) {
                exprsz[i] = plussz;
                expr[i] = plus;
            }
            if (termsz[i] >= plussz + 2) {
                termsz[i] = plussz + 2;
                term[i] = "(" + plus + ")";
            }

            if (j != 1 && i % j == 0) {
                string mul = term[i / j] + "*" + term[j];
                int mulsz = mul.size();
                if (exprsz[i] > mulsz) {
                    exprsz[i] = mulsz;
                    expr[i] = mul;
                }
                if (termsz[i] > mulsz) {
                    termsz[i] = mulsz;
                    term[i] = mul;
                }
            }
        }
    }

    cout << expr[N] << endl;
}
