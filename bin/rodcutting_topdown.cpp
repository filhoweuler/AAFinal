#include <bits/stdc++.h>

using namespace std;

#define BILLION 1000000000LL
#define MAX_N 17111

int p[MAX_N];
int dp[MAX_N];
int n;

int solve(int size) {
	if (size == 0) return 0;
	if (dp[size] != -1) return dp[size];
	int ans = 0;
	for (int i=1;i<=size;i++) {
		ans = max(ans, p[i] + solve(size - i));
	}
	dp[size] = ans;
	return ans;
}

int main () {
	struct timespec start, stop;
	scanf("%d",&n);
	memset(dp, -1, sizeof dp);
	for (int i=1;i<=n;i++) {
		scanf("%d",&p[i]);
	}
	clock_gettime( CLOCK_REALTIME, &start);
	solve(n);
	clock_gettime( CLOCK_REALTIME, &stop);
	
	//for (int i=1;i<=n;i++) {
	//	printf("%d ",dp[i]);
	//}
	
	double time_spent = ( stop.tv_sec - start.tv_sec ) + (double)(stop.tv_nsec - start.tv_nsec )/(double)BILLION;

     printf("%.12f\n",time_spent);
}
