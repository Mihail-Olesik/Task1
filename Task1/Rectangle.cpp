#include "Rectangle.h"
#include <iostream>

using namespace std;

double Rectangle::num_of_rectangles = 0;
double Rectangle::total_square = 0;

Rectangle::Rectangle() {
	left_down[0] = 0;
	left_down[1] = 0;
	right_up[0] = 1;
	right_up[1] = 1;
	total_square += abs(left_down[0] - right_up[0]) * abs(left_down[1] - right_up[1]);
	num_of_rectangles++;
}

Rectangle::Rectangle(double left_down[], double right_up[]) {
	for (int i = 0; i < 2; i++) {
		this->left_down[i] = *(left_down + i);
		this->right_up[i] = *(right_up + i);
	}
	total_square += abs(left_down[0] - right_up[0]) * abs(left_down[1] - right_up[1]);
	num_of_rectangles++;
}

Rectangle::Rectangle(double left_down[], double height, double width) {
	for (int i = 0; i < 2; i++)
		this->left_down[i] = *(left_down + i);
	this->right_up[0] += width;
	this->right_up[1] += height;
	total_square += abs(left_down[0] - right_up[0]) * abs(left_down[1] - right_up[1]);
	num_of_rectangles++;
}

Rectangle::~Rectangle() {
	total_square -= abs(left_down[0] - right_up[0]) * abs(left_down[1] - right_up[1]);
	num_of_rectangles--;
}

double Rectangle::get_num_of_rectangles() {
	return num_of_rectangles;
}

double Rectangle::get_total_square() {
	return total_square;
}