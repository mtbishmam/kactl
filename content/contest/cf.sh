#!/bin/bash
export PATH="$PATH:$HOME/cp"
code=$1
g++ ${code}.cpp -o $code -std=c++20 -g -DDeBuG -Wall -Wshadow -fsanitize=address,undefined && ./$code < in > out && diff exp out && echo -e "\nAC"