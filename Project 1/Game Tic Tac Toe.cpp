#include<stdio.h>
#include<conio.h>
#include<windows.h>
bool IsWin=false;
bool IsSwitch=false;
bool IsClick[25];
char pos[5][5];
//input the keyboard
char IsPressed(){
	if(kbhit()) return getch();
	return -1;
}
//initialization of the game
void initialize(){
	int l=0;
	for(int i=0; i<5; ++i){
		for(int j=0; j<5; ++j){
			pos[i][j]=' ';
			//initialize for IsClick
			IsClick[l]=true;
			++l;
		}
	}
}

//set X or O to position[_i][_j]
void InizGameOX(int _i, int _j, int index){
	if(IsClick[index]==true){
		// for switching
	if(IsSwitch==false){
		pos[_i][_j]='X';
		IsSwitch=true;	
	}
	else{
		pos[_i][_j]='O';
		IsSwitch=false;	
		
	}	
	}
	
}

//SelectPosition
void SelectPosition(){
	char input;
	int _i=-1, _j=-1;
	input= IsPressed();
	
	if(input=='1'  || input=='2'  || input=='3'  || input=='4'  || input=='5'  ||
	   input=='6'  || input=='7'  || input=='8'  || input=='9'  || input=='a' || 
	   input=='b' || input=='c' || input=='d' || input=='e' || input=='f' ||
	   input=='g' || input=='h' || input=='i' || input=='j' || input=='k' ||
	   input=='l' || input=='m' || input=='n' || input=='o' || input=='p' ){
	   	switch (input){
	   		case '1':_i=0; _j=0;  InizGameOX( _i, _j, 0); IsClick[0]=false; break;
	   		case '2':_i=0; _j=1;  InizGameOX( _i, _j, 1);  IsClick[1]=false; break;
			case '3': _i=0; _j=2; InizGameOX( _i, _j, 2); IsClick[2]=false; break;
			case '4': _i=0; _j=3; InizGameOX( _i, _j, 3); IsClick[3]=false; break;
			case '5': _i=0; _j=4; InizGameOX( _i, _j, 4); IsClick[4]=false; break;
			case '6': _i=1; _j=0; InizGameOX( _i, _j, 5); IsClick[5]=false; break;
			case '7': _i=1; _j=1; InizGameOX( _i, _j, 6); IsClick[6]=false; break;
			case '8': _i=1; _j=2; InizGameOX( _i, _j, 7); IsClick[7]=false; break;
			case '9': _i=1; _j=3; InizGameOX( _i, _j, 8); IsClick[8]=false; break;
			case 'a': _i=1; _j=4; InizGameOX( _i, _j, 9); IsClick[9]=false; break;
			case 'b': _i=2; _j=0; InizGameOX( _i, _j, 10); IsClick[10]=false; break;
			case 'c': _i=2; _j=1; InizGameOX( _i, _j, 11); IsClick[11]=false; break;
			case 'd': _i=2; _j=2; InizGameOX( _i, _j, 12); IsClick[12]=false; break;
			case 'e': _i=2; _j=3; InizGameOX( _i, _j, 13); IsClick[13]=false; break;
			case 'f': _i=2; _j=4; InizGameOX( _i, _j, 14); IsClick[14]=false; break;
			case 'g': _i=3; _j=0; InizGameOX( _i, _j, 15); IsClick[15]=false; break;
			case 'h': _i=3; _j=1; InizGameOX( _i, _j, 16); IsClick[16]=false; break;
			case 'i': _i=3; _j=2; InizGameOX( _i, _j, 17); IsClick[17]=false; break;
			case 'j': _i=3; _j=3; InizGameOX( _i, _j, 18); IsClick[18]=false; break;
			case 'k': _i=3; _j=4; InizGameOX( _i, _j, 19); IsClick[19]=false; break;
			case 'l': _i=4; _j=0; InizGameOX( _i, _j, 20); IsClick[20]=false; break;
			case 'm': _i=4; _j=1; InizGameOX( _i, _j, 21); IsClick[21]=false; break;
			case 'n': _i=4; _j=2; InizGameOX( _i, _j, 22); IsClick[22]=false; break;
			case 'o': _i=4; _j=3; InizGameOX( _i, _j, 23); IsClick[23]=false; break;
			case 'p': _i=4; _j=4; InizGameOX( _i, _j, 24); IsClick[24]=false; break;
		   }
	   }		
}

