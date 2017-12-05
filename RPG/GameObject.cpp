#include "GameObject.h"

GameObject LoadBackground(int level) {

	GameObject background;

	switch (level) {
	case 1:
		background.texture = TextureLoader::LoadTexture(renderer, "Linus.png");
		background.src.x = 0;
		background.src.y = 0;
		background.src.w = 464;
		background.src.h = 261;
		return background;
	case 2:
		background.texture = TextureLoader::LoadTexture(renderer, "MetalSlug.png");
		background.src.x = 0;
		background.src.y = 0;
		background.src.w = 384;
		background.src.h = 216;
		return background;
	default:
		background.texture = nullptr;
		background.src.x = 0;
		background.src.y = 0;
		background.src.w = 0;
		background.src.h = 0;
		return background;
	}
}

GameObject LoadForeground(int level) {

	GameObject foreground;

	switch (level) {
	case 1:
		foreground.texture = TextureLoader::LoadTexture(renderer, "Foreground.png");
		foreground.src.x = 0;
		foreground.src.y = 0;
		foreground.src.w = 1920;
		foreground.src.h = 1080;
		return foreground;
	case 2:
		foreground.texture = TextureLoader::LoadTexture(renderer, "MetalSlug.png");
		foreground.src.x = 0;
		foreground.src.y = 0;
		foreground.src.w = 384;
		foreground.src.h = 216;
		return foreground;
	default:
		foreground.texture = nullptr;
		foreground.src.x = 0;
		foreground.src.y = 0;
		foreground.src.w = 0;
		foreground.src.h = 0;
		return foreground;
	}
}

SDL_Rect* LoadPlatforms(int level) {

	switch (level) {
	case 1: {

		SDL_Rect platform1;
		SDL_Rect platform2;

		platform1.x = 0;
		platform1.y = 460;
		platform1.w = 300;
		platform1.h = 20;

		platform2.x = 0;
		platform2.y = (WINDOW_HEIGHT * SCALE) - 160;
		platform2.w = WINDOW_WIDTH * SCALE;
		platform2.h = 720;

		SDL_Rect yo[2] = { platform1, platform2 };

		return yo;
	}
	case 2: {

		SDL_Rect platform1;
		SDL_Rect platform2;

		platform1.x = 0;
		platform1.y = 400;
		platform1.w = 300;
		platform1.h = 20;

		platform2.x = 0;
		platform2.y = (WINDOW_HEIGHT * SCALE) - 160;
		platform2.w = WINDOW_WIDTH * SCALE;
		platform2.h = 720;

		SDL_Rect yo[2] = { platform1, platform2 };

		return yo;
	}
	}
}

bool* Collision(SDL_Rect A, SDL_Rect* B) {

	const int size = sizeof(B) / 4;
	bool col[size];
	bool col2;
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	for (int i = 0; i <= size - 1; i++) {

		leftA = A.x;
		rightA = A.x + A.w;
		topA = A.y;
		bottomA = A.y + A.h;

		leftB = B[i].x;
		rightB = B[i].x + B[i].w;
		topB = B[i].y;
		bottomB = B[i].y + B[i].h;

		col2 = true;

		if (bottomA <= topB)
		{
			col2 = false;
		}

		if (topA >= bottomB)
		{
			col2 = false;
		}

		if (rightA <= leftB)
		{
			col2 = false;
		}

		if (leftA >= rightB)
		{
			col2 = false;
		}
		col[i] = col2;
	}
	return col;
}
