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
BlockID wool_pink = createWool(COLOR_PINK);
BlockID wool_purple = createWool(COLOR_PURPLE);
BlockID wool_gray = createWool(COLOR_GRAY);
BlockID wool_lightgray = createWool(COLOR_LIGHT_GRAY);
BlockID wool_lightblue = createWool(COLOR_LIGHT_BLUE);
BlockID nether_fence = createFence(FenceType(7));
BlockID plank_fence = createFence(FenceType(1));
BlockID netherrack = createBlock(BLOCK_NETHERRACK);
BlockID glass = createBlock(BLOCK_GLASS);
BlockID grass = createBlock(BLOCK_GRASS);
TerracottaID terracotta_blue = createTerracotta(TERRACOTTA, COLOR_BLUE);
TerracottaID terracotta_lightblue = createTerracotta(TERRACOTTA, COLOR_LIGHT_BLUE);
TerracottaID terracotta_lime = createTerracotta(TERRACOTTA, COLOR_LIME);
TerracottaID terracotta_green = createTerracotta(TERRACOTTA, COLOR_GREEN);
BlockID B_pinkGlass = createBlock(BLOCK_STAINED_GLASS);
BlockID B_gold = createBlock(BLOCK_GOLD);


void circle(BlockID block, int radius, int x, int y, int z);
void woodsquare(int x, int y, int z, int vertical, int horizontal);
void branch(int x, int y, int z);
void trunk(int x, int y, int z);
void snowcircle(int radius, int x, int y, int z);
void bench(int x, int y, int z);
void wheel(int x, int y, int z, int radius);
void door(int x, int y, int z);



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

void sphere_ter(TerracottaID block, int radius, int x, int y, int z) {
	for (int i = -radius; i < radius; i++) {
		for (int j = -radius; j < radius; j++) {
			for (int k = -radius; k < radius; k++) {
				if (i*i + j * j + k * k < radius * radius) {
					locateTerracotta(block, x + i, y + k, z + j);
				}
			}
		}
	}
}


void sunken(int i, int x, int y, int z) {
	sphere_ter(terracotta_green, 4, x, y, z);
	sphere_ter(terracotta_green, 4, x - i, y + 4, z);
	sphere_ter(terracotta_green, 4, x - i, y + 8, z);
	sphere_ter(terracotta_green, 4, x, y + 12, z);
	sphere_ter(terracotta_green, 4, x, y + 16, z);
	sphere_ter(terracotta_green, 4, x + i, y + 20, z);
	sphere_ter(terracotta_green, 4, x + i, y + 24, z);
	sphere_ter(terracotta_green, 4, x, y + 28, z);
}
void sunken_blue(int i, int x, int y, int z) {
	sphere_ter(terracotta_blue, 4, x, y, z);
	sphere_ter(terracotta_blue, 4, x - i, y + 4, z);
	sphere_ter(terracotta_blue, 4, x - i, y + 8, z);
	sphere_ter(terracotta_blue, 4, x, y + 12, z);
	sphere_ter(terracotta_blue, 4, x, y + 16, z);
	sphere_ter(terracotta_blue, 4, x + i, y + 20, z);
	sphere_ter(terracotta_blue, 4, x + i, y + 24, z);
	sphere_ter(terracotta_blue, 4, x, y + 28, z);
}

void bluerock(int x, int y, int z) {
	sphere_ter(terracotta_blue, 4, x, y, z);
	sphere_ter(terracotta_blue, 4, x - 1, y + 4, z - 1);
	sphere_ter(terracotta_blue, 4, x - 2, y + 8, z - 2);
	sphere_ter(terracotta_blue, 4, x - 2, y + 12, z - 2);
	sphere_ter(terracotta_blue, 4, x - 4, y + 14, z - 4);
	sphere_ter(terracotta_blue, 4, x - 6, y + 16, z - 6);
	sphere_ter(terracotta_blue, 4, x - 8, y + 17, z - 8);
	sphere_ter(terracotta_blue, 4, x - 6, y + 15, z - 10);
	sphere_ter(terracotta_blue, 4, x - 3, y + 12, z - 11);
	sphere_ter(terracotta_blue, 4, x - 1, y + 8, z - 14);
	sphere_ter(terracotta_blue, 4, x + 1, y + 4, z - 15);
	sphere_ter(terracotta_blue, 4, x + 2, y, z - 16);
	sphere_ter(terracotta_blue, 4, x - 8, y + 17, z - 8);
	sphere_ter(terracotta_blue, 4, x - 10, y + 14, z - 8);
	sphere_ter(terracotta_blue, 4, x - 13, y + 12, z - 7);
	sphere_ter(terracotta_blue, 4, x - 15, y + 8, z - 6);
	sphere_ter(terracotta_blue, 4, x - 16, y + 4, z - 5);
	sphere_ter(terracotta_blue, 4, x - 16, y, z - 5);
}

