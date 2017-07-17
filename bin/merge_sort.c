#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge_sort(int* A, int l, int r);
void merge(int* A, int l, int mid, int r);

#define BILLION 1000000000LL

int main () {
    struct timespec start, stop;
    int k, i, a[400505];
    
    scanf("%d",&k);
    for (i=0;i<k;i++) {
	scanf("%d",&a[i]);
    }

    clock_gettime( CLOCK_REALTIME, &start);
    merge_sort(a, 0, k);
    clock_gettime( CLOCK_REALTIME, &stop);
    
    double time_spent = ( stop.tv_sec - start.tv_sec ) + (double)(stop.tv_nsec - start.tv_nsec )/(double)BILLION;
    
    printf("%.12lf\n",time_spent);
    //~ for (i=0;i<k;i++) printf("%d ",a[i]);

}

void merge (int* A, int l, int mid, int r) {

    int n1, n2, i, j, k;

    n1 = mid - l + 1;
    n2 = r - mid;

    int L[n1+1], R[n2+1];

    for (i = 0; i < n1; i++) {
        L[i] = A[l + i];
    }

    for (j = 0; j < n2; j++) {
        R[j] = A[mid + j + 1];
    }

    i = 0;
    j = 0;

    L[n1] = 1e8;
    R[n2] = 1e8;

    for (k = l; k <= r; k++) {
        if (L[i] <=  R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

void merge_sort(int* A, int l, int r) {
    if (l >= r) return;

    int mid;

    mid = (l+r)/2;

    merge_sort(A, l, mid);
    merge_sort(A, mid+1, r);
    merge(A, l, mid, r);

}

