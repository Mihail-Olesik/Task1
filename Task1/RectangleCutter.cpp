#include "RectangleCutter.h"

RectangleCutter::RectangleCutter(double* left_down, double* right_up):Rectangle(left_down, right_up){}

Rectangle* RectangleCutter::cut_rectangle(Rectangle &rectangle) {
	double left_down[2], right_up[2];
	for (int i = 0; i < 2; i++) {
		if (this->get_left_down()[i] >= rectangle.get_left_down()[i])
			left_down[i] = this->get_left_down()[i];
		else {
			if (this->get_right_up()[i] >= rectangle.get_left_down()[i])
				left_down[i] = rectangle.get_left_down()[i];
			else
				left_down[i] = this->get_right_up()[i];
		}
		if (this->get_right_up()[i] <= rectangle.get_right_up()[i])
			right_up[i] = this->get_right_up()[i];
		else {
			if (this->get_left_down()[i] >= rectangle.get_right_up()[i])
				right_up[i] = this->get_left_down()[i];
			else
				right_up[i] = rectangle.get_right_up()[i];
		}
	}
	return new Rectangle(left_down, right_up);
}
