#pragma once

#include "Vec2.h"

class RectR
{
public:
	RectR() = default;
	RectR(float lft, float rght, float Up, float Dwn);
	RectR(const Vec2& topleft, const Vec2& btmright);
	RectR(const Vec2& topleft, float width, float height);
	const bool IsOverlapping(const RectR& rhs) const;
	static RectR CentreRectangle(Vec2& Position, float HalfWidth, float HalfHeight);
	RectR GetExpanded(float offset) const;
	~RectR();

public:
	float left;
	float right;
	float up;
	float down;
};

