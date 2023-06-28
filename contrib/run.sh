#!/bin/sh

BIN_DIR='bin'

mkdir -p "$BIN_DIR"
g++ -std=c++17 "$1.cpp" -o "$BIN_DIR/$1"
chmod +x "$BIN_DIR/$1"
exec "$BIN_DIR/$1"
