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

 
//보드판 초기화 상태  
void main(int argc, char *argv[]) {
	int gameboard[6][6]={0};   //다른 함수들이 알 수 있게하려면 나중에 전역변수로 빼야 할 것같은데?? 
	int again = 0;
	int stone_x=0; int stone_y=0;
	int scanfReTwo=0; 
	int v_gameboard_cpy=0;
	board(gameboard);                         //초기화 된 게임판 생성
	  
	gameboard[2][2] = 1; 	gameboard[3][3] = 1;
	gameboard[2][3] = 2; 	gameboard[3][2] = 2;
	
	STATUS(gameboard);            //printf로 상황을 출력한다. 
	Stone(gameboard);                 //돌 상황 ox로 시각화. 
	
	while(isGameEnd(gameboard) == 0){             //isGameEnd 함수 return0;=>판 다 안참 , return1;=>판 다참. 
	white:
		find_space_W(gameboard);   //흰색 차례일때,흰돌을 둘 수 있는 곳을 찾아준다.(3으로 표시) 내부에 reverse함수 들어있음. 
		stone(gameboard);               //흑돌.백돌 상황 ox로 시각화		
		
		if (is_that_finish(gameboard) == 1){    //가능한 자리(3자리)가  없으면 1 반환, 있으면 0반환
			
				again++;                           

				if (again >= 2){                  //연속으로 둘 곳이 2번 없으면 서로 더 이상 둘수 없으니 게임이 종료된다. 
					Finish(gameboard);
					printf("서로 둘곳이 없습니다.게임 끝!");
				}

				else{
					printf("둘곳이 없습니다.\n");         //turn교체
					Eliminate_Three(gameboard);           //가능했던 자리(3)를 다시 초기화 시켜줘야 다음 턴때 영향을 안미친다. 
					goto black;                           //black turn 으로 이동. 
				}
		}			//->더 둘 곳이 있으면 if문 건너 뛰고 아래로 와야지.
		
		printf("put a new white othello : ");      //put a new white othello 출력하는 함수 
		scanf("%d %d",&stone_x,&stone_y);      //백색돌을 놓을 행.열 좌표를 받는다. 
		scanfReTwo = scanf("%d %d",&stone_x,&stone_y);       
		
		while(1){                             //scanf가 값 2개를 받으면 무한루프 돌게함 
			if(scanfReTwo == 2){
			
			   if ((gameboard[stone_x][stone_y] == 1) || (gameboard[stone_x][stone_y] == 2)){   //이미 흑돌.백돌이 있는 곳 
					
					printf("invalid input! (already occupied)");
					goto below;           //back은 뒤에 나온다..!!!!!!!!!!!(가능한 자리들 3으로 표시해주는 함수) 
				}             
					
				put_White_stone(stone_x, stone_y, gameboard);  //가능한 자리 중에서 내가 원하는 자리 지정하고 백색돌 놓기 
				gameboard_cpy( v_gameboard_cpy, gameboard);   //원본을 복사본에  넣어주기	
			
				//Reverse_BtoW(gameboard, stone_x, stone_y);  //!!!!!!how to code?????

				if (gameboard_compare(gameboard, v_gameboard_cpy) == 1){     //복사본과 원본 변화가 없으면 
					gameboard[stone_x][stone_y] = 0;                     //두었던 곳을 다시 0으로 만들어줘야지
					printf("invalid input (no flip happens)");
					goto below;        
				}
				else if (gameboard_compare(gameboard, v_gameboard_cpy) == 0) //복사본 원본의 변화가 있으면 (뭔가가 뒤집 혔으면)
						;                                                  //아무 것도하지마 뒤집힌 채로 있기 
				Eliminate_Three(gameboard);                           //돌을 둘 수 있는지 판단하는 3을 없애 (1턴 끝났으니까)
				 
				STATUS(gameboard);                          //백.흑돌 몇개 씩인지 보여주기 
				
				 	//!!!flip result보여줄 수 있는 문자열 출력해야해!!!!!// 
				
				gameboard_cpy(v_gameboard_cpy, gameboard); //흑돌 turn준비  
				find_space_B(gameboard); //흑돌  차례일때,흑돌 둘 수 있는 곳 찾아준다.(3으로 표시) 내부에 reverse함수 들어있음.
				Stone(gameboard);             //변화들 ox로 시각화해주기 	
				
				if (isGameEnd(gameboard) == 1)   //isGameEnd함수가 1을 반환하면 게임은 이제 더이상 진행X. 
					Finish(gameboard);
					 
				break; 
			}
			else{
			below:
				find_space_W(gameboard);    //가능한 자리들 3으로 표시 해주기 
				Stone(gameboard); //가능한 자리 시각화해주기 근데 가능한 자리 시각화 까지는 필요 없어 
			}                    //else 끝나는 점  
		}   //whiel(1)끝나는 점 
		Eliminate_Three(gameboard);
		find_space_B(gameboard);        // 흑돌 가능한 자리 찾아주고 3으로 표시하기 
		
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////
		////////////////////////////////이후로는 흑돌 턴일 때의 MAIN함수///////////////////////////////////////////// 
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
	black:
		
		find_space_B(gameboard);       // 흑돌 가능한 자리 찾아주고 3으로 표시하기
		Stone(gameboard); ///////둘 수 있는 곳 찾아서  0,1,2,3 시각화 하고
		
		if (is_that_finish(gameboard) == 1){     //더둘 곳이 없으면 1 반환, 있으면 0반환   
				again++;

				if (again>= 2){
					Finish(gameboard);
					printf("서로 둘곳이 없어 게임을 끝냅니다.");
				}
				else{
					printf("둘곳이 없습니다.\n");         //turn교체
					Eliminate_Three(gameboard);           //가능했던 자리(3)를 다시 초기화 시켜줘야 다음 턴때 영향을 안미친다. 
					goto white;                           //white turn 으로 이동. 
				}
			}			//->더 둘 곳이 있으면 if문 건너 뛰고 아래로 와야지!!!

			printf("put a new black othello : ");      //put a new white othello 출력하는 함수 
			scanf("%d %d",&stone_x,&stone_y);      //백색돌을 놓을 행.열 좌표를 받는다. 
			scanfReTwo = scanf("%d %d",&stone_x,&stone_y);    
			
		while(1){                             //scanf가 값 2개를 받으면 무한루프 돌게함 
			if(scanfReTwo == 2){
			
			   if ((gameboard[stone_x][stone_y] == 1) || (gameboard[stone_x][stone_y] == 2)){   //이미 흑돌.백돌이 있는 곳 
					
					printf("invalid input! (already occupied)");
					goto below2;           //back은 뒤에 나온다..!!!!!!!!!!!(가능한 자리들 3으로 표시해주는 함수) 
				}             
					
				put_Black_stone(stone_x, stone_y, gameboard);  //가능한 자리 중에서 내가 원하는 자리 지정하고 백색돌 놓기 
				gameboard_cpy(v_gameboard_cpy, gameboard);   //원본을 복사본에  넣어주기	
			
				//Reverse_WtoB(gameboard, stone_x, stone_y);  //!!!!!!how to code?????

				if (gameboard_compare(gameboard, v_gameboard_cpy) == 1){     //복사본과 원본 변화가 없으면 
					gameboard[stone_x][stone_y] = 0;                     //두었던 곳을 다시 0으로 만들어줘야지
					printf("invalid input (no flip happens)");
					goto below2;        
				}
				else if (gameboard_compare(gameboard, v_gameboard_cpy) == 0) //복사본 원본의 변화가 있으면 (뭔가가 뒤집 혔으면)
						;                                                  //아무 것도하지마 뒤집힌 채로 있기 
				Eliminate_Three(gameboard);                           //돌을 둘 수 있는지 판단하는 3을 없애 (1턴 끝났으니까)
				 
				STATUS(gameboard);                          //백.흑돌 몇개 씩인지 보여주기 
				
				 	//!!!flip result보여줄 수 있는 문자열 출력해야해!!!!!// 
				
				gameboard_cpy(v_gameboard_cpy, gameboard); //흑돌 turn준비  
				find_space_B(gameboard); //흑돌  차례일때,흑돌 둘 수 있는 곳 찾아준다.(3으로 표시) 내부에 reverse함수 들어있음.
				Stone(gameboard);             //변화들 ox로 시각화해주기 	
				
				if (isGameEnd(gameboard) == 1)   //isGameEnd함수가 1을 반환하면 게임은 이제 더이상 진행X. 
					Finish(gameboard);
					  
				break; while(1){                             //scanf가 값 2개를 받으면 무한루프 돌게함 
			if(scanfReTwo == 2){
			
			   if ((gameboard[stone_x][stone_y] == 1) || (gameboard[stone_x][stone_y] == 2)){   //이미 흑돌.백돌이 있는 곳 
					
					printf("invalid input! (already occupied)");
					goto below2;           //back은 뒤에 나온다..!!!!!!!!!!!(가능한 자리들 3으로 표시해주는 함수) 
				}             
					
				put_Black_stone(stone_x, stone_y, gameboard);  //가능한 자리 중에서 내가 원하는 자리 지정하고 흑돌 놓기 
				gameboard_cpy(v_gameboard_cpy, gameboard);   //원본을 복사본에  넣어주기	
			
				//Reverse_BtoW(gameboard, stone_x, stone_y);  //!!!!!!how to code?????

				if (gameboard_compare(gameboard, v_gameboard_cpy) == 1){     //복사본과 원본 변화가 없으면 
					gameboard[stone_x][stone_y] = 0;                     //두었던 곳을 다시 0으로 만들어줘야지
					printf("invalid input (no flip happens)");
					goto below2;        
				}
				else if (gameboard_compare(gameboard, v_gameboard_cpy) == 0) //복사본 원본의 변화가 있으면 (뭔가가 뒤집 혔으면)
						;                                                  //아무 것도하지마 뒤집힌 채로 있기 
				Eliminate_Three(gameboard);                           //돌을 둘 수 있는지 판단하는 3을 없애 (1턴 끝났으니까)
				 
				STATUS(gameboard);                          //백.흑돌 몇개 씩인지 보여주기 
				
				 	//!!!flip result보여줄 수 있는 문자열 출력해야해!!!!!// 
				
				gameboard_cpy(v_gameboard_cpy, gameboard); //흑돌 turn준비  
				find_space_B(gameboard); //흑돌  차례일때,흑돌 둘 수 있는 곳 찾아준다.(3으로 표시) 내부에 reverse함수 들어있음.
				Stone(gameboard);             //변화들 ox로 시각화해주기 	
				
				if (isGameEnd(gameboard) == 1)   //isGameEnd함수가 1을 반환하면 게임은 이제 더이상 진행X. 
					Finish(gameboard);
					
				break;   //While(1)문 탈출  
			}
			else{
			below2:
				find_space_B(gameboard);    //가능한 자리들 3으로 표시 해주기 
				Stone(gameboard); //가능한 자리 시각화해주기 근데 가능한 자리 시각화 까지는 필요 없어 
			}                    //else 끝나는 점  
		}   //whiel(1)끝나는 점 
		Eliminate_Three(gameboard);
		find_space_W(gameboard);        // 백돌 가능한 자리 찾아주고 3으로 표시하기	   	
	
			}//while문 끝  
	
		}  
	}
}//전체함수 끝  

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////사용된 함수들////////////////////////////////////////////////////////// 
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
void STATUS(int stone_x,int stone_y, int gameboard[6][6]){  //흑돌 백돌 개수 나타내는 함수 
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
	printf("WHITE : %d개, BLACK : %d개 ", White, Black);
}