//sceenResetPosition
void sceenResetPosition(){
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X=0;
	Position.Y=0;
	SetConsoleCursorPosition(hOut, Position);
}
//Check who is the winner ? X , O
void CheckIsWin(){
	char winner;
	//Check on x
	if(pos[0][0]=='X' && pos[0][1]=='X' && pos[0][2]=='X' && pos[0][3]=='X' && pos[0][4]=='X'){
		IsWin=true; winner = 'X';
	}else if(pos[1][0]=='X' && pos[1][1]=='X' && pos[1][2]=='X' && pos[1][3]=='X' && pos[1][4]=='X'){
		IsWin=true;winner = 'X';
	}else if(pos[2][0]=='X' && pos[2][1]=='X' && pos[2][2]=='X' && pos[2][3]=='X' && pos[2][4]=='X'){
		IsWin=true;winner = 'X';
	}else if(pos[3][0]=='X' && pos[3][1]=='X' && pos[3][2]=='X' && pos[3][3]=='X' && pos[3][4]=='X'){
		IsWin=true;winner = 'X';
	}else if(pos[4][0]=='X' && pos[4][1]=='X' && pos[4][2]=='X' && pos[4][3]=='X' && pos[4][4]=='X'){
		IsWin=true;winner = 'X';
	}else if(pos[0][0]=='X' && pos[1][0]=='X' && pos[2][0]=='X' && pos[3][0]=='X' && pos[4][0]=='X'){
		IsWin=true;winner = 'X';
	}else if(pos[0][1]=='X' && pos[1][1]=='X' && pos[2][1]=='X' && pos[3][1]=='X' && pos[4][1]=='X'){
		IsWin=true;winner = 'X';
	}else if(pos[0][2]=='X' && pos[1][2]=='X' && pos[2][2]=='X' && pos[3][2]=='X' && pos[4][2]=='X'){
		IsWin=true;winner = 'X';
	}else if(pos[0][3]=='X' && pos[1][3]=='X' && pos[2][3]=='X' && pos[3][3]=='X' && pos[4][3]=='X'){
		IsWin=true;winner = 'X';
	}else if(pos[0][4]=='X' && pos[1][4]=='X' && pos[2][4]=='X' && pos[3][4]=='X' && pos[4][4]=='X'){
		IsWin=true;winner = 'X';
	}else if(pos[0][4]=='X' && pos[1][3]=='X' && pos[2][2]=='X' && pos[3][1]=='X' && pos[4][0]=='X'){
		IsWin=true;winner = 'X';
	}else if(pos[0][0]=='X' && pos[1][1]=='X' && pos[2][2]=='X' && pos[3][3]=='X' && pos[4][4]=='X'){
		IsWin=true;winner = 'X';
	}
	
	//Check on O
	if(IsWin==false){
		if(pos[0][0]=='O' && pos[0][1]=='O' && pos[0][2]=='O' && pos[0][3]=='O' && pos[0][4]=='O'){
		IsWin=true;winner = 'O';
	}else if(pos[1][0]=='O' && pos[1][1]=='O' && pos[1][2]=='O' && pos[1][3]=='O' && pos[1][4]=='O'){
		IsWin=true;winner = 'O';
	}else if(pos[2][0]=='O' && pos[2][1]=='O' && pos[2][2]=='O' && pos[2][3]=='O' && pos[2][4]=='O'){
		IsWin=true;winner = 'O';
	}else if(pos[3][0]=='O' && pos[3][1]=='O' && pos[3][2]=='O' && pos[3][3]=='O' && pos[3][4]=='O'){
		IsWin=true;winner = 'O';
	}else if(pos[4][0]=='O' && pos[4][1]=='O' && pos[4][2]=='O' && pos[4][3]=='O' && pos[4][4]=='O'){
		IsWin=true;winner = 'O';
	}else if(pos[0][0]=='O' && pos[1][0]=='O' && pos[2][0]=='O' && pos[3][0]=='O' && pos[4][0]=='O'){
		IsWin=true;winner = 'O';
	}else if(pos[0][1]=='O' && pos[1][1]=='O' && pos[2][1]=='O' && pos[3][1]=='O' && pos[4][1]=='O'){
		IsWin=true;winner = 'O';
	}else if(pos[0][2]=='O' && pos[1][2]=='O' && pos[2][2]=='O' && pos[3][2]=='O' && pos[4][2]=='O'){
		IsWin=true;winner = 'O';
	}else if(pos[0][3]=='O' && pos[1][3]=='O' && pos[2][3]=='O' && pos[3][3]=='O' && pos[4][3]=='O'){
		IsWin=true;winner = 'O';
	}else if(pos[0][4]=='O' && pos[1][4]=='O' && pos[2][4]=='O' && pos[3][4]=='O' && pos[4][4]=='O'){
		IsWin=true;winner = 'O';
	}else if(pos[0][4]=='O' && pos[1][3]=='O' && pos[2][2]=='O' && pos[3][1]=='O' && pos[4][0]=='O'){
		IsWin=true;winner = 'O';
	}else if(pos[0][0]=='O' && pos[1][1]=='O' && pos[2][2]=='O' && pos[3][3]=='O' && pos[4][4]=='O'){
		IsWin=true;winner = 'O';
	}
	
	}
	//Show message of the winner
	if(IsWin==true)
	printf("\n\n\t\tThe Winner Is : %c\n",winner);
	
	// check isDraw
	bool IsDraw=false;
	if(IsClick[0]==false && IsClick[1]==false && IsClick[2]==false && IsClick[3]==false && IsClick[4]==false &&
	IsClick[5]==false && IsClick[6]==false && IsClick[7]==false && IsClick[8]==false && IsClick[9]==false &&
	IsClick[10]==false && IsClick[11]==false && IsClick[12]==false && IsClick[13]==false && IsClick[14]==false &&
	IsClick[15]==false && IsClick[16]==false && IsClick[17]==false && IsClick[18]==false && IsClick[19]==false &&
	IsClick[20]==false && IsClick[21]==false && IsClick[22]==false && IsClick[23]==false && IsClick[24]==false){
		printf("\n\n\t\tGame Draw !!!\n");
		IsWin=true;
	}
}

