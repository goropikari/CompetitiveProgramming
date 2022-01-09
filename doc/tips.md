+++
title = "Tips"
hascode = true
date = Date(2021, 12, 12)
+++
@def tags = ["algorithm", "cpp"]

# Performance

\toc


## multiset vs vector

multiset は遅いので二部探索のように使うときは注意する.
insert, find, erase の計算量は $\log(N)$ ($N$ は要素数)であるが, 定数項が効いているのかなかなかに遅い.

\input{cpp}{/assets/scripts/tips/multiset_vs_vector.cpp} <!--_-->

```
multiset
size    elapsed time (sec)
100     9e-06
1000    6.4e-05
10000   0.000915
100000  0.011328
1000000 0.144224
10000000        2.5446

vector
size    elapsed time (sec)
100     5e-06
1000    1e-05
10000   7.5e-05
100000  0.000858
1000000 0.010139
10000000        0.130072
```

![multiset_vs_vector](/assets/tips/multiset_vs_vector.png)
