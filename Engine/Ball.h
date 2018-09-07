#pragma once
#include "Vec2.h"
#include "Graphics.h"
#include "RectF.h"
#include "FrameTimer.h"

class Ball
{
public:
	Ball() = default;
	Ball(Graphics& gfx, Vec2 pos, Vec2 vel);
	void Draw(Graphics& gfx);
	void Update();
	void ReboundX();
	void ReboundY();
private:
	RectF rect;
	Graphics& gfx;
	Vec2 pos;
	Vec2 vel;
	Color c = Colors::Green;
	static constexpr int radius = 8;
	FrameTimer ft;
};