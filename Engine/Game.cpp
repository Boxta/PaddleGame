/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	ball(Vec2(100, 300), Vec2(200, 200)),
	GameWindow(0.0f, float(Graphics::ScreenWidth), 0.0f, float(Graphics::ScreenHeight)),
	soundsPad(L"Sounds\\arkpad.wav"),
	soundsBrick(L"Sounds\\arkbrick.wav"),
	pad(Vec2(100, 500), 40.0f, 5.0f)
{
	const Vec2 BrickStartVector = Vec2(25.0f, 40.0f);

	const Color colors[4] = { Colors::Blue, Colors::Magenta, Colors::Yellow, Colors::Green };
	int i = 0;
	for (int y = 0; y < BricksDeep; y++)
	{
		Color col = colors[y];
		for (int x = 0; x < BricksWide; x++)
		{
			Vec2 temp = Vec2(BrickStartVector.x + (x * BrickWidth), BrickStartVector.y + (y * BrickHeight));
			//Bricks[i] = Brick(temp, BrickWidth, BrickHeight);
			Bricks[i] = Brick(temp, BrickWidth, BrickHeight);
			Bricks[i].color = col;
			i++;
		}
	}
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	const float dt = time.Mark();
	ball.Update(dt);
	pad.Update(wnd.kbd, dt);
	if (pad.DoBallCollision(ball))
	{
		soundsPad.Play();
	}
	pad.DoWallCollision(GameWindow);

	if (ball.CheckCollision(GameWindow))
	{
		soundsPad.Play();
	}
	for (Brick& b : Bricks)
	{
		if (b.BallCollision(ball))
		{
			soundsBrick.Play();
			break;
		}
	}

}

void Game::ComposeFrame()
{
	for (const Brick& b : Bricks)
	{
		b.DrawBrick(gfx);
	}
	ball.DrawBall(gfx);
	pad.DrawPaddle(gfx);
}
