#include <iostream>
#include <omp.h>

using namespace std;

int main(int argc, char** argv){

	int sum = 0;
	int i;
	clock_t start = clock();
	int loop_size = 1000000;

//How not to do it. the atomic statement serializes the whole parallel region
	#pragma omp parallel for
	for (i=0; i<loop_size; i++){
		#pragma omp atomic
		sum += i;
	}

	cout << "Sum: " << sum << endl;
	cout << "Needed " << (clock() -start)/ (double) CLOCKS_PER_SEC * 1000 << " msec" << endl;

	sum = 0;
	start = clock();
//Here, each thread calculates the sum of its for-loop part, and afterwards the threads' sums are reduced
	#pragma omp parallel for reduction(+:sum)
	for (i=0; i<loop_size; i++){
		sum += i;
	}

	cout << "Sum: " << sum << endl;
	cout << "Needed " << (clock() -start)/ (double) CLOCKS_PER_SEC * 1000 << " msec" << endl;

	return 0;
}