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
	if (left_down[0] > right_up[0])
		swap(left_down[0], right_up[0]);
	if (left_down[1] > right_up[1])
		swap(left_down[1], right_up[1]);

	for (int i = 0; i < 2; i++) {
		this->left_down[i] = *(left_down + i);
		this->right_up[i] = *(right_up + i);
	}
	total_square += abs(left_down[0] - right_up[0]) * abs(left_down[1] - right_up[1]);
	num_of_rectangles++;
}

Rectangle::Rectangle(double left_down[], double height, double width) {
	if (left_down[0] > right_up[0])
		swap(left_down[0], right_up[0]);
	if (left_down[1] > right_up[1])
		swap(left_down[1], right_up[1]);
	
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
	return this->get_height() * this->get_width();
}

double Rectangle::get_r_inner_circle() { //������ ��������� ����������
	if (this->is_square())	//������ ��� �������, ��� ������������� -- ������� ����� �������
		return this->get_height() / 2;
	else
		return -1;	//��� �������������� ������� ������������ -1
}

double Rectangle::get_r_outer_circle() { //������ ��������� ����������
	return sqrt(pow(this->get_height(), 2) + pow(this->get_width(), 2)) / 2;
}

bool Rectangle::is_square() { //����� ���������� ������������� �� �������
	if (this->get_height() == this->get_width())
		return true;
	else
		return false;
}

bool Rectangle::check_point(double* coordinats) { //�����, ����������� �������������� ����� �������
	if ((coordinats[0] >= left_down[0] and coordinats[0] <= right_up[0]) and 
		(coordinats[1] >= left_down[1] and coordinats[1] <= right_up[1]))
		return true; 
	return false;
}

void Rectangle::change_geometry(double* left_down, double* right_up) { //��������� ��������� ��������������
	try {
		for (int i = 0; i < 2; i++) {	//����������, ���������� ��� ������� �������� ����������
			if (left_down[i] == right_up[i])	//����������� ����� ��� �����.
				throw "Rectangle is line of point.";	
		}
	}
	catch (string str) {
		cout << "Error: " + str;
		return;
	}

	total_square -= this->get_square();	//�������� �� ����� ������� ������� ������� ��������������
	
	if (left_down[0] > right_up[0])
		swap(left_down[0], right_up[0]);
	if (left_down[1] > right_up[1])
		swap(left_down[1], right_up[1]);

	for (int i = 0; i < 2; i++) {	//��������� ������������ ����� ���������
		this->left_down[i] = left_down[i];
		this->right_up[i] = right_up[i];
	}
	
	total_square += this->get_square();	//���������� ����� ������� � �����
}