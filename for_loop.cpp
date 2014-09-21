#include <iostream>
#include <omp.h>

using namespace std;

int main(int argc, char** argv){

	int sum = 0;

	#pragma omp parallel for
	for (int i=0; i<100; i++){
		#pragma omp atomic
		sum += i;
	}

	cout << sum << endl;

	return 0;
}