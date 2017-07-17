#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void insertion_sort(int* v, int n);
#define BILLION 1000000000LL

int main () {
    struct timespec start, stop;
    int k, i, a[400505];
    
    scanf("%d",&k);
    for (i=0;i<k;i++) {
	scanf("%d",&a[i]);
    }

    clock_gettime( CLOCK_REALTIME, &start);
    insertion_sort(a, k);
    clock_gettime( CLOCK_REALTIME, &stop);
    
    double time_spent = ( stop.tv_sec - start.tv_sec ) + (double)(stop.tv_nsec - start.tv_nsec )/(double)BILLION;
    
    printf("%.12lf\n",time_spent);
    //~ for (i=0;i<k;i++) printf("%d ",a[i]);
}

void insertion_sort(int* v, int n) {
    int j, i, chave, auxiliar;

    for (j=1; j<n; j++) {
        chave = v[j];
        i = j-1;
        while (i >= 0 && v[i] > chave) {
            v[i+1] = v[i];
            i--;
        }

        v[i+1] = chave;
    }
}
