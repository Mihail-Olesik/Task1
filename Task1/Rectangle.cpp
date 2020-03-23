#include "Rectangle.h"
#include <iostream>
#include <cmath>

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

double Rectangle::get_width() {	//�����, ������������ ������ ��������������
	return abs(this->left_down[0] - this->right_up[0]);
}

double Rectangle::get_height() { //�����, ������������ ����� ��������������
	return abs(this->left_down[1] - this->right_up[1]);
}

double* Rectangle::get_left_down() { //�����, ������������ ���������� ������ 
	return left_down;                //������� ���� � ���� �������
}

double* Rectangle::get_left_up() { //�����, ������������ ���������� ������ �������� ���� � ���� �������
	return new double[2] { this->left_down[0], this->right_up[1] };
}

double* Rectangle::get_right_down() { //�����, ������������ ���������� ������� ������� ���� � ���� �������
	return new double[2]{ this->right_up[0], this->left_down[1] };
}

double* Rectangle::get_right_up() { //�����, ������������ ���������� ������� �������� ���� � ���� �������
	return right_up;
}

double Rectangle::get_perimeter() { //�����, ������������ �������� ��������������
	return 2 * this->get_height() + 2 * this->get_width();
}

double Rectangle::get_square() { //�����, ������������ ������� ��������������
	return this->get_height() * this->get_height();
}

double Rectangle::get_r_inner_circle() { //������ ��������� ����������
	if (this->is_square())	//������ ��� �������, ��� ������������� -- ������� ����� �������
		return this->get_height / 2;
	else
		return -1;	//��� �������������� ������� ������������ -1
}

double Rectangle::get_r_outer_circle() { //������ ��������� ����������
	return sqrt(pow(this->get_height, 2) + pow(this->get_width, 2)) / 2;
}

