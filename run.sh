#!/bin/bash
g++ -std=c++11 *.cpp -o sort.ex
./sort.ex "$1" "$2"
