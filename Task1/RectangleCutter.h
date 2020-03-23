#include "Rectangle.h"
class RectangleCutter : public Rectangle{
public:
	RectangleCutter(double* left_down, double* right_up);
	Rectangle* cut_rectangle(Rectangle &rectangle);
};

