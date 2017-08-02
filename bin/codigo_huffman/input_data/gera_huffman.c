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
	if(argc != 3){
		printf("./gen_huffman k max_freq");
		exit(0);
	}

	int k = atoi(argv[1]);
	int MAX_FREQ = atoi(argv[2]); // frequencia maxima de um caracter
	int N = powerTwo(k);

	char filename[20];
	int i;
	
	sprintf(filename, "2a%d_huffman.txt", k);
	FILE *fp = fopen(filename, "w");

	srand(time(NULL));
	int freq;
	for(i = 0; i < N; i++){
		freq = rand() % MAX_FREQ + 1;
		fprintf(fp, "x %d\n", freq);
	}
	exit(0);
}
