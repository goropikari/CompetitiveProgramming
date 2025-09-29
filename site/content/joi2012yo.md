+++
date = '2025-09-19T02:43:42+09:00'
title = 'Joi2012yo'
+++

<https://atcoder.jp/contests/abcjoi2012yo>

## A. ランチ (Lunch)

<https://atcoder.jp/contests/joi2012yo/tasks/joi2012yo_a>

## B. サッカー (Soccer)

<https://atcoder.jp/contests/joi2012yo/tasks/joi2012yo_b>

## C. 最高のピザ (Best Pizza)

<https://atcoder.jp/contests/joi2012yo/tasks/joi2012yo_c>

## D. パスタ (Pasta)

<https://atcoder.jp/contests/joi2012yo/tasks/joi2012yo_d>

## E. イルミネーション (Illumination)

<https://atcoder.jp/contests/joi2012yo/tasks/joi2012yo_e>

## F. ジグザグ数 (Zig-Zag Numbers)

<https://atcoder.jp/contests/joi2012yo/tasks/joi2012yo_f>

桁 DP 解法だということをわかった状態で自力 AC.

```cpp
void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    modint::set_mod(10000);
    using mint = modint;

    auto f = [&](string X, ll MOD) -> mint {
        int N = X.size();

        // dp[is_less][prev number][dir][mod]
        // dir: 0 不定, 1 up, 2 down
        vector dp(2, vector(10, vector(3, vector<mint>(MOD))));
        dp[0][0][0][0] = 1;

        rep(i, N) {
            int t = X[i] - '0';
            vector dpn(2, vector(10, vector(3, vector<mint>(MOD))));

            rep(d, 10) rep(is_less, 2) rep(prev_number, 10) rep(dir, 3) rep(mod, MOD) {
                if (!is_less && d > t) continue;
                if (dir == 1 && prev_number <= d) continue;
                if (dir == 2 && prev_number >= d) continue;
                if (dir == 0 && d != 0 && prev_number == d) continue;

                int is_less_n = is_less || d < t;
                int dir_n = 0;
                if (dir == 0 && prev_number == 0) {
                    dir_n = 0;
                } else if (prev_number < d) {
                    dir_n = 1;
                } else if (prev_number > d) {
                    dir_n = 2;
                }

                int mod_n = (mod * 10 + d) % MOD;

                dpn[is_less_n][d][dir_n][mod_n] += dp[is_less][prev_number][dir][mod];
            }

            swap(dp, dpn);
        }

        mint ans = 0;
        rep(is_less, 2) rep(d, 10) rep(dir, 3) {
            ans += dp[is_less][d][dir][0];
        }

        // cout << ans << endl;

        return ans;
    };

    string A, B;
    ll M;
    cin >> A >> B >> M;

    ll zigzag = 0;
    {
        ll m = (A[0] - '0') % M;
        rep2(i, 1, (ll)A.size()) {
            m *= 10;
            m += A[i] - '0';
            m %= M;
        }

        int ok = 1;
        rep(i, (ll)A.size() - 1) {
            if (A[i] == A[i + 1]) {
                ok = 0;
                break;
            }
        }
        rep2(i, 1, (ll)A.size() - 1) {
            if (A[i - 1] < A[i] && A[i] < A[i + 1]) ok = 0;
            if (A[i - 1] > A[i] && A[i] > A[i + 1]) ok = 0;
        }
        zigzag = m == 0 && ok;
    }

    mint ans = f(B, M) - f(A, M) + zigzag;
    cout << ans.val() << endl;
}
```
