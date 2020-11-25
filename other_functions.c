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

int Stone(int gameboard[6][6]){          //스톤들 ox로 시각화하기  
	
	int i, j;
	for (i = 0; i < 6; i++){
		
		for (j = 0; j < 6; j++){
			if (arr[i][j] == 0)  //돌이 없으면 공백으로  
				printf(" |");
			else if (gameboard[i][j] == 1)  //흰돌을 나타내는 1은 O로  
				printf("O|");
			else if (gameboard[i][j] == 2) //흑돌을 나타내는 2는 X로  
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
	int possible_space = 0;    //가능한 자리가 있는지 확인  
	int x,y;
	for (x = 0; x <= 7; x++){
		
		for (y = 0; y <= 7; y++){
			
			if (arr[x][y] == 3)
				possible_space++;
		}
	}
	if (possible_space == 0)  //가능한 자리가 없으면 1반환 => 
		return 1;
	else                      //가능한 자리가 있으면 0반환 => 
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
		
int put_White_stone(int stone_row, int stone_col, int gameboard[6][6]){   //가능한 자리 중에서 백돌이 가능한 자리에 백돌을 두세요!!

	int stone_x = stone_row; 
	int stone_y = stone_col;


	if (gameboard[stone_x][stone_y] == 3){            //3이 적혀있으면  
		gameboard[stone_x][stone_y] = 1;              //흰색돌을 두세요  
	
	else if ((gameboard[stone_x][stone_y] == 1) || (gameboard[stone_x][stone_y] == 2)) //1,2가 적혀있으면(흑.백돌이 이미 있으면) 
		return gameboard[6][6];                                                        //아무것도 하지말고 나오세요. 
		
	return gameboard[6][6];
	}
}


void gameboard_cpy(int v_gameboard_cpy[6][6], int gameboard[6][6]){    //배열들을 복사본에 넣으세요~~
	int x = 0; int y = 0;

	for (x = 0; x <= 7; x++){
		
		for (y = 0; y <= 7; y++){
			v_gameboard_cpy[x][y] = gameboard[x][y];  //gameboard 배열들을 variable gameboard copy변수에 복사하자
		}
	}
}

int gamboard_compare(int gameboard[6][6], int gameboard_cpy[6][6])  //복사본 원본 비교하는 함수
{
	int num= 0;              //num은 복사본과 원본이 몇 칸이나 같은 지 개수를 셀 때 필요한 변수  
	int x = 0; int y = 0;

	for (x = 0; x <= 7; x++)
		for (y = 0; y <= 7; y++){
			if (gameboard_cpy[x][y] == gameboard[x][y])
				num++;
		}
	if (num == 64)
		return 1;              //복사본과 원본이 같으면 아무것도 뒤집히지 않은 거니까(함수 진행시 오류가 있었음) 

	else if (num != 64)
		return 0;            //복사본과 원본이 다르다면 뒤집힌거다 (게임이 순조롭게 진행되고 있음) 
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
		printf("WHITE : %d개", White);
		printf("BLACK : %d개", Black);

		if (White > Black)
			printf("백돌 승");
		else if (White == Black)
			printf("무승부");
		else if (White < Black)
			printf("흑돌 승");
		return 1;
	}

	else
		return 0;
}
	
	 
