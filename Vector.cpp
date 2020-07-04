// Name : Liam Pang-Naylor
// SSID : 1608793
// Assignment #: ASSIGNMENT_6
// Submission Date : 12/11/2019
//
// Description of program : Function Definitions.
//


#include <iostream>
#include <string>
#include "Container.h"
#include "Vector.h"

CS52::Vector::Vector() {
	_size = 0;
	_capacity = 0;
	_data = new int[_size] {};
}

CS52::Vector::Vector(int sz, int init_val) {												// overloaded constructor
	_size = sz;
	_capacity = _size;
	_data = new int[_size];
	for (int i = 0; i < _size; i++) {
		_data[i] = init_val;
	}
}

CS52::Vector::Vector(const Vector& that) {												// copy constructor 
	this->_size = that._size;
	this->_capacity = that._capacity;
	int* temp = new int[_size] {};
	for (int i = 0; i < _size; i++) {
		_data[i] = temp[i];														//throwing error for some reason. Can't tell why.
	}
	for (int i = 0; i < _size; i++) {
		temp[i] = that._data[i];												
	}
	delete[] temp;
}

CS52::Vector::~Vector() {																	// Destructor
	_data = nullptr;
	_size = 0;
	_capacity = 0;
}

void CS52::Vector::resize(int new_size, int init_val) {
	if (new_size > _capacity) {
		if (_capacity == 0) {
			_capacity = 1;
		}
		_capacity = 2 * _capacity;
	}
	for (int i = _size; i < new_size; i++) {
		_data[i] = init_val;
	}
	_size = new_size;

}

void CS52::Vector::reserve(int cap) {
	if (cap >= _capacity) {
		_capacity = cap;
	}
}

int& CS52::Vector::at(int i) const throw (std::string) {
	return _data[i];
}

int CS52::Vector::capacity() const {
	return _capacity;
}

void CS52::Vector::clear() {
	_size = 0;
	_data = new int[_size];
}

int* CS52::Vector::data() const {
	return _data;
}

bool CS52::Vector::empty() const {
	if (_size == 0) {
		return true;
	}
	return false;
}

void CS52::Vector::pop_back() {
	_size = _size - 1;
}

void CS52::Vector::push_back(int element) {
	_size++;
	if (_size > _capacity) {
		if (_capacity == 0) {
			_capacity = 1;
		}
		_capacity = _capacity * 2;
	}
	this->_data[_size - 1] = element;

}

int& CS52::Vector::front() const throw (...) {			// std :: out_of_range
	if (_data == nullptr) {
		throw;
	}
	return _data[0];
}

int& CS52::Vector::back() const throw (...) {			// std :: out_of_range
	return _data[_size - 1];
}

int CS52::Vector::size() const {
	return _size;

}

int CS52::Vector::find(int key) {
	for (int i = 0; i < _size - 1; i++) {
		if (_data[i] == key)
			return i;
	}
	return -1;
}

std::string CS52::Vector::type() const {
	return "CS52::Vector";
}

// Overloaded operators
int& CS52::Vector::operator[] (int i) {													// [] array syntax
	if (i > _size)
		std::cout << "Index out of bounds" << std::endl;
	return _data[i];
}
CS52::Vector& CS52::Vector::operator=(const Vector& that) {										// copy assignment
	for (int i = 0; i < _size; i++) {
		this->_data[i] = that._data[i];
	}
	return *this;
}

