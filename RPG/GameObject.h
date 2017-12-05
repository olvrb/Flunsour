#ifndef __GAME_OBJECT_H__
#define __GAME_OBJECT_H__

#ifdef _MSC_VER
#pragma once
#endif  // _MSC_VER

#include <SDL.h>
#include "Common.h"
#include "TextureLoader.h"
#include "Input.h"

struct GameObject {
	SDL_Rect src;
	SDL_Rect dst;
	SDL_Texture *texture;
	SDL_Surface *loadtexture;
};

GameObject LoadBackground(int level);
GameObject LoadForeground(int level);
SDL_Rect* LoadPlatforms(int level);
bool* Collision(SDL_Rect A, SDL_Rect* B);

#endif