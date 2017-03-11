#pragma once

#include "Vec2.h"

class RectR
{
public:
	RectR() = default;
	RectR(float lft, float rght, float Up, float Dwn);
	RectR(Vec2& topleft, Vec2& btmright);
	RectR(Vec2& topleft, float width, float height);
	const bool IsOverlapping(const RectR& rhs) const;
	static RectR CentreRectangle(Vec2& Position, float HalfWidth, float HalfHeight);
	~RectR();

public:
	float left;
	float right;
	float up;
	float down;
};

