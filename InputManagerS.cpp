/*
**	Glass Engine
**	$filename
**	Author: Francisco Núñez Villagómez "Ioennir"
**	Date: 2019
*/
#pragma once

#include "InputManagerS.h"

#if DEBUG
#include <stdio.h>
#endif



#pragma region Init()
// This function will only be called once
void 
InputManagerS::Init(bool8 * endProgramWM)
{
	//Initialization of the joyCount
	joyCount = 0;
	//Initialization of the eventHandler
	eventHandler = (SDL_Event *)malloc(sizeof(SDL_Event));
	//Initialization of a controllerStorage struct for every controller and set it to 0
	for (uint8 i = 0; i < MAX_CONTROLLERS; i++) {
		gameControllerStorage[i] = (GameControllerInput *)malloc(sizeof(GameControllerInput));
		*gameControllerStorage[i] = {};
	}
	//Initialization of the keyboardStorage struct and setting it to 0
	keyboardStorage = (KeyboardInput *)malloc(sizeof(KeyboardInput));
	*keyboardStorage = {};
	//Initialization of the mouseStorage struct and setting it to 0
	mouseStorage = (MouseInput*)malloc(sizeof(MouseInput));
	*mouseStorage = {};

	endProgPTR = endProgramWM;

#if DEBUG
	printf("\nInput Storage Initialized!");
#endif

}
#pragma endregion

#pragma region Update()
void
InputManagerS::Update()
{
	EventHandlingSystem();
}
#pragma endregion