int Stone(int gameboard[6][6]){          //스톤들 ox로 시각화하기  
	
	int i, j;
	for (i = 0; i < 6; i++){
		
		for (j = 0; j < 6; j++){
			if (gameboard[i][j] == 0)  //돌이 없으면 공백으로  
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
			
			if (gameboard[x][y] == 3)
				possible_space++;
		}
	}
	if (possible_space == 0)  //가능한 자리가 없으면 1반환 => 
		return 1;
	else                      //가능한 자리가 있으면 0반환 => 
		return 0;
}

		
int put_White_stone(int stone_x, int stone_y, int gameboard[6][6]){   //가능한 자리 중에서 백돌이 가능한 자리에 백돌을 두세요!!

	if (gameboard[stone_x][stone_y] == 3){            //3이 적혀있으면  
		gameboard[stone_x][stone_y] = 1;              //흰색돌을 두세요  
	}
	else if ((gameboard[stone_x][stone_y] == 1) || (gameboard[stone_x][stone_y] == 2)) //1,2가 적혀있으면(흑.백돌이 이미 있으면) 
		return gameboard[6][6];                                                        //아무것도 하지말고 나오세요. 
		
	return gameboard[6][6];
	}



void gameboard_cpy(int v_gameboard_cpy[6][6], int gameboard[6][6]){    //배열들을 복사본에 넣으세요~~
	int x = 0; int y = 0;

	for (x = 0; x <6; x++){
		
		for (y = 0; y <6; y++){
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
	
	printf("WHITE: %d개,Black : %d개 ", White, Black);
	
	if (White > Black)
		printf("백돌 승");
	else if (White == Black)
		printf("무승부");
	else if (White < Black)
	
		printf("흑돌 승");
		
	return;
}

//black turn 일 떄 추가로 필요한 함수들

int find_space_B(int gameboard[6][6]){       //흰색 차례일때 사용되며 흰돌을 둘 수 있는 곳을 찾아준다.
	int x = 0; int y = 0;
	int v_gameboard_cpy[6][6] = { 0 };             

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


				v_gameboard_cpy[x][y] = 2; //black turn이 놓은 백돌  자리를 복사본에도 지정해줘 

				//Reverse_WtoB(m_arr_cpy, x, y);   //흑돌로 뒤집힌다  (아직 함수 작성을 못했다ㅠ) 

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

int put_Black_stone(int stone_x, int stone_y, int gameboard[6][6]){   //흑돌이 가능한 자리 중에서  흑 을 두세요!!

	if (gameboard[stone_x][stone_y] == 3){            //3이 적혀있으면  
		gameboard[stone_x][stone_y] = 2;              //흑색 돌을 두세요  
	}
	else if ((gameboard[stone_x][stone_y] == 1) || (gameboard[stone_x][stone_y] == 2)) //1,2가 적혀있으면(흑.백돌이 이미 있으면) 
		return gameboard[6][6];                                                        //아무것도 하지말고 나오세요. 
		
	return gameboard[6][6];
	}
 
	
	 