void arc_bluerock(int x, int y, int z) {
/*	sphere_ter(terracotta_lightblue, 4, x, y, z);
	sphere_ter(terracotta_lightblue, 4, x - 3, y + 5, z - 2);
	sphere_ter(terracotta_lightblue, 4, x - 6, y + 10, z - 4);
	sphere_ter(terracotta_lightblue, 4, x - 9, y + 14, z - 6);
	sphere_ter(terracotta_lightblue, 4, x - 11, y + 18, z - 8);
	sphere_ter(terracotta_lightblue, 4, x - 13, y + 22, z - 10);
	sphere_ter(terracotta_lightblue, 4, x - 15, y + 23, z - 11);
	sphere_ter(terracotta_lightblue, 4, x - 17, y + 22, z - 12);
	sphere_ter(terracotta_lightblue, 4, x - 19, y + 18, z - 14);
	sphere_ter(terracotta_lightblue, 4, x - 21, y + 14, z - 16);
	sphere_ter(terracotta_lightblue, 4, x - 24, y + 10, z - 18);
	sphere_ter(terracotta_lightblue, 4, x - 27, y + 5, z - 20);
	sphere_ter(terracotta_lightblue, 4, x - 30, y, z - 22);*/
	for (int i = 0; i < 3; i++) {
		sphere_ter(terracotta_lightblue, 4, x - i, y + 4 * i, z - i);
	}
	for (int i = 0; i < 3; i++) {
		sphere_ter(terracotta_lightblue, 4, x - 2 - 2 * i, y + 8 + 4 * i, z - 2 - 2 * i);
	}
	for (int i = 0; i < 4; i++) {
		sphere_ter(terracotta_lightblue, 4, x - 6 - 2 * i, y + 16 + 2 * i, z - 6 - 2 * i);
	}
	for (int i = 0; i < 2; i++) {
		sphere_ter(terracotta_lightblue, 4, x - 12 - 2 * i, y + 22 + i, z - 12 - 2 * i);
	}
	for (int i = 0; i < 2; i++) {
		sphere_ter(terracotta_lightblue, 4, x - 14 - 2 * i, y + 23 - i, z - 14 - 2 * i);
	}
	for (int i = 0; i < 4; i++) {
		sphere_ter(terracotta_lightblue, 4, x - 16 - 2 * i, y + 22 - 2 * i, z - 16 - 2 * i);
	}
	for (int i = 0; i < 3; i++) {
		sphere_ter(terracotta_lightblue, 4, x - 22 - 2 * i, y + 16 - 4 * i, z - 22 - 2 * i);
	}
	for (int i = 0; i < 3; i++) {
		sphere_ter(terracotta_lightblue, 4, x - 26 - 2 * i, y + 8 - 4 * i, z - 26 - 2 * i);
	}
}

