#pragma once

#include "RectR.h"
#include "Colors.h"
#include "Graphics.h"

class Brick
{
public:
	Brick() = default;
	Brick(Vec2 topleft, Vec2 btmright);
	~Brick();

	void DrawBrick(Graphics& gfx);

public:
	RectR rect;
	Color color = Colors::Blue;
	bool IsDestroyed = false;
};

