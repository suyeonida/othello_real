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
	return gameboard[6][6]; 
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
	Stone(gameboard);            //스톤들 ox문자로 시각화 하기 
	
	printf("WHITE : %d개", White);
	
	printf("BLACK : %d개", Black);

	
	if (White > Black)
		printf("백돌 승");
	
	else if (White == Black)
		printf("무승부");
	else if (White < Black)
		printf("흑돌 승");
	

	return 0;
}

		
int put_White_stone(int stone_x, int stone_y, int gameboard[6][6]){   //가능한 자리 중에서 백돌이 가능한 자리에 백돌을 두세요!!

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

int gameboard_compare(int gameboard[6][6], int gameboard_cpy[6][6]){ //복사본 원본 비교하는 함수

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


int isGameEnd(int gameboard[6][6]){     //흑돌,백돌로 게임판이 다 차면 게임을 종료한다. 
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

int find_space_W(int gameboard[6][6]){       //흰색 차례일때 사용되며 흰돌을 둘 수 있는 곳을 찾아준다.
	int x = 0; int y = 0;
	int v_gameboard_cpy[6][6] = { 0 };             
	int v2_gameboard_cpy[6][6] = { 0 };  //필요 없는 것 같은데?? 

	for (x = 0; x<6 ; x++){
		
		for (y = 0; y <6; y++){
			
			gameboard_cpy(v_gameboard_cpy, gameboard);   //gameboard 복사본 만들기  

			if ((v_gameboard_cpy[x][y] == 1) || (v_gameboard_cpy[x][y] == 2))  //복사본에 1,2(백돌, 흑돌)있으면 그냥pass 
				;

			else if ((v_gameboard_cpy[x][y] == 0) || (v_gameboard_cpy[x][y] == 3)){  //복사본에 아직 채워지지 않은 곳이 있으면  

				int num = 0;                            

				if (v_gameboard_cpy[x][y] == 0)         //복사본에 빈자리라면 num에 0대입  
					num = 0;
				else if (v_gameboard_cpy[x][y] == 1)    //복사본에 흑돌이 있다면 num에 1대입  
					num = 1;
				else if (v_gameboard_cpy[x][y] == 2)    //복사본에 검은돌이 있다면 num에 2대입   
					num = 2;
				else if (v_gameboard_cpy[x][y] == 3)    //복사본에 가능했던 자리였다면 num에 3대입   
					num = 3;


				v_gameboard_cpy[x][y] = 1; //white turn이 놓은 백돌자리를 복사본에도 지정해줘 

				//Reverse_B_to_W(m_arr_cpy, col, row);   //흰돌로 뒤집힌다  (아직 함수 작성을 못했다ㅠ) 

				//v_gameboard_cpy[x][y] = num;             //복사본에 player가 둔 자리에 돌을 놔야하니까 num변수가 필요함. 

				if (gameboard_compare(gameboard, v_gameboard_cpy) == 1)  //복사본 원본 그대로면 white가 둘 수 있는 곳이 아니다.  
					;
				else if (gameboard_compare(gameboard, v_gameboard_cpy) == 0){  //복사본 원본 다르다면 무언가 뒤집힌거(white가 둘 수 있는 자리) 
					gameboard[x][y] = 3;                               //가능한 자리에 3을 적어 표시해줘야지  
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

	
	 
