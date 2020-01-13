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



class InputManagerS : public Singleton<InputManagerS>
{
	friend class Singleton<InputManagerS>;

private:
#pragma region Structures
	struct GameControllerInput
	{
		uint16	buttonValue;
		int16	LJSXAxis;
		int16	LJSYAxis;
		int16	RJSXAxis;
		int16	RJSYAxis;
		int16	LTAxis;
		int16	RTAxis;
	};

	struct KeyboardInput {
		uint64 keys;
	};

	struct MouseInput {
		int8 button_L;
		int8 button_R;
	};
#pragma endregion
	InputManagerS() {};

	//Vars
	bool8 joyCount;
	bool8 * endProgPTR;
	// Controllers
	SDL_GameController * connectedControllers[MAX_CONTROLLERS];

	// Event handler
	SDL_Event * eventHandler;

	// Input containers
	GameControllerInput * gameControllerStorage[MAX_CONTROLLERS];
	KeyboardInput * keyboardStorage;
	MouseInput * mouseStorage;
	
	void EventHandlingSystem();
	real32 RemapAxisValue(int16 value);
public:
	void Init(bool8 * endProgramWM);
	void Update();
	uint8 GetGameControllerIndex(uint8 instanceID);
	uint8 GetKeyboardKeyValue(uint64 keyCode);
	uint8 GetControllerButtonValue(uint8 deviceIndex, uint16 controllerCode);
	real32 GetControllerAxisValue(uint8 deviceIndex, uint16 axisCode);
};
