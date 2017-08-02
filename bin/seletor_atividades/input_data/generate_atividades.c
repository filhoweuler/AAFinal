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
		printf("./gen_atividades k duracao_maxima inicio_maximo");
		exit(0);
	}

	int k = atoi(argv[1]);
	int DUR_MAX = atoi(argv[2]); // duracao maxima de uma tarefa
	int INICIO_MAX = atoi(argv[2]); // tempo maximo de inicio de uma tarefa
	int N = powerTwo(k);

	char filename[20];
	int i;
	
	sprintf(filename, "2a%d_atividades.txt", k);
	FILE *fp = fopen(filename, "w");

	srand(time(NULL));
	int inicio, termino;
	for(i = 0; i < N; i++){
		inicio = rand() % INICIO_MAX + 1;
		termino = inicio + (rand() % DUR_MAX + 1);
		fprintf(fp, "%d %d\n", inicio, termino);
	}
	exit(0);
}
