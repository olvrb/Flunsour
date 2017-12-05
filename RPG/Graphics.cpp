#include "Graphics.h"

int a = 0;
int i = 0;

Player Animation(Player player, int picsize, int piccount, Controller cntrl) {

	int ö = cntrl.xaxis;

	if (ö < 0) { ö = -ö; }
	if (a < ö) { a = ö; }
	if (a == ö) {
		player.src.x += picsize;
		if (player.src.x > picsize * (piccount - 1)) {
			player.src.x = 0;
		}
		a = 10 * SCALE;
	}
	a -= 2;
	return player;
}

void UpdatePlayer(SDL_Renderer *renderer, SDL_Texture *sprite, SDL_Rect src, SDL_Rect dst, bool flip) {
	if (flip == true) {
		SDL_RenderCopyEx(renderer, sprite, &src, &dst, NULL, NULL, SDL_FLIP_HORIZONTAL);
	}
	else {
		SDL_RenderCopy(renderer, sprite, &src, &dst);
	}
}

void UpdateBackground(SDL_Renderer *renderer, SDL_Texture *texture, SDL_Rect src) {
	SDL_RenderCopy(renderer, texture, &src, NULL);
}
