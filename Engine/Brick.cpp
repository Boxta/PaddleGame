#include "Brick.h"



Brick::Brick(Vec2 topleft, Vec2 btmright)
	:
	rect(topleft, btmright)
{
}

Brick::~Brick()
{
}

void Brick::DrawBrick(Graphics & gfx) const
{
	if(!IsDestroyed)
		gfx.DrawRect(rect, color);
}

bool Brick::BallCollision(Ball & theball)
{
	if (!IsDestroyed && theball.BallRectangle.IsOverlapping(rect))
	{
		IsDestroyed = true;
		theball.ChangeYDirection();
		return true;
	}
	return false;
}

