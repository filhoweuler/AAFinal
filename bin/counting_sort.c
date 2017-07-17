#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define BILLION 1000000000LL

void counting_sort(int *A, int *B, int n, int k);


int main()
{
	struct timespec start, stop;
    int A[17222], B[17222], i, k, n;

    scanf("%d", &n);
    k = n + 5;
    for(i=0; i<n; i++){
        scanf("%d",&A[i]);
    }
    clock_gettime( CLOCK_REALTIME, &start);
    counting_sort(A,B,n,k);
    clock_gettime( CLOCK_REALTIME, &stop);

    double time_spent = ( stop.tv_sec - start.tv_sec ) + (double)(stop.tv_nsec - start.tv_nsec )/(double)BILLION;

    printf("%.12f\n",time_spent);
    return 0;
}


void counting_sort(int *A, int *B, int n, int k){
	int i, C[k], j;

    memset(C, 0, sizeof C);

    for(j=0; j<n; j++){
        C[A[j]]++;;
    }
	for(i=1; i<k; i++){
        C[i] += C[i-1];
	}

	for(j=(n-1); j>=0; j--) {
		B[C[A[j]]-1] = A[j];
		C[A[j]]--;
	}

	for(i=0; i<n; i++){
        A[i] = B[i];
	}
}