#pragma region EventHandlingSystem(bool8 * endProgram)
void 
InputManagerS::EventHandlingSystem()
{
	while (SDL_PollEvent(eventHandler))
	{
		switch (eventHandler->type)
		{
		case SDL_QUIT: {
			*endProgPTR = 1;
			//why cleaning if you can let that to the OS bruh
			break;
		}
		case SDL_WINDOWEVENT: {
			//Window specific event: resize, minimize, maximize etc
			break;
		}
		case SDL_KEYDOWN: {
			if (!eventHandler->key.repeat)
			{
				switch (eventHandler->key.keysym.sym)
				{
				case SDLK_q:
					keyboardStorage->keys |= KEY_Q;
					break;
				case SDLK_w:
					keyboardStorage->keys |= KEY_W;
					break;
				case SDLK_e:
					keyboardStorage->keys |= KEY_E;
					break;
				case SDLK_r:
					keyboardStorage->keys |= KEY_R;
					break;
				case SDLK_t:
					keyboardStorage->keys |= KEY_T;
					break;
				case SDLK_y:
					keyboardStorage->keys |= KEY_Y;
					break;
				case SDLK_u:
					keyboardStorage->keys |= KEY_U;
					break;
				case SDLK_i:
					keyboardStorage->keys |= KEY_I;
					break;
				case SDLK_o:
					keyboardStorage->keys |= KEY_O;
					break;
				case SDLK_p:
					keyboardStorage->keys |= KEY_P;
					break;
				case SDLK_a:
					keyboardStorage->keys |= KEY_A;
					break;
				case SDLK_s:
					keyboardStorage->keys |= KEY_S;
					break;
				case SDLK_d:
					keyboardStorage->keys |= KEY_D;
					break;
				case SDLK_f:
					keyboardStorage->keys |= KEY_F;
					break;
				case SDLK_g:
					keyboardStorage->keys |= KEY_G;
					break;
				case SDLK_h:
					keyboardStorage->keys |= KEY_H;
					break;
				case SDLK_j:
					keyboardStorage->keys |= KEY_J;
					break;
				case SDLK_k:
					keyboardStorage->keys |= KEY_K;
					break;
				case SDLK_l:
					keyboardStorage->keys |= KEY_L;
					break;
				case SDLK_z:
					keyboardStorage->keys |= KEY_Z;
					break;
				case SDLK_x:
					keyboardStorage->keys |= KEY_X;
					break;
				case SDLK_c:
					keyboardStorage->keys |= KEY_C;
					break;
				case SDLK_v:
					keyboardStorage->keys |= KEY_V;
					break;
				case SDLK_b:
					keyboardStorage->keys |= KEY_B;
					break;
				case SDLK_n:
					keyboardStorage->keys |= KEY_N;
					break;
				case SDLK_m:
					keyboardStorage->keys |= KEY_M;
					break;
				case SDLK_UP:
					keyboardStorage->keys |= ARROW_UP;
					break;
				case SDLK_LEFT:
					keyboardStorage->keys |= ARROW_LEFT;
					break;
				case SDLK_DOWN:
					keyboardStorage->keys |= ARROW_DOWN;
					break;
				case SDLK_RIGHT:
					keyboardStorage->keys |= ARROW_RIGHT;
					break;
				case SDLK_SPACE:
					keyboardStorage->keys |= KEY_SPACE;
					break;
				case SDLK_ESCAPE:
					keyboardStorage->keys |= KEY_ESC;
					break;
				case SDLK_KP_ENTER:
					keyboardStorage->keys |= KEY_ENTER;
					break;
				case SDLK_LCTRL:
				case SDLK_RCTRL:
					keyboardStorage->keys |= KEY_CTRL;
					break;
				case SDLK_LSHIFT:
				case SDLK_RSHIFT:
					keyboardStorage->keys |= KEY_SHIFT;
					break;
				case SDLK_RALT:
				case SDLK_LALT:
					keyboardStorage->keys |= KEY_ALT;
					break;
				case SDLK_0:
					keyboardStorage->keys |= KEY_0;
					break;
				case SDLK_1:
					keyboardStorage->keys |= KEY_1;
					break;
				case SDLK_2:
					keyboardStorage->keys |= KEY_2;
					break;
				case SDLK_3:
					keyboardStorage->keys |= KEY_3;
					break;
				case SDLK_4:
					keyboardStorage->keys |= KEY_4;
					break;
				case SDLK_5:
					keyboardStorage->keys |= KEY_5;
					break;
				case SDLK_6:
					keyboardStorage->keys |= KEY_6;
					break;
				case SDLK_7:
					keyboardStorage->keys |= KEY_7;
					break;
				case SDLK_8:
					keyboardStorage->keys |= KEY_8;
					break;
				case SDLK_9:
					keyboardStorage->keys |= KEY_9;
					break;
				}
			}
			break;
		}
		case SDL_KEYUP: {
			switch (eventHandler->key.keysym.sym)
			{
			case SDLK_q:
				keyboardStorage->keys ^= KEY_Q;
				break;
			case SDLK_w:
				keyboardStorage->keys ^= KEY_W;
				break;
			case SDLK_e:
				keyboardStorage->keys ^= KEY_E;
				break;
			case SDLK_r:
				keyboardStorage->keys ^= KEY_R;
				break;
			case SDLK_t:
				keyboardStorage->keys ^= KEY_T;
				break;
			case SDLK_y:
				keyboardStorage->keys ^= KEY_Y;
				break;
			case SDLK_u:
				keyboardStorage->keys ^= KEY_U;
				break;
			case SDLK_i:
				keyboardStorage->keys ^= KEY_I;
				break;
			case SDLK_o:
				keyboardStorage->keys ^= KEY_O;
				break;
			case SDLK_p:
				keyboardStorage->keys ^= KEY_P;
				break;
			case SDLK_a:
				keyboardStorage->keys ^= KEY_A;
				break;
			case SDLK_s:
				keyboardStorage->keys ^= KEY_S;
				break;
			case SDLK_d:
				keyboardStorage->keys ^= KEY_D;
				break;
			case SDLK_f:
				keyboardStorage->keys ^= KEY_F;
				break;
			case SDLK_g:
				keyboardStorage->keys ^= KEY_G;
				break;
			case SDLK_h:
				keyboardStorage->keys ^= KEY_H;
				break;
			case SDLK_j:
				keyboardStorage->keys ^= KEY_J;
				break;
			case SDLK_k:
				keyboardStorage->keys ^= KEY_K;
				break;
			case SDLK_l:
				keyboardStorage->keys ^= KEY_L;
				break;
			case SDLK_z:
				keyboardStorage->keys ^= KEY_Z;
				break;
			case SDLK_x:
				keyboardStorage->keys ^= KEY_X;
				break;
			case SDLK_c:
				keyboardStorage->keys ^= KEY_C;
				break;
			case SDLK_v:
				keyboardStorage->keys ^= KEY_V;
				break;
			case SDLK_b:
				keyboardStorage->keys ^= KEY_B;
				break;
			case SDLK_n:
				keyboardStorage->keys ^= KEY_N;
				break;
			case SDLK_m:
				keyboardStorage->keys ^= KEY_M;
				break;
			case SDLK_UP:
				keyboardStorage->keys ^= ARROW_UP;
				break;
			case SDLK_LEFT:
				keyboardStorage->keys ^= ARROW_LEFT;
				break;
			case SDLK_DOWN:
				keyboardStorage->keys ^= ARROW_DOWN;
				break;
			case SDLK_RIGHT:
				keyboardStorage->keys ^= ARROW_RIGHT;
				break;
			case SDLK_SPACE:
				keyboardStorage->keys ^= KEY_SPACE;
				break;
			case SDLK_ESCAPE:
				keyboardStorage->keys ^= KEY_ESC;
				break;
			case SDLK_KP_ENTER:
				keyboardStorage->keys ^= KEY_ENTER;
				break;
			case SDLK_LCTRL:
			case SDLK_RCTRL:
				keyboardStorage->keys ^= KEY_CTRL;
				break;
			case SDLK_LSHIFT:
			case SDLK_RSHIFT:
				keyboardStorage->keys ^= KEY_SHIFT;
				break;
			case SDLK_RALT:
			case SDLK_LALT:
				keyboardStorage->keys ^= KEY_ALT;
				break;
			case SDLK_0:
				keyboardStorage->keys ^= KEY_0;
				break;
			case SDLK_1:
				keyboardStorage->keys ^= KEY_1;
				break;
			case SDLK_2:
				keyboardStorage->keys ^= KEY_2;
				break;
			case SDLK_3:
				keyboardStorage->keys ^= KEY_3;
				break;
			case SDLK_4:
				keyboardStorage->keys ^= KEY_4;
				break;
			case SDLK_5:
				keyboardStorage->keys ^= KEY_5;
				break;
			case SDLK_6:
				keyboardStorage->keys ^= KEY_6;
				break;
			case SDLK_7:
				keyboardStorage->keys ^= KEY_7;
				break;
			case SDLK_8:
				keyboardStorage->keys ^= KEY_8;
				break;
			case SDLK_9:
				keyboardStorage->keys ^= KEY_9;
				break;
			}
			break;
		}
		case SDL_MOUSEMOTION: {
			break;
		}
		case SDL_MOUSEBUTTONDOWN: {
			break;
		}
		case SDL_MOUSEBUTTONUP: {
			break;
		}
		case SDL_MOUSEWHEEL: {
			break;
		}
		case SDL_CONTROLLERAXISMOTION: {
			//INFO(fran):
			uint8 index = eventHandler->cdevice.which;
			if (index < MAX_CONTROLLERS)
			{
				int16 axisValue = eventHandler->caxis.value;
				switch (eventHandler->caxis.axis)
				{
				case SDL_CONTROLLER_AXIS_LEFTX: {
					gameControllerStorage[index]->LJSXAxis = axisValue;
					break;
				}
				case SDL_CONTROLLER_AXIS_LEFTY: {
					gameControllerStorage[index]->LJSYAxis = axisValue;
					break;
				}
				case SDL_CONTROLLER_AXIS_RIGHTX: {
					gameControllerStorage[index]->RJSXAxis = axisValue;
					break;
				}
				case SDL_CONTROLLER_AXIS_RIGHTY: {
					gameControllerStorage[index]->RJSYAxis = axisValue;
					break;
				}
				case SDL_CONTROLLER_AXIS_TRIGGERLEFT: {
					gameControllerStorage[index]->LTAxis = axisValue;
					break;
				}
				case SDL_CONTROLLER_AXIS_TRIGGERRIGHT: {
					gameControllerStorage[index]->RTAxis = axisValue;
					break;
				}
				}
			}
			break;
		}
		case SDL_CONTROLLERBUTTONDOWN: {
			//TODO(fran): Maybe Handle repeating buttons
			//INFO(fran): SDL_CONTROLLER_BUTTON_GUIDE is xbox button
			uint8 instanceID = eventHandler->cdevice.which;
			uint8 index = GetGameControllerIndex(instanceID);
			if (index < MAX_CONTROLLERS)
			{
				printf("%d", index);
				switch (eventHandler->cbutton.button)
				{
				case SDL_CONTROLLER_BUTTON_A:
					gameControllerStorage[index]->buttonValue |= GP_A;
					break;
				case SDL_CONTROLLER_BUTTON_B:
					gameControllerStorage[index]->buttonValue |= GP_B;
					break;
				case SDL_CONTROLLER_BUTTON_X:
					gameControllerStorage[index]->buttonValue |= GP_X;
					break;
				case SDL_CONTROLLER_BUTTON_Y:
					gameControllerStorage[index]->buttonValue |= GP_Y;
					break;
				case SDL_CONTROLLER_BUTTON_RIGHTSHOULDER:
					gameControllerStorage[index]->buttonValue |= GP_RB;
					break;
				case SDL_CONTROLLER_BUTTON_LEFTSHOULDER:
					gameControllerStorage[index]->buttonValue |= GP_LB;
					break;
				case SDL_CONTROLLER_BUTTON_START:
					gameControllerStorage[index]->buttonValue |= GP_START;
					break;
				case SDL_CONTROLLER_BUTTON_BACK:
					gameControllerStorage[index]->buttonValue |= GP_SELECT;
					break;
				case SDL_CONTROLLER_BUTTON_LEFTSTICK:
					gameControllerStorage[index]->buttonValue |= GP_LSB;
					break;
				case SDL_CONTROLLER_BUTTON_RIGHTSTICK:
					gameControllerStorage[index]->buttonValue |= GP_RSB;
					break;
				case SDL_CONTROLLER_BUTTON_DPAD_UP:
					gameControllerStorage[index]->buttonValue |= GP_DPU;
					break;
				case SDL_CONTROLLER_BUTTON_DPAD_DOWN:
					gameControllerStorage[index]->buttonValue |= GP_DPD;
					break;
				case SDL_CONTROLLER_BUTTON_DPAD_LEFT:
					gameControllerStorage[index]->buttonValue |= GP_DPL;
					break;
				case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:
					gameControllerStorage[index]->buttonValue |= GP_DPR;
					break;
				}
			}
			break;
		}
		case SDL_CONTROLLERBUTTONUP: {
			uint8 instanceID = eventHandler->cdevice.which;
			uint8 index = GetGameControllerIndex(instanceID);
			if (index < MAX_CONTROLLERS)
			{
				switch (eventHandler->cbutton.button)
				{
				case SDL_CONTROLLER_BUTTON_A:
					gameControllerStorage[index]->buttonValue ^= GP_A;
					break;
				case SDL_CONTROLLER_BUTTON_B:
					gameControllerStorage[index]->buttonValue ^= GP_B;
					break;
				case SDL_CONTROLLER_BUTTON_X:
					gameControllerStorage[index]->buttonValue ^= GP_X;
					break;
				case SDL_CONTROLLER_BUTTON_Y:
					gameControllerStorage[index]->buttonValue ^= GP_Y;
					break;
				case SDL_CONTROLLER_BUTTON_RIGHTSHOULDER:
					gameControllerStorage[index]->buttonValue ^= GP_RB;
					break;
				case SDL_CONTROLLER_BUTTON_LEFTSHOULDER:
					gameControllerStorage[index]->buttonValue ^= GP_LB;
					break;
				case SDL_CONTROLLER_BUTTON_START:
					gameControllerStorage[index]->buttonValue ^= GP_START;
					break;
				case SDL_CONTROLLER_BUTTON_BACK:
					gameControllerStorage[index]->buttonValue ^= GP_SELECT;
					break;
				case SDL_CONTROLLER_BUTTON_LEFTSTICK:
					gameControllerStorage[index]->buttonValue ^= GP_LSB;
					break;
				case SDL_CONTROLLER_BUTTON_RIGHTSTICK:
					gameControllerStorage[index]->buttonValue ^= GP_RSB;
					break;
				case SDL_CONTROLLER_BUTTON_DPAD_UP:
					gameControllerStorage[index]->buttonValue ^= GP_DPU;
					break;
				case SDL_CONTROLLER_BUTTON_DPAD_DOWN:
					gameControllerStorage[index]->buttonValue ^= GP_DPD;
					break;
				case SDL_CONTROLLER_BUTTON_DPAD_LEFT:
					gameControllerStorage[index]->buttonValue ^= GP_DPL;
					break;
				case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:
					gameControllerStorage[index]->buttonValue ^= GP_DPR;
					break;
				}
			}
			break;
		}
		case SDL_CONTROLLERDEVICEADDED: {
			// Note(fran): Here the which returns the actual index, not the instance id.
			// The instance id (which is returned in removed) increases every time you plug
			// a controller.
			joyCount = SDL_NumJoysticks();
			uint8 index = eventHandler->cdevice.which;
			if (index < MAX_CONTROLLERS && joyCount) {
				connectedControllers[index] = SDL_GameControllerOpen(index);

				if (!connectedControllers[index]) {
					printf("\nCouldn't open game controller");
				}
			}
#if DEBUG
			printf("\nNew controller plugged. Controller Array Index: %d", index);
#endif
			break;
		}
		case SDL_CONTROLLERDEVICEREMOVED: {
			// Note(fran):
			joyCount = SDL_NumJoysticks();
			uint8 instanceID = eventHandler->cdevice.which;
			uint8 index = GetGameControllerIndex(instanceID);
			if (index < MAX_CONTROLLERS)
			{
				SDL_GameControllerClose(connectedControllers[index]);
				connectedControllers[index] = 0;
			}
#if DEBUG
			printf("\nNew controller unplugged. Controller Array Index: %d", index);
#endif
			break;
		}
		}
	}
}
#pragma endregion

