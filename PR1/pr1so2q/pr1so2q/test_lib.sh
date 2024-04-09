#!/bin/bash


INPUT="/bin/bash"
OUTPUT="/tmp/so_experiment_lib"
REPS=25
FORMAT="\t%e elapsed,\t%U user,\t%S sys"

rm -f $OUTPUT*
for size in 32768 16384 8192 4096 2048 1024 512 256 128 64 32 16 8 4 2 1
do
	printf "Testing size %5d : " $size
	/usr/bin/time -f "$FORMAT" ./benchmark_lib $size $REPS $INPUT $OUTPUT.$size
	rm -f $OUTPUT.$size
done
