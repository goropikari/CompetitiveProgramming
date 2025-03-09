+++
date = '2025-03-09T20:54:47+09:00'
title = 'ソラで書くセグメント木から ACL へ移行する'
+++


## はじめに

[木マスター養成講座](https://youtu.be/LjhVy1ZJTMc?si=iKiqgeg0nBkg5Dsg)で普通のセグメント木ををソラでかけるようになったあとに、「[遅延評価セグメント木をソラで書きたいあなたに](https://tsutaj.hatenablog.com/entry/2017/03/30/224339)」 (以降ソラ版と呼ぶ)を読んで遅延評価セグメント木をソラでかけるようになった。

とはいえ、ソラで書くの面倒なので ACL に移行するために「[AtCoder LibraryのLazy Segtreeの使い方](https://betrue12.hateblo.jp/entry/2020/09/22/194541)」を読んでみたものの、lazy 配列の使い方がソラ版と違っていて対応関係がよくわからなかったのでまとめる。

## 主な違いまとめ

- ソラ版は lazy node に入れた値を自分の data node に適用するが、ACL 版だと子の data node に適用している
  - <https://github.com/atcoder/ac-library/blob/v1.5.1/atcoder/lazysegtree.hpp#L204-L212>
  - 親のノードにある lazy node の値を子に `mapping` で適用している
- ソラ版は lazy node に配列が被覆している範囲分も含めて値が入っているが、ACL 版だと範囲分は含まれていない
  - 例
    - 区間加算で範囲に $x$ を加算する場合を考える
    - ソラ版は範囲の長さが $n$ なら lazy node に $n \times x$ が入っているが、ACL 版だと $x$ が入っている
    - ACL 版の場合は長さの情報は data node にもたせて lazy node のデータを data node に適用するときに使う
- ソラ版の `eval` 関数は ACL 版の mapping 関数と composition 関数を同時にやっているようなもの

ACL 版を使うときの `S`, `op`, `e`, `F`, `mapping`, `composition` はそれぞれ何を表しているのか

- `S`: data node の型
- `op`: data node に対する二項演算
  - data node の値が渡される
  - 内部的には 2つの子の data node の値が渡されて、現在見ている data node の値が更新される
  - 渡される data node の値は lazy node 分の情報が適用された正しいものが入っていると期待してよい
- `e`: data node の単位元. `op(x, e()) = op(e(), x) = x` が成り立つ
  - 区間最小値なら $\min(x, \infty) = \min(\infty, x) = x$ なので $\infty$ が単位元
  - 区間最大値なら $\max(x, -\infty) = \max(-\infty, x) = x$ なので $-\infty$ が単位元
- `F`: lazy node の型
  - ACL の doc には $F$ は $S$ から $S$ への写像の集合と書かれているが、写像と言いつつ関数ではない。
  - 関数でないのがなんだか気持ち悪い気もするが行列の乗算のことを思い出すと受け入れやすくなるかも
  - $A$ という行列があり、ベクトル $v$ との掛け算を考えるとき、$A$ は単純な関数の形をしていないがベクトル空間からベクトル空間への写像である
  - $Av = \mathrm{mapping}(A, v)$ と書いているみたいなもん
- `mapping`: lazy node の内容を data node に適用する関数
  - lazy node の内容をどのように data node に適用するか考える必要がある
  - 区間加算、区間最小値の場合は加算した値が lazy node に入っており、data node には区間加算が適用される前の状態の範囲最小値が入っている
    - 区間最小値の場合は区間の幅は気にする必要がなく単純に加算分増えるだけなので `F mapping(f, x) = { return f + x; }` となる
    - 区間更新の場合は
- `composition`: lazy node の内容を合算する関数
  - たとえば区間に $x$ を加算したあとに $y$ を加算する場合、`F composition(y, x) = { return y + x; }` となる
  - 先に適用した区間の操作のデータが第2引数に来る
- `id`: lazy node の単位元. `mapping(id(), x) = x` が成り立つ

## 例

AtCoder Library Practice Contest, K - Range Affine Range Sum を見ながら何を書けばいいのかを確認していく

- <https://atcoder.jp/contests/practice2/tasks/practice2_k>
- <https://atcoder.jp/contests/practice2/submissions/63592798>

- 各 $i = l, l+1, \cdots, r-1$ について、$a_i \leftarrow b \times a_i + c$
- $\sum_{i=l}^{r-1} a_i \mod 998244353$ を出力する

全体像は以下のよう

```cpp
struct S {
    mint val;  // data node の値
    int size;  // data node が被覆している範囲
};

// 2つの子の data node から値を更新する
S op(S a, S b) {
    return {a.val + b.val, a.size + b.size};
}

// data node の単位元
S e() {
    return {0, 1};
}

// 区間適用する操作を表すデータ
// 末端の値に対して x <- b * x + c というデータの更新をするので b, c が必要
struct F {
    mint b, c;
};

// x <- b * x + c という操作の本体
S mapping(F f, S x) {
    return {
        f.b * x.val + f.c * x.size,
        x.size,
    };
}

F composition(F f, F g) {
    return {
        f.b * g.b,
        f.b * g.c + f.c,
    };
}

F id() {
    return {1, 0};
}

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    lazy_segtree<S, op, e, F, mapping, composition, id> seg(n);

    rep(i, n) {
        ll a;
        cin >> a;
        seg.set(i, {a, 1});
    }

    rep(i, q) {
        int t;
        cin >> t;
        if (t == 0) {
            int l, r;
            ll b, c;
            cin >> l >> r >> b >> c;
            seg.apply(l, r, {b, c});
        } else {
            int l, r;
            cin >> l >> r;
            cout << seg.prod(l, r).val.val() << endl;
        }
    }
}
```

### 詳細

----

```cpp
struct S {
    mint val;  // data node の値
    int size;  // data node が被覆している範囲
};
```

`S` は data node の型で。値と被覆範囲を持っている。ソラ版では $l$, $r$ の値を使えたので lazy の内容を data node に適用する際に範囲情報を含めて値を更新できたが、ACL 版では `mapping` に範囲情報が渡されないのでどこか別の場所に範囲を持っておく必要がある。
`F` のほうに範囲をもたせるのは多分無理なので `S` にもたせる

----

```cpp
S op(S a, S b) {
    return {a.val + b.val, a.size + b.size};
}
```

2つの子の data node から値を更新する。
前半の `a.val + b.val` は子の値を合算している。普通のセグメント木でもやっている操作。
後半の `a.size + b.size` は子のサイズを合算して更新対象の data node が被覆している範囲を計算している。

----

```cpp
S e() {
    return {0, 1};
}
```

`op(e(), x) = op(x, e()) = x` が成り立つように `e` を定義する

----

```cpp
struct F {
    mint b, c;
};
```

区間適用する操作を表すデータ。
末端の値に対して $a_i \leftarrow b \times a_i + c$ というデータの更新をするので $b$, $c$ が必要

----

```cpp
S mapping(F f, S x) {
    return {
        f.b * x.val + f.c * x.size,
        x.size,
    };
}
```

`x` はセグメント木の data node のいずれかの値。
$x = a_i+\cdots + a_{l+\text{(node size)}}$ とすると、$i \in [l, l+\text{(node size)})$ に対して $a_i \leftarrow b \times a_i + c$ を適用したあとの値は

\begin{align}
    &\sum_{i=l}^{l+\text{(node size)}-1} b \times a_i + c \nonumber \\\\
    &= b \left( \sum_{i=l}^{l+\text{(node size)}-1} a_i \right) + c \times \text{(node size)} \nonumber \\\\
    &= b \times x + c \times (\text{node size}) \nonumber
\end{align}

となる。

----

```cpp
F composition(F f, F g) {
    return {
        f.b * g.b,
        f.b * g.c + f.c,
    };
}
```

lazy node の内容を更に合算する操作

$g(x) = b_g  x + c_g$, $f(x) = b_f  x + c_f$ とすると、

\begin{align}
    f(g(x)) &= b_f (b_g  x + c_g) + c_f \nonumber \\\\
        &= b_f b_g x + b_f c_g + c_f \nonumber \\\\
    f(g(x)) &= f \circ g (x) = b_{fg} x + c_{fg} \nonumber
\end{align}

where $b_{fg} = b_f b_g$, $c_{fg} = b_f c_g + c_f$

となる。

----

```cpp
F id() {
    return {1, 0};
}
```

`mapping(id(), x) = x` が成り立つように `id` を定義する。

$b = 1, c = 0$ のとき $b \times a_i + c = 1 \times a_i + 0 = a_i$ なので恒等演算になる。
