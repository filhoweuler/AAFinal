#!/bin/bash
	#1 parametro: nome do arquivo c com o metodo de ordenacao	

	run_test() {
		#1 parametro: nome do outfile
		#2 parametro: o plotter a ser usado (quadratic_plotter, log_plotter e linear_plotter)
		#3 parametro: max k possivel //para mchain usar kmax = 10, para rodcutting kmax = 14
		#4 parametro: vector type: 0 para inteiros e 2 para strings
		OUT_NAME=$1
		PLOTTER_TYPE=$2
		KMAX=$3
		TYPE=$4
		echo "Running $OUT_NAME ..."
		for ((k=3;k<=$KMAX;k++)); do
			echo "k = $k ..."
			val1=$($APP_DIR/bin/vector_create 3 1 $k $TYPE | $APP_DIR/bin/$ALGO_TYPE)
			val2=$($APP_DIR/bin/vector_create 3 1 $k $TYPE | $APP_DIR/bin/$ALGO_TYPE)
			val3=$($APP_DIR/bin/vector_create 3 1 $k $TYPE | $APP_DIR/bin/$ALGO_TYPE)
			val4=$($APP_DIR/bin/vector_create 3 1 $k $TYPE | $APP_DIR/bin/$ALGO_TYPE)
			val5=$($APP_DIR/bin/vector_create 3 1 $k $TYPE | $APP_DIR/bin/$ALGO_TYPE)
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
		
		gnuplot -c $APP_DIR/bin/$PLOTTER_TYPE.gp "$MY_HOME/data.tmp" "$MY_HOME/$OUT_NAME.png"		
		
		cat $MY_HOME/data.tmp > $MY_HOME/$OUT_NAME.dat
		rm $MY_HOME/data.tmp
	}
	
	APP_DIR=$"$HOME/ufu/ter/aa/final"
	ALGO_TYPE=$1
	MY_HOME=$"$APP_DIR/out/$ALGO_TYPE"
	mkdir -p $MY_HOME

	if [ "$ALGO_TYPE" == "rodcutting_topdown" ]; then
		run_test rodcutting_topdown quadratic_plotter 14 0
	fi
	
	if [ "$ALGO_TYPE" == "rodcutting_bottomup" ]; then
		run_test rodcutting_bottomup quadratic_plotter 14 0
	fi
	
	if [ "$ALGO_TYPE" == "mchain_bottomup" ]; then
		run_test mchain_bottomup cubic_plotter 10 0
	fi
	
	if [ "$ALGO_TYPE" == "mchain_topdown" ]; then
		run_test mchain_topdown cubic_plotter 10 0
	fi
	
	if [ "$ALGO_TYPE" == "lcs_bottomup" ]; then
		run_test lcs_bottomup quadratic_plotter 14 2
	fi
	
	if [ "$ALGO_TYPE" == "nthorder" ]; then
		run_test nthorder linear_plotter 14 0
	fi
	
