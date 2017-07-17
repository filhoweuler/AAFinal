#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void radixsort(int *A, int n);

#define BILLION 1000000000LL

int main() {
	struct timespec start, stop;
	int A[400505], i, n;

	scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d",&A[i]);
    }
    clock_gettime( CLOCK_REALTIME, &start);
    radixsort(A,n);
    clock_gettime( CLOCK_REALTIME, &stop);

    double time_spent = ( stop.tv_sec - start.tv_sec ) + (double)(stop.tv_nsec - start.tv_nsec )/(double)BILLION;

    printf("%.12f\n",time_spent);
    return 0;
}

void radixsort(int *A, int n) {
	int i, exp = 1, maior = 0, bucket[n], temp[n];

	for(i = 0; i < n; i++) {
		if(A[i] > maior) {
			maior = A[i];
		}
	}

	while((maior/exp) > 0) {
		for (i = 0; i < n; i++) {
			bucket[i] = 0;
		}
		for(i = 0; i < n; i++) {
			bucket[(A[i] / exp) % 10]++;
		}
		for(i = 1; i < n; i++) {
			bucket[i] += bucket[i-1];
		}
		for(i = (n - 1); i >= 0; i--) {
			temp[--bucket[(A[i] / exp) % 10]] = A[i];
		}
		for(i = 0; i < n; i++) {
			A[i] = temp[i];
		}
		exp *= 10;
	}
}
