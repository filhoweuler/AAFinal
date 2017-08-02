#include <bits/stdc++.h>

using namespace std;

int isDouble;
int isString;

int sToInt(string s) {
	int nm = 0;
	for (int i=0;i<(int)s.size();i++) {
		nm *= 10;
		nm += s[i] - '0';
	}
	return nm;
}

void getAscendent(int op, int k);

void getDescendent(int op, int k);

void getRandom(int k);

void getStrings(int k);

int main (int argc, char *argv[]) {
	srand(time(NULL));
	isDouble = 0;
	isString = 0;
	string op1, op2, op3, op4;
	op1 = argv[1];// Ordenado, nao ordenado ou aleatorio
	op2 = argv[2];//1-6 indicando o tipo do vetor
	op3 = argv[3];//k variando de 3 a 13 indicando o tamanho do vetor
	op4 = argv[4];//0 - int 1 - double 2 - strings
	
	int o1, o2, o3, o4;	
	o1 = sToInt(op1);
	o2 = sToInt(op2);
	o3 = sToInt(op3);
	o4 = sToInt(op4);
	
	if (o4 == 1) isDouble = 1;
	
	if (o4 == 2) {
		getStrings(o3);
		return 0;
	}
	
	switch (o1) {
		case(1):
			getAscendent(o2, o3);
			break;
		case(2):
			getDescendent(o2, o3);
			break;
		case(3):
			getRandom(o3);
			break;
		default:
			fprintf(stderr, "Invalid parameters\n");
			exit(1);
	}
}

void getAscendent(int op, int k) {
	random_device rd; // obtain a random number from hardware
    mt19937 eng(rd()); // seed the generator
	
	k = pow(2, k);
	k++;
	
	printf("%d ", k);
	
	vector<int> idx;
	for (int i=0;i<k;i++) idx.push_back(i);
	vector<double> idxx;	
	for (int i=0;i<k;i++) {
		idxx.push_back( (double)rand() / (double)RAND_MAX);
	}	
	sort(idxx.begin(), idxx.end());	
	switch(op) {
		case 1:
			break; 
		case 2: {
			int nt = k/10;
			uniform_int_distribution<> distr(nt, k-1);
			for (int i=0;i<nt;i++) {
				int nid = distr(eng);
				//int side
				int ax = idx[nid];
				idx[nid] = idx[i];
				idx[i] = ax;
				
				//double side
				double axx = idxx[nid];
				idxx[nid] = idxx[i];
				idxx[i] = axx;
			}
		}
			break;
		case 3: {
			int nt = k/5;
			uniform_int_distribution<> distr(nt, k-1);
			for (int i=0;i<nt;i++) {
				int nid = distr(eng);
				int ax = idx[nid];
				idx[nid] = idx[i];
				idx[i] = ax;
				
				//double side
				double axx = idxx[nid];
				idxx[nid] = idxx[i];
				idxx[i] = axx;
			}
		}
			break;
		case 4: {
			int nt = (k*3)/10;
			uniform_int_distribution<> distr(nt, k-1);
			for (int i=0;i<nt;i++) {
				int nid = distr(eng);
				int ax = idx[nid];
				idx[nid] = idx[i];
				idx[i] = ax;
				
				//double side
				double axx = idxx[nid];
				idxx[nid] = idxx[i];
				idxx[i] = axx;
			}
		}
			break;
		case 5: {
			int nt = (k*4)/10;
			uniform_int_distribution<> distr(nt, k-1);
			for (int i=0;i<nt;i++) {
				int nid = distr(eng);
				
				//the int side
				int ax = idx[nid];
				idx[nid] = idx[i];
				idx[i] = ax;
				
				//double side
				double axx = idxx[nid];
				idxx[nid] = idxx[i];
				idxx[i] = axx;
			}
		}
			break;
	}
	
	
	if (isDouble == 0) {
		for (int i=0;i<k;i++) printf("%d ",idx[i]);
		printf("\n");
	} else {
		for (int i=0;i<k;i++) printf("%f ",idxx[i]);
		printf("\n");
	}
}

void getDescendent(int op, int k) {
	random_device rd; // obtain a random number from hardware
    mt19937 eng(rd()); // seed the generator
	
	k = pow(2, k);
	k++;
	
	printf("%d ", k);
	
	vector<int> idx;
	for (int i=k;i>=1;i--) idx.push_back(i);
	
	vector<double> idxx;	
	for (int i=0;i<k;i++) {
		idxx.push_back( (double)rand() / (double)RAND_MAX);
	}	
	sort(idxx.begin(), idxx.end());	
	
	switch(op) {
		case 1:
			break;
		case 2: {
			int nt = k/10;
			uniform_int_distribution<> distr(nt, k-1);
			for (int i=0;i<nt;i++) {
				int nid = distr(eng);
				int ax = idx[nid];
				idx[nid] = idx[i];
				idx[i] = ax;
				
				//double side
				double axx = idxx[nid];
				idxx[nid] = idxx[i];
				idxx[i] = axx;
			}
		}
			break;
		case 3: {
			int nt = k/5;
			uniform_int_distribution<> distr(nt, k-1);
			for (int i=0;i<nt;i++) {
				int nid = distr(eng);
				int ax = idx[nid];
				idx[nid] = idx[i];
				idx[i] = ax;
				
				//double side
				double axx = idxx[nid];
				idxx[nid] = idxx[i];
				idxx[i] = axx;
			}
		}
			break;
		case 4: {
			int nt = (k*3)/10;
			uniform_int_distribution<> distr(nt, k-1);
			for (int i=0;i<nt;i++) {
				int nid = distr(eng);
				int ax = idx[nid];
				idx[nid] = idx[i];
				idx[i] = ax;
				
				//double side
				double axx = idxx[nid];
				idxx[nid] = idxx[i];
				idxx[i] = axx;
			}
		}
			break;
		case 5: {
			int nt = (k*4)/10;
			uniform_int_distribution<> distr(nt, k-1);
			for (int i=0;i<nt;i++) {
				int nid = distr(eng);
				int ax = idx[nid];
				idx[nid] = idx[i];
				idx[i] = ax;
				
				//double side
				double axx = idxx[nid];
				idxx[nid] = idxx[i];
				idxx[i] = axx;
			}
		}
			break;
	}
	
	if (isDouble == 0) {
		for (int i=0;i<k;i++) printf("%d ",idx[i]);
		printf("\n");
	} else {
		for (int i=0;i<k;i++) printf("%f ",idxx[i]);
		printf("\n");
	}
}

void getRandom(int k) {
	k = pow(2, k);
	k++;
	printf("%d ", k);
	if (isDouble == 0) {	
		random_device rd; // obtain a random number from hardware
		mt19937 eng(rd()); // seed the generator
		uniform_int_distribution<> distr(0, k);
		for (int i=0;i<k;i++) {
			printf("%d ", distr(eng));
		}
		printf("\n");
	} else {
		for (int i=0;i<k;i++) {
			printf("%f ", (double)rand() / (double)RAND_MAX);
		}
		printf("\n");
	}
}

void getStrings(int k) {
	k = pow(2, k);
	random_device rd; // obtain a random number from hardware
	mt19937 eng(rd()); // seed the generator
	uniform_int_distribution<> distr(0, 25);
	for (int i=0;i<k;i++) {
		printf("%c", 'a' + distr(eng));
	}
	printf("\n");
	for (int i=0;i<k;i++) {
		printf("%c", 'a' + distr(eng));
	}
	printf("\n");	
}

