#include <stdio.h>
#include <stdlib.h>
#define N 6
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//보드판 초기화 상태  
void main(int argc, char *argv[]) {
	int gameboard[6][6]={0};   //다른 함수들이 알 수 있게하려면 나중에 전역변수로 빼야 할 것같은데?? 
	int again = 0;
	int stone_x=0; stone_y=0;
	   
	board(gameboard);                         //초기화 된 게임판 생성
	  
	gameboard[2][2] = 1; 	gameboard[3][3] = 1;
	gameboard[2][3] = 2; 	gameboard[3][2] = 2;
	
	STATUS(x,y,gameboard);           //printf로 상황을 출력한다. 
	stone(gameboard);                 //돌 상황 ox로 시각화. 
	
	while(isGameEnd() == 0){             //isGameEnd 함수 return0;=>판 다 안참 , return1;=>판 다참. 
	white:
		find_space_W(gameboard);   //흰색 차례일때 사용되며 흰돌을 둘 수 있는 곳을 찾아준다.
		stone(gameboard);               //흑돌.백돌 상황 ox로 시각화		
		
		if (is_that_finish(gameboard) == 1){    //is_that_finish가 더둘 곳이 없으면 1 반환, 있으면 0반환
			
				again++;                           

				if (again >= 2){                  //연속으로 둘 곳이 2번 없으면 서로 더 이상 둘수 없으니 게임이 종료된다. 
					check_result(gameboard);
					printf("서로 둘곳이 없습니다.게임 끝!");
				}

				else{
					printf("둘곳이 없습니다.\n");         //turn교체
					Eliminate_Three(gameboard);           //가능했던 자리(3)를 다시 초기화 시켜줘야 다음 턴때 영향을 안미친다. 
					goto black;                           //black turn 으로 이동. 
				}
		}			//->더 둘 곳이 있으면 if문 건너 뛰고 아래로 와야지.
		
		printf("put a new white othello : ")       //put a new white othello 출력하는 함수 
		scanf("%d %d",&stone_x,&stone_y);      //백색돌을 놓을 행.열 좌표를 받는다. 
		
		while(1){                             //무한루프 돌게함 
			   
			 
			if ((gameboard[stone_x][stone_y] == 1) || (arr[stone_x][stone_y] == 2)){   //이미 흑돌.백돌이 있는 곳 
					
						printf("invalid input! (already occupied)");
						goto below;           //back은 뒤에 나온다..!!!!!!!!!!!(가능한 자리들 3으로 표시해주는 함수) 
					}             
					
			put_White_stone(stone_row, stone_col, gameboard);  //가능한 자리 중에서 내가 원하는 자리 지정하고 백색돌 놓기 
			gameboard_cpy(v_gameboard_cpy, gameboard);   //원본을 복사본에  넣어주기	
			
			Reverse_BtoW(gameboard, stone_x, stone_y);  //!!!!!!how to code?????

					if (gameboard_compare(gameboard, v_gameboard_cpy) == 1){     //복사본과 원본 변화가 없으면 
						gameboard[stone_x][stone_y] = 0;                     //두었던 곳을 다시 0으로 만들어줘야지
						printf("invalid input (no flip happens)");
						goto below;        //!!!! 
					}
					else if (gameboard_compare(gameboard, v_arr_cpy) == 0) //복사본 원본의 변화가 있으면 (뭔가가 뒤집 혔으면)
						;                                                  //아무 것도하지마 뒤집힌 채로 있기 
				Eliminate_Three(gameboard);                           //돌을 둘 수 있는지 판단하는 3을 없애 (1턴 끝났으니까)
				 
				STATUS(x, y, gameboard);                          //백.흑돌 몇개 씩인지 보여주기 
				
				//!!!flip result보여줄 수 있는 문자열 출력해야해!!!!!// 
				
				arr_cpy(m_arr_cpy, arr); //??????????????????뭘 의미할까 
				Can_I_Put_There_W_to_B(arr); //흑돌 함수임 !!둘 수 있는 곳 바뀐 변화 적용해주기 
				Stone(gameboard);             //변화들 ox로 시각화해주기 	
				
				if (check_result(gameboard) == 1)   //gameover함수가 1을 반환하면 게임은 이제 더이상 진행X. 
						Finish();
						return 0;
			else{
			below:
					Can_I_Put_There_B_to_W(arr); //가능한 자리들 3으로 표시 해주기 
					Stone(gameboard); //가능한 자리 시각화해주기 근데 가능한 자리 시각화 까지는 필요 없어 
					 
				}
		}
		Eliminate_Three(gameboard);
		find_space_W(gameboard);
			

					
					break;  // while문 탈출~~~
				}	 
					
			
					
		} 
		
		
	}
	
}


