#include <stdio.h>
#include <stdlib.h>
#define N 6
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//������ �ʱ�ȭ ����  
void main(int argc, char *argv[]) {
	int gameboard[6][6]={0};   //�ٸ� �Լ����� �� �� �ְ��Ϸ��� ���߿� ���������� ���� �� �Ͱ�����?? 
	int again = 0;
	   
	board(gameboard);                         //�ʱ�ȭ �� ������ ����
	  
	gameboard[2][2] = 1; 	gameboard[3][3] = 1;
	gameboard[2][3] = 2; 	gameboard[3][2] = 2;
	
	STATUS(x,y,gameboard);           //printf�� ��Ȳ�� ����Ѵ�. 
	stone(gameboard);                 //�� ��Ȳ ox�� �ð�ȭ. 
	
	while(isGameEnd() == 0){             //isGameEnd�Լ� �������Ѵ�.!!!!!!!return0;=>����, return1;���� �ȳ���. 
	white:
		find_space_W(gameboard);   //��� �����϶� ���Ǹ� ���� �� �� �ִ� ���� ã���ش�.
		stone(gameboard);               //�浹.�鵹 ��Ȳ ox�� �ð�ȭ		
		
		if (is_that_finish(gameboard) == 1){    //is_that_finish�� ���� ���� ������ 1 ��ȯ, ������ 0��ȯ
			
				again++;                           

				if (again >= 2){                  //�������� �� ���� 2�� ������ ���� �� �̻� �Ѽ� ������ ������ ����ȴ�. 
					check_result(gameboard);
					printf("���� �Ѱ��� ���� ������ �������ϴ�.");
				}

				else{
					printf("�Ѱ��� �����ϴ�.\n");         //turn��ü
					Eliminate_Three(gameboard);           //�����ߴ� �ڸ��� �ٽ� �ʱ�ȭ ������� ���� �϶� ������ �ȹ�ģ��. 
					goto black;                           //black turn ���� �̵�. 
				}
		}			//->�� �� ���� ������ if�� �ǳ� �ٰ� �Ʒ��� �;���!!!
		
		White_turn();       //put a new white othello ����ϴ� �Լ� 
		
		while(!!!!!!!!){   //�̺κ� ����� �ľ���!!! 
			   
			scanf("%d %d",&stone_row,&stone_col);  //������� ���� ��.�� ��ǥ�� �޴´�. 
			
			if ((gameboard[stone_row][stone_col] == 1) || (arr[stone_row][stone_col] == 2)){ //�̹� ���� �ִ� ���� 
					
						printf("invalid input! (already occupied)");
						goto back1;           //back�� �ڿ� ���´�..!!!!!!!!!!!(������ �ڸ��� 3���� ǥ�����ִ� �Լ�) 
					}             
					
			put_White_stone(stone_row, stone_col, gameboard);  //������ �ڸ� �߿��� ���� ���ϴ� �ڸ� �����ϰ� ����� ���� 
			gameboard_cpy(v_gameboard_cpy, gameboard);   //������ ���纻��  �־��ֱ�	
			
			Reverse_BtoW(gameboard, stone_x, stone_y);  //�� ������ �Լ��� �� ����ü,,,��ǻ� ���� �߿��� �κ�..!!!!!!how to code?????

					if (board_compare(gameboard, v_gameboard_cpy) == 1){     //���纻�� ���� ��ȭ�� ������ 
						gameboard[stone_x][stone_y] = 0;                     //�ξ��� ���� �ٽ� 0���� ����������
						printf("invalid input (no flip happens)");
						goto back1;        //�� �� ��� �� ��  
					}
					else if (gameboard_compare(gameboard, v_arr_cpy) == 0) //���纻 ������ ��ȭ�� ������ (������ ���� ������)
						;                                                  //�ƹ� �͵������� ������ ä�� �ֱ� 
				eliminate_3(gameboard);                           //���� �� �� �ִ��� �Ǵ��ϴ� 3�� ���� (1�� �������ϱ�) 
				STATUS(x, y, gameboard);                          //��.�浹 � ������ �����ֱ� 
				//flip result������ �� �ִ� ���ڿ� ����ؾ���!!!!!// 

		 
				
				Stone(gameboard);             //��ȭ�� ox�� �ð�ȭ���ֱ� 	
				
				if (gameover(gameboard) == 1)   //gameover�Լ��� 1�� ��ȯ�ϸ� ������ ���� ���̻� ����X. 
						return 0;
			

					
					break;  // while�� Ż��~~~
				}	 
					
			
					
		} 
		
		
	}
	
}


