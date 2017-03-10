#include "Brick.h"



Brick::Brick(Vec2 topleft, Vec2 btmright)
	:
	rect(topleft, btmright)
{
}

Brick::~Brick()
{
}

void Brick::DrawBrick(Graphics & gfx)
{
	gfx.DrawRect(rect, color);
}
