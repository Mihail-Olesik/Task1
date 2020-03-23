#include "InscribedCircle.h"

InscribedCircle::InscribedCircle(Rectangle &rectangle): 
	radius(rectangle.get_r_outer_circle()){}

double InscribedCircle::get_radius() {
	return radius;
}