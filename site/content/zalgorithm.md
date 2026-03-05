+++
date = '2026-02-09T01:06:36+09:00'
title = 'Z Algorithm'
tags = ['z-algorithm']
+++


## library

```cpp
template <class T>
std::vector<int> z_algorithm(const std::vector<T>& s) {
    int n = int(s.size());
    if (n == 0) return {};
    std::vector<int> z(n);
    z[0] = 0;
    for (int i = 1, j = 0; i < n; i++) {
        int& k = z[i];
        k = (j + z[j] <= i) ? 0 : std::min(j + z[j] - i, z[i - j]);
        while (i + k < n && s[k] == s[i + k]) k++;
        if (j + z[j] < i + z[i]) j = i;
    }
    z[0] = n;
    return z;
}

std::vector<int> z_algorithm(const std::string& s) {
    int n = int(s.size());
    std::vector<int> s2(n);
    for (int i = 0; i < n; i++) {
        s2[i] = s[i];
    }
    return z_algorithm(s2);
}
```

## Z Algorithm 解説

※この記事は ChatGPT によって生成されました。

### Z 配列とは何か

長さ $n$ の文字列 $S$ に対して、各位置 $i$ について

$$
Z[i] = \mathrm{LCP}(S, S[i:])
$$

と定義します。

ここで $\mathrm{LCP}$ は **最長共通接頭辞（Longest Common Prefix）** の長さです。

つまり $Z[i]$ は、

> 「文字列全体 $S$ と、位置 $i$ から始まる接尾辞との一致の長さ」

を表します。

特に

$$
Z[0] = n
$$

とするのが一般的です。

---

### 具体例

例えば

$$
S = \text{"aabcaabxaaaz"}
$$

のとき、

* $Z[1]$ は `"aabcaabxaaaz"` と `"abcaabxaaaz"` の LCP → $1$
* $Z[4]$ は `"aabcaabxaaaz"` と `"aabxaaaz"` の LCP → $3$

というように求めます。

---

### ナイーブ解法

各 $i$ について愚直に比較すると、

$$
O(n^2)
$$

になります。

Z algorithm はこれを

$$
O(n)
$$

で求めます。

---

### Z-box の考え方

現在までに一致している区間を

$$
[l, r)
$$

とします。

この区間は

$$
S[l:r] = S[0:r-l]
$$

を満たします。

これを **Z-box** と呼びます。

---

### アルゴリズムの核心

位置 $i$ に対して次の2ケースに分かれます。

---

#### 1. $i \ge r$

Z-box の外なので、通常通り先頭から比較して $Z[i]$ を求めます。

---

#### 2. $i < r$

Z-box の内部なので、

$$
Z[i] = \min(r - i, Z[i - l])
$$

からスタートできます。

もしそれ以上一致するなら、そこから先を追加で比較します。

---

### なぜ線形時間か？

重要なのは：

* 右端 $r$ は単調増加
* 各文字は高々一度しか「新規比較」されない

したがって全体で

$$
O(n)
$$

になります。

---

### 文字列検索への応用

パターン $P$ とテキスト $T$ に対して

$$
S = P + \# + T
$$

を作り、Z 配列を計算します。

すると

$$
Z[i] = |P|
$$

となる位置がマッチ位置です。

---

### 周期判定

長さ $n$ の文字列に対して、

$$
Z[i] = n - i
$$

となる $i$ が存在すれば、

$$
i
$$

が周期になります。

---

### KMP との関係

* Z algorithm は「prefix vs suffix」
* KMP は「prefix vs prefix」

どちらも本質は

> 自己一致情報の再利用

です。

実は

* prefix function
* Z function

は相互変換可能です。

---

### まとめ

* $Z[i] = \mathrm{LCP}(S, S[i:])$
* Z-box によって $O(n)$
* 文字列検索・周期判定・境界列挙などに応用可能
* 競技プログラミングで非常に重要な基礎アルゴリズム

AtCoder や AOJ の文字列問題で
「prefix と suffix の一致長を高速に求めたい」と思ったら、
まず Z algorithm を疑うとよいです。

## Z Algorithm 問題集（AtCoder / AOJ）

---

### yosupo judge: Z Algorithm

