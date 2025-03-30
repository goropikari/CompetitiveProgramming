#!/bin/bash

basepath=$(cd `dirname $0`; pwd)

hugo new content $1.md

python3 $basepath/gen.py $1 >> content/$1.md
