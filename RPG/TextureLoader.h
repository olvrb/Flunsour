#ifndef __TEXTURE_LOADER_H__
#define __TEXTURE_LOADER_H__

#ifdef _MSC_VER
#pragma once
#endif  // _MSC_VER

#include <SDL_image.h>

namespace TextureLoader {
	SDL_Texture *LoadTexture(SDL_Renderer *renderer, const char *File);
}

#endif