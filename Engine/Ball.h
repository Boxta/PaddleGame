#pragma once

#include "Vec2.h"
#include "Graphics.h"
#include "SpriteCodex.h"

class Ball
{
public:
	Ball(Vec2& Pos, Vec2& Vel);
	~Ball();
	void Update(float delta_time);
	void DrawBall(Graphics& gfx) const;
	void ChangeXDirection();
	void ChangeYDirection();
	bool CheckWindowCollision(const RectR& other);
	RectR GetRect() const;
public:
	Vec2 Position;
	Vec2 Velocity;
	const float Radius = 7.0f;
	RectR BallRectangle;
};