void jellyfish(int x, int y, int z) {
	//-154 21 -140

	sphere(wool_pink, 3, x, y + 1, z);
	locateBlock(wool_red, x, y + 3, z + 2);
	locateBlock(wool_red, x + 1, y + 2, z + 2);
	locateBlock(wool_red, x + 1, y + 3, z + 1);
	locateBlock(wool_red, x + 2, y, z - 1);
	locateBlock(wool_red, x + 2, y - 1, z - 1);
	locateBlock(wool_red, x + 2, y, z - 2);
	locateBlock(wool_pink, x - 2, y - 1, z - 1);
	locateBlock(wool_pink, x - 2, y - 1, z);
	locateBlock(wool_pink, x - 2, y - 1, z + 1);
	locateBlock(wool_pink, x - 2, y , z - 1);
	locateBlock(wool_pink, x - 2, y , z);
	locateBlock(wool_pink, x - 2, y - 1, z + 1);
	locateBlock(wool_pink, x - 3, y - 1, z);
	locateBlock(wool_pink, x - 4, y - 1, z);
	locateBlock(wool_pink, x - 5, y - 2, z);
	locateBlock(wool_pink, x - 6, y - 2, z);
	locateBlock(wool_pink, x - 3, y + 1, z + 1);
	locateBlock(wool_pink, x - 4, y + 1, z + 1);
	locateBlock(wool_pink, x - 5, y + 1, z + 2);
	locateBlock(wool_pink, x - 6, y + 1, z + 2);
	locateBlock(wool_pink, x - 3, y + 2, z - 1);
	locateBlock(wool_pink, x - 4, y + 2, z - 1);
	locateBlock(wool_pink, x - 5, y + 2, z - 2);
	locateBlock(wool_pink, x - 6, y + 2, z - 2);

	locateBlock(wool_pink, x - 3, y + 4, z - 1);
	locateBlock(wool_pink, x - 4, y + 4, z - 1);
	locateBlock(wool_pink, x - 5, y + 5, z - 1);
	locateBlock(wool_pink, x - 6, y + 5, z - 1);

	locateBlock(wool_pink, x - 3, y + 3, z + 1);
	locateBlock(wool_pink, x - 4, y + 3, z + 1);
	locateBlock(wool_pink, x - 5, y + 4, z + 2);
	locateBlock(wool_pink, x - 6, y + 4, z + 2);

}

