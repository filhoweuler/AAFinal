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
	
	int PESO;
	int pesoMochila;
	float valorMochila;
	
	int *quantidades;
	int *valores;
	float *valores_unitarios;
	int *itensId;
	float *porcentagemAdicionada;
	
	char filename[25];
	int i;
	FILE *fileData = fopen("mochila_fracionaria.dat", "w");
	for(k = 1; k <= 16; k++){
		N = powerTwo(k);
		PESO = N * 5;
		
		quantidades = (int*)malloc(N*sizeof(int));
		valores = (int*)malloc(N*sizeof(int));
		valores_unitarios = (float*)malloc(N*sizeof(float));
		itensId = (int*)malloc(N*sizeof(int));
		porcentagemAdicionada = (float*)malloc(N*sizeof(float));
		
		sprintf(filename, "2a%d_itens_mochila.txt", k);
		FILE *fp = fopen(filename, "r");
		for(i = 0; i < N; i++){
			fscanf(fp, "%d %d\n", &valores[i], &quantidades[i]);
		}
		fclose(fp);
		
		for(i = 0; i < N; i++){
			itensId[i] = i;
			porcentagemAdicionada[i] = 0.0;
			valores_unitarios[i] = valores[i] / quantidades[i];
		}
		// ordenar por valor unitario
		int key, keyId, j;
   		for (i = 1; i < N; i++){
        	key = valores_unitarios[i];
        	keyId = itensId[i];
        	j = i-1;
 
        	while (j >= 0 && valores_unitarios[j] > key){
            	valores_unitarios[j+1] = valores_unitarios[j];
            	itensId[j+1] = itensId[j];
            	j = j-1;
        	}
    		valores_unitarios[j+1] = key;
        	itensId[j+1] = keyId;
   		}

		int iterations = N_TESTES;
		double sum_time_spent = 0.0;
	   	for(iterations; iterations > 0; iterations--){
	   	
		    struct timespec start, stop;
		    clock_gettime( CLOCK_REALTIME, &start);  
		    
			i = N-1;
			pesoMochila = 0;
			valorMochila = 0;
			int cabe;
			float porcentagem;
			while(pesoMochila <= PESO && i >= 0){
				if(pesoMochila + quantidades[itensId[i]] > PESO){
					cabe = PESO - pesoMochila;
					porcentagem = (float)cabe / (float)quantidades[itensId[i]];
					porcentagemAdicionada[itensId[i]] = porcentagem;
					pesoMochila += cabe;
					valorMochila += valores[itensId[i]] * cabe;
				}
				else{
					porcentagemAdicionada[itensId[i]] = 1;
					pesoMochila += quantidades[itensId[i]];
					valorMochila += valores[itensId[i]];
				}
				i--;	
			}

		    clock_gettime( CLOCK_REALTIME, &stop);
		    
		    sum_time_spent += ( stop.tv_sec - start.tv_sec ) + (double)(stop.tv_nsec - start.tv_nsec )/(double)BILLION;
	    }
	    fprintf(fileData, "%d %.12lf\n", N, sum_time_spent/N_TESTES);
	    free(valores);
	    free(quantidades);
	    free(valores_unitarios);
	    free(porcentagemAdicionada);
	}

	fclose(fileData);
/*
    for (i=0; i < N; i++)
        printf("Item %d: - QTY: %d - Val: %d VU: %lf - Porc: %f\n", i, quantidades[i], valores[i], valores_unitarios[itensId[i]], porcentagemAdicionada[itensId[i]]);
    printf("\n");
*/
	exit(0);
}

