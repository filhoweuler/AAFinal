#include <bits/stdc++.h>

using namespace std;

#define BILLION 1000000000LL
#define MAX_N 17111

int p[MAX_N];
int n;

int main () {
	struct timespec start, stop;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		scanf("%d",&p[i]);
	}
	
	int dp[MAX_N];
	memset(dp, -1, sizeof dp);
	dp[0] = 0;
	clock_gettime( CLOCK_REALTIME, &start);
	for (int i=1;i<=n;i++) {
		int ans = -1;
		for (int k=1; k<=i;k++) {
			ans = max(ans , p[k] + dp[i-k]);
		}
		dp[i] = ans;	
	}
	clock_gettime( CLOCK_REALTIME, &stop);
	
	//~ for (int i=1;i<=n;i++) {
		//~ printf("%d ",dp[i]);
	//~ }
	
	double time_spent = ( stop.tv_sec - start.tv_sec ) + (double)(stop.tv_nsec - start.tv_nsec )/(double)BILLION;

    printf("%.12f\n",time_spent);
}
