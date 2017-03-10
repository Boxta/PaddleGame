#include "RectR.h"

RectR::RectR(float lft, float rght, float Up, float Dwn)
{
	left = lft;
	right = rght;
	up = Up;
	down = Dwn;
}

RectR::RectR(Vec2 topleft, Vec2 btmright)
	:
	RectR(topleft.y, btmright.y, topleft.x, btmright.x)
{
}

bool RectR::IsOverlapping(const RectR & rhs)
{
	return left >= rhs.left && 
		 right <= rhs.right
}

RectR::~RectR()
{
}
