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
	void DrawBall(Graphics& gfx);
	void ChangeXDirection();
	void ChangeYDirection();
	void CheckWindowBoundary();

public:
	Vec2 Position;
	Vec2 Velocity;
	const float Diameter = 7.0f;
};

