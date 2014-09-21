#include <iostream>
#include <omp.h>

using namespace std;

int main(int argc, char** argv){

	#pragma omp parallel
	#pragma omp critical
	{
		cout << "Hi, I'm thread " << omp_get_thread_num() << " of " << omp_get_num_threads() << endl;
	}

	return 0;
}