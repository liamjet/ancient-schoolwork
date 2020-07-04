// Name : Liam Pang-Naylor
// SSID : 1608793
// Assignment #: ASSIGNMENT_6
// Submission Date : 12/11/2019
//
// Description of program : Vector Class, function prototypes.
//

#pragma once

#include <iostream>
#include <string>

namespace CS52 {
	class Vector : public Container {
	public:
		Vector(); // default constructor
		Vector(int sz, int init_val); // overloaded constructor
		Vector(const Vector&); // copy constructor
		~Vector(); // Destructor
		// Resize Vector . For details see provided links
		void resize(int new_size, int init_val);
		// Increase capacity of Vector . For details see provided links
		void reserve(int cap);
		// Returns a reference to the element at location i in Vector .
		int& at(int i) const throw (std::string);
		// Returns the allocated storage for the Vector .
		int capacity() const;
		// Erases the elements of the Vector but does not change capacity .
		void clear();
		// Returns pointer to the first element in the Vector .
		int* data() const;
		// If Vector is empty return true , else false .
		bool empty() const;
		// Deletes the element at the end of the vector .
		void pop_back();
		// Add an element to the end of the vector .
		void push_back(int element);
		// Returns a reference to the first element in the Vector .
		int& front() const throw (...); // std :: out_of_range
		// Returns a reference to the last element in Vector v.
		int& back() const throw (...); // std :: out_of_range
		// Returns the number of elements in the vector .
		int size() const;
		// Search for a key in Vector , return index of key or -1 if not found
		int find(int key);
		// Overloaded operators
		int& operator [] (int i); // [] array syntax
		Vector& operator =(const Vector&); // copy assignment
		// Overloaded stream insertion operator
		friend std::ostream& operator<<(std::ostream& out, Vector& v) {
			for (int i = 0; i < v._size; i++) {
				out << v._data[i] << " ";
			}
			return out;
		}
		std::string type() const;
	private:
		int _size = 0; int _capacity = 0; int* _data = nullptr;
	}; // Vector
}// namespace