#include <stdio.h>
#include <stdlib.h>
#define N 6
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//������ �ʱ�ȭ ����  
void main(int argc, char *argv[]) {
	int gameboard[6][6]={0};   //�ٸ� �Լ����� �� �� �ְ��Ϸ��� ���߿� ���������� ���� �� �Ͱ�����?? 
	int again = 0;
	int stone_x=0; int stone_y=0;
	int scanfReTwo=0; 
	int v_gameboard_cpy=0;
	board(gameboard);                         //�ʱ�ȭ �� ������ ����
	  
	gameboard[2][2] = 1; 	gameboard[3][3] = 1;
	gameboard[2][3] = 2; 	gameboard[3][2] = 2;
	
	STATUS(gameboard);            //printf�� ��Ȳ�� ����Ѵ�. 
	stone(gameboard);                 //�� ��Ȳ ox�� �ð�ȭ. 
	
	while(isGameEnd() == 0){             //isGameEnd �Լ� return0;=>�� �� ���� , return1;=>�� ����. 
	white:
		find_space_W(gameboard);   //��� �����϶�,���� �� �� �ִ� ���� ã���ش�.(3���� ǥ��) ���ο� reverse�Լ� �������. 
		stone(gameboard);               //�浹.�鵹 ��Ȳ ox�� �ð�ȭ		
		
		if (is_that_finish(gameboard) == 1){    //������ �ڸ�(3�ڸ�)��  ������ 1 ��ȯ, ������ 0��ȯ
			
				again++;                           

				if (again >= 2){                  //�������� �� ���� 2�� ������ ���� �� �̻� �Ѽ� ������ ������ ����ȴ�. 
					check_result(gameboard);
					printf("���� �Ѱ��� �����ϴ�.���� ��!");
				}

				else{
					printf("�Ѱ��� �����ϴ�.\n");         //turn��ü
					Eliminate_Three(gameboard);           //�����ߴ� �ڸ�(3)�� �ٽ� �ʱ�ȭ ������� ���� �϶� ������ �ȹ�ģ��. 
					goto black;                           //black turn ���� �̵�. 
				}
		}			//->�� �� ���� ������ if�� �ǳ� �ٰ� �Ʒ��� �;���.
		
		printf("put a new white othello : ");      //put a new white othello ����ϴ� �Լ� 
		scanf("%d %d",&stone_x,&stone_y);      //������� ���� ��.�� ��ǥ�� �޴´�. 
		scanfReTwo = scanf("%d %d",&stone_x,&stone_y);       
		
		while(1){                             //scanf�� �� 2���� ������ ���ѷ��� ������ 
			if(scanfReTwo == 2){
			
			   if ((gameboard[stone_x][stone_y] == 1) || (gameboard[stone_x][stone_y] == 2)){   //�̹� �浹.�鵹�� �ִ� �� 
					
					printf("invalid input! (already occupied)");
					goto below;           //back�� �ڿ� ���´�..!!!!!!!!!!!(������ �ڸ��� 3���� ǥ�����ִ� �Լ�) 
				}             
					
				put_White_stone(stone_x, stone_y, gameboard);  //������ �ڸ� �߿��� ���� ���ϴ� �ڸ� �����ϰ� ����� ���� 
				gameboard_cpy(v_gameboard_cpy, gameboard);   //������ ���纻��  �־��ֱ�	
			
				//Reverse_BtoW(gameboard, stone_x, stone_y);  //!!!!!!how to code?????

				if (gameboard_compare(gameboard, v_gameboard_cpy) == 1){     //���纻�� ���� ��ȭ�� ������ 
					gameboard[stone_x][stone_y] = 0;                     //�ξ��� ���� �ٽ� 0���� ����������
					printf("invalid input (no flip happens)");
					goto below;        
				}
				else if (gameboard_compare(gameboard, v_gameboard_cpy) == 0) //���纻 ������ ��ȭ�� ������ (������ ���� ������)
						;                                                  //�ƹ� �͵������� ������ ä�� �ֱ� 
				Eliminate_Three(gameboard);                           //���� �� �� �ִ��� �Ǵ��ϴ� 3�� ���� (1�� �������ϱ�)
				 
				STATUS(gameboard);                          //��.�浹 � ������ �����ֱ� 
				
				 	//!!!flip result������ �� �ִ� ���ڿ� ����ؾ���!!!!!// 
				
				gameboard_cpy(v_gameboard_cpy, gameboard); //�浹 turn�غ�  
				find_space_B(gameboard); //�浹  �����϶�,�浹 �� �� �ִ� �� ã���ش�.(3���� ǥ��) ���ο� reverse�Լ� �������.
				Stone(gameboard);             //��ȭ�� ox�� �ð�ȭ���ֱ� 	
				
				if (isGameEnd() == 1)   //isGameEnd�Լ��� 1�� ��ȯ�ϸ� ������ ���� ���̻� ����X. 
					Finish();
					return 0;  //!!!!!!!while�� Ż��  
				break; 
			}
			else{
			below:
				find_space_W(gameboard);    //������ �ڸ��� 3���� ǥ�� ���ֱ� 
				Stone(gameboard); //������ �ڸ� �ð�ȭ���ֱ� �ٵ� ������ �ڸ� �ð�ȭ ������ �ʿ� ���� 
			}                    //else ������ ��  
		}   //whiel(1)������ �� 
		Eliminate_Three(gameboard);
		find_space_B(gameboard);        // �浹 ������ �ڸ� ã���ְ� 3���� ǥ���ϱ� 
		
		////////////////////////////////���ķδ� �浹 ���� ���� MAIN�Լ�///////////////////////////////////////////// 
		
	 

					
			
		
		
	
	
	}//while�� ��  

}  //��ü�Լ� ��  