//-214, 20, -100
void king_jellyfish(int x, int y, int z) {
	sphere(wool_purple, 6, x, y, z);
	for (int i = 0; i < 4; i++) {
		circle(wool_purple, 6, x, y - i, z);
	}
	circle(wool_purple, 7, x, y - 4, z);
	circle(wool_purple, 8, x, y - 5, z);
	locateBlock(B_gold, x + 1, y + 6, z);
	locateBlock(B_gold, x + 1, y + 6, z - 1);
	locateBlock(B_gold, x + 1, y + 6, z + 1);
	locateBlock(B_gold, x, y + 6, z - 2);
	locateBlock(B_gold, x, y + 6, z - 1);
	locateBlock(B_gold, x, y + 6, z);
	locateBlock(B_gold, x, y + 6, z + 1);
	locateBlock(B_gold, x, y + 6, z + 2);
	locateBlock(B_gold, x - 1, y + 6, z);
	locateBlock(B_gold, x - 1, y + 6, z - 1);
	locateBlock(B_gold, x - 1, y + 6, z + 1);
	for (int i = -1; i < 2; i++) {
		locateBlock(B_gold, x + i, y + 7, z - 1);
		locateBlock(B_gold, x + i, y + 7, z);
		locateBlock(B_gold, x + i, y + 7, z + 1);
	}
	for (int i = -1; i < 2; i++) {
		locateBlock(B_gold, x + i, y + 8, z - 1);
		locateBlock(B_gold, x + i, y + 8, z + 1);
	}
	locateBlock(B_gold, x, y + 8, z);
	locateBlock(B_gold, x, y + 8, z - 2);
	locateBlock(B_gold, x, y + 8, z + 2);

	for (int i = -2; i < 3; i++) {
		locateBlock(B_gold, x, y + 9, z + i);
	}
	locateBlock(B_gold, x, y + 10, z + 2);
	locateBlock(B_gold, x, y + 11, z + 2);
	locateBlock(B_gold, x, y + 10, z);
	locateBlock(B_gold, x, y + 11, z);
	locateBlock(B_gold, x, y + 10, z - 2);
	locateBlock(B_gold, x, y + 11, z - 2);

	locateBlock(wool_purple, x, y - 6, z + 6);
	locateBlock(wool_purple, x, y - 7, z + 6);
	locateBlock(wool_purple, x, y - 8, z + 6);
	locateBlock(wool_purple, x, y - 9, z + 5);
	locateBlock(wool_purple, x, y - 10, z + 5);
	locateBlock(wool_purple, x, y - 11, z + 5);
	locateBlock(wool_purple, x, y - 12, z + 4);

	locateBlock(wool_purple, x, y - 6, z - 6);
	locateBlock(wool_purple, x, y - 7, z - 6);
	locateBlock(wool_purple, x, y - 8, z - 6);
	locateBlock(wool_purple, x, y - 9, z - 5);
	locateBlock(wool_purple, x, y - 10, z - 5);
	locateBlock(wool_purple, x, y - 11, z - 5);
	locateBlock(wool_purple, x, y - 12, z - 4);

	locateBlock(wool_purple, x - 6, y - 6, z);
	locateBlock(wool_purple, x - 6, y - 7, z);
	locateBlock(wool_purple, x - 6, y - 8, z);
	locateBlock(wool_purple, x - 5, y - 9, z);
	locateBlock(wool_purple, x - 5, y - 10, z);
	locateBlock(wool_purple, x - 5, y - 11, z);
	locateBlock(wool_purple, x - 4, y - 12, z);

	locateBlock(wool_purple, x + 6, y - 6, z);
	locateBlock(wool_purple, x + 6, y - 7, z);
	locateBlock(wool_purple, x + 6, y - 8, z);
	locateBlock(wool_purple, x + 5, y - 9, z);
	locateBlock(wool_purple, x + 5, y - 10, z);
	locateBlock(wool_purple, x + 5, y - 11, z);
	locateBlock(wool_purple, x + 4, y - 12, z);

	locateBlock(wool_purple, x - 5, y - 6, z - 5);
	locateBlock(wool_purple, x - 5, y - 7, z - 5);
	locateBlock(wool_purple, x - 5, y - 8, z - 5);
	locateBlock(wool_purple, x - 4, y - 9, z - 4);
	locateBlock(wool_purple, x - 4, y - 10, z - 4);
	locateBlock(wool_purple, x - 4, y - 11, z - 4);
	locateBlock(wool_purple, x - 3, y - 12, z - 3);

	locateBlock(wool_purple, x - 5, y - 6, z + 5);
	locateBlock(wool_purple, x - 5, y - 7, z + 5);
	locateBlock(wool_purple, x - 5, y - 8, z + 5);
	locateBlock(wool_purple, x - 4, y - 9, z + 4);
	locateBlock(wool_purple, x - 4, y - 10, z + 4);
	locateBlock(wool_purple, x - 4, y - 11, z + 4);
	locateBlock(wool_purple, x - 3, y - 12, z + 3);

	locateBlock(wool_purple, x + 5, y - 6, z + 5);
	locateBlock(wool_purple, x + 5, y - 7, z + 5);
	locateBlock(wool_purple, x + 5, y - 8, z + 5);
	locateBlock(wool_purple, x + 4, y - 9, z + 4);
	locateBlock(wool_purple, x + 4, y - 10, z + 4);
	locateBlock(wool_purple, x + 4, y - 11, z + 4);
	locateBlock(wool_purple, x + 3, y - 12, z + 3);

	locateBlock(wool_purple, x + 5, y - 6, z - 5);
	locateBlock(wool_purple, x + 5, y - 7, z - 5);
	locateBlock(wool_purple, x + 5, y - 8, z - 5);
	locateBlock(wool_purple, x + 4, y - 9, z - 4);
	locateBlock(wool_purple, x + 4, y - 10, z - 4);
	locateBlock(wool_purple, x + 4, y - 11, z - 4);
	locateBlock(wool_purple, x + 3, y - 12, z - 3);
}
void faucet(int x, int y, int z) {  //본체 위 구조물-수도꼭지 형태(펜스)

	BlockID block = createFence(FenceType(1));
	locateFence(block, x, y, z);
	locateFence(block, x, y + 1, z);
	locateFence(block, x + 1, y + 1, z);
	locateFence(block, x - 1, y + 1, z);
	locateFence(block, x, y + 1, z + 1);
	locateFence(block, x, y + 1, z - 1);

}


