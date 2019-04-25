#!/bin/bash

if [ ! -d out ]
then
    mkdir out
fi

rm -rf out/*
cmake -H. -Bout
cmake --build out
