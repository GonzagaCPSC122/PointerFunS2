#include <iostream>

using namespace std;

void divide(int num, int den, int * res, int * rem);
void printArray(int * arr, int size);

int main() {
	int i = 3, j = 5, k;
	int * p = &i, * q = &j, * r;
	r = &k;
	*r = *p * *q;

	cout << i << " " << j << " " << k << " " << endl;
	cout << *p << " " << *q << " " << *r << " " << endl;
	cout << &i << " " << &j << " " << &k << " " << endl;
	cout << p << " " << q << " " << r << " " << endl;

	// recall: a pointer is a variable that stores as its contents
	// the memory address of another variable
	// the many uses of the *
	// 1) multiplication operator
	// e.g. 3 * x;
	// 2) pointer type
	// e.g. int * ptr = NULL;
	// 3) unary indirection operator
	// e.g. *ptr = 7;
	// AKA "the contents of what ptr points to"
	// AKA "follow the pointer"
	// AKA "dereference the pointer"
	
	// the two uses of the &
	// 1) reference variable
	// e.g. int & xRef
	// 2) address of operator
	// e.g. int * ptr = &x;
	
	// OUTPUT PARAMETERS
	// you can only return one value from a function via the 
	// return statement 
	// with pass by reference we can have "output parameters"
	// which are parameters that modify memory of the calling
	// code to return "multiple values"
	// we can use pointers for output parameters
	// example
	int result, remainder;
	divide(13, 11, &result, &remainder);
	cout << "result: " << result << " remainder: " << remainder << endl;
	
	// POINTER ARITHMETIC AND POINTER NOTATION
	// recall: arrays are pass by reference... but we don't 
	// use an & on the parameter type... why??
	// arrays are pointers... so we are passing in 
	// the mem address of the first element of the array
	// (the mem address is copied into a parameter)
	int nums[] = {3, 7, 4, 9};
	int size = 4;
	printArray(nums, size);

	return 0;
}

void printArray(int * arr, int size) {
	int i;
	for (i = 0; i < size; i++) {
		//cout << arr[i] << " "; // array notation
		cout << *(arr + i) << " "; // pointer notation
		// i is an offset that adds the number of memory
		// cells... array of ints, each memory cell is an
		// int, which is 4 bytes
	}
	cout << endl;
}

void divide(int num, int den, int * res, int * rem) {
	*res = num / den; // int div
	// "the contents of what res points to is assigned
	// num divided by den
	*rem = num % den; // mod
}
