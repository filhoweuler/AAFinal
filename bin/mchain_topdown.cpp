#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000000000
#define BILLION 1000000000LL
#define MAX_N 2244

long long m[MAX_N][MAX_N], s[MAX_N][MAX_N];
long long n; //number of matrixes
long long p[MAX_N];

long long solve(int i, int j) {	
	if (i == j) return 0;
	if (m[i][j] < INF) return m[i][j];
	//printf("solving [ %d , %d ]\n",i, j);
	for (int k=i; k<=j-1; k++) {
		long long ans = solve(i, k) + solve(k+1, j) + p[i-1]*p[k]*p[j];
		
		if (ans < m[i][j]) m[i][j] = ans;
	}
	return m[i][j];
}

int main () {
	struct timespec start, stop;
	scanf("%lld",&n);
	n--;
	for (long long i=0;i<n+1;i++) {
		scanf("%lld",&p[i]); //scan n+1 index cuz mat i has dimensions on index i and i-1
	}
	
	for (long long i=1; i<=n;i++) {
		for (long long j=1;j<=n;j++) {
			m[i][j] = INF;
		}
	}
	clock_gettime( CLOCK_REALTIME, &start);
	solve(1, n);
	clock_gettime( CLOCK_REALTIME, &stop);
	
	//~ for (long long i=1;i<=n;i++) {
		//~ for (long long j=1;j<=n;j++) {
			//~ prlong longf("%d\t",m[i][j]);
		//~ }
		//~ prlong longf("\n");
	//~ }
	
	double time_spent = ( stop.tv_sec - start.tv_sec ) + (double)(stop.tv_nsec - start.tv_nsec )/(double)BILLION;

    printf("%.12f\n",time_spent);
}
