#!/bin/sh
make -j
/gpfs/software/opt/gcc/gcc-6.3.0/bin/g++   -Ofast -DNDEBUG   -fopenmp CMakeFiles/matmul_benchmark.dir/src/main.c.o  -o matmul_benchmark  -L/opt/ibm/xlsmp/4.1.5/lib  -L/opt/ibm/xlmass/8.1.5/lib  -L/opt/ibm/xlC/13.1.5/lib -rdynamic libmatmul.a -fopenmp -lpthread -lrt -lxlopt -lxl -ldl -lpthread
