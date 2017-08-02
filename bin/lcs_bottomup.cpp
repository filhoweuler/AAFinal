#include <bits/stdc++.h>

using namespace std;

#define BILLION 1000000000LL
#define MAX_N 17444

int c[MAX_N][MAX_N];

int main () {
	struct timespec start, stop;
	string x, y;
	getline(cin, x);
	getline(cin, y);
	
	int m = (int)x.size();
	int n = (int)y.size();
	
	for (int i=0;i<=m;i++) {
		c[i][0] = 0;
	}
	for (int j=0;j<=n;j++) {
		c[0][j] = 0;
	}
	
	clock_gettime( CLOCK_REALTIME, &start);
	for (int i=1;i<=m;i++) {
		for (int j=1;j<=n;j++) {
			if (x[i-1] == y[j-1]) {
				c[i][j] = c[i-1][j-1] + 1;
			} else {
				c[i][j] = max(c[i-1][j], c[i][j-1]);
			}
		}
	}
	clock_gettime( CLOCK_REALTIME, &stop);
	
	//printf("%d\n",c[m][n]);
	
	double time_spent = ( stop.tv_sec - start.tv_sec ) + (double)(stop.tv_nsec - start.tv_nsec )/(double)BILLION;

    printf("%.12f\n",time_spent);

}
