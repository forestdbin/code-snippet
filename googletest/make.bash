#!/bin/bash

OUT_DIR=out
[ -d ${OUT_DIR} ] && rm -rf ${OUT_DIR}/* || mkdir ${OUT_DIR}
mkdir ${OUT_DIR}/{googletest,googlemock}

SRC_DIR=`pwd`
cp ${SRC_DIR}/README.md ${OUT_DIR}
cp -r ${SRC_DIR}/googletest/README.md ${OUT_DIR}/googletest
cp -r ${SRC_DIR}/googlemock/README.md ${OUT_DIR}/googlemock
cp -r ${SRC_DIR}/googletest/include ${OUT_DIR}/googletest
cp -r ${SRC_DIR}/googletest/src ${OUT_DIR}/googletest
cp -r ${SRC_DIR}/googletest/docs ${OUT_DIR}/googletest
cp -r ${SRC_DIR}/googlemock/include ${OUT_DIR}/googlemock
cp -r ${SRC_DIR}/googlemock/src ${OUT_DIR}/googlemock
cp -r ${SRC_DIR}/googlemock/docs ${OUT_DIR}/googlemock

GTEST_DIR=${OUT_DIR}/googletest
g++ -std=c++11 -Wall -Wextra -pthread -isystem ${GTEST_DIR}/include -I ${GTEST_DIR} -c ${GTEST_DIR}/src/gtest-all.cc -o ${GTEST_DIR}/gtest-all.o
ar rv ${GTEST_DIR}/libgtest.a ${GTEST_DIR}/gtest-all.o

GMOCK_DIR=${OUT_DIR}/googlemock
g++ -std=c++11 -Wall -Wextra -pthread -isystem ${GTEST_DIR}/include -I ${GTEST_DIR} -isystem ${GMOCK_DIR}/include -I ${GMOCK_DIR} -c ${GMOCK_DIR}/src/gmock-all.cc -o ${GMOCK_DIR}/gmock-all.o
ar rv ${GMOCK_DIR}/libgmock.a ${GTEST_DIR}/gtest-all.o ${GMOCK_DIR}/gmock-all.o
