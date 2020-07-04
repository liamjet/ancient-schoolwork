// Name : Liam Pang-Naylor
// SSID : 1608793
// Assignment #: ASSIGNMENT_6
// Submission Date : 12/11/2019
//
// Description of program : Driver Test Code.
//

#include <iostream>
#include <string>
#include "Container.h"
#include "Vector.h"

int main() {
	std::cout << "CS52::Vector Testing";
	CS52::Container* container[2];
	container[0] = new CS52::Vector(2, 1);
	container[1] = new CS52::Vector(5, 3);
	// Print out the type and length of each Container element
	std::cout << "\n\nTest polymorphism \n";
	for (int i = 0; i < 2; i++)
	{
		std::cout << "Container [" << i << "]" << " is a " << container[i] -> type();
		std::cout << " with length " << container[i] -> size() << "\n";
	}
	// delete Vector Objects Pointed to by Container
	for (int i = 0; i < 2; i++)
		delete container[i];
	return 0;
}
