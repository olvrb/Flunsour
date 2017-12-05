#include "TextureLoader.h"

SDL_Texture *TextureLoader::LoadTexture(SDL_Renderer *renderer, const char *File) {
	SDL_Surface *TempSurface = IMG_Load(File);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, TempSurface);
	SDL_FreeSurface(TempSurface);
	return texture;
}