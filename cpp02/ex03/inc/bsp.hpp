#pragma once
#include "../inc/Point.hpp"

enum CrossResult {PLUS, MINUS, INVALID_TRIANGLE};

bool bsp( Point const a, Point const b, Point const c, Point const point);
