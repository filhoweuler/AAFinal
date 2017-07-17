#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void max_heapify(int *A, int n, int i);

void constroi_max_heap(int *A, int n);

void heap_sort(int *A,int n);

#define BILLION 1000000000LL

int main () {
    struct timespec start, stop;
    int k, i, a[400505];
    
    scanf("%d",&k);
    for (i=0;i<k;i++) {
	scanf("%d",&a[i]);
    }

    clock_gettime( CLOCK_REALTIME, &start);    
    heap_sort(a, k);
    clock_gettime( CLOCK_REALTIME, &stop);
    
    double time_spent = ( stop.tv_sec - start.tv_sec ) + (double)(stop.tv_nsec - start.tv_nsec )/(double)BILLION;
    
    printf("%.12lf\n",time_spent);
    //~ for (i=0;i<k;i++) printf("%d ",a[i]);

}

void max_heapify(int *A, int n, int i) {
    int e, d, maior, menor;
    e = 2*i + 1;
    d = (2*i) + 2;

    if(e<n && A[e]>A[i]){
        maior = e;
    }else{
        maior = i;
    }

    if(d<n && A[d]>A[maior]){
        maior = d;
    }

    if(i != maior){
        int auxiliar;
        auxiliar = A[i];
        A[i] = A[maior];
        A[maior] = auxiliar;
        max_heapify(A,n,maior);
    }
}

void constroi_max_heap(int *A, int n){
    int i;

    for(i=((n/2)-1); i>=0; i--){
        max_heapify(A,n,i);
    }
}

void heap_sort(int *A,int n){
    constroi_max_heap(A,n);
    int m=n;
    int i;

    for(i=n-1; i>=1; i--){
        int auxiliar;
        auxiliar = A[i];
        A[i] = A[0];
        A[0] = auxiliar;
        m--;
        max_heapify(A,m,0);
    }
}
