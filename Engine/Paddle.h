#pragma once

#include "Ball.h"
#include "Graphics.h"
#include "Keyboard.h"
#include "RectR.h"

class Paddle
{
public:
	Paddle(const Vec2& Pos, float W, float H);
	~Paddle();
	const bool DoBallCollision(Ball& theball);
	void Update(const Keyboard& kbd, float dt);
	void DoWallCollision(const RectR& thewall);
	void DrawPaddle(Graphics& gfx);
	RectR GetRectangle();

public:
	Vec2 Position;
	float Speed = 300.0f;
	float HalfWidth;
	float HalfHeight;
	Color color = Colors::White;
};