<https://judge.yosupo.jp/problem/zalgorithm>

### AOJ ALDS1_14_B – String Search

**URL** <https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_14_B>

**概要**
文字列 `T` が文字列 `S` に出現するすべての開始位置を出力せよ。

<details>

<summary>💡 ヒント（クリックで展開）</summary>

* 典型的なパターンマッチ問題。
* `U = T + '#' + S` を作る。
* `Z[i] == |T|` となる位置が一致箇所。
* 連結した分のインデックス補正を忘れない。

</details>

<details>

<summary>💡 解答（クリックで展開）</summary>

$S = P + T$ とする。

Z Algorithm を用いて文字列 $S$ の最大共通接頭辞の長さを求める。
$Z_i$ を $S[i:]$ と $S$ の最大共通接頭辞の長さとする。

$Z_i \geq |P| \wedge i \geq |P|$ となる $i$ を全て求めればよい。

```cpp
void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string T, P;
    cin >> T >> P;

    string s = P + "$" + T;
    vint z = z_algorithm(s);

    vint ans;
    rep(i, (ll)T.size() - (ll)P.size() + 1) {
        if (z[P.size() + i + 1] == (ll)P.size()) ans.push_back(i);
    }
    for (ll x : ans) cout << x << '\n';
}
```

</details>

---

### ABC430: E - Shift String

**URL** <https://atcoder.jp/contests/abc430/tasks/abc430_e>

<details>
<summary>💡 解答（クリックで展開）</summary>

AOJ: ALDS1_14_B の類題。

$S[i:]$ に対して Z Algorithm を適用し、求める解を探す。

```cpp
void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    auto cal = []() -> void {
        string A, B;
        cin >> A >> B;

        string S = B + A + A;

        vint z = z_algorithm(S);

        int n = A.size();
        rep(i, n) {
            if (z[n + i] >= n) {
                cout << i << '\n';
                return;
            }
        }
        cout << -1 << '\n';
    };

    int t;
    cin >> t;
    rep(i, t) cal();
}
```

</details>

---

### ABC141 E – Who Says a Pun?

**URL**
<https://atcoder.jp/contests/abc141/tasks/abc141_e>

**概要**
同じ部分文字列を重ならないように2回使える最大長を求める。

<details>
<summary>💡 ヒント（クリックで展開）</summary>

* 各開始位置 `i` について `S[i:]` の Z を計算。
* `Z[j]` は `S[i:]` と `S[i+j:]` の一致長。
* ただし重ならない条件より
  `min(Z[j], j)` を考える。
* 全体の最大値を取る。

</details>

<details>
<summary>💡 解説（クリックで展開）</summary>

```cpp
void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    string S;
    cin >> N >> S;

    ll ans = 0;
    rep(i, N) {
        vint z = z_algorithm(S.substr(i));
        int n = z.size();
        rep(j, n) {
            chmax(ans, min(j, (ll)z[j]));
        }
    }
    cout << ans << endl;
}
```

</details>

---

### ABC284 F – ABCBAC

**URL**
<https://atcoder.jp/contests/abc284/tasks/abc284_f>

**概要**
条件を満たす文字列を構成できるか判定する問題。

<details>
<summary>💡 ヒント（クリックで展開）</summary>

* 文字列の一部とその反転を比較する構造になる。
* `revS + '#' + S` の形を考えると整理しやすい。
* prefix と suffix の一致判定に
  `Z[n-k] == k` を使える。

</details>

<details>
<summary>💡 解説（クリックで展開）</summary>

[解説]({{< ref "abc/284.md#f-abcbac" >}})

</details>

---

### ABC257 G – Prefix Concatenation

**URL**
<https://atcoder.jp/contests/abc257/tasks/abc257_g>

**概要**
文字列を prefix 一致を利用して分割する。

<details>
<summary>💡 ヒント（クリックで展開）</summary>

* `T + '#' + S` の Z を計算。
* 各位置で「何文字一致するか」が分かる。
* その一致長を利用して DP 遷移。
* Z は「一致長をまとめて取得できる」のが強み。

</details>

<details>
<summary>💡 ヒント（クリックで展開）</summary>

[解説]({{< ref "abc/257.md#g-prefix-concatenation" >}})

</details>

---
