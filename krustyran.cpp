#include <CoalaMOD.h>
#pragma comment(lib, "CoalaMOD.lib")

#include <stdio.h>
#include <cmath>

#define M_PI 3.14159265358979323846

BlockID B_quartz = createBlock(BLOCK_NETHER_QUARTZ);
BlockID B_bone = createBlock(BLOCK_BONE);
BlockID B_glowstone = createBlock(BLOCK_GLOWSTONE);
BlockID B_WhiteGlass = createBlock(BLOCK_STAINED_GLASS);
BricksID B_brick = createBricks(BRICKS_STONE);
BlockID B_water = createWater(true);
BlockID B_sand = createBlock(BLOCK_SAND);
BlockID B_wood = createWood(WOOD_OAK, STRIP_ALL_SIDE);
BlockID B_air = createBlock(BLOCK_AIR);
BlockID wool_orange = createWool(COLOR_ORANGE);
BlockID wool_yellow = createWool(COLOR_YELLOW);
BlockID wool_blue = createWool(COLOR_BLUE);
BlockID wool_white = createWool(COLOR_WHITE);
BlockID wool_red = createWool(COLOR_RED);
BlockID wool_green = createWool(COLOR_GREEN);
BlockID wool_lime = createWool(COLOR_LIME);
BlockID wool_gray = createWool(COLOR_GRAY);
BlockID wool_lightgray = createWool(COLOR_LIGHT_GRAY);
BlockID wool_lightblue = createWool(COLOR_LIGHT_BLUE);
BlockID nether_fence = createFence(FenceType(7));
BlockID plank_fence = createFence(FenceType(1));
BlockID netherrack = createBlock(BLOCK_NETHERRACK);
BlockID glass = createBlock(BLOCK_GLASS);
BlockID grass = createBlock(BLOCK_GRASS);





void ellipse(BlockID block, char dir, int Bradius, int Sradius, int x, int y, int z) {
	for (int deg = 0; deg < 360; deg++) {
		if (dir == 'x') {
			locateBlock(block, x, y + Bradius * sin(M_PI / 180 * deg), z + Sradius * cos(M_PI / 180 * deg));
		}
		if (dir == 'y') {
			locateBlock(block, x + Bradius * sin(M_PI / 180 * deg), y, z + Sradius * cos(M_PI / 180 * deg));
		}
		if (dir == 'z') {
			locateBlock(block, x + Bradius * sin(M_PI / 180 * deg), y + Sradius * cos(M_PI / 180 * deg), z);
		}
	}
}

void circle(BlockID block, int radius, int x, int y, int z) {
	for (int i = -radius; i < radius; i++) {
		for (int j = -radius; j < radius; j++) {
			if (i*i + j * j < radius * radius) {
				locateBlock(block, x + i, y, z + j);
			}
		}
	}
}

void circle_x(BlockID block, int radius, int x, int y, int z) {
	for (int i = -radius; i < radius; i++) {
		for (int j = -radius; j < radius; j++) {
			if (i*i + j * j < radius * radius) {
				locateBlock(block, x , y + i, z + j);
			}
		}
	}
}


void circle_z(BlockID block, int radius, int x, int y, int z) {
	for (int i = -radius; i < radius; i++) {
		for (int j = -radius; j < radius; j++) {
			if (i*i + j * j < radius * radius) {
				locateBlock(block, x + j, y + i, z);
			}
		}
	}
}


void sphere(BlockID block, int radius, int x, int y, int z) {
	for (int i = -radius; i < radius; i++) {
		for (int j = -radius; j < radius; j++) {
			for (int k = -radius; k < radius; k++) {
				if (i*i + j * j + k * k < radius * radius) {
					locateBlock(block, x + i, y + k, z + j);
				}
			}
		}
	}
}


void walls(BlockID block, int x1, int y1, int z1, int x2, int y2, int z2) {
	int x = (x1 < x2) ? x1 : x2, y = (y1 < y2) ? y1 : y2, z = (z1 < z2) ? z1 : z2;
	for (int i = 0; i < ((y1 - y2 == 0) ? 1 : abs(y1 - y2)); i++) {
		for (int j = 0; j <= ((x1 - x2 == 0) ? 1 : abs(x1 - x2)); j++) {
			locateBlock(block, x + j, y + i, z1);
			locateBlock(block, x + j, y + i, z2);
		}
		for (int k = 0; k <= ((z1 - z2 == 0) ? 1 : abs(z1 - z2)); k++) {
			locateBlock(block, x1, y + i, z + k);
			locateBlock(block, x2, y + i, z + k);
		}
	}
}

