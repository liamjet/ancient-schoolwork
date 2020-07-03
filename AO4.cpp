// Name : Liam Pang-Naylor
// SSID : 1608793
// Assignment #: ASSIGNMENT_4
// Submission Date : 11/12/19
//
// Description of program : This program simulates and runs std::vector functions
//

//NOTE: I recall this code being somewhat broken but it was two semesters ago so I haven't gone through it to find the problem.


#include <iostream>

struct Vector {	// vector struct
	int size = 0;
	int capacity = 0;
	int* data = nullptr;
};//function prototypes																						// Construct a Vector v with a default size 0.
void construct_vector(Vector& v, int size = 0, int initVal = 0);
																						// Destroy Vector v and return memory to the freestore ( heap ).
void destroy_vector(Vector& v);
																						// Returns pointer to the first element in Vector v.
int* data(const Vector& v);
																						// Returns the number of elements in Vector v.
int size(const Vector& v);
																						// Returns a reference to the element at location i in Vector v. ( optional ) Throws exception if out of bounds
int& at(Vector& v, int i) throw (std::string);
																						// Returns a reference to the last element in Vector v ( optional ) Throws exception if Vector is empty
int& back(const Vector& v) throw (std::out_of_range);
																						// Returns the allocated storage for Vector v.
int capacity(const Vector& v);
																						// Erases the elements of Vector v but does not change capacity .
void clear(Vector& v);
																						// If Vector v is empty return true , else false .
bool empty(const Vector& v);
																						// Returns a reference to the first element in the Vector ( optional ) Throws exception if Vector is empty .
int& front(const Vector& v) throw (std::out_of_range);
																						// Deletes the last element of Vector v.
void pop_back(Vector& v);
																						// Add element to the end of the Vector v.
void push_back(Vector& v, int element);
																						// Resize Vector v. For details see provided links
void resize(Vector& v, int newsize, int val);
																						// Increase capacity of Vector v. For details see provided links
void reserve(Vector& v, int new_capacity);
																						// Search for a key in Vector v, return index of key or -1 if not found
