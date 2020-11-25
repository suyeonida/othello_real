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

int Stone(int gameboard[6][6]){          //����� ox�� �ð�ȭ�ϱ�  
	
	int i, j;
	for (i = 0; i < 6; i++){
		
		for (j = 0; j < 6; j++){
			if (arr[i][j] == 0)  //���� ������ ��������  
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
			
			if (arr[x][y] == 3)
				possible_space++;
		}
	}
	if (possible_space == 0)  //������ �ڸ��� ������ 1��ȯ => 
		return 1;
	else                      //������ �ڸ��� ������ 0��ȯ => 
		return 0;
}

void check_result(int gameboard[6][6]){
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
				White++;
			}
			else if (gameboard[x][y] == 2){
				Black++;
			}
		}
	}
	Stone(gameboard);            //����� ox���ڷ� �ð�ȭ �ϱ� 
	
	printf("WHITE : %d��", White);
	
	printf("BLACK : %d��", Black);

	
	if (White > Black)
		printf("�鵹 ��");
	
	else if (White == Black)
		printf("���º�");
	else if (White < Black)
		printf("�浹 ��");
	

	return 0;
}

		
int put_White_stone(int stone_x, int stone_y, int gameboard[6][6]){   //������ �ڸ� �߿��� �鵹�� ������ �ڸ��� �鵹�� �μ���!!

	if (gameboard[stone_x][stone_y] == 3){            //3�� ����������  
		gameboard[stone_x][stone_y] = 1;              //������� �μ���  
	
	else if ((gameboard[stone_x][stone_y] == 1) || (gameboard[stone_x][stone_y] == 2)) //1,2�� ����������(��.�鵹�� �̹� ������) 
		return gameboard[6][6];                                                        //�ƹ��͵� �������� ��������. 
		
	return gameboard[6][6];
	}
}


void gameboard_cpy(int v_gameboard_cpy[6][6], int gameboard[6][6]){    //�迭���� ���纻�� ��������~~
	int x = 0; int y = 0;

	for (x = 0; x <= 7; x++){
		
		for (y = 0; y <= 7; y++){
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

	for (x = 0; x <= 7; x++){
		for (y = 0; y <= 7; y++){
			if (arr[x][y] == 0)
				;
			else if (arr[x][y] == 3)
				;
			else if (arr[x][y] == 1){
				finish++;
				White++;
			}
			else if (arr[x][y] == 2){
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
	int v2_gameboard_cpy[6][6] = { 0 };  //�ʿ� ���� �� ������?? 

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
	for (int x = 0; x <6; x++)
		for (int y = 0; y <6; y++){
			if (gameboard[x][y] == 3)
				gameboard[x][y] = 0;
		}

	return gameboard[6][6];
}

	
	 
