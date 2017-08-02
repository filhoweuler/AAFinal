#include <bits/stdc++.h>

using namespace std;

#define MAX_N 17444
#define BILLION 1000000000LL

int A[MAX_N], n, k;

random_device rd; // obtain a random number from hardware
mt19937 eng(rd()); // seed the generator
uniform_int_distribution<> distr(0, MAX_N);

int partition(int p, int r) {
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

int randomized_partition(int p, int r) {
	int i = distr(eng);
	i = (i/MAX_N)*(r - p + 1) + p;
	
	
	int ax = A[i];
	A[i] = A[r];
	A[r] = ax;
	
	return partition(p, r);
}

int randomized_select(int p, int r, int i) {
	if (p == r) return A[p];
	
	int q = randomized_partition(p, r);
	int k = q - p + 1;
	
	if (i == k) return A[q];
	else if (i < k) {
		return randomized_select(p, q-1, i);
	} else {
		return randomized_select(q+1, r, i-k);
	}
}

int main () {	
	struct timespec start, stop;
	scanf("%d",&n);
	for (int i=0;i<n-1;i++) {
		scanf("%d",&A[i]);
	}
	scanf("%d",&k);
	if (k == n) k = n/2;
	
	clock_gettime( CLOCK_REALTIME, &start);
	randomized_select(1,n-1, k);
	clock_gettime( CLOCK_REALTIME, &stop);
	
	double time_spent = ( stop.tv_sec - start.tv_sec ) + (double)(stop.tv_nsec - start.tv_nsec )/(double)BILLION;

    printf("%.12f\n",time_spent);
}
