/*
**	Glass Engine
**	$filename
**	Author: Francisco Núñez Villagómez "Ioennir"
**	Date: 2019
*/
#pragma once
#include "Singleton.h"
#include <SDL.h>
#include <SDL_image.h>
#include "dataDefinitions.h"
#include <vector>
#include "WindowManagerS.h"
class BaseObject;


class GraphicManagerS : public Singleton<GraphicManagerS>
{
	friend class Singleton<GraphicManagerS>;

private:
	SDL_Renderer * renderer;
	uint32 objCount;
	std::vector<BaseObject *> renderObjects;
public:
	inline SDL_Renderer * GetRenderer() { return renderer; };
	void Init();
	void Update();
	void AddRenderObject(BaseObject * object);
	void DestroyObject(BaseObject * object);
};