void set(BlockID block, int x1, int y1, int z1, int x2, int y2, int z2) {
	int x = (x1 < x2) ? x1 : x2, y = (y1 < y2) ? y1 : y2, z = (z1 < z2) ? z1 : z2;
	for (int i = 0; i < ((y1 - y2 == 0) ? 1 : abs(y1 - y2)); i++) {
		for (int j = 0; j <= ((x1 - x2 == 0) ? 0 : abs(x1 - x2 + 1)); j++) {
			for (int k = 0; k <= ((z1 - z2 == 0) ? 0 : abs(z1 - z2)); k++) {
				locateBlock(block, x + j, y + i, z + k);
			}
		}
	}
}

void krustykrab(int x, int y, int z) {
	//int x = -83, y = 4, z = -60;
	for (int i = -15; i <= 16; i++) {
		ellipse(B_wood, 'z', 10, 15, x - 15, y, z + i);
	}

	for (int j = 0; j <= 12; j++) {
		ellipse(B_wood, 'z', j, 17, x - 15, 4, z - 15);
		ellipse(B_wood, 'z', j, 17, x - 15, 4, z + 16);
		ellipse(B_wood, 'z', j, 17, x - 15, 4, z - 16);
		ellipse(B_wood, 'z', j, 17, x - 15, 4, z + 17);
		walls(B_wood, x - 5, y, z - 14, x - 5, y, z + 15);
		walls(B_wood, x - 26, y, z - 14, x - 26, y, z + 15);
		set(B_WhiteGlass, x - 25, y + 5, z - 14, x - 25, y + 1, z + 15);
		set(B_WhiteGlass, x - 6, y + 5, z - 14, x - 6, y + 1, z + 15);
		set(B_wood, x - 6, y, z - 3, x - 6, y + 5, z + 4);
		set(B_WhiteGlass, x - 6, y + 1, z - 2, x - 6, y + 4, z + 3);
		set(B_wood, x - 25, y, z - 3, x - 25, y + 5, z + 4);
		set(B_WhiteGlass, x - 25, y + 1, z - 2, x - 25, y + 4, z + 3);
	}


	locateBlock(wool_red, x - 8, y + 10, z + 14);
	locateBlock(wool_red, x - 8, y + 10, z + 13);
	locateBlock(wool_yellow, x - 8, y + 10, z + 12);
	locateBlock(wool_red, x - 8, y + 10, z + 11);
	locateBlock(wool_red, x - 8, y + 10, z + 10);

	locateBlock(wool_yellow, x - 8, y + 9, z + 14);
	locateBlock(wool_yellow, x - 8, y + 9, z + 13);
	locateBlock(wool_yellow, x - 8, y + 9, z + 12);
	locateBlock(wool_yellow, x - 8, y + 9, z + 11);
	locateBlock(wool_yellow, x - 8, y + 9, z + 10);

	locateBlock(wool_red, x - 7, y + 8, z + 14);
	locateBlock(wool_red, x - 7, y + 8, z + 13);
	locateBlock(wool_yellow, x - 7, y + 8, z + 12);
	locateBlock(wool_red, x - 7, y + 8, z + 11);
	locateBlock(wool_red, x - 7, y + 8, z + 10);

	locateBlock(wool_red, x - 7, y + 7, z + 14);
	locateBlock(wool_red, x - 7, y + 7, z + 13);
	locateBlock(wool_yellow, x - 7, y + 7, z + 12);
	locateBlock(wool_red, x - 7, y + 7, z + 11);
	locateBlock(wool_red, x - 7, y + 7, z + 10);

	locateBlock(wool_yellow, x - 8, y + 9, z + 8);
	locateBlock(wool_yellow, x - 8, y + 9, z + 7);
	locateBlock(wool_yellow, x - 8, y + 9, z + 6);
	locateBlock(wool_yellow, x - 8, y + 9, z + 5);
	locateBlock(wool_yellow, x - 8, y + 9, z + 4);

	locateBlock(wool_yellow, x - 7, y + 8, z + 8);
	locateBlock(wool_blue, x - 7, y + 8, z + 7);
	locateBlock(wool_blue, x - 7, y + 8, z + 6);
	locateBlock(wool_blue, x - 7, y + 8, z + 5);
	locateBlock(wool_yellow, x - 7, y + 8, z + 4);

	locateBlock(wool_yellow, x - 7, y + 7, z + 8);
	locateBlock(wool_blue, x - 7, y + 7, z + 7);
	locateBlock(wool_blue, x - 7, y + 7, z + 6);
	locateBlock(wool_blue, x - 7, y + 7, z + 5);
	locateBlock(wool_yellow, x - 7, y + 7, z + 4);

	locateBlock(wool_yellow, x - 6, y + 6, z + 8);
	locateBlock(wool_yellow, x - 6, y + 6, z + 7);
	locateBlock(wool_yellow, x - 6, y + 6, z + 6);
	locateBlock(wool_yellow, x - 6, y + 6, z + 5);
	locateBlock(wool_yellow, x - 6, y + 6, z + 4);

	locateBlock(wool_blue, x - 7, y + 8, z + 2);
	locateBlock(wool_white, x - 7, y + 8, z + 1);
	locateBlock(wool_white, x - 7, y + 8, z + 0);
	locateBlock(wool_white, x - 7, y + 8, z - 1);

	locateBlock(wool_blue, x - 7, y + 7, z + 2);
	locateBlock(wool_blue, x - 7, y + 7, z + 1);
	locateBlock(wool_white, x - 7, y + 7, z + 0);
	locateBlock(wool_white, x - 7, y + 7, z - 1);

	locateBlock(wool_blue, x - 6, y + 6, z + 2);
	locateBlock(wool_blue, x - 6, y + 6, z + 1);
	locateBlock(wool_blue, x - 6, y + 6, z + 0);
	locateBlock(wool_white, x - 6, y + 6, z - 1);

	locateBlock(wool_white, x - 8, y + 9, z - 3);
	locateBlock(wool_white, x - 8, y + 9, z - 4);
	locateBlock(wool_red, x - 8, y + 9, z - 5);
	locateBlock(wool_red, x - 8, y + 9, z - 6);
	locateBlock(wool_red, x - 8, y + 9, z - 7);

	locateBlock(wool_white, x - 7, y + 8, z - 3);
	locateBlock(wool_white, x - 7, y + 8, z - 4);
	locateBlock(wool_red, x - 7, y + 8, z - 5);
	locateBlock(wool_red, x - 7, y + 8, z - 6);
	locateBlock(wool_red, x - 7, y + 8, z - 7);

	locateBlock(wool_red, x - 7, y + 7, z - 3);
	locateBlock(wool_red, x - 7, y + 7, z - 4);
	locateBlock(wool_white, x - 7, y + 7, z - 5);
	locateBlock(wool_white, x - 7, y + 7, z - 6);
	locateBlock(wool_white, x - 7, y + 7, z - 7);

	locateBlock(wool_red, x - 6, y + 6, z - 3);
	locateBlock(wool_red, x - 6, y + 6, z - 4);
	locateBlock(wool_white, x - 6, y + 6, z - 5);
	locateBlock(wool_white, x - 6, y + 6, z - 6);
	locateBlock(wool_white, x - 6, y + 6, z - 7);

	locateBlock(wool_yellow, x - 8, y + 10, z - 9);
	locateBlock(wool_yellow, x - 8, y + 10, z - 10);
	locateBlock(wool_yellow, x - 8, y + 10, z - 11);
	locateBlock(wool_blue, x - 8, y + 10, z - 12);
	locateBlock(wool_blue, x - 8, y + 10, z - 13);

	locateBlock(wool_yellow, x - 8, y + 9, z - 9);
	locateBlock(wool_yellow, x - 8, y + 9, z - 10);
	locateBlock(wool_yellow, x - 8, y + 9, z - 11);
	locateBlock(wool_blue, x - 8, y + 9, z - 12);
	locateBlock(wool_blue, x - 8, y + 9, z - 13);

	locateBlock(wool_yellow, x - 7, y + 8, z - 9);
	locateBlock(wool_yellow, x - 7, y + 8, z - 10);
	locateBlock(wool_yellow, x - 7, y + 8, z - 11);
	locateBlock(wool_blue, x - 7, y + 8, z - 12);
	locateBlock(wool_blue, x - 7, y + 8, z - 13);

	locateBlock(wool_yellow, x - 7, y + 7, z - 9);
	locateBlock(wool_yellow, x - 7, y + 7, z - 10);
	locateBlock(wool_yellow, x - 7, y + 7, z - 11);
	locateBlock(wool_blue, x - 7, y + 7, z - 12);
	locateBlock(wool_blue, x - 7, y + 7, z - 13);

	locateBlock(wool_white, x - 14, y + 15, z + 6);
	locateBlock(wool_white, x - 14, y + 15, z + 5);
	locateBlock(wool_white, x - 14, y + 16, z + 5);
	locateBlock(wool_white, x - 14, y + 17, z + 5);
	locateBlock(wool_white, x - 14, y + 18, z + 5);
	locateBlock(wool_white, x - 14, y + 15, z + 4);
	locateBlock(wool_white, x - 15, y + 16, z + 6);
	locateBlock(wool_white, x - 15, y + 16, z + 4);
	locateBlock(wool_white, x - 15, y + 17, z + 6);
	locateBlock(wool_white, x - 15, y + 17, z + 4);
	locateBlock(wool_white, x - 15, y + 18, z + 6);

	locateBlock(plank_fence, x - 15, y + 16, z - 6);
	locateBlock(plank_fence, x - 15, y + 17, z - 6);
	locateBlock(plank_fence, x - 15, y + 18, z - 6);
	locateBlock(plank_fence, x - 15, y + 19, z - 6);
	locateBlock(plank_fence, x - 15, y + 20, z - 6);
	locateBlock(plank_fence, x - 15, y + 21, z - 6);
	locateBlock(plank_fence, x - 15, y + 20, z - 5);
	locateBlock(plank_fence, x - 15, y + 20, z - 7);

	locateBlock(plank_fence, x, y, z + 23);
	locateBlock(plank_fence, x, y + 1, z + 23);
	locateBlock(plank_fence, x, y + 2, z + 23);
	locateBlock(plank_fence, x, y + 3, z + 23);
	locateBlock(plank_fence, x, y + 4, z + 23);
	locateBlock(plank_fence, x, y + 5, z + 23);
	locateBlock(plank_fence, x, y + 6, z + 23);
	locateBlock(plank_fence, x, y + 7, z + 23);
	locateBlock(plank_fence, x, y + 8, z + 23);
	locateBlock(plank_fence, x, y + 9, z + 23);
	locateBlock(plank_fence, x, y + 10, z + 23);
	locateBlock(plank_fence, x, y + 11, z + 23);
	locateBlock(plank_fence, x, y + 12, z + 23);
	locateBlock(plank_fence, x, y + 13, z + 23);
	locateBlock(plank_fence, x, y + 14, z + 23);
	locateBlock(plank_fence, x, y + 15, z + 23);
	locateBlock(plank_fence, x, y + 16, z + 23);
	locateBlock(plank_fence, x, y + 17, z + 23);
	locateBlock(plank_fence, x, y + 18, z + 23);

	locateBlock(wool_white, x, y + 18, z + 21);
	locateBlock(wool_red, x, y + 18, z + 22);
	locateBlock(wool_white, x, y + 18, z + 23);
	locateBlock(wool_red, x, y + 18, z + 24);
	locateBlock(wool_white, x, y + 18, z + 25);

	locateBlock(wool_white, x - 1, y + 19, z + 21);
	locateBlock(wool_white, x - 1, y + 19, z + 22);
	locateBlock(wool_red, x - 1, y + 19, z + 23);
	locateBlock(wool_red, x - 1, y + 19, z + 24);
	locateBlock(wool_white, x - 1, y + 19, z + 25);

	locateBlock(wool_white, x - 1, y + 20, z + 21);
	locateBlock(wool_red, x - 1, y + 20, z + 22);
	locateBlock(wool_white, x - 1, y + 20, z + 23);
	locateBlock(wool_red, x - 1, y + 20, z + 24);
	locateBlock(wool_white, x - 1, y + 20, z + 25);

	locateBlock(wool_white, x - 1, y + 21, z + 22);
	locateBlock(wool_white, x - 1, y + 21, z + 23);
	locateBlock(wool_white, x - 1, y + 21, z + 24);

	locateBlock(wool_white, x + 1, y + 17, z + 22);
	locateBlock(wool_white, x + 1, y + 17, z + 23);
	locateBlock(wool_white, x + 1, y + 17, z + 24);
}	


