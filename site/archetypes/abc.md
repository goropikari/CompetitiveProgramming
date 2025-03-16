+++
date = '{{ .Date }}'
title = 'ABC {{ replace .File.ContentBaseName "-" " " | title }}'
tags = ["atcoder", "abc"]
+++

https://atcoder.jp/contests/abc{{ .File.ContentBaseName }}
