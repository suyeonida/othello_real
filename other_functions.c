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
	return gameboard[N][N]; 
}

void White_turn(){
	
	printf("put a new white othello : ")
	
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

void Finish(int gameboard[6][6]){
	int White = 0;
	int Black = 0;
	int x,y;
}

	for (x = 0; x <= 7; x++){
		for (y = 0; y <= 7; y++){
			
			if (gameboard[x][y] == 0)
				;
			else if (gameboard[x][y] == 3)
				;
			else if (gameboard[x][y] == 1)
			{
				White++;
			}
			else if (gameboard[x][y] == 2)
			{
				Black++;
			}
		}
	}
		
int put_White_stone(int stone_row, int stone_col, int gameboard[6][6]){   //������ �ڸ� �߿��� �鵹�� ������ �ڸ��� �鵹�� �μ���!!

	int stone_x = stone_row; 
	int stone_y = stone_col;


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

int gamboard_compare(int gameboard[6][6], int gameboard_cpy[6][6])  //���纻 ���� ���ϴ� �Լ�
{
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

int eliminate_3 (int gameboard[6][6]){
	for (int x = 0; x <= 7; x++)
		for (int y = 0; y <= 7; y++){
			if (gameboard[x][y] == 3)
				gameboard[x][y] = 0;
		}
	return gameboard[6][6];
}

int game_over(int gameboard[6][6]){
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
	
	if (finish == 64){
	
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
	
	 
