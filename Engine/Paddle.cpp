#include "Paddle.h"



Paddle::Paddle(const Vec2& Pos, float W, float H)
	:
	Position(Pos),
	HalfWidth(W),
	HalfHeight(H)
{
}


Paddle::~Paddle()
{
}

const bool Paddle::DoBallCollision(Ball& theball)
{
	if (GetRectangle().IsOverlapping(theball.BallRectangle))
	{
		theball.ChangeYDirection();
		return true;
	}
	return false;
}

void Paddle::Update(const Keyboard & kbd, float dt)
{
	if (kbd.KeyIsPressed('A'))
	{
		Position.x -= Speed * dt;
	}
	if (kbd.KeyIsPressed('D'))
	{
		Position.x += Speed * dt;
	}
}

void Paddle::DoWallCollision(const RectR & thewall)
{
	if (Position.x - HalfWidth <= thewall.left)
	{
		Position.x = thewall.left + HalfWidth;
	}
	else if (Position.x + HalfWidth >= thewall.right)
	{
		Position.x = thewall.right - HalfWidth;
	}
}

void Paddle::DrawPaddle(Graphics & gfx)
{
	gfx.DrawRect(GetRectangle(), color);
}

RectR Paddle::GetRectangle()
{
	return RectR::CentreRectangle(Position, HalfWidth, HalfHeight);
}
