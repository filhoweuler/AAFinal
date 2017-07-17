set term png size 350,262
f(x) = a * x**2 + b * x + c

fit f(x) INPUT_FILE via a,b,c

set output OUTPUT_FILE

plot f(x), INPUT_FILE with lines
