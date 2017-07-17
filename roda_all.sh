#!/bin/bash
	
	APP_DIR=${PWD}
	
	while read p; do
		echo "Running $p ..."
		$APP_DIR/bin/roda_graphs.sh $p
	done < $APP_DIR/res/algorithms
