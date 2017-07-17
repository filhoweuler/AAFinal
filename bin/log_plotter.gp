#!/usr/local/bin/gnuplot --persist

INPUT_FILE=ARG1
OUTPUT_FILE=ARG2

set key noautotitles
#set yrange []
#set xrange [0:20]

set ylabel "time (s)"
set xlabel "input size"

set term png font "arialbd.ttf" 11 size 800,500
f(x) = a * x * log(x) + b

set fit quiet
fit f(x) INPUT_FILE using 1:2 via a,b

#Printar para o arquivo values o valor de f(2^32)
#f32=2**32
#set print "/home/weuler/ufu/ter/aa/final/values" append
#print OUTPUT_FILE
#print f(f32)

set label 1 sprintf("f(x) = %.12fxlog(x) + %.12f",a,b) at graph 0.05,0.8 font "arialbd,11"

set output OUTPUT_FILE

plot f(x) title 'f(x)', INPUT_FILE using 1:2 with linespoints lt 3 lw 3 pt 3 title 'Measures'
