#include "RectR.h"

RectR::RectR(float lft, float rght, float Up, float Dwn)
{
	left = lft;
	right = rght;
	up = Up;
	down = Dwn;
}

RectR::RectR(Vec2& topleft, Vec2& btmright)
	:
	RectR(topleft.y, btmright.y, topleft.x, btmright.x)
{
}

const bool RectR::IsOverlapping(const RectR& rhs) const
{
	return right >= rhs.left &&
		left <= rhs.right &&
		down >= rhs.up &&
		up <= rhs.down;
}

RectR::~RectR()
{
}