#pragma region GetGameControllerIndex()
uint8
InputManagerS::GetGameControllerIndex(uint8 instanceID)
{
	for (uint8 i = 0; i < MAX_CONTROLLERS; i++) {
		if (instanceID == SDL_JoystickInstanceID(SDL_GameControllerGetJoystick(connectedControllers[i])))
		{
			return i;
		}
	}
	return MAX_CONTROLLERS;
}
#pragma endregion

#pragma region GetKeyboardKeyValue()
uint8 
InputManagerS::GetKeyboardKeyValue(uint64 keyCode)
{
	return ((keyboardStorage->keys & keyCode) == keyCode);
}
#pragma endregion

#pragma region GetControllerButtonValue()
uint8
InputManagerS::GetControllerButtonValue(uint8 deviceIndex, uint16 controllerCode)
{
	return ((gameControllerStorage[deviceIndex]->buttonValue & controllerCode) == controllerCode);
}
#pragma endregion

#pragma region GetControllerAxisValue()
real32
InputManagerS::GetControllerAxisValue(uint8 deviceIndex, uint16 axisCode)
{
	switch (axisCode)
	{
	case AX_LJSX: {
		return RemapAxisValue(gameControllerStorage[deviceIndex]->LJSXAxis);
		break;
	}
	case AX_LJSY: {
		return RemapAxisValue(gameControllerStorage[deviceIndex]->LJSYAxis);
		break;
	}
	case AX_RJSX: {
		return RemapAxisValue(gameControllerStorage[deviceIndex]->RJSXAxis);
		break;
	}
	case AX_RJSY: {
		return RemapAxisValue(gameControllerStorage[deviceIndex]->RJSYAxis);
		break;
	}
	case AX_LTAX: {
		return RemapAxisValue(gameControllerStorage[deviceIndex]->LTAxis);
		break;
	}
	case AX_RTAX: {
		return RemapAxisValue(gameControllerStorage[deviceIndex]->RTAxis);
		break;
	}
	default: {
		//Invalid value
		return 0.0f;
		break;
	}
	}
}
#pragma endregion

#pragma region RemapAxisValue()
real32
InputManagerS::RemapAxisValue(int16 value)
{
	return (!(value > -ABSDEADZONE && value < ABSDEADZONE) ? (value < 0 ? ((real32)value / int16min) : ((real32)value / int16max)) : 0.0f);
}
#pragma endregion