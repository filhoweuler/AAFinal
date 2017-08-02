#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000000000
#define BILLION 1000000000LL
#define MAX_N 2244

long long m[MAX_N][MAX_N], s[MAX_N][MAX_N];
long long n; //number of matrixes
long long p[MAX_N];

void solve() {	
	for (long long i=1; i<=n;i++) {
		m[i][i] = 0;
	}
	for (int l=2;l<=n;l++) {
		for (int i=1;i<=(n-l+1);i++) {
			int j = i + l - 1;
			m[i][j] = INF;
			for (int k=i; k<=j-1;k++) {
				long long q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
				if (q < m[i][j]) {
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
}
int main () {
	struct timespec start, stop;

	scanf("%lld",&n);
	n--;
	for (int i=0;i<n+1;i++) {
		scanf("%lld",&p[i]); //scan n+1 index cuz mat i has dimensions on index i and i-1
	}
	clock_gettime( CLOCK_REALTIME, &start);
	solve();
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
