#pragma once
#include "../inc/Point.hpp"

enum side {PLUS, MINUS};

struct Vector {
	float x;
	float y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
