#!/usr/bin/env bash
set -euo pipefail

binary=$(mktemp)
trap 'rm -f "$binary"' EXIT
cc "$(dirname "$0")/main.c" -o "$binary" \
  $(pkg-config --cflags --libs gtk+-3.0 webkit2gtk-4.1)
"$binary" "$(dirname "$0")/index.html"
