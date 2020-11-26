#include <stdio.h>
#include <stdlib.h>
#define N 6
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int board(int gameboard[6][6]);

int Stone(int gameboard[6][6]);
int is_that_finish(int gameboard[6][6]);
int put_White_stone(int stone_x, int stone_y, int gameboard[6][6]);
void Finish(int gameboard[6][6]);
int gameboard_compare(int gameboard[6][6], int gameboard_cpy[6][6]);
int isGameEnd(int gameboard[6][6]);
int find_space_W(int gameboard[6][6]);
int Eliminate_Three(int gameboard[6][6]);

int put_Black_stone(int stone_x, int stone_y, int gameboard[6][6]);

 
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
	Stone(gameboard);                 //�� ��Ȳ ox�� �ð�ȭ. 
	
	while(isGameEnd(gameboard) == 0){             //isGameEnd �Լ� return0;=>�� �� ���� , return1;=>�� ����. 
	white:
		find_space_W(gameboard);   //��� �����϶�,���� �� �� �ִ� ���� ã���ش�.(3���� ǥ��) ���ο� reverse�Լ� �������. 
		stone(gameboard);               //�浹.�鵹 ��Ȳ ox�� �ð�ȭ		
		
		if (is_that_finish(gameboard) == 1){    //������ �ڸ�(3�ڸ�)��  ������ 1 ��ȯ, ������ 0��ȯ
			
				again++;                           

				if (again >= 2){                  //�������� �� ���� 2�� ������ ���� �� �̻� �Ѽ� ������ ������ ����ȴ�. 
					Finish(gameboard);
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
				gameboard_cpy( v_gameboard_cpy, gameboard);   //������ ���纻��  �־��ֱ�	
			
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
				
				if (isGameEnd(gameboard) == 1)   //isGameEnd�Լ��� 1�� ��ȯ�ϸ� ������ ���� ���̻� ����X. 
					Finish(gameboard);
					 
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
		
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////
		////////////////////////////////���ķδ� �浹 ���� ���� MAIN�Լ�///////////////////////////////////////////// 
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
	black:
		
		find_space_B(gameboard);       // �浹 ������ �ڸ� ã���ְ� 3���� ǥ���ϱ�
		Stone(gameboard); ///////�� �� �ִ� �� ã�Ƽ�  0,1,2,3 �ð�ȭ �ϰ�
		
		if (is_that_finish(gameboard) == 1){     //���� ���� ������ 1 ��ȯ, ������ 0��ȯ   
				again++;

				if (again>= 2){
					Finish(gameboard);
					printf("���� �Ѱ��� ���� ������ �����ϴ�.");
				}
				else{
					printf("�Ѱ��� �����ϴ�.\n");         //turn��ü
					Eliminate_Three(gameboard);           //�����ߴ� �ڸ�(3)�� �ٽ� �ʱ�ȭ ������� ���� �϶� ������ �ȹ�ģ��. 
					goto white;                           //white turn ���� �̵�. 
				}
			}			//->�� �� ���� ������ if�� �ǳ� �ٰ� �Ʒ��� �;���!!!

			printf("put a new black othello : ");      //put a new white othello ����ϴ� �Լ� 
			scanf("%d %d",&stone_x,&stone_y);      //������� ���� ��.�� ��ǥ�� �޴´�. 
			scanfReTwo = scanf("%d %d",&stone_x,&stone_y);    
			
		while(1){                             //scanf�� �� 2���� ������ ���ѷ��� ������ 
			if(scanfReTwo == 2){
			
			   if ((gameboard[stone_x][stone_y] == 1) || (gameboard[stone_x][stone_y] == 2)){   //�̹� �浹.�鵹�� �ִ� �� 
					
					printf("invalid input! (already occupied)");
					goto below2;           //back�� �ڿ� ���´�..!!!!!!!!!!!(������ �ڸ��� 3���� ǥ�����ִ� �Լ�) 
				}             
					
				put_Black_stone(stone_x, stone_y, gameboard);  //������ �ڸ� �߿��� ���� ���ϴ� �ڸ� �����ϰ� ����� ���� 
				gameboard_cpy(v_gameboard_cpy, gameboard);   //������ ���纻��  �־��ֱ�	
			
				//Reverse_WtoB(gameboard, stone_x, stone_y);  //!!!!!!how to code?????

				if (gameboard_compare(gameboard, v_gameboard_cpy) == 1){     //���纻�� ���� ��ȭ�� ������ 
					gameboard[stone_x][stone_y] = 0;                     //�ξ��� ���� �ٽ� 0���� ����������
					printf("invalid input (no flip happens)");
					goto below2;        
				}
				else if (gameboard_compare(gameboard, v_gameboard_cpy) == 0) //���纻 ������ ��ȭ�� ������ (������ ���� ������)
						;                                                  //�ƹ� �͵������� ������ ä�� �ֱ� 
				Eliminate_Three(gameboard);                           //���� �� �� �ִ��� �Ǵ��ϴ� 3�� ���� (1�� �������ϱ�)
				 
				STATUS(gameboard);                          //��.�浹 � ������ �����ֱ� 
				
				 	//!!!flip result������ �� �ִ� ���ڿ� ����ؾ���!!!!!// 
				
				gameboard_cpy(v_gameboard_cpy, gameboard); //�浹 turn�غ�  
				find_space_B(gameboard); //�浹  �����϶�,�浹 �� �� �ִ� �� ã���ش�.(3���� ǥ��) ���ο� reverse�Լ� �������.
				Stone(gameboard);             //��ȭ�� ox�� �ð�ȭ���ֱ� 	
				
				if (isGameEnd(gameboard) == 1)   //isGameEnd�Լ��� 1�� ��ȯ�ϸ� ������ ���� ���̻� ����X. 
					Finish(gameboard);
					  
				break; while(1){                             //scanf�� �� 2���� ������ ���ѷ��� ������ 
			if(scanfReTwo == 2){
			
			   if ((gameboard[stone_x][stone_y] == 1) || (gameboard[stone_x][stone_y] == 2)){   //�̹� �浹.�鵹�� �ִ� �� 
					
					printf("invalid input! (already occupied)");
					goto below2;           //back�� �ڿ� ���´�..!!!!!!!!!!!(������ �ڸ��� 3���� ǥ�����ִ� �Լ�) 
				}             
					
				put_Black_stone(stone_x, stone_y, gameboard);  //������ �ڸ� �߿��� ���� ���ϴ� �ڸ� �����ϰ� �浹 ���� 
				gameboard_cpy(v_gameboard_cpy, gameboard);   //������ ���纻��  �־��ֱ�	
			
				//Reverse_BtoW(gameboard, stone_x, stone_y);  //!!!!!!how to code?????

				if (gameboard_compare(gameboard, v_gameboard_cpy) == 1){     //���纻�� ���� ��ȭ�� ������ 
					gameboard[stone_x][stone_y] = 0;                     //�ξ��� ���� �ٽ� 0���� ����������
					printf("invalid input (no flip happens)");
					goto below2;        
				}
				else if (gameboard_compare(gameboard, v_gameboard_cpy) == 0) //���纻 ������ ��ȭ�� ������ (������ ���� ������)
						;                                                  //�ƹ� �͵������� ������ ä�� �ֱ� 
				Eliminate_Three(gameboard);                           //���� �� �� �ִ��� �Ǵ��ϴ� 3�� ���� (1�� �������ϱ�)
				 
				STATUS(gameboard);                          //��.�浹 � ������ �����ֱ� 
				
				 	//!!!flip result������ �� �ִ� ���ڿ� ����ؾ���!!!!!// 
				
				gameboard_cpy(v_gameboard_cpy, gameboard); //�浹 turn�غ�  
				find_space_B(gameboard); //�浹  �����϶�,�浹 �� �� �ִ� �� ã���ش�.(3���� ǥ��) ���ο� reverse�Լ� �������.
				Stone(gameboard);             //��ȭ�� ox�� �ð�ȭ���ֱ� 	
				
				if (isGameEnd(gameboard) == 1)   //isGameEnd�Լ��� 1�� ��ȯ�ϸ� ������ ���� ���̻� ����X. 
					Finish(gameboard);
					
				break;   //While(1)�� Ż��  
			}
			else{
			below2:
				find_space_B(gameboard);    //������ �ڸ��� 3���� ǥ�� ���ֱ� 
				Stone(gameboard); //������ �ڸ� �ð�ȭ���ֱ� �ٵ� ������ �ڸ� �ð�ȭ ������ �ʿ� ���� 
			}                    //else ������ ��  
		}   //whiel(1)������ �� 
		Eliminate_Three(gameboard);
		find_space_W(gameboard);        // �鵹 ������ �ڸ� ã���ְ� 3���� ǥ���ϱ�	   	
	
			}//while�� ��  
	
		}  
	}
}//��ü�Լ� ��  

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////���� �Լ���////////////////////////////////////////////////////////// 
int board(int gameboard[6][6]) {
	int i,j;
	printf("  0 1 2 3 4 5\n--------------\n");
	for(i=0;i<6;i++){
			printf("%d|",i);
		for(j=0;j<6;j++){
			printf("%d|",gameboard);  
		}
	printf("\n--------------\n");
	}
	return gameboard[6][6];
}
void STATUS(int stone_x,int stone_y, int gameboard[6][6]){  //�浹 �鵹 ���� ��Ÿ���� �Լ� 
	int x,y;
	x=stone_x;
	y=stone_y;
	int White = 0;  int Black = 0;

	for (x = 0; x<6; x++){
		for (y = 0; y <6; y++){
			if (gameboard[x][y] == 0)
				;
			else if (gameboard[x][y] == 1)
				White++;
			else if (gameboard[x][y] == 2)
				Black++;
			else if (gameboard[x][y] == 3)
				;
		}
	}
	printf("WHITE : %d��, BLACK : %d�� ", White, Black);
}

int Stone(int gameboard[6][6]){          //����� ox�� �ð�ȭ�ϱ�  
	
	int i, j;
	for (i = 0; i < 6; i++){
		
		for (j = 0; j < 6; j++){
			if (gameboard[i][j] == 0)  //���� ������ ��������  
				printf(" |");
			else if (gameboard[i][j] == 1)  //���� ��Ÿ���� 1�� O��  
				printf("O|");
			else if (gameboard[i][j] == 2) //�浹�� ��Ÿ���� 2�� X��  
				printf("X|");
		}
		printf("\n--------------\n"); 
	}
	return gameboard[6][6]; 
}

		
int is_that_finish(int gameboard[6][6]){
	int possible_space = 0;    //������ �ڸ��� �ִ��� Ȯ��  
	int x,y;
	for (x = 0; x <= 7; x++){
		
		for (y = 0; y <= 7; y++){
			
			if (gameboard[x][y] == 3)
				possible_space++;
		}
	}
	if (possible_space == 0)  //������ �ڸ��� ������ 1��ȯ => 
		return 1;
	else                      //������ �ڸ��� ������ 0��ȯ => 
		return 0;
}

		
int put_White_stone(int stone_x, int stone_y, int gameboard[6][6]){   //������ �ڸ� �߿��� �鵹�� ������ �ڸ��� �鵹�� �μ���!!

	if (gameboard[stone_x][stone_y] == 3){            //3�� ����������  
		gameboard[stone_x][stone_y] = 1;              //������� �μ���  
	}
	else if ((gameboard[stone_x][stone_y] == 1) || (gameboard[stone_x][stone_y] == 2)) //1,2�� ����������(��.�鵹�� �̹� ������) 
		return gameboard[6][6];                                                        //�ƹ��͵� �������� ��������. 
		
	return gameboard[6][6];
	}



void gameboard_cpy(int v_gameboard_cpy[6][6], int gameboard[6][6]){    //�迭���� ���纻�� ��������~~
	int x = 0; int y = 0;

	for (x = 0; x <6; x++){
		
		for (y = 0; y <6; y++){
			v_gameboard_cpy[x][y] = gameboard[x][y];  //gameboard �迭���� variable gameboard copy������ ��������
		}
	}
}

int gameboard_compare(int gameboard[6][6], int gameboard_cpy[6][6]){ //���纻 ���� ���ϴ� �Լ�

	int num= 0;              //num�� ���纻�� ������ �� ĭ�̳� ���� �� ������ �� �� �ʿ��� ����  
	int x = 0; int y = 0;

	for (x = 0; x <= 7; x++)
		for (y = 0; y <= 7; y++){
			if (gameboard_cpy[x][y] == gameboard[x][y])
				num++;
		}
	if (num == 64)
		return 1;              //���纻�� ������ ������ �ƹ��͵� �������� ���� �Ŵϱ�(�Լ� ����� ������ �־���) 

	else if (num != 64)
		return 0;            //���纻�� ������ �ٸ��ٸ� �������Ŵ� (������ �����Ӱ� ����ǰ� ����) 
}


int isGameEnd(int gameboard[6][6]){     //�浹,�鵹�� �������� �� ���� ������ �����Ѵ�. 
	int finish = 0;
	int White = 0;
	int Black = 0;
	int x,y;
	
	for (x = 0; x <= 7; x++){
		for (y = 0; y <= 7; y++){
			if (gameboard[x][y] == 0)
				;
			else if (gameboard[x][y] == 3)
				;
			else if (gameboard[x][y] == 1){
				finish++;
				White++;
			}
			else if (gameboard[x][y] == 2){
				finish++;
				Black++;
			}
		}
	}
	
	if (finish == 36){
	
		Stone(gameboard);
		printf("WHITE : %d��", White);
		printf("BLACK : %d��", Black);

		if (White > Black)
			printf("�鵹 ��");
		else if (White == Black)
			printf("���º�");
		else if (White < Black)
			printf("�浹 ��");
		return 1;
	}

	else
		return 0;
}

int find_space_W(int gameboard[6][6]){       //��� �����϶� ���Ǹ� ���� �� �� �ִ� ���� ã���ش�.
	int x = 0; int y = 0;
	int v_gameboard_cpy[6][6] = { 0 };              

	for (x = 0; x<6 ; x++){
		
		for (y = 0; y <6; y++){
			
			gameboard_cpy(v_gameboard_cpy, gameboard);   //gameboard ���纻 �����  

			if ((v_gameboard_cpy[x][y] == 1) || (v_gameboard_cpy[x][y] == 2))  //���纻�� 1,2(�鵹, �浹)������ �׳�pass 
				;

			else if ((v_gameboard_cpy[x][y] == 0) || (v_gameboard_cpy[x][y] == 3)){  //���纻�� ���� ä������ ���� ���� ������  

				int num = 0;                            

				if (v_gameboard_cpy[x][y] == 0)         //���纻�� ���ڸ���� num�� 0����  
					num = 0;
				else if (v_gameboard_cpy[x][y] == 1)    //���纻�� �浹�� �ִٸ� num�� 1����  
					num = 1;
				else if (v_gameboard_cpy[x][y] == 2)    //���纻�� �������� �ִٸ� num�� 2����   
					num = 2;
				else if (v_gameboard_cpy[x][y] == 3)    //���纻�� �����ߴ� �ڸ����ٸ� num�� 3����   
					num = 3;


				v_gameboard_cpy[x][y] = 1; //white turn�� ���� �鵹�ڸ��� ���纻���� �������� 

				//Reverse_B_to_W(m_arr_cpy, col, row);   //�򵹷� ��������  (���� �Լ� �ۼ��� ���ߴ٤�) 

				//v_gameboard_cpy[x][y] = num;             //���纻�� player�� �� �ڸ��� ���� �����ϴϱ� num������ �ʿ���. 

				if (gameboard_compare(gameboard, v_gameboard_cpy) == 1)  //���纻 ���� �״�θ� white�� �� �� �ִ� ���� �ƴϴ�.  
					;
				else if (gameboard_compare(gameboard, v_gameboard_cpy) == 0){  //���纻 ���� �ٸ��ٸ� ���� ��������(white�� �� �� �ִ� �ڸ�) 
					gameboard[x][y] = 3;                               //������ �ڸ��� 3�� ���� ǥ���������  
				}
			}
		}
	}

	return gameboard[6][6]; 

}

int Eliminate_Three(int gameboard[6][6]) {
	int x,y;
	for (x = 0; x <6; x++)
		for (y = 0; y <6; y++){
			if (gameboard[x][y] == 3)
				gameboard[x][y] = 0;
		}

	return gameboard[6][6];
}

void Finish(int gameboard[6][6]){
	int White = 0;
	int Black = 0;
	int x,y;
	for (x = 0; x <6; x++){
		for (y = 0; y <6; y++){
			if (gameboard[x][y] == 0)
				;
			else if (gameboard[x][y] == 3)
				;
			else if (gameboard[x][y] == 1)
				White++;
			else if (gameboard[x][y] == 2)
				Black++;
		}
	}
	
	Stone(gameboard);
	
	printf("WHITE: %d��,Black : %d�� ", White, Black);
	
	if (White > Black)
		printf("�鵹 ��");
	else if (White == Black)
		printf("���º�");
	else if (White < Black)
	
		printf("�浹 ��");
		
	return;
}

//black turn �� �� �߰��� �ʿ��� �Լ���

int find_space_B(int gameboard[6][6]){       //��� �����϶� ���Ǹ� ���� �� �� �ִ� ���� ã���ش�.
	int x = 0; int y = 0;
	int v_gameboard_cpy[6][6] = { 0 };             

	for (x = 0; x<6 ; x++){
		
		for (y = 0; y <6; y++){
			
			gameboard_cpy(v_gameboard_cpy, gameboard);   //gameboard ���纻 �����  

			if ((v_gameboard_cpy[x][y] == 1) || (v_gameboard_cpy[x][y] == 2))  //���纻�� 1,2(�鵹, �浹)������ �׳�pass 
				;

			else if ((v_gameboard_cpy[x][y] == 0) || (v_gameboard_cpy[x][y] == 3)){  //���纻�� ���� ä������ ���� ���� ������  

				int num = 0;                            

				if (v_gameboard_cpy[x][y] == 0)         //���纻�� ���ڸ���� num�� 0����  
					num = 0;
				else if (v_gameboard_cpy[x][y] == 1)    //���纻�� �浹�� �ִٸ� num�� 1����  
					num = 1;
				else if (v_gameboard_cpy[x][y] == 2)    //���纻�� �������� �ִٸ� num�� 2����   
					num = 2;
				else if (v_gameboard_cpy[x][y] == 3)    //���纻�� �����ߴ� �ڸ����ٸ� num�� 3����   
					num = 3;


				v_gameboard_cpy[x][y] = 2; //black turn�� ���� �鵹  �ڸ��� ���纻���� �������� 

				//Reverse_WtoB(m_arr_cpy, x, y);   //�浹�� ��������  (���� �Լ� �ۼ��� ���ߴ٤�) 

				//v_gameboard_cpy[x][y] = num;             //���纻�� player�� �� �ڸ��� ���� �����ϴϱ� num������ �ʿ���. 

				if (gameboard_compare(gameboard, v_gameboard_cpy) == 1)  //���纻 ���� �״�θ� white�� �� �� �ִ� ���� �ƴϴ�.  
					;
				else if (gameboard_compare(gameboard, v_gameboard_cpy) == 0){  //���纻 ���� �ٸ��ٸ� ���� ��������(white�� �� �� �ִ� �ڸ�) 
					gameboard[x][y] = 3;                               //������ �ڸ��� 3�� ���� ǥ���������  
				}
			}
		}
	}

	return gameboard[6][6]; 

}

int put_Black_stone(int stone_x, int stone_y, int gameboard[6][6]){   //�浹�� ������ �ڸ� �߿���  �� �� �μ���!!

	if (gameboard[stone_x][stone_y] == 3){            //3�� ����������  
		gameboard[stone_x][stone_y] = 2;              //��� ���� �μ���  
	}
	else if ((gameboard[stone_x][stone_y] == 1) || (gameboard[stone_x][stone_y] == 2)) //1,2�� ����������(��.�鵹�� �̹� ������) 
		return gameboard[6][6];                                                        //�ƹ��͵� �������� ��������. 
		
	return gameboard[6][6];
	}
 
	
	 
