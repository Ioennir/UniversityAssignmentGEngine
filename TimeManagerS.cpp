/*
**	Glass Engine
**	$filename
**	Author: Francisco Núñez Villagómez "Ioennir"
**	Date: 2019
*/
#pragma once

#include "TimeManagerS.h"

void
TimeManagerS::Init()
{
	lastTick = 0;
	currentTick = SDL_GetPerformanceCounter();
	deltaTime = 0.0;

}

//First dt is 0.24342 more or less
//After that one, the rest are inside the order of 0.000x
//Ask why
void
TimeManagerS::Update()
{
	lastTick = currentTick;
	currentTick = SDL_GetPerformanceCounter();
	deltaTime = (real32) (((currentTick - lastTick) * 1000) / (real64)SDL_GetPerformanceFrequency());
}