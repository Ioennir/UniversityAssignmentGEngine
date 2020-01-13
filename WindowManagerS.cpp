/*
**	Glass Engine
**	$filename
**	Author: Francisco Núñez Villagómez "Ioennir"
**	Date: 2019
*/
#pragma once

#include "WindowManagerS.h"

#if DEBUG
#include <stdio.h>
#endif

#pragma region Init()
void
WindowManagerS::Init()
{
	endProgram = 0;
	WindowInit();
	FillDefaultWindowData();
	CreateWindow();
}
#pragma endregion

#pragma region Update()
void
WindowManagerS::Update()
{

}
#pragma endregion

#pragma region WindowInit()
void
WindowManagerS::WindowInit()
{
	currWinFlags = SDLF_VID | SDLF_GPAD | SDLF_EVENT | SDLF_JOY;
	winInit = (!SDL_Init(currWinFlags));
	
}
#pragma endregion

#pragma region SetWindowResizeData()
void
WindowManagerS::SetWindowResizeData(const char * name,
							  int32 x, 
							  int32 y, 
							  int32 w, 
							  int32 h, 
							  uint32 flags)
{
	winData,name = name;
	winData.x = x;
	winData.y = y;
	winData.w = w;
	winData.h = h;
	winData.flags = flags;
}
#pragma endregion

#pragma region FillDefaultWindowData()
void
WindowManagerS::FillDefaultWindowData()
{
	winData = {
									 "Default name",
									 WPOS_UNDEFINED,
									 WPOS_UNDEFINED,
									 DEF_WINDOW_WIDTH,
									 DEF_WINDOW_HEIGHT,
									 WINDOW_SHOWN
	};
}
#pragma endregion

#pragma region CreateWindow()
void
WindowManagerS::CreateWindow()
{
	currWindowInstance = SDL_CreateWindow(winData.name,
										  winData.x,
										  winData.y,
										  winData.w,
										  winData.h,
										  winData.flags);

}
#pragma endregion
