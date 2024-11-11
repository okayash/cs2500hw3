#!/bin/bash
g++ -std=c++11 *.cpp -o fibo.ex
./fibo.ex "$1" "$2"
