/*
**	Glass Engine
**	$filename
**	Author: Francisco Núñez Villagómez "Ioennir"
**	Date: 2019
*/
// Other includes
#pragma once

#include "EngineManagerS.h"

void 
EngineManagerS::Init()
{
	TimeManagerS::CreateSingleton();
	TM = TimeManagerS::GetPTR();
	TM->Init();

	WindowManagerS::CreateSingleton();
	WM = WindowManagerS::GetPTR();
	WM->Init();
	endProgram = WM->getEndProgram();

	InputManagerS::CreateSingleton();
	IM = InputManagerS::GetPTR();
	IM->Init(endProgram);

	ObjectManagerS::CreateSingleton();
	OM = ObjectManagerS::GetPTR();
	OM->Init();

	GraphicManagerS::CreateSingleton();
	GM = GraphicManagerS::GetPTR();
	GM->Init();
}

void
EngineManagerS::PreUpdate()
{
	TM->Update();
	IM->Update();
}

void 
EngineManagerS::PostUpdate()
{
	OM->Update();
	GM->Update();
}