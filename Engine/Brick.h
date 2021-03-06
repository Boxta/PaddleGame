#pragma once

#include "RectR.h"
#include "Colors.h"
#include "Graphics.h"
#include "Ball.h"

class Brick
{
public:
	Brick() = default;
	Brick(const Vec2 topleft, float width, float height);
	~Brick();

	void DrawBrick(Graphics& gfx) const;
	const bool BallCollision(Ball& theball);

public:
	RectR rect;
	Color color = Colors::Blue;
	bool IsDestroyed = false;
};

