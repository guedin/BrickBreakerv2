#include "BrickLayout.h"

BrickLayout::BrickLayout()
{
	Generate();
}

void BrickLayout::Generate()
{
	int i = 0;
	for (int x = 0; x < row; x++)
	{
		for (int y = 0; y < column; y++)
		{
			bricks[i] = Brick(Vec2(x*brickWidth, y*brickHeight), brickWidth, brickHeight, Color(255,255,0));
			i++;
		}
	}
}

void BrickLayout::Draw(Graphics& gfx)
{
	for (int i = 0; i < nBrick; i++)
	{
		bricks[i].Draw(gfx);
	}
}