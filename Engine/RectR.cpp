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

RectR::RectR(Vec2 & topleft, float width, float height)
	:
	RectR(topleft, topleft + Vec2(width, height))
{
}

const bool RectR::IsOverlapping(const RectR& rhs) const
{
	return right >= rhs.left &&
		left <= rhs.right &&
		down >= rhs.up &&
		up <= rhs.down;
}

RectR RectR::CentreRectangle(Vec2 & Position, float HalfWidth, float HalfHeight)
{
	return RectR(Position - Vec2(HalfWidth, HalfHeight), Position + Vec2(HalfWidth, HalfHeight));
}

RectR::~RectR()
{
}
