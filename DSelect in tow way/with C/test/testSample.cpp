#include "../src/DSelect.h"
#include <iostream>
#include <time.h>
#include "I.cpp"
#include <cstdlib>
using namespace std;

int main(){
	int	i, n = 10;

	DSelect<I>* select;
	select = new DSelect<I>();

	I	A[n] = {1, 10, 3, 4, 8, 9, 2, 6, 5, 7};
	int	Counts[n] = {110, 170, 220, 320, 420, 520, 620, 720, 820, 920};
	srand((unsigned int)time(NULL));
	
	cout << "The Array:\n";
	for (i = 0; i < n; i++){
		// A[i] = rand();
		cout << A[i] << "\t";
	}

	cout << endl << "First Pivot" << ": " << select->choosePivot(A, 0, n-1) << "\t<- Answer is 4";

	cout << "\noutput:\n";
	for (i = 1; i <= n; i++){
		cout << i << ": " << select->select(A, 0, n-1, i) << endl;
		cout << I::counter << "\tless than " << Counts[i-1] << endl << endl;
	}
	
	// delete[] A;
	delete select;

	return 0;
}
