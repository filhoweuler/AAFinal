#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int powerTwo(int k){
	int result = 1;
	int i;
	for(i = 1; i <= k; i++){
		result *= 2;
	}
	return result;
}


int main(int argc, char *argv[]){
	if(argc != 4){
		printf("./gen_mochila k max_value max_quant");
		exit(0);
	}

	int k = atoi(argv[1]);
	int MAX_VALUE = atoi(argv[2]); // valor maximo de um item
	int MAX_QUANT = atoi(argv[3]); // quantidade maxima de um item
	int N = powerTwo(k);

	char filename[20];
	int i;
	
	sprintf(filename, "2a%d_itens_mochila.txt", k);
	FILE *fp = fopen(filename, "w");

	srand(time(NULL));
	int value, quant;
	for(i = 0; i < N; i++){
		value = rand() % MAX_VALUE + 1;
		quant = rand() % MAX_QUANT + 1;
		fprintf(fp, "%d %d\n", value, quant);
	}
	exit(0);
}
