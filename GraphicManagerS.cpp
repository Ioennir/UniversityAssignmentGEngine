/*
**	Glass Engine
**	$filename
**	Author: Francisco Núñez Villagómez "Ioennir"
**	Date: 2019
*/
#pragma once
#include "GraphicManagerS.h"
#include "BaseObject.h"

void
GraphicManagerS::Init()
{
	objCount = 0;
	renderer = SDL_CreateRenderer(WindowManagerS::GetPTR()->GetWindow(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	IMG_Init(IMG_INIT_PNG);
}

void
GraphicManagerS::Update()
{
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);
	for (uint32 i = 0; i < objCount; i++)
	{
		renderObjects[i]->Draw();
	}
	SDL_RenderPresent(renderer);
}


void
GraphicManagerS::AddRenderObject(BaseObject * object) {
	objCount++;
	renderObjects.push_back(object);
}

void
GraphicManagerS::DestroyObject(BaseObject * object) {
	uint32 i = 0;
	for (i; i < objCount; i++) {
		if (renderObjects[i] == object) {
			renderObjects.erase(renderObjects.begin() + i);
			objCount--;
			break;
		}
	}
}