#ifndef __INPUT_H__
#define __INPUT_H__

#ifdef _MSC_VER
#pragma once
#endif  // _MSC_VER

#include <SDL.h>
#include "Common.h"

struct Controller {
	bool flip;
	int	xaxis;
	float rawxaxis;
	int	Min;
	int	Max;
	int	nMin;
	int	nMax;
	int	deadzoneMin;
	int deadzoneMax;
	bool Abutton;
	static Controller Input(Controller controller);
	static Controller LoadController();
};

#endif
