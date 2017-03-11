#pragma once

#include "RectR.h"
#include "Colors.h"
#include "Graphics.h"
#include "Ball.h"

class Brick
{
public:
	Brick() = default;
	Brick(Vec2 topleft, Vec2 btmright);
	~Brick();

	void DrawBrick(Graphics& gfx) const;
	bool BallCollision(Ball& theball);

public:
	RectR rect;
	Color color = Colors::Blue;
	bool IsDestroyed = false;
};

