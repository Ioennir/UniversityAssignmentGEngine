/*
**	Glass Engine
**	$filename
**	Author: Francisco Núñez Villagómez "Ioennir"
**	Date: 2019
*/
#pragma once
#include "glass.h"
#include "BaseObject.h"
#include "Sprite.h"

int32
main(int argc, 
	 char* args[]
	)
{
	EngineManagerS::CreateSingleton();
	EngineManagerS * EM = EngineManagerS::GetPTR();
	EM->Init();

	
	BaseObject * obj = new BaseObject(0, 0, 0, 0, 0, 1, new Sprite("D:/Escritorio/EngineWPP/2x3L.png"));
	//Game Loop
	uint32 i = 0;
	while (!EM->EndProgram())
	{
		EM->PreUpdate();
		InputManagerS * IM = InputManagerS::GetPTR();
		if (IM->GetKeyboardKeyValue(KEY_A)) {
			if(obj)
			{
				obj->Destroy();
				delete obj;
				obj = NULL;
			}
		}
		//GAMEPLAY
		//BaseObject * obj = new BaseObject(0,0,0,0,0,1,new Sprite("D:/Escritorio/EngineWPP/2x3L.png"));
#if DEBUG
		//printf("\nCurrentDT: %f\n", TM->DeltaTime());
		//printf("%i",IM->GetKeyboardKeyValue(KEY_A));
		//printf("\n%f",GetControllerAxisValue(0,AX_LJSX));
		//printf("\n0: %d , 1: %d",GetControllerButtonValue(0, GP_A), GetControllerButtonValue(1, GP_A));
#endif
		EM->PostUpdate();
	}
	
	return 0;
}