int find(Vector& v, int key);int main() {

	Vector a, b, c; // create three vectors

//testing vector a for construct_vector, at, size, capacity, front, back, and destroy_vector
	std::cout << "Vector a, b, c;\n\n";
	std::cout << "construct_vector (a ,5 ,0);" << std::endl;
	construct_vector(a, 5, 0);
	std::cout << "Test construct_vector. Vector a: ";
	for (int i = 0; i < size(a); i++) {
		std::cout << at(a, i) << " ";
	}
	std::cout << "\nSize of a = " << size(a) << std::endl;
	std::cout << "Capacity of a = " << capacity(a) << std::endl;

	at(a, 0) = 10;
	at(a, 3) = 5;
	std::cout << "at(a, 0) = 10;" << std::endl;
	std::cout << "at(a, 3) = 5;" << std::endl;
	std::cout << "a = ";
	for (int i = 0; i < size(a); i++)
		std::cout << at(a, i) << " ";

	int& vFront = front(a);
	std::cout << "\n\nfront (a) = " << vFront << std::endl;
	int& vBack = back(a);
	std::cout << "back (a) = " << vBack << std::endl;

	destroy_vector(a);
	std::cout << "destroy_vector (a);" << std::endl;


//testing vector b for construct_vector, size, capacity, push_back, at, pop_back, clear, empty, find, data, and destroy_vector.
	std::cout << "\nconstruct_vector (b);" << std::endl;
	construct_vector(b, 0, 0);
	std::cout << "Size of b = " << size(b) << ";";
	std::cout << "Capacity of b = " << capacity(b) << std::endl;

	std::cout << "\npush_back(b,0); push_back(b,1);\n" << "push_back(b, 2); push_back(b, 3);\n\n";
	push_back(b, 0); push_back(b, 1);
	push_back(b, 2); push_back(b, 3);	for (int i = 0; i < b.size; i++) {
		std::cout << at(b, i) << " ";
	}
	std::cout << "\nSize of b = " << size(b) << std::endl;
	std::cout << "Capacity of b = " << capacity(b) << std::endl;
	std::cout << "at(b, 1) is " << at(b, 1) << std::endl;

	std::cout << "\nat(b, 1) = 88" << std::endl;
	at(b, 1) = 88;
	std::cout << "b = ";
	for (int i = 0; i < b.size; i++) {
		std::cout << at(b, i) << " ";
	}

	std::cout << "\n\npop_back(b)" << std::endl;
	pop_back(b);
	std::cout << "b = ";
	for (int i = 0; i < b.size; i++) {
		std::cout << at(b, i) << " ";
	}

	std::cout << "\n\npush_back(b,55); push_back(b,75);" << std::endl;
	push_back(b, 55); push_back(b, 75);	std::cout << "b = ";	for (int i = 0; i < b.size; i++) {
		std::cout << at(b, i) << " ";
	}

	std::cout << "\n\nclear(b);" << std::endl;
	clear(b);	std::cout << "Size of b = " << size(b) << std::endl;
	std::cout << "Capacity of b = " << capacity(b) << std::endl;	if (empty(b) == 1)		std::cout << "empty(b) is true" << std::endl;	else		std::cout << "empty(b) is false" << std::endl;	std::cout << "\n\npush_back(b,10); push_back(b,20); push_back(b,30);" << "\npush_back(b, 40); push_back(b, 50); push_back(b, 60);" << std::endl;	push_back(b, 10); push_back(b, 20); push_back(b, 30);
	push_back(b, 40); push_back(b, 50); push_back(b, 60);	std::cout << "\nSize of b = " << size(b) << std::endl;
	std::cout << "Capacity of b = " << capacity(b) << std::endl;	std::cout << "\nint i = find(b, 30) , i = " << find(b, 30) << std::endl;
	std::cout << "int i = find(b, 999) , i = " << find(b, 999) << std::endl;

	std::cout << "\nint* ptr = data(b); " << std::endl;
	int* ptr = data(b);
	for (int i = 0; i < b.size; i++) {
		std::cout << *ptr++ << " ";
	}

	std::cout << "\n\ndestroy_vector(b);" << std::endl;
	destroy_vector(b);
	std::cout << "Size of b = " << size(b) << std::endl;
	std::cout << "Capacity of b = " << capacity(b) << std::endl;


//testing vector c for construct_vector, size, capacity, at, resize, reserve, and destroy_vector.
	std::cout << "\n\nconstruct_vector(c, 3, 8);" << std::endl;
	construct_vector(c, 3, 8);
	std::cout << "Size of c = " << size(c) << std::endl;
	std::cout << "Capacity of c = " << capacity(c) << std::endl;
	std::cout << "Contents of c = ";
	for (int i = 0; i < c.size; i++) {
		std::cout << at(c, i) << " ";
	}

	std::cout << "\n\nresize(c, 10, -1);" << std::endl;
	resize(c, 10, -1);	std::cout << "Size of c = " << size(c) << std::endl;
	std::cout << "Capacity of c = " << capacity(c) << std::endl;
	std::cout << "Contents of c = ";
	for (int i = 0; i < c.size; i++) {
		std::cout << at(c, i) << " ";
	}
	std::cout << "\n\nresize(c, 5, 0);" << std::endl;
	resize(c, 5, 0);
	std::cout << "Size of c = " << size(c) << std::endl;
	std::cout << "Capacity of c = " << capacity(c) << std::endl;
	std::cout << "Contents of c = ";
	for (int i = 0; i < c.size; i++) {
		std::cout << at(c, i) << " ";
	}

	std::cout << "\n\nreserve(c,15);" << std::endl;
	reserve(c, 15);
	std::cout << "Size of c = " << size(c) << std::endl;
	std::cout << "Capacity of c = " << capacity(c) << std::endl;
	std::cout << "Contents of c = ";
	for (int i = 0; i < c.size; i++) {
		std::cout << at(c, i) << " ";
	}

	std::cout << "\n\nreserve(c,1);" << std::endl;
	reserve(c, 1);
	std::cout << "Size of c = " << size(c) << std::endl;
	std::cout << "Capacity of c = " << capacity(c) << std::endl;
	std::cout << "Contents of c = ";
	for (int i = 0; i < c.size; i++) {
		std::cout << at(c, i) << " ";
	}







	return 0;
}



//function definitions

void construct_vector(Vector& v, int size, int initVal) {
	v.size = size;
	v.capacity = size;
	v.data = new int[size];
	for (int i = 0; i < size; i++) {
		v.data[i] = initVal;
	}
}

void destroy_vector(Vector& v) {
	v.data = nullptr;
	v.size = 0;
	v.capacity = 0;
}

int* data(const Vector& v) {
	return v.data;
}

int size(const Vector& v) {
	return v.size;
}

int& at(Vector& v, int i) throw (std::string) {
	return v.data[i];
}

int& back(const Vector& v) throw (std::out_of_range) {
	return v.data[v.size-1];
}

int capacity(const Vector& v) {
	return v.capacity;
}

void clear(Vector& v) {
	v.size = 0;
}

bool empty(const Vector& v) {
	if (v.size == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int& front(const Vector& v) throw (std::out_of_range) {
	return v.data[0];
}

void pop_back(Vector& v) {
	v.size = v.size - 1;
}

void push_back(Vector& v, int element) {
	v.size = v.size + 1;
	if (v.size > v.capacity) {
		if (v.capacity == 0) {
			v.capacity = 1;
		}
		v.capacity = v.capacity * 2;
	}
	v.data[v.size-1] = element; 
}

void resize(Vector& v, int newsize, int val) {
	for (int i = v.size; i < newsize; i++) {
		v.data[i] = val;
	}
	v.size = newsize;
	if (newsize > v.capacity) {
		if (v.capacity == 0) {
			v.capacity = 1;
		}
		v.capacity = v.capacity * 2;
	}
}

void reserve(Vector& v, int new_capacity) {
	if (new_capacity >= v.capacity) {
		v.capacity = new_capacity;
	}
}

int find(Vector& v, int key) {	for (int i = 0; i < v.size; i++) {		if (v.data[i] == key) {			return i;		}	}	return -1;}