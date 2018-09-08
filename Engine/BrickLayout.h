#pragma once
#include "Brick.h"
#include "Graphics.h"

class BrickLayout
{
public:
	BrickLayout();
	void Generate();
	void Draw(Graphics& gfx);
private:
	static constexpr int row = 15;
	static constexpr int column = 3;
	static constexpr int nBrick = row * column;
	static constexpr float brickWidth = 45.0f;
	static constexpr float brickHeight = 15.0f;
	Brick bricks[999];
};
