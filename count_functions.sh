#!/bin/bash

# Ignorer visualizer et complexity
find src -type f -name "*.c" -not -path "*/visualizer/*" -not -path "*/complexity/*" | while read file; do
  echo -n "$file: "
  grep -E '^(static[[:space:]]+)?[[:alnum:]_]+[[:space:]]+([[:alnum:]_*]+[[:space:]]*)+\([^;]*$' "$file" | wc -l
done | sort -k2 -nr
