#pragma once
#include "Rectangle.h"

class InscribedCircle{
private:
	double radius;
public:
	InscribedCircle(Rectangle& rectangle);
	double get_radius();
};

