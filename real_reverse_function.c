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

//������ �� �ִ� ���� �밢�� �������� �� 8����  


void Reverse_BtoW_Right(int gameboard[6][6], int stone_x, int stone_y){
	
	//�����ʿ� �������� �ִ��� �ľ� �� �ִٸ� �� �ִ��� �ľ�
	int num = 0;
	int k;
	for (k = k + 1; k <6; k++){
		
		if (gameboard[stone_x][stone_y] == 2){ 
	
			if (stone_y + 1 <6){

				if (gameboard[stone_x][stone_y + 1] == 2)
					num++;

				else if (gameboard[stone_x][stone_y + 1] == 1){
					
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