void GameMenu(){
	printf("\t\t=========================================\n");
	printf("\t\t|| Player 1: %c    | Player 2: %c        ||\n");
	printf("\t\t=========================================\n\n");
	printf("\t\t=============> Tic Tac Toe <=============\n");
	printf("\t\t\t\n\n");
	
	printf("\t\t\t  %c   %c  %c  %c   %c %c  %c  %c  %c   \n",pos[0][0],186,pos[0][1],186,pos[0][2],186,pos[0][3],186,pos[0][4]);
	//printf("\t\t\t      %c     %c     %c     %c     \n",186,186,186,186,186);
	printf("\t\t\t      %c     %c     %c     %c     \n",186,186,186,186,186);
	printf("\t\t\t _____%c_____%c_____%c_____%c_____\n",186,186,186,186,186);
	
	printf("\t\t\t  %c   %c  %c  %c   %c %c  %c  %c  %c   \n",pos[1][0],186,pos[1][1],186,pos[1][2],186,pos[1][3],186,pos[1][4]);
	//printf("\t\t\t      %c     %c     %c     %c     \n",186,186,186,186,186);
	printf("\t\t\t      %c     %c     %c     %c     \n",186,186,186,186,186);
	printf("\t\t\t _____%c_____%c_____%c_____%c_____\n",186,186,186,186,186);
	
	printf("\t\t\t  %c   %c  %c  %c   %c %c  %c  %c  %c   \n",pos[2][0],186,pos[2][1],186,pos[2][2],186,pos[2][3],186,pos[2][4]);
	//printf("\t\t\t      %c     %c     %c     %c     \n",186,186,186,186,186);
	printf("\t\t\t      %c     %c     %c     %c     \n",186,186,186,186,186);
	printf("\t\t\t _____%c_____%c_____%c_____%c_____\n",186,186,186,186,186);
	
	printf("\t\t\t  %c   %c  %c  %c   %c %c  %c  %c  %c   \n",pos[3][0],186,pos[3][1],186,pos[3][2],186,pos[3][3],186,pos[3][4]);
	//printf("\t\t\t      %c     %c     %c     %c     \n",186,186,186,186,186);
	printf("\t\t\t      %c     %c     %c     %c     \n",186,186,186,186,186);
	printf("\t\t\t _____%c_____%c_____%c_____%c_____\n",186,186,186,186,186);
	
	printf("\t\t\t  %c   %c  %c  %c   %c %c  %c  %c  %c   \n",pos[4][0],186,pos[4][1],186,pos[4][2],186,pos[4][3],186,pos[4][4]);
	//printf("\t\t\t      %c     %c     %c     %c     \n",186,186,186,186,186);
	printf("\t\t\t      %c     %c     %c     %c     \n",186,186,186,186,186);	
}

int main(){
	system("color 9");
	initialize();
	while(!IsWin){//Iswin==false
			sceenResetPosition();
			SelectPosition();
			GameMenu();
			CheckIsWin();
			
	}
	return 0;
}
