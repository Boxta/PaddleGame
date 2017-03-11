#include "Ball.h"

Ball::Ball(Vec2& Pos, Vec2& Vel)
{
	Position = Pos;
	Velocity = Vel;
	BallRectangle = RectR((Vec2(Position.x - Diameter, Position.y - Diameter)), (Vec2(Position.x + Diameter, Position.y + Diameter)));
}

Ball::~Ball()
{
}

void Ball::Update(float delta_time)
{
	Position += Velocity * delta_time;
	BallRectangle = RectR((Vec2(Position.x - Diameter, Position.y - Diameter)), (Vec2(Position.x + Diameter, Position.y + Diameter)));
	CheckWindowBoundary();
}

void Ball::DrawBall(Graphics& gfx)
{
	SpriteCodex::DrawBall(Position, gfx);
}

void Ball::ChangeXDirection()
{
	Velocity.x = -Velocity.x;
}

void Ball::ChangeYDirection()
{
	Velocity.y = -Velocity.y;
}

void Ball::CheckWindowBoundary()
{
	if (Position.x <= Diameter)
	{
		Position.x = Diameter;
		ChangeXDirection();
		return;
	}
	else if (Position.x >= Graphics::ScreenWidth - Diameter)
	{
		Position.x = Graphics::ScreenWidth - Diameter;
		ChangeXDirection();
		return;
	}

	if (Position.y <= Diameter)
	{
		Position.y = Diameter;
		ChangeYDirection();
		return;
	}
	else if (Position.y >= Graphics::ScreenHeight - Diameter)
	{
		Position.y = Graphics::ScreenHeight - Diameter;
		ChangeYDirection();
		return;
	}
}
