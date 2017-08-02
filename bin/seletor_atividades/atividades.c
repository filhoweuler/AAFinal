#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BILLION 1000000000LL

int powerTwo(int k){
	int result = 1;
	int i;
	for(i = 1; i <= k; i++){
		result *= 2;
	}
	return result;
}

int main(int argc, char *argv[]){
	
	int N_TESTES = 3;
	int k;
	int N;
	int *startArray;
	int *finishArray;
	char filename[20];
	int i;
	FILE *fileData = fopen("atividades.dat", "w");
	for(k = 1; k <= 16; k++){
		N = powerTwo(k);
		startArray = (int*)malloc(N*sizeof(int));
		finishArray = (int*)malloc(N*sizeof(int));
		sprintf(filename, "input_data/2a%d_atividades.txt", k);
		FILE *fp = fopen(filename, "r");
		for(i = 0; i < N; i++){
			fscanf(fp, "%d %d\n", &startArray[i], &finishArray[i]);
		}
		fclose(fp);
	
		// ordenar por termino
		int key, keyStart, j;
	   	for (i = 1; i < N; i++){
	        key = finishArray[i];
	        keyStart = startArray[i];
	        j = i-1;
	 
	        while (j >= 0 && finishArray[j] > key){
	            finishArray[j+1] = finishArray[j];
	            startArray[j+1] = startArray[j];
	            j = j-1;
	        }
	    	finishArray[j+1] = key;
	        startArray[j+1] = keyStart;
	   	}

		int iterations = 3;
		double sum_time_spent = 0.0;
	   	for(iterations; iterations > 0; iterations--){
			int atividades[N];
			int countAtividades = 0;
			int m;
			int k = 1;

		    struct timespec start, stop;
		    clock_gettime( CLOCK_REALTIME, &start);  

		    atividades[countAtividades++] = 1;
			for(m = 0; m < N; m++){
				if(startArray[m] >= finishArray[k]){
					atividades[countAtividades++] = m;
					k = m;
				}
			}

		    clock_gettime( CLOCK_REALTIME, &stop);
		    
		    sum_time_spent += ( stop.tv_sec - start.tv_sec ) + (double)(stop.tv_nsec - start.tv_nsec )/(double)BILLION;
	    }
	    fprintf(fileData, "%d %.12lf\n", N, sum_time_spent/3);
	    free(startArray);
	    free(finishArray);
	}

	fclose(fileData);

	/*int i;
	printf("\nAtividades: ");
	for(i = 0; i < countAtividades; i++){
		printf("%d ", atividades[i]);
	}*/
	
	exit(0);
}

