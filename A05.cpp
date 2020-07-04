// Name : Liam Pang-Naylor
// SSID : 1608793
// Assignment #: ASSIGNMENT_5
// Submission Date : 
//
// Description of program :
//

#include <iostream>
#include <string>


namespace CS52 {
	class Vector {
		public:
			Vector() {											// default constructor
				_size = 0;
				_capacity = 0;
			}
			Vector(int sz, int init_val) {						// overloaded constructor
				_size = sz;
				_capacity = _size;
				_data = new int[_size];
				for (int i = 0; i < _size; i++) {
					_data[i] = init_val;
				}
			}					
			Vector(const Vector&);								// copy constructor
			~Vector() {											// Destructor
				_data = nullptr;
				_size = 0;
				_capacity = 0;
			}
																						// Resize Vector . For details see provided links
			void resize(int new_size, int init_val) {
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
																						// Increase capacity of Vector . For details see provided links
			void reserve(int cap) {
				if (cap >= _capacity) {
					_capacity = cap;
				}
			}
																						// Returns a reference to the element at location i in Vector .
			int& at(int i) const throw (std::string) {
				return _data[i];
			}
																						// Returns the allocated storage for the Vector .
			int capacity() const {
				std::cout << _capacity;
			}
																						// Erases the elements of the Vector but does not change capacity .
			void clear() {
				_data = nullptr;
				_size = 0;
			}
																						// Returns pointer to the first element in the Vector .
			int* data() const {
				return _data;
			}
																						// If Vector is empty return true , else false .
			bool empty() const {
				if (_size == 0) {
					return true;
				}
				return false;
			}
																						// Deletes the element at the end of the vector .
			void pop_back() {
				_size = _size - 1;
			}
																						// Add an element to the end of the vector .
			void push_back(int element) {
				_size = _size + 1;
				if (_size > _capacity) {
					if (_capacity == 0) {
						_capacity = 1;
					}
					_capacity = _capacity * 2;
				}
				_data[_size - 1] = element;
			}
																						// Returns a reference to the first element in the Vector .
			int& front() const throw (...) {			// std :: out_of_range
				return _data[0];
			}
																						// Returns a reference to the last element in Vector v.
			int& back() const throw (...) {			// std :: out_of_range
				return _data[_size - 1];
			}
																						// Returns the number of elements in the vector .
			int size() const {
				std::cout << _size;
			}
																						// Search for a key in Vector , return index of key or -1 if not found
			int find(int key) {
				for (int i = 0; i < _size; i++) {
					if (_data[i] == key)
						return i;
				}
				return -1;
			}
																						// Overloaded operators
			int& operator[] (int i) {				// [] array syntax
				if (i > _size)
					std::cout << "Index out of bounds" << std::endl;
				return _data[i];
			}
			Vector& operator=(const Vector&);		// copy assignment
																						// Overloaded stream insertion operator
			friend std::ostream& operator<< (std::ostream & out, Vector&) {
				for (int i = 0; i < _size; i++) {
					out << _data[i] << " ";
				}
				return out;
			}
		private:
			int _size = 0; int _capacity = 0; int* _data = nullptr;
	}; // Vector
}// namespace

void info(CS52::Vector& v) { 
	std::cout << "Size is: " << v.size() << "\n"; 
	std::cout << "Capacity is: " << v.capacity() << "\n"; 
	std::cout << "Contents : "; 
	for (int i = 0; i < v.size(); i++) { 
		std::cout << v[i] << " "; 
	} 
	std::cout << "\n"; 
}

int main() 
{
	// default constructor , push_back , at methods 
	std::cout << "//default constructor , push_back , at \nCS52::Vector a;\n"; 
	CS52::Vector a; std::cout << "\na.push_back(10); a.push_back(88)\n"; 
	a.push_back(10); a.push_back(88); 
	std::cout << "a.at(0) = 99;\n"; a.at(0) = 99; info(a);
	//b 
	std::cout << "\n//overloaded constructor , [] op, at, find , empty , clear , \ exception handling: front , at \nCS52::Vector b(2,5);\n";

	CS52::Vector b(2, 5); 
	std::cout << "b is " << b << "\n";

	std::cout << "\n//Add more elements to b\n"; 
	std::cout << "b.push_back(10); b.push_back(2);\n"; 
	std::cout << "b.push_back(99); b.push_back(-5);\n"; 
	b.push_back(10); b.push_back(2); 
	b.push_back(99); b.push_back(-5);

	std::cout << "\n//array index [] and at()\n"; 
	std::cout << "b[0] = 25; b[1] = 1;\n"; 
	b[0] = 25; b[1] = 1; 
	std::cout << "b.at(0) ; b.at(1) ;\n"; 
	std::cout << b.at(0) << " " << b.at(1) << "\n";

	std::cout << "\n//find method\nint i = b.find(25) , "; 
	std::cout << "i = " << b.find(25); 
	std::cout << "\nint i = b.find(999), "; 
	std::cout << "i = " << b.find(999);

	std::cout << "\n\n//empty method , size , and capacity\n"; 
	std::cout << "b.empty() " << (b.empty() ? "True" : "False") << "\n"; 
	std::cout << "b.clear()\n"; 
	b.clear(); 
	info(b); 
	std::cout << "b.empty() " << (b.empty() ? "True" : "False") << "\n";

	std::cout << "\n\n//Exception handling:"; 
	try { 
		std::cout << "\nb.front() = "; 
		std::cout << b.front(); 
	}
	catch (std::out_of_range e) { 
		std::cerr << e.what(); 
	}
	try {
		std::cout << "\nb.at(9) = "; std::cout << b.at(9);
	}
	catch (std::string msg) { std::cerr << "\n" << msg << std::endl; }

	//c 
	std::cout << "\n//copy constructor , copy assignment , pop_back ,reserve ,\n//resize , capacity , size\nCS52::Vector c(b);\n";

	std::cout << "\n//Add more elements to b\n"; 
	std::cout << "b.push_back(11); b.push_back(7);\n"; 
	std::cout << "b.push_back(3); b.push_back(23);\n"; 
	b.push_back(11); b.push_back(7); 
	b.push_back(3); b.push_back(23); 
	CS52::Vector c(b); 
	info(c);

	//d 
	std::cout << "\n//copy assignment\n"; 
	CS52::Vector d; 
	d = c; 
	std::cout << "CS52::Vector d = c; " << "\n"; 
	std::cout << "d is " << d << "\n";

	std::cout << "\n//size vs capacity()\n"; 
	std::cout << "d.size() is " << d.size() << "\n"; 
	std::cout << "d.capacity() is " << d.capacity() << "\n";

	std::cout << "\n//pop_back()\n"; 
	std::cout << "d.pop_back();d.pop_back();\n"; 
	d.pop_back(); d.pop_back();

	std::cout << "\n//size vs capacity\n"; 
	std::cout << "d.size() is " << d.size() << "\n"; 
	std::cout << "d.capacity() is " << d.capacity() << "\n";

	std::cout << "\n//Resize -Reserve Testing \n"; 
	d.resize(10, -1); 
	std::cout << "d.resize(10, -1); \n"; 
	info(d);

	d.resize(5, 0); 
	std::cout << "\nd.resize(5, 0); \n"; 
	info(d);

	d.reserve(15); 
	std::cout << "\nd.reserve(15); \n"; 
	info(d);

	d.reserve(1); 
	std::cout << "\nd.reserve(1); \n"; 
	info(d);

	char stop; 
	std::cin >> stop;

	return 0;

}
