#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

#ifdef _MSC_VER
#pragma once
#endif  // _MSC_VER

#include "SDL.h"
#include "Common.h"
#include "GameObject.h"
#include "Player.h"
#include "Input.h"
#include "TextureLoader.h"

Player Animation(Player player, int picsize, int piccount, Controller cntrl);
void UpdatePlayer(SDL_Renderer *renderer, SDL_Texture *sprite, SDL_Rect src, SDL_Rect dst, bool flip);
void UpdateBackground(SDL_Renderer *renderer, SDL_Texture *texture, SDL_Rect src);

#endif