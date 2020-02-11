#include <iostream>

using namespace std;

void divide(int num, int den, int * res, int * rem);
void printArray(int * arr, int size);
void swapIt(int * xPtr, int * yPtr);
int * createRandomArray(int size);

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

	// warmup
	int x = 5;
	int y = 7;
	swapIt(&x, &y);
	cout << x << " " << y << endl;
	
	// DYNAMIC MEMORY ALLOCATION
	// recall: a local variable is variable declared inside of a function
	// when a function exits, the local variables are deallocated (AKA freed)
	// local variables are stored in an area of memory called the "stack"
	// NEVER return the address of a local variable
	// we can return an address to memory that was allocated in a function so long as it was allocated dynamically (e.g. on the "heap")
	// the heap is another region of memory
	// heap memory is not deacllated when a function exits
	// you (the programmer) has to deallocated when you are done with it
	// use "new" keyword to dyn allocate memory ono the stack
	// the "delete" keyword to free when we are done with it
	// example
	int * randArr = NULL;
	randArr = createRandomArray(10); // 10 random ints the array
	printArray(randArr, 10);
	// note: delete randArry mem when done!!
	// if we forget to free our heap memory we have a "memory leak"
	delete [] randArr; // free AKA deallocate the memory
	randArr = NULL; // good practice
	
	return 0;
}

int * createRandomArray(int size) {
	int i; // statically allocated in stack
	int * arr = new int[size]; // 40 bytes dynamically allocated in heap
	for (i = 0; i < size; i++) {
		*(arr + i) = rand() % size;
	}
	return arr;
}

void swapIt(int * xPtr, int * yPtr) {
	int temp = *xPtr; // 5
	*xPtr = *yPtr; // 7
	*yPtr = temp; // 5
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
