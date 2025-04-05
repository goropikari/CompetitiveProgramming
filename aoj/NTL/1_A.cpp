// https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A
// 2025年04月05日 23時04分10秒
// https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A
// 2025年04月05日 22時53分22秒
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

// prime, cnt
vector<pair<ll, ll>> factor(ll n) {
    vector<pair<ll, ll>> ps;
    ll t = n;
    for (int i = 2; i * i <= n; i++) {
        if (t % i == 0) {
            ll cnt = 0;
            while (t % i == 0) {
                t /= i;
                cnt++;
            }
            ps.emplace_back(i, cnt);
        }
    }
    if (t > 1)
        ps.emplace_back(t, 1);

    return ps;
}

// https://qiita.com/drken/items/3beb679e54266f20ab63#4-%E6%B4%BB%E7%94%A8%E4%BE%8B-1-%E9%AB%98%E9%80%9F%E7%B4%A0%E5%9B%A0%E6%95%B0%E5%88%86%E8%A7%A3%E9%AB%98%E9%80%9F%E7%B4%84%E6%95%B0%E5%88%97%E6%8C%99
struct Sieve {
    vector<bool> isprime;

    // 整数 i を割り切る最小の素数
    vector<int> minfactor;

    Sieve(int N) : isprime(N + 1, true),
                   minfactor(N + 1, -1) {
        isprime[1] = false;
        minfactor[1] = 1;

        for (int p = 2; p <= N; ++p) {
            // すでに合成数であるものはスキップする
            if (!isprime[p])
                continue;

            // p についての情報更新
            minfactor[p] = p;

            // p 以外の p の倍数から素数ラベルを剥奪
            for (int q = p * 2; q <= N; q += p) {
                // q は合成数なのでふるい落とす
                isprime[q] = false;

                // q は p で割り切れる旨を更新
                if (minfactor[q] == -1)
                    minfactor[q] = p;
            }
        }
    }

    // 高速素因数分解
    // pair (素因子, 指数) の vector を返す
    vector<pair<ll, ll>> factorize(int n) {
        vector<pair<ll, ll>> res;
        while (n > 1) {
            int p = minfactor[n];
            int exp = 0;

            // n で割り切れる限り割る
            while (minfactor[n] == p) {
                n /= p;
                ++exp;
            }
            res.emplace_back(p, exp);
        }
        return res;
    }

    // 高速約数列挙
    vector<int> divisors(int n) {
        vector<int> res({1});

        // n を素因数分解 (メンバ関数使用)
        auto pf = factorize(n);

        // 約数列挙
        for (auto p : pf) {
            int s = (int)res.size();
            for (int i = 0; i < s; ++i) {
                int v = 1;
                for (int j = 0; j < p.second; ++j) {
                    v *= p.first;
                    res.push_back(res[i] * v);
                }
            }
        }
        return res;
    }
};

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Sieve sieve((int)1e7);

    ll n;
    cin >> n;
    cout << n << ":";

    vector<pair<ll, ll>> ps;
    if (n < (int)1e7) {
        ps = sieve.factorize(n);
    } else {
        ps = factor(n);
    }
    for (auto [x, cnt] : ps) {
        rep(i, cnt) {
            cout << ' ' << x;
        }
    }
    cout << endl;
}
