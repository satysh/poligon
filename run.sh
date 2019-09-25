#!/bin/bash

rm -fv *.out
g++ bin.cpp -o bin.out
wait

./bin.out
