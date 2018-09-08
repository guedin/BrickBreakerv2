#pragma once
#include "Brick.h"
#include "Graphics.h"
#include "Canvas.h"

class BrickLayout
{
public:
	BrickLayout(Canvas& canvas);
	void Generate();
	void Draw(Graphics& gfx);
	int GetNBrick() const;
	Brick& GetBrick(int i);
	void DestroyBrick(int i);
private:
	static constexpr float topOffset = 50;
	static constexpr int row = 10;
	static constexpr int column = 7;
	static constexpr int nBrick = row * column;
	float brickWidth;
	static constexpr float brickHeight = 15.0f;
	Canvas& canvas;
	Brick bricks[999];
};
