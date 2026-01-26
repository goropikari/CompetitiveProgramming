+++
date = '2026-01-25T00:20:52+09:00'
title = 'Joisc2007'
+++

<https://atcoder.jp/contests/abcjoisc2007>

## score. 得点 (Score)

<https://atcoder.jp/contests/joisc2007/tasks/joisc2007_score>

## factorial. 階乗 (Factorial)

<https://atcoder.jp/contests/joisc2007/tasks/joisc2007_factor>

## mall. ショッピングモール (Mall)

<https://atcoder.jp/contests/joisc2007/tasks/joisc2007_mall>

## building. ビルの飾り付け (Building)

<https://atcoder.jp/contests/joisc2007/tasks/joisc2007_buildi>

## fermat. フェルマー方程式 (Fermat)

<https://atcoder.jp/contests/joisc2007/tasks/joisc2007_fermat>

## salt. SALT TREE XV

<https://atcoder.jp/contests/joisc2007/tasks/joisc2007_salt>

## anagram. アナグラム (Anagram)

<https://atcoder.jp/contests/joisc2007/tasks/joisc2007_anagra>

2026/1/25 自力 AC

<https://kenkoooo.com/atcoder/#/contest/show/d1b52ca5-dd9a-4c44-a49c-47f405fa737e>

```cpp
void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;
    vll cnt(26);
    for (char c : S) cnt[c - 'A']++;

    vll fac(21);
    fac[0] = 1;
    rep(i, 20) fac[i + 1] = fac[i] * (i + 1);

    reverse(all(S));

    auto f = [&](auto f, string s) -> ll {
        if (s == "") return 1;
        int up = s.back() - 'A';

        ll sum = 0;
        rep(i, up) {
            if (cnt[i] == 0) continue;
            cnt[i]--;

            ll num = 0, den = 1;
            rep(j, 26) {
                if (cnt[j]) {
                    num += cnt[j];
                    den *= fac[cnt[j]];
                }
            }
            sum += fac[num] / den;

            cnt[i]++;
        }
        s.pop_back();
        cnt[up]--;
        return sum + f(f, s);
    };

    cout << f(f, S) << endl;
}
```

## route. 象使い (Route)

<https://atcoder.jp/contests/joisc2007/tasks/joisc2007_route>

## circuit. 電気回路の結線 (Circuit)

<https://atcoder.jp/contests/joisc2007/tasks/joisc2007_circui>

## fiber. 光ファイバー (Fiber)

<https://atcoder.jp/contests/joisc2007/tasks/joisc2007_fiber>

## lines. 直線 (Lines)

<https://atcoder.jp/contests/joisc2007/tasks/joisc2007_lines>

## packing1. 半導体工場 (Packing)

<https://atcoder.jp/contests/joisc2007/tasks/joisc2007_packin>

## packing2. 半導体工場 (Packing)

<https://atcoder.jp/contests/joisc2007/tasks/joisc2007_packing2>

## packing3. 半導体工場 (Packing)

<https://atcoder.jp/contests/joisc2007/tasks/joisc2007_packing3>

## packing4. 半導体工場 (Packing)

<https://atcoder.jp/contests/joisc2007/tasks/joisc2007_packing4>

## packing5. 半導体工場 (Packing)

<https://atcoder.jp/contests/joisc2007/tasks/joisc2007_packing5>
