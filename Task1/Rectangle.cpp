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

double Rectangle::get_width() {	//метод, возвращающий ширину прямоугольника
	return abs(this->left_down[0] - this->right_up[0]);
}

double Rectangle::get_height() { //метод, возвращающий длину прямоугольника
	return abs(this->left_down[1] - this->right_up[1]);
}

double* Rectangle::get_left_down() { //метод, возвращающий координаты левого 
	return left_down;                //нижнего угла в виде массива
}

double* Rectangle::get_left_up() { //метод, возвращающий координаты левого верхнего угла в виде массива
	return new double[2] { this->left_down[0], this->right_up[1] };
}

double* Rectangle::get_right_down() { //метод, возвращающий координаты правого нижнего угла в виде массива
	return new double[2]{ this->right_up[0], this->left_down[1] };
}

double* Rectangle::get_right_up() { //метод, возвращающий координаты правого верхнего угла в виде массива
	return right_up;
}

double Rectangle::get_perimeter() { //метод, возвращающий периметр прямоугольника
	return 2 * this->get_height() + 2 * this->get_width();
}

double Rectangle::get_square() { //метод, возвращающий площадь прямоугольника
	return this->get_height() * this->get_width();
}

double Rectangle::get_r_inner_circle() { //радиус вписанной окружности
	if (this->is_square())	//только при условии, что прямоугольник -- квадрат можно вписать
		return this->get_height() / 2;
	else
		return -1;	//при несоответствии условия возвращается -1
}

double Rectangle::get_r_outer_circle() { //радиус описанной окружности
	return sqrt(pow(this->get_height(), 2) + pow(this->get_width(), 2)) / 2;
}

bool Rectangle::is_square() { //метод проверящий прямоугольник на квадрат
	if (this->get_height() == this->get_width())
		return true;
	else
		return false;
}

bool Rectangle::check_point(double* coordinats) { //метод, проверяющий принадлежности точки области
	if ((coordinats[0] >= left_down[0] and coordinats[0] <= right_up[0]) and 
		(coordinats[1] >= left_down[1] and coordinats[1] <= right_up[1]))
		return true; 
	return false;
}

void Rectangle::change_geometry(double* left_down, double* right_up) { //Изменение геометрии прямоугольника
	try {
		for (int i = 0; i < 2; i++) {	//Исключение, вызываемое при попытке передать координаты
			if (left_down[i] == right_up[i])	//формирующие линию или точку.
				throw "Rectangle is line of point.";	
		}
	}
	catch (string str) {
		cout << "Error: " + str;
		return;
	}

	total_square -= this->get_square();	//Вычитаем из общей площади площадь старого прямоугольника
	
	if (left_down[0] > right_up[0])
		swap(left_down[0], right_up[0]);
	if (left_down[1] > right_up[1])
		swap(left_down[1], right_up[1]);

	for (int i = 0; i < 2; i++) {	//Выполняем присваивание новых координат
		this->left_down[i] = left_down[i];
		this->right_up[i] = right_up[i];
	}
	
	total_square += this->get_square();	//Прибавляем новую площадь к общей
}