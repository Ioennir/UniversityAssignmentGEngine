/*
**	Glass Engine
**	$filename
**	Author: Francisco Núñez Villagómez "Ioennir"
**	Date: 2019
*/
// Other includes
#pragma once

#include "Singleton.h"

#include "InputManagerS.h"
#include "WindowManagerS.h"
#include "TimeManagerS.h"
#include "ObjectManagerS.h"
#include "GraphicManagerS.h"
#include "BaseObject.h"

class EngineManagerS : public Singleton<EngineManagerS>
{
	friend class Singleton<EngineManagerS>;
private:
	bool8 * endProgram;
	TimeManagerS * TM;
	WindowManagerS * WM;
	InputManagerS * IM;
	ObjectManagerS * OM;
	GraphicManagerS * GM;
public:
	inline bool8 EndProgram() { return *endProgram; };
	void Init();
	void PreUpdate();
	void PostUpdate();
};