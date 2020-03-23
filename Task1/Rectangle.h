#pragma once
class Rectangle {
private:
	double left_down[2];
	double right_up[2];
	static double num_of_rectangles;
	static double total_square;
public:
	Rectangle();
	~Rectangle();
	Rectangle(double left_down[], double right_up[]);
	Rectangle(double left_down[], double height, double width);
	double get_width();
	double get_height();
	double* get_left_down();
	double* get_left_up();
	double* get_right_down();
	double* get_right_up();
	double get_perimeter();
	double get_square();
	double get_r_inner_circle();
	double get_r_outer_circle();
	double get_num_of_rectangles();
	double get_total_square();
	
	bool is_square();
	bool check_point(double* coordinats);

	void change_geometry(double* left_down, double* right_up);

};