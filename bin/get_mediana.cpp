#include <bits/stdc++.h>

using namespace std;


int main () {
	int n;
	cin >> n;
	vector<double> mm;
	double ax;
	for (int i=0;i<n;i++) {
		cin >> ax;
		mm.push_back(ax);
	}
	sort(mm.begin(), mm.end());
	if (n % 2 == 1) cout << mm[n/2] << endl;
	else cout << setprecision(12) << (mm[n/2] + mm[n/2 - 1])/2.0 << endl; 	
}
