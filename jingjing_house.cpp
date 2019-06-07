#include<stdio.h>
#include "pch.h"
#include<CoalaMOD.h>
#pragma comment(lib,"CoalaMOD.lib")
#define M_PI   3.14159265358979323846

 void circle(int x, int y, int z)
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
		 circle(x, y + i, z);
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
			 locateBlock(glass, x + 8, y + 22+i, z + 3+j);//왼쪽눈알
			 locateBlock(glass, x + 8, y + 22+i, z - 5+j);//오른쪽눈알
		 }
	 }
	 for (int k = 0; k < 4; k++)
	 {
		 for (int u = 0; u < 3; u++)
		 {
			 locateBlock(edge, x + 8, y + 22 + u, z - 6 + 4*k);//눈테두리세로
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
 int main()
 {
	 int x, y, z;
	 scanf_s("%d%d%d", &x, &y, &z);
	 jing_body(x, y, z);
	 jing_eye(x, y, z); 
	 jing_mouth(x, y, z);
	 jing_ear(x, y, z); 
	 jing_nose(x, y, z);
}