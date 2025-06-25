#include "../inc/Fixed.hpp"
#include "../inc/Point.hpp"
#include "../inc/bsp.hpp"

static float	vector_cross( Point const a, Point const b ) {

}

static Vector	create_vector( Point const a, Point const b ) {
	Vector	new_vector;

	float a_x = a.getXPoint();
	float a_y = a.getYPoint();
	float b_x = b.getXPoint();
	float b_y = b.getYPoint();

	new_vector.x = b_x - a_x; //maybe there is starter way to use operators that are created
	new_vector.y = b_y - a_y; //maybe there is starter way to use operators that are created
}

static bool	cross_ab_ac( Point const a, Point const b, Point const c ) {
	float res;
	float a_x = a.getXPoint();
	float a_y = a.getYPoint();
	float b_x = b.getXPoint();
	float b_y = b.getYPoint();
	float c_x = c.getXPoint();
	float c_y = c.getYPoint();

	res =
	if (res >= 0)
		return (PLUS);
	return (MINUS);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point) {
	bool	inside;

	inside = cross_ab_ac(a, b, c);
}
