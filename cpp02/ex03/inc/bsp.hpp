#pragma once
#include "../inc/Point.hpp"

enum side {PLUS, MINUS};

bool bsp( Point const a, Point const b, Point const c, Point const point);