void arraytogame(int* arr[], BlockID block, int x1, int y1, int z1, int x2, int y2, int z2) {
	for (int i = 0; i < (x1 - x2 == 0) ? abs(y2 - y1) : abs(x2 - x1); i++) {
		for (int j = 0; j < (x1 - x2 == 0) ? abs(x2 - x1) : abs(y2 - y1); j++) {
			if (arr[i][j] == 1) {
				locateBlock(block, x1 + i, y1 + j, z1);
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

void slab_walls(SlabID slab, int x1, int y1, int z1, int x2, int y2, int z2) {
	int x = (x1 < x2) ? x1 : x2, y = (y1 < y2) ? y1 : y2, z = (z1 < z2) ? z1 : z2;
	for (int i = 0; i < ((y1 - y2 == 0) ? 1 : abs(y1 - y2)); i++) {
		for (int j = 0; j <= ((x1 - x2 == 0) ? 1 : abs(x1 - x2)); j++) {
			locateSlab(slab, x + j, y + i, z1);
			locateSlab(slab, x + j, y + i, z2);
		}
		for (int k = 0; k <= ((z1 - z2 == 0) ? 1 : abs(z1 - z2)); k++) {
			locateSlab(slab, x1, y + i, z + k);
			locateSlab(slab, x2, y + i, z + k);
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

SlabID slab_height(SlabType type, SlabSize size) {
	SlabID slab = createSlab(type, size);
	return slab;
}


void set_slab(SlabID slab, int x1, int y1, int z1, int x2, int y2, int z2) {
	int x = (x1 < x2) ? x1 : x2, y = (y1 < y2) ? y1 : y2, z = (z1 < z2) ? z1 : z2;
	for (int i = 0; i < ((y1 - y2 == 0) ? 1 : abs(y1 - y2)); i++) {
		for (int j = 0; j <= ((x1 - x2 == 0) ? 1 : abs(x1 - x2)); j++) {
			for (int k = 0; k <= ((z1 - z2 == 0) ? 1 : abs(z1 - z2)); k++) {
				locateSlab(slab, x + j, y + i, z + k);
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

void jing_circle(int x, int y, int z)
{

	BlockID bedrock = createBlock(BLOCK_BEDROCK);

	for (int i = -9; i < 9; i++)
	{
		for (int j = -9; j < 9; j++)
		{
			if (i*i + j * j < 81)
			{
				locateBlock(bedrock, x + i, y, z + j);
			}
		}
	}
}

void jing_body(int x, int y, int z) //징징이집_몸통
{
	for (int i = 0; i < 36; i++)
	{
		jing_circle(x, y + i, z);
	}

}

void jing_eye(int x, int y, int z)
{
	BlockID glass = createBlock(BLOCK_GLASS);
	BlockID edge = createBlock(BLOCK_IRON);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			locateBlock(glass, x + 8, y + 22 + i, z + 3 + j);//왼쪽눈알
			locateBlock(glass, x + 8, y + 22 + i, z - 5 + j);//오른쪽눈알
		}
	}
	for (int k = 0; k < 4; k++)
	{
		for (int u = 0; u < 3; u++)
		{
			locateBlock(edge, x + 8, y + 22 + u, z - 6 + 4 * k);//눈테두리세로
		}
	}
	for (int n = 0; n < 3; n++)
	{
		locateBlock(edge, x + 8, y + 21, z - 5 + n);
		locateBlock(edge, x + 8, y + 21, z + 3 + n);
		locateBlock(edge, x + 8, y + 25, z - 5 + n);
		locateBlock(edge, x + 8, y + 25, z + 3 + n);  //눈테두리가로
	}
}


void jing_mouth(int x, int y, int z)
{
	BlockID air = createBlock(BLOCK_AIR);
	BlockID door = createWood(WOOD_SPRUCE);
	BlockID bedrock = createBlock(BLOCK_BEDROCK);

	for (int i = -2; i < 3; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			locateBlock(air, x + 8, y + j, z + i);//문구멍뚫기
			locateBlock(door, x + 7, y + j, z + i);//문넣기
		}
	}
	locateBlock(bedrock, x + 8, y + 6, z - 2);
	locateBlock(bedrock, x + 8, y + 6, z + 2);
	locateBlock(bedrock, x + 8, y + 7, z - 2);
	locateBlock(bedrock, x + 8, y + 7, z - 1);
	locateBlock(bedrock, x + 8, y + 7, z + 1);
	locateBlock(bedrock, x + 8, y + 7, z + 2);//꾸민거
}
void jing_ear(int x, int y, int z)
{
	BlockID bedrock = createBlock(BLOCK_BEDROCK);

	for (int i = -10; i < 11; i++)
	{
		for (int j = 12; j < 24; j++)
		{
			locateBlock(bedrock, x, y + j, z + i);
		}
	}
}

void jing_nose(int x, int y, int z)
{
	BlockID bedrock = createBlock(BLOCK_BEDROCK);

	for (int z1 = -6; z1 < 7; z1++)
	{
		for (int x1 = 6; x1 < 10; x1++)
		{
			locateBlock(bedrock, x + x1, y + 26, z + z1);
			locateBlock(bedrock, x + x1, y + 27, z + z1); //징징이이마
		}
	}


	for (int z3 = -2; z3 < 3; z3++)
	{
		for (int y3 = 12; y3 < 19; y3++)
		{
			locateBlock(bedrock, x + 9, y + y3, z + z3);//징징이코넓어지는중

		}
	}

	locateBlock(bedrock, x + 9, y + 12, z - 3);
	locateBlock(bedrock, x + 9, y + 13, z - 3);
	locateBlock(bedrock, x + 9, y + 12, z + 3);
	locateBlock(bedrock, x + 9, y + 13, z + 3);//징징이콧볼


	for (int i = 12; i < 19; i++)
	{
		locateBlock(bedrock, x + 10, y + i, z);
	}
	for (int j = 12; j < 17; j++)
	{
		locateBlock(bedrock, x + 10, y + j, z + 1);
		locateBlock(bedrock, x + 10, y + j, z - 1);
	}
	locateBlock(bedrock, x + 10, y + 12, z + 2);
	locateBlock(bedrock, x + 10, y + 12, z - 2);//징징이의 입체적인 코



	for (int z2 = -1; z2 < 2; z2++)
	{
		for (int y2 = 12; y2 < 26; y2++)
		{
			locateBlock(bedrock, x + 9, y + y2, z + z2);//징징이콧대
		}
	}


}

void orange_sphere(double x, double y, double z, double radius) {
	WoolID orange = createWool(COLOR_ORANGE);

	double radian = M_PI / 180.;

	for (int i = 0; i < 360; i++) {
		for (int j = 0; j < 360; j++) {
			double x_ = radius * sin(radian * i) * cos(radian * j);
			double z_ = radius * sin(radian * i) * sin(radian * j);
			double y_ = radius * cos(radian * i);

			locateBlock(orange, x + x_, y + y_, z + z_);
		}
	}
}


void orange_circle(double x, double y, double z, double radius) {
	WoolID orange = createWool(COLOR_ORANGE);

	double radian = M_PI / 180.;

	for (int i = 0; i < 360; i++) {

		double x_ = radius * cos(radian * i);
		double z_ = radius * sin(radian * i);

		locateBlock(orange, x + x_, y, z + z_);

	}
}


void y_line(BlockID block, int x, int y, int z, int floor)
{
	for (int i = 0; i <= floor; i++)
	{
		locateBlock(block, x, y + i, z);
	}
}

void z_Lstair(BlockID block, int x, int y, int z, int floor)
{
	for (int i = 1; i <= floor; i++)
	{
		y_line(block, x, y + i, z - i, 2);
	}

}

void z_Rstair(BlockID block, int x, int y, int z, int floor)
{
	for (int i = 1; i <= floor; i++)
	{
		y_line(block, x, y + i, z + i, 2);
	}

}


void F_body(int sx, int sy, int sz, int radius)
{
	WoolID orange = createWool(COLOR_ORANGE);

	for (int i = 0; i <= 10; i++)
	{
		orange_circle(sx, sy + i, sz, radius);
	}
	orange_sphere(sx, sy + 10, sz, radius);
}

void F_hair(int x, int y, int z)
{
	WoolID green = createWool(COLOR_LIME);

	for (int i = -1; i <= 1; i++)
	{
		y_line(green, x + i, y + 18, z, 12);
		y_line(green, x, y + 18, z + i, 11);
	}

	z_Lstair(green, x, y + 19, z, 5);
	z_Rstair(green, x, y + 19, z, 5);

	for (int i = -1; i <= 1; i++)
	{
		z_Lstair(green, x + i, y + 19, z, 4);
		z_Rstair(green, x + i, y + 19, z, 4);
	}

}
void accessories(int sx, int sy, int sz)
{
	WoolID woolWh = createWool(COLOR_WHITE);
	WoolID woolBl = createWool(COLOR_LIGHT_BLUE);

	DoorID door = createDoor(DOOR_IRON, false, HINGE_RIGHT);

	locateBlock(woolBl, sx + 8, sy, sz - 1);
	locateBlock(woolBl, sx + 8, sy, sz + 1);
	locateBlock(woolBl, sx + 8, sy + 1, sz - 1);
	locateBlock(woolBl, sx + 8, sy + 2, sz);
	locateBlock(woolBl, sx + 8, sy + 1, sz + 1);

	installDoor(door, sx + 8, sy, sz, FACING_WEST);

	locateBlock(woolBl, sx + 8, sy + 11, sz + 3);
	locateBlock(woolWh, sx + 8, sy + 11, sz + 2);
	locateBlock(woolBl, sx + 8, sy + 11, sz + 1);
	locateBlock(woolBl, sx + 8, sy + 10, sz + 2);
	locateBlock(woolBl, sx + 8, sy + 12, sz + 2);

	locateBlock(woolBl, sx + 8, sy + 5, sz - 4);
	locateBlock(woolWh, sx + 8, sy + 5, sz - 3);
	locateBlock(woolBl, sx + 8, sy + 5, sz - 2);
	locateBlock(woolBl, sx + 8, sy + 4, sz - 3);
	locateBlock(woolBl, sx + 8, sy + 6, sz - 3);

	locateBlock(woolBl, sx, sy + 10, sz - 8);
	locateBlock(woolBl, sx + 1, sy + 10, sz - 8);
	locateBlock(woolBl, sx, sy + 10, sz - 9);
	locateBlock(woolBl, sx + 1, sy + 10, sz - 9);
	locateBlock(woolBl, sx, sy + 10, sz - 10);
	locateBlock(woolBl, sx + 1, sy + 10, sz - 10);

	y_line(woolBl, sx, sy + 10, sz - 11, 3);
	y_line(woolBl, sx + 1, sy + 10, sz - 11, 3);

}

void woodsquare(int x, int y, int z, int vertical, int horizontal) {  //직사각형 만들기_xz평면(나무)

	for (int j = -vertical; j < vertical; j++) {
		for (int i = -horizontal; i < horizontal; i++) {
			BlockID block = createWood(WoodType(1), WoodStrip(0));
			locateWood(block, x + i, y, z + j);
		}
	}
}

void woodcircle(int radius, int x, int y, int z) {  //속이 채워진 원 만들기_xz평면(나무)
	for (int i = -radius; i < radius; i++) {
		for (int j = -radius; j < radius; j++) {
			if (i*i + j * j < radius * radius) {
				BlockID block = createWood(WoodType(1), WoodStrip(0));
				locateWood(block, x + i, y, z + j);
			}
		}
	}
}

void wheel(int x, int y, int z, int radius) {	        //쳇바퀴 만들기 (나무-펜스-나무 구조)

	BlockID wood = createWood(WoodType(1), WoodStrip(0));
	BlockID leg = createFence(FenceType(1));

	double radian = M_PI / 180.;

	for (int i = 0; i < 360; i++) {
		double y_ = radius * cos(radian * i);
		double z_ = radius * sin(radian * i);
		locateBlock(wood, x, y + y_, z + z_);
		locateBlock(wood, x - 2, y + y_, z + z_);
		locateFence(leg, x - 1, y + y_, z + z_);
	}
	locateFence(leg, x, y - radius - 1, z);
	locateFence(leg, x - 1, y - radius - 1, z);


}

void trunk(int x, int y, int z) {  //중심 나무 몸통 만들기(나무)

	for (int i = 0; i < 17; i++) {
		woodsquare(x, y + i, z, 2, 2);
	}

	for (int j = 0; j < 6; j++) {

		woodcircle(6 - j, x, y + j, z);

	}

}

void branch(int x, int y, int z) {  //나뭇가지 만들기(나무 위에 눈 올리는 것까지 포함)

	for (int i = 0; i < 7; i++) {
		woodcircle(2, x + i, y + 16 + i, z + i);
		snowcircle(2, x + i, y + 17 + i, z + i);

		woodcircle(2, x + i, y + 16 + i, z - i);
		snowcircle(2, x + i, y + 17 + i, z - i);

		woodcircle(2, x - i, y + 16 + i, z - i);
		snowcircle(2, x - i, y + 17 + i, z - i);

		woodcircle(2, x - i, y + 16 + i, z + i);
		snowcircle(2, x - i, y + 17 + i, z + i);
	}

}


void snowcircle(int radius, int x, int y, int z) {  //바닥에 눈 깔기

	for (int i = -radius; i < radius; i++) {
		for (int j = -radius; j < radius; j++) {
			if (i*i + j * j < radius * radius) {

				locateSnow(createSnow(2), x + i, y, z + j);
			}
		}
	}
}

void sphere2(BlockID block, int x, int y, int z, double radius) {  //외부 벽면_반구(유리)
	double radian = M_PI / 180.;

	for (int i = 0; i < 90; i++) {
		for (int j = 0; j < 360; j++) {
			double x_ = radius * sin(radian * i) * cos(radian * j);
			double z_ = radius * sin(radian * i) * sin(radian * j);
			double y_ = radius * cos(radian * i);

			locateBlock(block, x + x_, y + y_, z + z_);
		}
	}
}

void bench(int x, int y, int z) {  //벤치(의자부분 - 계단, 다리부분 - 펜스)
	BlockOrientation orientations[4] = { FACING_EAST, FACING_WEST, FACING_SOUTH, FACING_NORTH };

	for (int i = 0; i < 4; i++) {
		BlockID chair = createStairs(StairsType(1), 0);
		BlockID leg = createFence(FenceType(1));
		locateFence(leg, x + 10, y, z + i + 7);
		installStairs(chair, x + 10, y + 1, z + i + 7, orientations[1]);
	}
}

void door(int x, int y, int z) {  //철문, 열린 상태
	BlockOrientation orientations[4] = { FACING_EAST, FACING_WEST, FACING_SOUTH, FACING_NORTH };
	BlockID door = createDoor(DoorType(2), 1, DoorHinge(1));
	BlockID glass = createBlock(BLOCK_GLASS);
	BlockID air = createBlock(BLOCK_AIR);
	installDoor(door, x - 31, y, z, orientations[0]);
	locateBlock(glass, x - 31, y, z + 1);
	locateBlock(glass, x - 31, y + 1, z + 1);
	locateBlock(glass, x - 31, y, z - 1);
	locateBlock(glass, x - 31, y + 1, z - 1);
	locateBlock(glass, x - 31, y + 2, z);
	locateBlock(air, x - 30, y, z);
	locateBlock(air, x - 30, y + 1, z);
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
	int jing_x = -18, jing_y = 4, jing_z = 35;
	jing_body(jing_x, jing_y, jing_z);
	jing_eye(jing_x, jing_y, jing_z);
	jing_mouth(jing_x, jing_y, jing_z);
	jing_ear(jing_x, jing_y, jing_z);
	jing_nose(jing_x, jing_y, jing_z);


	int pat_x = -18, pat_y = 4, pat_z = 57;

	sphere(netherrack, 9, pat_x, pat_y, pat_z);
	faucet(pat_x, pat_y + 9, pat_z);
	

	int s_x = -18, s_y = 4, s_z = 13;

	F_body(s_x, s_y, s_z, 8);
	F_hair(s_x, s_y, s_z);
	accessories(s_x, s_y, s_z);


	int krust_x = 83, krust_y = 4, krust_z = 60;
	krustykrab(krust_x, krust_y, krust_z);

	int sq_x = 130, sq_y = 4, sq_z = -26;

	sphere2(glass, sq_x, sq_y, sq_z, 30);
	snowcircle(30, sq_x, sq_y, sq_z);
	snowcircle(30, sq_x, sq_y, sq_z);
	trunk(sq_x, sq_y, sq_z);
	branch(sq_x, sq_y, sq_z);
	bench(sq_x, sq_y, sq_z);
	wheel(sq_x - 10, sq_y + 6, sq_z - 15, 5);
	door(sq_x, sq_y, sq_z);

	straw_house(10, 20, 'd', 140, 4, 15);
	straw_house(8, 16, 'd', 102, 4, 48);
	straw_house(7, 18, 'b', 105, 4, 23);
	straw_house(8, 24, 'r', 127, 4, 51);
	straw_house(13, 16, 'g', 129, 4, 82);
	straw_house(10, 28, 'b', 85, 4, 113);
	
	
	sunken(2, 52, 4, 114);
	sunken(-2, -43, 4, 49);
	sunken(2, 46, 4, 54);
	sunken(2, 73, 4, 12);
	sunken(-2, 108, 4, 107);
	sunken(2, 121, 4, 27);
	sunken(-2, -7, 4, -35);
	sunken(-2, -10, 9, -109);
	sunken(2, 58, 7, -116);
	sunken(-2, 100, 5, -82);
	sunken(2, 121, 7, -141);
	sunken_blue(2, -34, 4, 74);

	arc_bluerock(61, 6, -84);
	arc_bluerock(17, 7, -134);

	bluerock(128, 5, -91);
	

	jellyfish(29, 35, -173);
	jellyfish(66, 41, -190);
	jellyfish(79, 24, -182);
	jellyfish(110, 35, -158);
	jellyfish(144, 42, -139);
	jellyfish(103, 36, -110);
	jellyfish(94, 22, -112);
	jellyfish(55, 50, -104);
	jellyfish(22, 50, -91);
	jellyfish(11, 26, -64);

	king_jellyfish(56, 36, -172);
}
