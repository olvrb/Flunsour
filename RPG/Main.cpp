#include <iostream>
#include <SDL.h>
#include "Common.h"
#include "GameObject.h"
#include "Movement.h"
#include "Graphics.h"
#include "Input.h"
#include "Player.h"

int main(int argc, char *argv[]) {

	SDL_Window *window;
	int frametime = 1;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		fprintf(stderr, "Couldn't initialize SDL: %s\n", SDL_GetError());
		exit(1);
	}
	for (int i = 0; i < SDL_NumJoysticks(); ++i) {
		if (SDL_IsGameController(i)) {
			printf("Index \'%i\' is a compatible controller, named \'%s\'\n", i, SDL_GameControllerNameForIndex(i));
			SDL_GameController *ctrlr = SDL_GameControllerOpen(i);
			SDL_Joystick *joy = SDL_GameControllerGetJoystick(ctrlr);
		}
		else {
			printf("Index \'%i\' is not a compatible controller.\n", i);
		}
	}
	window = SDL_CreateWindow("Zelda", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH * SCALE, WINDOW_HEIGHT * SCALE, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, 0);

	Player player = Player::LoadPlayer(2);
	GameObject background = LoadBackground(1);
	Controller xbox = Controller::LoadController();
	SDL_Rect platforms[2] = { LoadPlatforms(1)[0], LoadPlatforms(1)[1] };
	while (isRunning == true) { 

		xbox = Controller::Input(xbox);
		player = Player::Gravity(player, xbox);
		player = Player::Jump(player, xbox, platforms);
		player = Player::Ground(player, platforms);
		player = Player::Movement(player, xbox);
		if (xbox.xaxis != 0) { player = Animation(player, 72, 4, xbox); }
    	//std::cout << "isStanding = " << player.isStanding << std::endl;
	    //std::cout << "isJumping = " << player.isJumping << std::endl;

		UpdateBackground(renderer, background.texture, background.src);
		UpdatePlayer(renderer, player.texture, player.src, player.dst, xbox.flip);
		SDL_RenderPresent(renderer);

		SDL_Delay(1000 / 60);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	window = nullptr;

	SDL_Quit();
	return 0;
}
