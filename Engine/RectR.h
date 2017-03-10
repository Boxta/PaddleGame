#pragma once

#include "Vec2.h"

class RectR
{
public:
	RectR() = default;
	RectR(float lft, float rght, float Up, float Dwn);
	RectR(Vec2 topleft, Vec2 btmright);
	bool IsOverlapping(const RectR& rhs);
	~RectR();

public:
	float left;
	float right;
	float up;
	float down;
};

