+++
date = '{{ .Date }}'
title = 'AGC {{ replace .File.ContentBaseName "-" " " | title }}'
tags = ["atcoder", "agc"]
+++

https://atcoder.jp/contests/agc{{ .File.ContentBaseName }}
