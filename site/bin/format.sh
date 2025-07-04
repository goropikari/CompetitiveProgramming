#!/bin/bash

find content -name '*.md' | while read -r file; do
  awk '
  /\\begin{(align\*?|equation\*?|eqnarray\*?)}/ {
    if (prev != "<!-- dprint-ignore -->") print "<!-- dprint-ignore -->"
  }
  { print; prev = $0 }
  ' "$file" > "$file.tmp" && mv "$file.tmp" "$file"
done

dprint fmt ./content/**/*.md
