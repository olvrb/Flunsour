#include "Player.h"
#include <iostream>

Player Player::LoadPlayer(int character) {
	Player player;
	player.isJumping = false;
	player.isStanding = false;
	player.xvelocity = 0;
	player.yvelocity = 0.2* SCALE;

	switch (character) {
	case 2:
		player.texture = TextureLoader::LoadTexture(renderer, "Running.png");

		player.src.x = 0;
		player.src.y = 0;
		player.src.w = 72;
		player.src.h = 52;

		player.dst.x = (WINDOW_WIDTH * SCALE) / 2;
		player.dst.y = (WINDOW_HEIGHT * SCALE) / 2;
		player.dst.w = player.src.w * SCALE;
		player.dst.h = player.src.h * SCALE;
		return player;
	}
}

Player Player::Ground(Player player, SDL_Rect* ground) {
	for (int i = 0; i < sizeof(ground) / 4; i++) {
		if (player.dst.y > (ground[i].y - player.dst.h) && Collision(player.dst, ground)[i] == true) {
			player.dst.y = ground[i].y - player.dst.h;
			player.isStanding = true;
			return player;
		}
		else if (player.dst.y == ground[i].y - player.dst.h) {
			player.isStanding = true;
			return player;
		}
		else {
			player.isStanding = false;
		}
	}
	std::cout << "ground: " << ground[1].y << std::endl;
	std::cout << "player: " << player.dst.y << std::endl;
	return player;
}

Player Player::Jump(Player player, Controller controller, SDL_Rect* ground) {
	for (int i = 0; i < sizeof(ground) - 1; i++) {
		if (controller.Abutton == true && Collision(player.dst, ground)[i] == true) {
			player.isJumping = true;
			return player;
		}
		else {
			player.isJumping = false;
		}
	}
	return player;
}

Player Player::Movement(Player player, Controller controller) {
	player.dst.x += controller.xaxis;
	if (player.isJumping == true) {
		player.yvelocity = -6 * SCALE;
	}
	return player;
}

Player Player::Gravity(Player player, Controller controller) {

	if ((player.isStanding == false) || (player.yvelocity < 10)) {
		player.yvelocity += 0.3 * SCALE;
		player.dst.y += player.yvelocity;
		return player;
	}
	else {
		player.yvelocity = 10;
		player.dst.y += player.yvelocity;
		return player;

	}
}
