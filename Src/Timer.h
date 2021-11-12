#pragma once

#include "Common.h"

class Timer {

public:
	Timer() 
	{
		last = SDL_GetTicks() / 1000.0f;
	};

	float last  = 0;
	float delta = 0;
	
	float frameCount = 0;
	float frameLimit = 100;
	float frameLast = 0;
	float fps = 0;

	void Tick(unsigned int milli)
	{
		float now = SDL_GetTicks() / 1000.0f;
		
		this->delta = now - last;
		this->last = now;

		this->CalculateFPS();
	}

	void CalculateFPS()
	{
		if (frameCount == frameLimit)
		{
			float frameNow = SDL_GetTicks() / 1000.0f;
			float dt = frameNow - frameLast;

			fps = frameLimit / dt;

			frameLast = frameNow;
			frameCount = 0;
		}

		frameCount++;
	}
};