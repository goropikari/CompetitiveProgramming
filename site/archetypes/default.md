+++
date = '{{ .Date }}'
title = '{{ replace .File.ContentBaseName "-" " " | title }}'
+++

https://atcoder.jp/contests/abc{{ .File.ContentBaseName }}
