#include "../inc/Fixed.hpp"
#include "../inc/Point.hpp"
#include "../inc/Vector.hpp"
#include "../inc/bsp.hpp"

static bool	vector_cross( Vector A, Vector B ) {
	Fixed	res = A.getX() * B.getY() - A.getY() * B.getX();
	if (res > Fixed(0))
		return (PLUS);
	return (MINUS);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point) {
	bool	inside;
	bool	cross_product;
	Vector ab(a, b);
	Vector ac(a, c);
	Vector ap(a, point);
	Vector bc(b, c);
	Vector bp(b, point);
	Vector ca(c, a);
	Vector cp(c, point);

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
