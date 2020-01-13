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

class WindowManagerS : public Singleton<WindowManagerS>
{
	friend class Singleton<WindowManagerS>;
private:
#pragma region Structures
	struct windowData
	{
		const char * name;
		int32 x;
		int32 y;
		int32 w;
		int32 h;
		uint32 flags;
	};
#pragma endregion
	windowData winData;
	SDL_Window * currWindowInstance;
	uint32 currWinFlags;
	bool8 winInit;
	bool8 endProgram;
	WindowManagerS() {};
	void WindowInit();
	void FillDefaultWindowData();
	void CreateWindow();
public:
#pragma region Methods
	void Init();
	void Update();
	inline bool8 * getEndProgram() { return &endProgram; }
	void SetWindowResizeData(const char * name, int32 x, int32 y, int32 w, int32 h, uint32 flags);
	inline bool8 WindowInitialized() { return winInit; }
	inline bool8 WindowInstanceCreated() { return (currWindowInstance ? 1 : 0); }
	inline SDL_Window * GetWindow() { return currWindowInstance; };
#pragma endregion Methods
};