#include "Ball.h"

Ball::Ball(Vec2& Pos, Vec2& Vel)
{
	Position = Pos;
	Velocity = Vel;
	BallRectangle = RectR((Vec2(Position.x - Radius, Position.y - Radius)), (Vec2(Position.x + Radius, Position.y + Radius)));
}

Ball::~Ball()
{
}

void Ball::Update(float delta_time)
{
	Position += Velocity * delta_time;
	BallRectangle = RectR::CentreRectangle(Position, Radius, Radius);
}

void Ball::DrawBall(Graphics& gfx) const
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

bool Ball::CheckCollision(const RectR& other)
{
	bool Collided = false;
	if (Position.x - Radius <= other.left)
	{
		Position.x += Position.x - other.left;
		ChangeXDirection();
		Collided = true;
	}
	else if (Position.x + Radius >= other.right)
	{
		Position.x -=  other.right - Position.x;
		ChangeXDirection();
		Collided = true;
	}

	if (Position.y - Radius <= other.up)
	{
		Position.y += Position.y - other.up;
		ChangeYDirection();
		Collided = true;
	}
	else if (Position.y + Radius >= other.down)
	{
		Position.y -= other.down - Position.y;
		ChangeYDirection();
		Collided = true;
	}
	return Collided;
}
