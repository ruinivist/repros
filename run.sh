#!/usr/bin/env bash
set -e

cc main.c -o paste-webkitgtk $(pkg-config --cflags --libs gtk+-3.0 webkit2gtk-4.1)
./paste-webkitgtk index.html
