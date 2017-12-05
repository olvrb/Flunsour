#include "Input.h"

Controller Controller::Input(Controller controller) {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {

		switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;
		case SDL_JOYAXISMOTION:
			switch (event.jaxis.axis) {
			case SDL_CONTROLLER_AXIS_LEFTX:
				controller.rawxaxis = event.jaxis.value;
				if (controller.rawxaxis > controller.Max) controller.rawxaxis = controller.Max;
				if (controller.rawxaxis < controller.Min) controller.rawxaxis = controller.Min;
				if (controller.rawxaxis > controller.deadzoneMax || controller.rawxaxis < controller.deadzoneMin) {
					controller.xaxis = round((controller.nMax * controller.rawxaxis) / controller.Max);
					if (controller.xaxis > 0) {
						controller.flip = false;
					}
					else if (controller.xaxis < 0) {
						controller.flip = true;
					}
					break;
				}
				else {
					controller.xaxis = 0;
				}
			}
			break;
		case SDL_CONTROLLERBUTTONDOWN:
			switch (event.cbutton.button) {
			case SDL_CONTROLLER_BUTTON_A:
				controller.Abutton = true;
				break;
			}
			break;
		case SDL_CONTROLLERBUTTONUP:
			switch (event.cbutton.button) {
			case SDL_CONTROLLER_BUTTON_A:
				controller.Abutton = false;
				break;
			}
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_SPACE:
				controller.Abutton = true;
				break;
			case SDLK_LEFT:
				controller.xaxis = controller.nMin;
				controller.flip = true;
				break;
			case SDLK_RIGHT:
				controller.xaxis = controller.nMax;
				controller.flip = false;
				break;
			}
			break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym) {
			case SDLK_SPACE:
				controller.Abutton = false;
				break;
			case SDLK_LEFT:
				controller.xaxis = 0;
			case SDLK_RIGHT:
				controller.xaxis = 0;
			}
		}
	}
	return controller;
}

Controller Controller::LoadController() {
	Controller controller;
	controller.flip = 1;
	controller.xaxis = 0;
	controller.rawxaxis = 0;
	controller.Min = -32768;
	controller.Max = 32767;
	controller.nMin = -6 * SCALE;
	controller.nMax = 6 * SCALE;
	controller.deadzoneMin = -7000;
	controller.deadzoneMax = 7000;
	controller.Abutton = false;

	return controller;
}