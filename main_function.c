#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//보드판 초기화 상태  
void main(int argc, char *argv[]) {
	int gameboard[6][6]={0};   
	int Done = 0;
	int stone_row, stone_col ;   
	
	board();                         //초기화 된 게임판 생성
	  
	gameboard[2][2] = 1; 	gameboard[3][3] = 1;
	gameboard[2][3] = 2; 	gameboard[3][2] = 2;
	
	STATUS(x,y,gameboard);           //printf로 상황을 출력한다. 
	stone(gameboard);                 //돌 상황 ox로 시각화. 
	
	while(1){
	white:
		stone(gameboard);               //흑돌.백돌 상황 ox로 시각화
		if (is_that_finish(gameboard) == 1){    //is_that_finish가 더둘 곳이 없으면 1 반환, 있으면 0반환
			
				Done++;                           

				if (Done >= 2){                  //연속으로 둘 곳이 2번 없으면 게임이 종료된다. 
					Finish(gameboard);
					printf("서로 둘곳이 없어 게임이 끝났습니다.");
				}

				else{
					pass_turn(); //turn교체
					Eliminate_Three(arr);
					goto black;  //black turn 으로 이동. 
				}
		}			//->더 둘 곳이 있으면 if문 건너 뛰고 아래로 와야지!!!
		
		White_turn();       //put a new white othello 출력하는 함수 
		
		while(1){
			   
			scanf("%d %d",&stone_row,&stone_col);  //백색돌을 놓을 행.열 좌표를 받는다. 
			
			if ((gameboard[stone_row][stone_col] == 1) || (arr[stone_row][stone_col] == 2)){ //이미 돌이 있는 곳이 
					
						printf("invalid input! (already occupied)");
						goto back1;           //back은 뒤에 나온다..!!!!!!!!!!!(가능한 자리들 3으로 표시해주는 함수) 
					}             
					
			put_White_stone(stone_row, stone_col, gameboard);  //가능한 자리 중에서 내가 원하는 자리 지정하고 백색돌 놓기 
			gameboard_cpy(v_gameboard_cpy, gameboard);   //원본을 복사본에  넣어주기	
			
			Reverse_BtoW(gameboard, stone_x, stone_y);  //돌 뒤집는 함수를 총 묶음체,,,사실상 제일 중요한 부분..!!!!!!how to code?????

					if (board_compare(gameboard, v_gameboard_cpy) == 1){     //복사본과 원본 변화가 없으면 
						gameboard[stone_x][stone_y] = 0;                     //두었던 곳을 다시 0으로 만들어줘야지
						printf("invalid input (no flip happens)");
						goto back1;        //좀 더 고민 해 볼  
					}
					else if (gameboard_compare(gameboard, v_arr_cpy) == 0) //복사본 원본의 변화가 있으면 (뭔가가 뒤집 혔으면)
						;                                                  //아무 것도하지마 뒤집힌 채로 있기 
				eliminate_3(gameboard);                           //돌을 둘 수 있는지 판단하는 3을 없애 (1턴 끝났으니까) 
				STATUS(x, y, gameboard);                          //백.흑돌 몇개 씩인지 보여주기 
				//flip result보여줄 수 있는 문자열 출력해야해!!!!!// 

		 
				
				Stone(gameboard);             //변화들 ox로 시각화해주기 	
				
				if (gameover(gameboard) == 1)   //gameover함수가 1을 반환하면 게임은 이제 더이상 진행X. 
						return 0;
			

					
					break;  // while문 탈출~~~
				}	 
					
			
					
		} 
		
		
	}
	
}


