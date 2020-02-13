#include <iostream>
#include <cstring>

using namespace std;

// command line args
// inputs to our program
// main() is overloaded to accept them
int main(int argc, char * argv[]) {
	// argc is the size of the array argv
	cout << argc << endl;
	cout << argv[0] << endl;
	
	// write a for loop to iterate over each arg
	// a C-string is a null terminated char array
	// \0 is the null terminator
	// example: seven
	// 0 1 2 3 4 5
	// s e v e n \0
	// loop through the args and print them out as C++ strings
	int i;
	for (i = 0; i < argc; i++) {
		string argString = argv[i]; // assign the C-string at index i to a C++ string
		cout << argString << endl;
	}
	// #include <cstring> library with functions for working with C-strings
	char myCString[] = "seven";
	cout << strlen(myCString) << endl;
	cout << sizeof(myCString) << endl;
	// strcat() concatenate +
	// strcmp() compare < <= == 

	return 0;
}
