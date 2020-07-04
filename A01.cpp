//
// Name: Liam Pang-Naylor
// SSID: 1608793
// Assignment: #1
// Submission Date: 9/5/19
//
// Program Description: This program takes any three words and reverses them.
//

#include <iostream>
#include <string>

int main(int argc, char* argv[])
{

	// Ending variable
	char end;

	// Request Input into three strings
	std::cout << "Enter any 3 words and hit [Enter] to reverse their letters: "; 
	std::string x, y, z;
	std::cin >> x >> y >> z;
	
	// Reverse function reverses each word
	std::reverse(x.begin(), x.end());											 
	std::reverse(y.begin(), y.end());
	std::reverse(z.begin(), z.end());
	
	// Print the words with spaces and followed by new lines
	std::cout << x << " " << y << " " << z << "\n \n"; 
		

	// Takes any character as end program
	std::cout << "Enter any character and hit [Enter] to exit the program. \n";					 
	std::cin >> end;
	return 0;

}