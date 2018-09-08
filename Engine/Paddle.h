#pragma once
#include "RectF.h"
#include "Vec2.h"
#include "Graphics.h"
#include "Canvas.h"
#include "MainWindow.h"
#include "FrameTimer.h"

class Paddle
{
public:
	Paddle(Canvas& canvas);
	void Draw(Graphics& gfx);
	void Update(Keyboard& kbd);
private:
	Canvas & canvas;
	Vec2 pos = Vec2(canvas.GetCenter().x, 500.0f);
	RectF boundingBox = RectF(pos, 70.0f, 15.0f);
	FrameTimer ft;
	float vel = 600.0f;
};