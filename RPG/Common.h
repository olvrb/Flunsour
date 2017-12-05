#ifndef __COMMON_H__
#define __COMMON_H__

#ifdef _MSC_VER
#pragma once
#endif  // _MSC_VER

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 360
#define REFRESH 60
#define SCALE 2
#include <iostream>
bool isRunning = true;
SDL_Renderer *renderer;

#endif