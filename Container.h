// Name : Liam Pang-Naylor
// SSID : 1608793
// Assignment #: ASSIGNMENT_6
// Submission Date : 12/11/2019
//
// Description of program : Container Class
//

#pragma once

#include <iostream>
#include <string>

namespace CS52 {
	class Container {
	public:
		virtual int size() const = 0;
		virtual std::string type() const = 0;
		virtual ~Container() {/* empty body */ }
	};
}

