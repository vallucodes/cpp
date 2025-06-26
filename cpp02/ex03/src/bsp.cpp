#include "../inc/Fixed.hpp"
#include "../inc/Point.hpp"
#include "../inc/bsp.hpp"

static bool	vector_cross( Vector A, Vector B ) {
	float	res = A.x * B.y - A.y * B.x;
	if (res >= 0)
		return (PLUS);
	return (MINUS);
}

static Vector	create_vector( Point const A, Point const B ) {
	Vector	new_vector;

	float A_x = A.getXPoint();
	float A_y = A.getYPoint();
	float B_x = B.getXPoint();
	float B_y = B.getYPoint();

	new_vector.x = B_x - A_x; //maybe there is smarter way to use operators that are created
	new_vector.y = B_y - A_y; //maybe there is smarter way to use operators that are created
	return (new_vector);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point) {
	bool	inside;
	bool	cross_product;
	Vector	ab = create_vector(a, b);
	Vector	ac = create_vector(a, c);
	Vector	ap = create_vector(a, point);
	Vector	bc = create_vector(b, c);
	Vector	bp = create_vector(b, point);
	Vector	ca = create_vector(c, a);
	Vector	cp = create_vector(c, point);

	// todo check its triangle
	inside = vector_cross(ab, ac);
	cross_product = vector_cross(ab, ap);
	if (cross_product != inside)
		return (0);
	cross_product = vector_cross(bc, bp);
	if (cross_product != inside)
		return (0);
	cross_product = vector_cross(ca, cp);
	if (cross_product != inside)
		return (0);
	return (1);
}
