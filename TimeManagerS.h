/*
**	Glass Engine
**	$filename
**	Author: Francisco Núñez Villagómez "Ioennir"
**	Date: 2019
*/
#pragma once

#include "Singleton.h"
#include <SDL.h>
#include "dataDefinitions.h"

class TimeManagerS : public Singleton<TimeManagerS>
{
	friend class Singleton<TimeManagerS>;

private:
	uint64 lastTick;
	uint64 currentTick;
	real32 deltaTime;
public:
	void Init();
	void Update();
	inline uint32 CurrentTimeMS() { return (uint32)currentTick; };
	inline real32 DeltaTime() { return (real32)(deltaTime * 0.001); };
};