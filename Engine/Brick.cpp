#include "Brick.h"



Brick::Brick(Vec2 topleft, float width, float height)
	:
	rect(topleft, width, height)
{
}

Brick::~Brick()
{
}

void Brick::DrawBrick(Graphics & gfx) const
{
	if(!IsDestroyed)
		gfx.DrawRect(rect.GetExpanded(-1), color);
}

const bool Brick::BallCollision(Ball & theball)
{
	if (!IsDestroyed && theball.BallRectangle.IsOverlapping(rect))
	{
		if (theball.Position.x >= rect.left && theball.Position.x <= rect.right)
		{
			theball.ChangeYDirection();
		}
		else
		{
			theball.ChangeXDirection();
		}
		IsDestroyed = true;
		return true;
	}
	return false;
}

