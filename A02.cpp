//
// Name : Liam Pang-Naylor
// SSID : 1608793
// Assignment #: ASSIGNMENT_2
// Submission Date : DATE_YOU_SUBMIT
//
// Description of program :
//

#include <iostream>
#include <string>

const int x = 8;
const int y = 8;

std::string choice = "none";

enum class Shapes { FILLED, HALF_RIGHT, BANDED, CHECKERBOARD, SQUARE, X, LOWER_LEFT };
enum class Colors { BLACK, WHITE };
struct Pixel { Colors color; };

Pixel p[x][y];

void CreateShape(Pixel p[x][y], int nPixels, Shapes shape) {

	shape = Shapes::FILLED;
	if (shape == Shapes::FILLED) {
		for (i = 0; x < 8; x++) {
			for (y = 0; y < 8; y++) {
				p[x][y] = {Colors::BLACK};

			}

		}
	}
}
void Draw(Pixel p[], int nPixels);



int main(int argc, char** argv) {

	CreateShape(p[x][y], 64, Shapes::FILLED);

	int run = 1;
	while (run == 1) {
		std::cout << "Enter in a shape to draw: filled, half_right, banded, checkered, square, x, or lower_left. Otherwise enter [q] to quit: ";
		std::cin >> choice;
		if (choice == "q") {
			run = 0;
		}
	}
}
