//
//Name: Liam Pang-Naylor
//SSID: 1608793
//Assignment #: 3
//Submission Date: 10/22/19
//
//Program Description: This program reads several pgm image files and change the font and background colors while writing them to a ppm image file.
//


//NOTE: This code does not work without pgm image files in the directory

//Libraries
#include <iostream>
#include <string>
#include <fstream>

//Typedef's, Constants, Arrays, and Structs
typedef unsigned char uchar;
const int NUM_IMAGES = 10;
uchar data[28 * 28][NUM_IMAGES];
struct Color { uchar rgb[3]; } bgk, font;

//Function Prototypes
void  readPGMImages(unsigned char images[][NUM_IMAGES], int img_size, const char* filename, int digit);
	
void  draw(uchar data[][NUM_IMAGES], int img_size, int digit);

void writeToColorPGMImages(uchar images[][NUM_IMAGES], int imgsize, Color bgk, Color font, std::string filename, int digit);



int main() {
	
	readPGMImages(data, 28 * 28, "digit_00.pgm" , 1);															//read in all files
	readPGMImages(data, 28 * 28, "digit_01.pgm", 2);
	readPGMImages(data, 28 * 28, "digit_02.pgm", 3);
	readPGMImages(data, 28 * 28, "digit_03.pgm", 4);
	readPGMImages(data, 28 * 28, "digit_04.pgm", 5);
	readPGMImages(data, 28 * 28, "digit_05.pgm", 6);
	readPGMImages(data, 28 * 28, "digit_06.pgm", 7);
	readPGMImages(data, 28 * 28, "digit_07.pgm", 8);
	readPGMImages(data, 28 * 28, "digit_08.pgm", 9);
	readPGMImages(data, 28 * 28, "digit_09.pgm", 10);

	while (true) {																								//user input loop
		int num;
		std::cout << "Which MNIST handwritten digit do you want to display(0, ..., 9)?" << std::endl;			//user number selection
		std::cin >> num;
		draw(data, 28 * 28, num+1);																				//draw function to display image shape
		std::cout << "\n\nDo you want to change the background color and font (yes or no)?" << std::endl;		//background and font change
		std::string choice;
		std::cin >> choice;
		if (choice == "yes") {																					//font and background color user input
			int bkg_c[3], font_c[3];
			std::cout << "Enter in the background color:" << std::endl;
			std::cin >> bkg_c[0] >> bkg_c[1] >> bkg_c[2];
			
			std::cout << "Enter in the font color:" << std::endl;
			std::cin >> font_c[0] >> font_c[1] >> font_c[2];
			for (int i = 0; i < 3; i++) {																		//cast inputs as uchar
				bgk.rgb[i] = (uchar)bkg_c[i];
				font.rgb[i] = (uchar)font_c[i];
			}
			std::string files[10] = { "digit_00.ppm", "digit_01.ppm", "digit_02.ppm", "digit_03.ppm", "digit_04.ppm", "digit_05.ppm", "digit_07.ppm", "digit_07.ppm", "digit_08.ppm", "digit_09.ppm" };		//list of string file names to reduce redundant code
			writeToColorPGMImages(data, 28 * 28, bgk, font, files[num], num + 1);								//write function using variable num to determine which image to write to
		}
		std::cout << "Do you want to see another digit (yes or no)?" << std::endl;
		std::cin >> choice;
		if (choice == "no") {
			std::cout << "goodbye";
			break;
		}
	}
}

void  readPGMImages(unsigned char images[][NUM_IMAGES], int img_size, const char* filename, int digit) {
	std::ifstream file;	
	file.open(filename);																						//open file
	if (file.fail()) {																							//check if open
		std::cout << "Opening file failed.";
		return;
	}
	std::string l1, l2, l3, l4;																					//skip first 4 text chunks on file by assigning them to variables (I have no doubt there is a superior way to do this but I could not think of it)
	file >> l1 >> l2 >> l3 >> l4;
	for (int i = digit; i <= digit; i++) {																		//for loop to read each number into a variable, cast that variable, then place in an array
		for (int j = 0; j < img_size; j++) {
			int cast;
			char c;
			file >> cast;
			c = (uchar)cast;
			images[j][i] = c;

		}
	}
	file.close();																								//close file
}

void  draw(uchar data[][NUM_IMAGES], int img_size, int digit) {													//draw function, similar to other assignment
	for (int i = digit; i < digit+1; i++) {
		for (int j = 0; j < img_size; j++) {
			if (data[j][i] > 150) {
				std::cout << "*";
			}
			else {
				std::cout << " ";
			}
			if (j % 28 == 0) {
				std::cout << "\n";
			}
		}
	}
}

void writeToColorPGMImages(uchar images[][NUM_IMAGES], int img_size, Color bgk, Color font, std::string filename, int digit) {
	std::ofstream file(filename);																				//open or create file
	file << "P3" << std::endl << "28 28" << std::endl << "255" << std::endl;									//enter in required content to make file readable
	int font_color[3] = { font.rgb[0], font.rgb[1], font.rgb[2] };												//place Color struct within 2 arrays
	int background_color[3] = { bgk.rgb[0], bgk.rgb[1], bgk.rgb[2] };
	int color_pixel[3];																							//create general color pixel array with 3 elements, one for each color
	for (int i = digit; i < digit + 1; i++) {
		for (int j = 0; j < img_size; j++) {
			if (images[j][i] > 150) {																			//set general color array elements to the font color if it has a great value in the original data array
				color_pixel[0] = font_color[0];
				color_pixel[1] = font_color[1];
				color_pixel[2] = font_color[2];
			}
			else {																								//set general color array elements to the background color otherwise
				color_pixel[0] = background_color[0];
				color_pixel[1] = background_color[1];
				color_pixel[2] = background_color[2];
			}
			if ((j % 6 == 0) && (j != 0)) {																		//add new line each 6 values of j
				file << std::endl;
			}
			for (int k = 0; k < 3; k++) {																		//print general pixel array on file
				file << color_pixel[k] << " ";
			}
		}
	}
	file.close();																								//close file
}