#include "Ball.h"
#include <assert.h>

Ball::Ball(Vec2& Pos, Vec2& Vel)
{
	Position = Pos;
	Velocity = Vel;
	BallRectangle = RectR::CentreRectangle(Position, Radius, Radius);
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

bool Ball::CheckWindowCollision(const RectR& other)
{
	const RectR rec = GetRect();
	bool Collided = false;
	if (rec.left <= other.left)
	{
		Position.x += other.left - rec.left;
		ChangeXDirection();
		Collided = true;
	}
	else if (rec.right >= other.right)
	{
		Position.x -=  rec.right - other.right;
		ChangeXDirection();
		Collided = true;
	}

	if (rec.up <= other.up)
	{
		Position.y += other.up - rec.up;
		ChangeYDirection();
		Collided = true;
	}
	else if (rec.down >= other.down)
	{
		Position.y -= rec.down - other.down;
		ChangeYDirection();
		Collided = true;
	}
	return Collided;
}

RectR Ball::GetRect() const
{
	return BallRectangle;
}
