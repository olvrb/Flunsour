#ifndef __PLAYER_H__
#define __PLAYER_H__

#ifdef _MSC_VER
#pragma once
#endif  // _MSC_VER

#include <SDL.h>
#include "TextureLoader.h"
#include "Common.h"
#include "GameObject.h"
#include "Input.h"

struct Player {
	SDL_Rect src;
	SDL_Rect dst;
	SDL_Texture* texture;
	bool isJumping;
	bool isStanding;
	int xvelocity;
	double yvelocity;
	static Player LoadPlayer(int character);
	static Player Ground(Player player, SDL_Rect* ground);
	static Player Jump(Player player, Controller controller, SDL_Rect* ground);
	static Player Movement(Player player, Controller controller);
	static Player Gravity(Player player, Controller controller);
};

#endif