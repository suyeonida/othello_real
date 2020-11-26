#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void Reverse_BtoW(int gameboard[6][6], int  x, int y){
	void Reverse_BtoW_Right(int gameboard[6][6], int x, int y);
	void Reverse_BtoW_Left(int gameboard[6][6], int x, int y);
	void Reverse_BtoW_Down(int gameboard[6][6], int x, int y);
	void Reverse_BtoW_Up(int gameboard[6][6], int x, int y);
	void Reverse_BtoW_Right_Down(int gameboard[6][6], int x, int y);
	void Reverse_BtoW_Left_Up(int gameboard[6][6], int x, int y);
	void Reverse_BtoW_Left_Down(int gameboard[6][6], int x, int y);
	void Reverse_BtoW_Right_Up(int gameboard[6][6], int x, int y);
	
}

void Reverse_WtoB(int gameboard[6][6], int  x, int y){
	void Reverse_WtoB_Right(int gameboard[6][6], int x, int y);
	void Reverse_WtoB_Left(int gameboard[6][6], int x, int y);
	void Reverse_WtoB_Down(int gameboard[6][6], int x, int y);
	void Reverse_WtoB_Up(int gameboard[6][6], int x, int y);
	void Reverse_WtoB_Right_Down(int gameboard[6][6], int x, int y);
	void Reverse_WtoB_Left_Up(int gameboard[6][6], int x, int y);
	void Reverse_WtoB_Left_Down(int gameboard[6][6], int x, int y);
	void Reverse_WtoB_Right_Up(int gameboard[6][6], int x, int y);
	
}

//뒤집을 수 있는 방향 대각선 방향포함 총 8가지  


void Reverse_BtoW_Right(int gameboard[6][6], int stone_x, int stone_y){
	
	int num = 0;
	
	for (stone_x = stone_x + 1; stone_x <6; stone_x++){
		
		if (gameboard[stone_x][stone_y] == 2){ 
	
			if (stone_y + 1 <6){

				if (gameboard[stone_x][stone_y + 1] == 2)     //오른쪽에 검은돌이 있는지 먼저 파악한다.
					num++;

				else if (gameboard[stone_x][stone_y + 1] == 1){    //흰돌이 있는지 파악한다. 
					
					for (num = stone_y - num; stone_y >= num; stone_y--){
						gameboard[stone_x][stone_y] = 1;
					}
					break;
				}
				else
					break;
			}
			else
				break;
		}
		else

			break;
	}
}

void Reverse_BtoW_Left(int boardgame[6][6], int stone_x, int stone_y){
	int num = 0;
	
	for (stone_x = stone_x - 1; stone_x >= 0; stone_x--){
		if (gameboard[row][stone_x] == 2) {
			
			if (stone_x - 1 >= 0){

				if (gameboard[row][stone_x - 1] == 2)
					num++;

				else if (gameboard[row][stone_x - 1] == 1){
					for (num = stone_x + num; stone_x <= num; stone_x++){
						gameboard[row][stone_x] = 1;
					}
					break;
				}
				else
					break;
			}
			else
				break;
		}
		else
			break;
	}
}

void Reverse_BtoW_Down(int gameboard[6][6], int stone_x, int stone_y)
{
	
	int num = 0;
	for (stone_y = stone_y + 1; stone_y <6; stone_y++){
		if (gameboard[stone_y][stone_x] == 2) {
			if (row + 1 <6){

				if (gameboard[stone_y + 1][stone_x] == 2)
					num++;

				else if (gameboard[stone_y + 1][stone_x] == 1)
				{
					for (num = stone_y - num; stone_y >= num; stone_y--)
					{
						gameboard[stone_y][stone_x] = 1;
					}
					break;
				}
				else
					break;
			}
			else
				break;
		}
		else

			break;
	}
}

void Reverse_BtoW_Up(int gameboard[6][6], int stone_x, int stone_y){
	int num = 0;

	for (stone_y = stone_y - 1; stone_y >= 0; stone_y--){
		if (gameboard[stone_y][col] == 2) {
			if (stone_y - 1 >= 0){

				if (gameboard[stone_y - 1][col] == 2)
					num++;

				else if (gameboard[stone_y - 1][col] == 1){
					
					for (num = stone_y + num; stone_y <= num; stone_y++){
						gameboard[stone_y][stone_x] = 1;
						Stone(gameboard);
					}
					break;
				}
				else
					break;
			}
			else
				break;
		}
		else
			break;
	}
}
