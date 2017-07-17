#include <bits/stdc++.h>

using namespace std;

#define BILLION 1000000000LL

void bucketsort(float arr[], int n);

int main() {
	struct timespec start, stop;
	int i, n;
	float A[400505];

	scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%f",&A[i]);
    }
    clock_gettime( CLOCK_REALTIME, &start);
    bucketsort(A,n);
    clock_gettime( CLOCK_REALTIME, &stop);

    double time_spent = ( stop.tv_sec - start.tv_sec ) + (double)(stop.tv_nsec - start.tv_nsec )/(double)BILLION;
    
    //~ for (int i=0;i<n;i++) {
		//~ cout << A[i] << " ";
	//~ }

    printf("%.12f\n",time_spent);
}

void bucketsort(float arr[], int n)
{
    vector<float> b[n];
    
    for (int i=0; i<n; i++)
    {
       int bi = n * (arr[i]);
       b[bi].push_back(arr[i]);
    }
 
    for (int i=0; i<n; i++)
       sort(b[i].begin(), b[i].end());
 
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < (int)b[i].size(); j++)
          arr[index++] = b[i][j];
}
