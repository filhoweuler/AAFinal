#!/bin/bash
	#1 parametro: nome do arquivo c com o metodo de ordenacao	

	run_test() {
		#1 parametro: 1 - Crescente, 2 - Decrescente 3 - Aleatorio
		#2 parametro: 1 - Ordenado, 2 - 10%, 3 - 20%, 4 - 30%, 5 - 40%
		#3 parametro: nome do outfile
		#4 parametro: o plotter a ser usado (quadratic_plotter, log_plotter e linear_plotter)
		cres=$1
		ord=$2
		OUT_NAME=$3
		PLOTTER_TYPE=$4
		echo "Running $OUT_NAME ..."
		for ((k=3;k<=14;k++)); do
			echo "k = $k ..."
			val1=$($APP_DIR/bin/vector_create $cres $ord $k $VAR_TYPE | $APP_DIR/bin/$SORT_TYPE)
			val2=$($APP_DIR/bin/vector_create $cres $ord $k $VAR_TYPE | $APP_DIR/bin/$SORT_TYPE)
			val3=$($APP_DIR/bin/vector_create $cres $ord $k $VAR_TYPE | $APP_DIR/bin/$SORT_TYPE)
			val4=$($APP_DIR/bin/vector_create $cres $ord $k $VAR_TYPE | $APP_DIR/bin/$SORT_TYPE)
			val5=$($APP_DIR/bin/vector_create $cres $ord $k $VAR_TYPE | $APP_DIR/bin/$SORT_TYPE)
			avg=$(echo $val1 + $val2 + $val3 + $val4 + $val5 | bc)		
			avg=$(echo "scale=7; $avg/5.0" | bc)
			#avg=$"0"$avg
			#echo $k $val1 $val2 $val3 $avg
			pot=$(echo "2^$k" | bc)
			#echo $val1 + $val2 + $val3 + $val4 + $val5 === $avg
			echo $pot $avg >> $MY_HOME/data.tmp		
		done
		#cat $MY_HOME/data.tmp
		echo "Plotting ... "
		
		
		gnuplot -c $APP_DIR/bin/$PLOTTER_TYPE.gp "$MY_HOME/data.tmp" "$MY_HOME/$PREFIX-$OUT_NAME.png"		
		
		cat $MY_HOME/data.tmp > $MY_HOME/$OUT_NAME.dat
		rm $MY_HOME/data.tmp
	}
	
	APP_DIR=$"$HOME/ufu/ter/aa/final"
	SORT_TYPE=$1
	PREFIX=$(echo $SORT_TYPE | cut -c1-3) 
	MY_HOME=$"$APP_DIR/out/$SORT_TYPE"
	mkdir -p $MY_HOME

	if [ "$PREFIX" == "buc" ]; then
		VAR_TYPE=1
	else	
		VAR_TYPE=0
	fi

	if [ "$SORT_TYPE" == "quicksort" ]; then
		run_test 1 1 cres-ord quadratic_plotter
		run_test 1 2 cres-10 log_plotter
		run_test 1 3 cres-20 log_plotter
		run_test 1 4 cres-30 log_plotter
		run_test 1 5 cres-40 log_plotter
		run_test 2 1 decres-ord quadratic_plotter
		run_test 2 2 decres-10 log_plotter
		run_test 2 3 decres-20 log_plotter
		run_test 2 4 decres-30 log_plotter
		run_test 2 5 decres-40 log_plotter
		run_test 3 1 random log_plotter
	fi

	if [ "$SORT_TYPE" == "insertion_sort" ]; then
		run_test 1 1 cres-ord linear_plotter
		run_test 1 2 cres-10 quadratic_plotter
		run_test 1 3 cres-20 quadratic_plotter
		run_test 1 4 cres-30 quadratic_plotter
		run_test 1 5 cres-40 quadratic_plotter
		run_test 2 1 decres-ord quadratic_plotter
		run_test 2 2 decres-10 quadratic_plotter
		run_test 2 3 decres-20 quadratic_plotter
		run_test 2 4 decres-30 quadratic_plotter
		run_test 2 5 decres-40 quadratic_plotter
		run_test 3 1 random quadratic_plotter
	fi

	if [ "$SORT_TYPE" == "merge_sort" ]; then
		run_test 1 1 cres-ord log_plotter
		run_test 1 2 cres-10 log_plotter
		run_test 1 3 cres-20 log_plotter
		run_test 1 4 cres-30 log_plotter
		run_test 1 5 cres-40 log_plotter
		run_test 2 1 decres-ord log_plotter
		run_test 2 2 decres-10 log_plotter
		run_test 2 3 decres-20 log_plotter
		run_test 2 4 decres-30 log_plotter
		run_test 2 5 decres-40 log_plotter
		run_test 3 1 random log_plotter
	fi

	if [ "$SORT_TYPE" == "heap_sort" ]; then
		run_test 1 1 cres-ord log_plotter
		run_test 1 2 cres-10 log_plotter
		run_test 1 3 cres-20 log_plotter
		run_test 1 4 cres-30 log_plotter
		run_test 1 5 cres-40 log_plotter
		run_test 2 1 decres-ord log_plotter
		run_test 2 2 decres-10 log_plotter
		run_test 2 3 decres-20 log_plotter
		run_test 2 4 decres-30 log_plotter
		run_test 2 5 decres-40 log_plotter
		run_test 3 1 random log_plotter
	fi

	if [ "$SORT_TYPE" == "counting_sort" ]; then
		run_test 1 1 cres-ord linear_plotter
		run_test 1 2 cres-10 linear_plotter
		run_test 1 3 cres-20 linear_plotter
		run_test 1 4 cres-30 linear_plotter
		run_test 1 5 cres-40 linear_plotter
		run_test 2 1 decres-ord linear_plotter
		run_test 2 2 decres-10 linear_plotter
		run_test 2 3 decres-20 linear_plotter
		run_test 2 4 decres-30 linear_plotter
		run_test 2 5 decres-40 linear_plotter
		run_test 3 1 random linear_plotter
	fi

	if [ "$SORT_TYPE" == "radix_sort" ]; then
		run_test 1 1 cres-ord linear_plotter
		run_test 1 2 cres-10 linear_plotter
		run_test 1 3 cres-20 linear_plotter
		run_test 1 4 cres-30 linear_plotter
		run_test 1 5 cres-40 linear_plotter
		run_test 2 1 decres-ord linear_plotter
		run_test 2 2 decres-10 linear_plotter
		run_test 2 3 decres-20 linear_plotter
		run_test 2 4 decres-30 linear_plotter
		run_test 2 5 decres-40 linear_plotter
		run_test 3 1 random linear_plotter
	fi

	if [ "$SORT_TYPE" == "bucket_sort" ]; then
		run_test 1 1 cres-ord linear_plotter
		run_test 1 2 cres-10 linear_plotter
		run_test 1 3 cres-20 linear_plotter
		run_test 1 4 cres-30 linear_plotter
		run_test 1 5 cres-40 linear_plotter
		run_test 2 1 decres-ord linear_plotter
		run_test 2 2 decres-10 linear_plotter
		run_test 2 3 decres-20 linear_plotter
		run_test 2 4 decres-30 linear_plotter
		run_test 2 5 decres-40 linear_plotter
		run_test 3 1 random linear_plotter
	fi
	
		
	