void straw_house(int radius, int height, char color, int x, int y, int z) {
	if (color == 'g') {
		for (int i = 0; i < height; i++) {
			if (i <= height / 3) {
				circle(wool_lime, radius - 2, x, y + i, z);
			}
			else if (i <= height / 3 * 2) {
				circle(wool_lime, radius - 1, x, y + i, z);
			}
			else {
				circle(wool_lime, radius, x, y + i, z);
			}

		}
		circle(wool_green, radius, x, y + height, z);
		circle_x(wool_green, height / 8, x + radius, y + height - 3, z);
		circle_x(B_WhiteGlass, height / 8 - 1, x + radius, y + height - 3, z);
		locateBlock(B_glowstone, x + radius - 1, y + height - 3, z);

		circle_x(wool_green, height / 8, x - radius + 1, y + height / 3 + 2, z);
		circle_x(B_WhiteGlass, height / 8 - 1, x - radius + 1, y + height / 3 + 2, z);
		locateBlock(B_glowstone, x - radius + 2, y + height / 3 + 2, z);

		for (int i = 1; i < height / 5; i++) {
			circle(wool_green, 2, x + radius / 3, y + height + i, z);
			circle(B_air, radius / 3 - 1, x + radius / 3, y + height + i, z);
		}
	}
	if (color == 'b') {
		for (int i = 0; i < height; i++) {
			if (i <= height / 3) {
				circle(wool_lightblue, radius - 2, x, y + i, z);
			}
			else if (i <= height / 3 * 2) {
				circle(wool_lightblue, radius - 1, x, y + i, z);
			}
			else {
				circle(wool_lightblue, radius, x, y + i, z);
			}

		}
		circle(wool_blue, radius, x, y + height, z);
		circle_x(wool_blue, height / 8, x + radius, y + height - 3, z);
		circle_x(B_WhiteGlass, height / 8 - 1, x + radius, y + height - 3, z);
		locateBlock(B_glowstone, x + radius - 1, y + height - 3, z);

		circle_x(wool_blue, height / 8, x - radius + 1, y + height / 3 + 2, z);
		circle_x(B_WhiteGlass, height / 8 - 1, x - radius + 1, y + height / 3 + 2, z);
		locateBlock(B_glowstone, x - radius + 2, y + height / 3 + 2, z);

		for (int i = 1; i < height / 5; i++) {
			circle(wool_blue, radius / 3, x + radius / 3, y + height + i, z);
			circle(B_air, radius / 3 - 1, x + radius / 3, y + height + i, z);
		}
	}
	if (color == 'r') {
		for (int i = 0; i < height; i++) {
			if (i <= height / 3) {
				circle(wool_orange, radius - 2, x, y + i, z);
			}
			else if (i <= height / 3 * 2) {
				circle(wool_orange, radius - 1, x, y + i, z);
			}
			else {
				circle(wool_orange, radius, x, y + i, z);
			}

		}
		circle(wool_red, radius, x, y + height, z);
		circle_z(wool_red, height / 8, x , y + height - 3, z + radius);
		circle_z(B_WhiteGlass, height / 8 - 1, x , y + height - 3, z + radius);
		locateBlock(B_glowstone, x , y + height - 3, z + radius - 1);

		circle_x(wool_red, height / 8, x - radius + 1, y + height / 3 + 2, z);
		circle_x(B_WhiteGlass, height / 8 - 1, x - radius + 1, y + height / 3 + 2, z);
		locateBlock(B_glowstone, x - radius + 2, y + height / 3 + 2, z);

		for (int i = 1; i < height / 5; i++) {
			circle(wool_red, radius / 3, x + radius / 3, y + height + i, z);
			circle(B_air, radius / 3 - 1, x + radius / 3, y + height + i, z);
		}
	}
	if (color == 'd') {
		for (int i = 0; i < height; i++) {
			if (i <= height / 3) {
				circle(wool_lightgray, radius - 2, x, y + i, z);
			}
			else if (i <= height / 3 * 2) {
				circle(wool_lightgray, radius - 1, x, y + i, z);
			}
			else {
				circle(wool_lightgray, radius, x, y + i, z);
			}

		}
		circle(wool_gray, radius, x, y + height, z);
		circle_x(wool_gray, height / 8, x + radius, y + height - 3, z);
		circle_x(B_WhiteGlass, height / 8 - 1, x + radius, y + height - 3, z);
		locateBlock(B_glowstone, x + radius - 1, y + height - 3, z);

		circle_z(wool_gray, height / 8, x , y + height / 3 + 2, z - radius + 1);
		circle_z(B_WhiteGlass, height / 8 - 1, x, y + height / 3 + 2, z - radius + 1);
		locateBlock(B_glowstone, x , y + height / 3 + 2, z - radius + 2);

		for (int i = 1; i < height / 5; i++) {
			circle(wool_gray, radius / 3, x + radius / 3, y + height + i, z);
			circle(B_air, radius / 3 - 1, x + radius / 3, y + height + i, z);
		}
	}
}


int main()
{
	int krust_x = 83, krust_y = 4, krust_z = 60;
	krustykrab(krust_x, krust_y, krust_z);
  
  
	straw_house(10, 20, 'd', 140, 4, 15);
	straw_house(8, 16, 'd', 102, 4, 48);
	straw_house(7, 18, 'b', 105, 4, 23);
	straw_house(8, 24, 'r', 127, 4, 51);
	straw_house(13, 16, 'g', 129, 4, 82);
	straw_house(10, 28, 'b', 85, 4, 113);
}
