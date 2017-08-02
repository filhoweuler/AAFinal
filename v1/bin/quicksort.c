#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int partition(int* A, int p, int r);
void quicksort(int* A, int p, int r);

#define BILLION 1000000000LL

int main () {
    struct timespec start, stop;
    int k, i, a[400505];
    
    scanf("%d",&k);
    for (i=0;i<k;i++) {
	scanf("%d",&a[i]);
    }

    clock_gettime( CLOCK_REALTIME, &start);
    quicksort(a, 1, k);
    clock_gettime( CLOCK_REALTIME, &stop);
    
    double time_spent = ( stop.tv_sec - start.tv_sec ) + (double)(stop.tv_nsec - start.tv_nsec )/(double)BILLION;
    
    printf("%.12lf\n",time_spent);
    //~ for (i=0;i<k;i++) printf("%d ",a[i]);

}

int partition(int* A, int p, int r) {
    int x, i, j;

    x = A[r];
    i = p - 1;

    for (j = p; j <= r-1; j++) {
        if (A[j] <= x) {
            i++;
            int aux;
            aux = A[j];
            A[j] = A[i];
            A[i] = aux;
        }
    }

    int aux;
    aux = A[i+1];
    A[i+1] = A[r];
    A[r] = aux;

    return i+1;
}

void quicksort(int* A, int p, int r) {
    if (p < r) {
        int q;

        q = partition(A, p, r);
        quicksort(A, p, q-1);
        quicksort(A, q+1, r);
    }
}
