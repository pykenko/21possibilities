#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

/*pacman stuff*/
#define HEIGHT 12
#define WIDTH 20
char map[HEIGHT][WIDTH];
int pacmanh = 1; int pacmanw = 1;
int running = 1;
int score = 0;
int both = 10; int botw = 18;

void rmap(){
	int i;int j;
	for(i=0;i<HEIGHT;i++){
		for(j=0;j<WIDTH;j++){
			if(i == 0 || j == 0 || i == HEIGHT - 1 || j == WIDTH - 1){
				map[i][j] = '#';
			} else if(i == 1 || j == 1 || i == HEIGHT - 2 || j == WIDTH - 1 || j == WIDTH - 2){
				map[i][j] = '.';
			} else {
				int random = rand() % 4;
				if(random == 1){
					map[i][j] = '#';
				} else {
					map[i][j] = '.';
				}
			}
		}
	}
}

void botmove(){
	int try = 0;
	do{
	int x = 0; int y = 0;
	int random = rand() % 4;
	if(random == 1){
		x = 1;
	} else if (random == 2){
		x = -1;
	} else if (random == 3){
		y = 1;
	} else {
		y = -1;
	}
	int newy = both + y;
	int newx = botw + x;
	if(newy >= 0 && newy < HEIGHT && newx >= 0 && newx < WIDTH && map[newy][newx]!='#'){
		both=newy;
		botw=newx;
		break;
	}
	try++;
} while(try < 10);
}

void pacmove(int y,int x){
	int newy = pacmanh + y;
	int newx = pacmanw + x;
	if(map[newy][newx]!='#'){
		pacmanh=newy;
		pacmanw=newx;
		if(map[pacmanh][pacmanw] == '.'){
			score += 10;
			map[pacmanh][pacmanw] = ' ';
		}
	}
}

void pmap(){
	system("cls");
	int i;int j;
	for(i=0;i<HEIGHT;i++){
		for(j=0;j<WIDTH;j++){
			if(i==pacmanh&&j==pacmanw){
				printf("C");
			} else if(i == both&&j == botw){
				printf("$");
			} else { 
				printf("%c", map[i][j]);
			}		
		}
		printf("\n");
	}
	printf("score : %d",score);
}

void gameloop(){
	while(running){
		if(_kbhit()){
		char move = getch();
		switch(move){
			case 'a':
				pacmove(0, -1);break;
			case 'w':
				pacmove(-1, 0);break;
			case 's':
				pacmove(1, 0);break;
			case 'd':
				pacmove(0, 1);break;
		}
	}
	if(both == pacmanh && botw == pacmanw){
		system("cls");
		printf("you lost");
		running = 0;
		break;
	}
	checkwin();
	botmove();
	pmap();
	Sleep(150);
	}
}

void checkwin(){
	int i;int j;
	int continu = 0;
	for(i = 0;i<HEIGHT;i++){
		for(j = 0;j<WIDTH;j++){
			if(map[i][j] == '.'){
				continu += 1;
			} else {
				continu += 0;
			}
		}
	}
	if(continu == 0){
		system("cls");
		printf("you win!");
		running = 0;
	}
}

void logo(){
    printf("  ______     __                        __        __       \n");
    printf(" /      \\  _/  |                      /  |      /  |      \n");
   	printf("/$$$$$$  |/ $$ |    ______    _______ $$ |____  $$ |      \n");
    printf("$$____$$ |$$$$ |   /      \\  /       |$$      \\ $$ |      \n");
    printf(" /    $$/   $$ |  /$$$$$$  |/$$$$$$$/ $$$$$$$  |$$ |      \n");
   	printf("/$$$$$$/    $$ |  $$ |  $$ |$$      \\ $$ |  $$ |$$/       \n");
    printf("$$ |_____  _$$ |_ $$ |__$$ | $$$$$$  |$$ |__$$ | __       \n");
   	printf("$$       |/ $$   |$$    $$/ /     $$/ $$    $$/ /  |      \n");
    printf("$$$$$$$$/ $$$$$$/ $$$$$$$/  $$$$$$$/  $$$$$$$/  $$/       \n");
   	printf("                  $$ |                                     \n");
    printf("                  $$ |                                     \n");
   	printf("                  $$/                                      \n");    
}

void fakeloading(){
	logo();
	printf("[----------] 0%%\n");
	Sleep(300);
	system("cls");
	logo();
    printf("[=---------] 2%%\n");
    Sleep(300);
    system("cls");
	logo();
    printf("[==--------] 4%%\n");
    Sleep(300);
    system("cls");
	logo();
    printf("[===-------] 6%%\n");
    Sleep(300);
    system("cls");
	logo();
    printf("[====------] 8%%\n");
    Sleep(300);
    system("cls");
	logo();
    printf("[=====-----] 10%%\n");
    Sleep(300);
    system("cls");
	logo();
    printf("[======----] 12%%\n");
    Sleep(300);
    system("cls");
	logo();
    printf("[=======---] 14%%\n");
    Sleep(300);
    system("cls");
	logo();
    printf("[========--] 16%%\n");
    Sleep(300);
    system("cls");
	logo();
    printf("[=========+] 100%%\n");
    Sleep(300);
}

void mainmenu(){
    printf(" ______________\n");
    printf("||            ||\n");
    printf("||    made    ||\n");
    printf("||     by     ||\n");
    printf("||    renko   ||\n");
    printf("||____________||\n");
    printf("|______________|\n");
    printf(" \\\\############\\\\\n");
    printf("  \\\\############\\\\\n");
    printf("   \\      ____    \\   \n");
    printf("    \\_____\\___\\____\\\n");
    printf("\nOptions :\n1. Play Black Jack\n2. Quit\n3. Pacman\n4. renko's slot machine\n5. tictactoe\n\n\n10. ???\n> ");
}

void shield(){
	printf("\\_______2_1_______/\n");
    printf("|       | |       |\n");
    printf("|       | |       |\n");
    printf("|       | |       |\n");
    printf("|_______| |_______|\n");
    printf("|_______   _______|\n");
    printf("|       | |       |\n");
    printf("|       | |       |\n");
    printf(" \\      | |      /\n");
    printf("  \\     | |     /\n");
    printf("   \\    | |    /\n");
    printf("    \\   | |   /\n");
    printf("     \\  | |  /\n");
    printf("      \\ | | /\n");
    printf("       \\| |/\n");
    printf("        \\_/\n");
}

void shieldbreak(){
	printf("\\\__\\___2  _1__master/\n");
    printf("|    \  |   |       |\n");
    printf("|    \  |   |       |\n");
    printf("|    \  |   |       |\n");
    printf("|______\_|   |_______|\n");
    printf("|_______\     _______|\n");
    printf("|       |   |       |\n");
    printf("|       \ |   |       |\n");
    printf(" \\      |   |      /\n");
    printf("  \\     \ |   |     /\n");
    printf("   \\   \ |   |    /\n");
    printf("    \\   |\   |   /\n");
    printf("     \\  |\   |  /\n");
    printf("      \\ | |   /\n");
    printf("       \\| |/\n");
    printf("        \\_/\n");
}

void shuffle(){
	system("cls");
	printf("the 21 master is shuffling the deck");
	Sleep(300);
	printf(".");
	Sleep(300);
	printf(".");
	Sleep(300);
	printf(".");
	Sleep(500);
}

int stop = 2;
int user = 0;
int dealer = 0;

void move(){
	int times = 0;
	int quit = 1;
	int card = rand() % 9;
	card += 1;
	do {
		printf("press C for card\nS for stop\n\n\n");
		char turn = getch();
		switch(turn){
			case 'c':
				user += card;
				system("cls");
				printf("you got %d\n\n\n",card);
				printf("your card : %d\n", user);
				printf("dealer    : ???\n\n\n>>> ");
				if(dealer < 16){
					Sleep(500);
					srand(clock());
					card = rand() % 9;
					card += 1;
					dealer += card;
				}
				stop++;
				break;
			case 's':
				quit += 10;
				break;
		} 
	} while(stop < 5&&quit == 1&&user < 21&&dealer < 21);
}

void losegame(){
	system("cls");
		printf("your card : %d\n", user);
		printf("dealer    : ???\n");
		Sleep(700);
		system("cls");
		printf("your card : %d\n", user);
		printf("dealer    : ??\n");
		Sleep(700);
		system("cls");
		printf("your card : %d\n", user);
		printf("dealer    : ?\n");
		Sleep(700);
		system("cls");
		printf("your card : %d\n", user);
		printf("dealer    : - \n");
		printf("you thought");
		Sleep(500);
		printf(".");
		Sleep(500);
		printf(".");
		Sleep(500);
		printf(".");
		Sleep(500);
		printf("\n\n\nYOU THOUGHT YOU COULD WIN YOU LOST AND NOW PREPARE TO LOSE YOUR SHIELD!");
		Sleep(2000);
		system("cls");
		shieldbreak();
		printf("your shield broke and so is your peace you lost harshly...\n\n\n");
		printf("press any key to continue");
		getch();
}

void gamebj(){
	shuffle();
	system("cls");
	int card = rand() % 9;
	card += 1;
	printf("your card : %d\n", user);
	printf("dealer    : ???\n");
	printf("press any key to play\n");
	getch();
	user += card;
	printf("you got %d!", card);
	Sleep(1000);
	shuffle();
	srand(clock());
	card = rand() % 9;
	card += 1;
	dealer += card;
	system("cls");
	srand(time(0));
	card = rand() % 9;
	card += 1;
	user += card;
	printf("you got %d!\n\n\n", card);
	printf("your card : %d\n", user);
	printf("dealer    : ???\n\n\n");
	Sleep(1000);
	srand(clock());
	card = rand() % 9;
	card += 1;
	dealer += card;
	move();
	if(user > 21){
		losegame();
	} else if(dealer > 21){
		printf("the 21 master quit");
	} else if(user > dealer){
		system("cls");
		shield();
		printf("\n by seeing this shield this means that you won the war and brought piece only using cards and shields\n\n\nYOU WON!\n\n\n");
	} else if(dealer > user){
		losegame();
	} else {
		printf("%d %d",dealer,user);
	}
}

int pacmain(){
	rmap();
	pmap();
	gameloop();
	return 0;	
}

int a = 0;
int b = 0;
int c = 0;
char answer;
int win = 0;
int money = 1000;

int gamblemain();

int main(){
	int continu = 1;
	int i;
	srand(time(0));
	logo();
	system("cls");
	fakeloading();
	printf("\npress any key to start\n");
	getch();
	system("cls");
	mainmenu();
	int menu;
	scanf("%d", &menu);
	switch(menu){
		case 1:
			system("cls");
			printf("you are currently fighting the 21 master\nand you are the only one who can win in this 21 world\nyour tools are only cards and shield\nDo your best!\n\n\nPress any key to continue");
			getch();
			gamebj();
			break;
		case 2:
			printf("quitting.");
			Sleep(500);
			printf(".");
			Sleep(500);
			printf(".");
			Sleep(500);
			break;
		case 3:
			pacmain();
			break;
		case 4:
			gamblemain();
			break;
		case 5:
			tictactoemain();
			break;
		case 10:
			system("cls");
			printf("developed by : Renko VA\n");
			printf("Arts 	     : Google\n");
			printf("press any key to test your luck : ");
			char test = getch();
			while(continu){
			switch(test){
				case 'q':
					continu = 0;
					break;
				default:
					i = rand() % 100;
					printf("\nyour luck is %d%% out of 100",i);
					break;
			}
			test = getch();
		}
		default:
			printf("\nyou made the wrong move and the 21 master defeated you while you tripped.");
}
	return 0;
}




void reset(){
	a = 0;
	b = 0;
	c = 0;
}

void board(){
	system("cls");
	printf("_____________________\n");
	printf(" |     |     |     |\n");
	printf(" |  %d  |  %d  |  %d  |\n",a,b,c);
	printf(" |     |     |     |\n");
	printf("=====================\n");
	printf("wallet : %d $\n\n", money);
	if(money < 600){
		printf("you should check your bank\n\n");
	}
}

void result(){
	if(a == 0 && b == 0 && c == 0){
		printf("resetted");
	} else if(a == b && a == c){
		printf("\n\nYOU WON");
		money += 1000000;
		win = 1;
		Sleep(2000);
	}
}

void roll(){
	int random1, random2, random3;
	random1 = (rand() % 3)+1;
	a = random1;
	board();
	Sleep(500);
	random2 = (rand() % 3)+1;
	b = random2;
	Sleep(500);
	board();
	random3 = (rand() % 3)+1;
  	c = random3;
  	Sleep(500);
	board();
	result();
	Sleep(500);
	reset();
}

void start(){
	while(money > 0){
		while(!win){
			if(GetAsyncKeyState('R')){
				money -= 100;
				roll();
			}
			if(GetAsyncKeyState('Q')){
				break;
			}
			board();
			printf("press r to roll");
			Sleep(1000);
		}
		break;
	}
}

int gamblemain(){
	srand(time(0));
	board();
	printf("welcome to my slot machine\n");
	start();
	printf("\n\nyou won 1.000.000$!");
	Sleep(1000);
	return 0;
}

char grid[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};
const player = 'X'; 
const bot = 'O';
int play = 1; 
char winner = ' ';

/* tic-tac-toe map */
void ticmap(){
	system("cls");
	printf("  %c  |  %c  |  %c  \n", grid[0][0], grid[0][1], grid[0][2]);
	printf("----------------- \n");
	printf("  %c  |  %c  |  %c  \n", grid[1][0], grid[1][1], grid[1][2]);
	printf("----------------- \n");
	printf("  %c  |  %c  |  %c \n", grid[2][0], grid[2][1], grid[2][2]);
}

/* player move */
void playerplay(){
	int k, n;
	do{
		printf("pick your column and row (1-3): ");
		scanf("%d %d", &k, &n);
		k--; n--;
		if(k > 2 || n > 2){
			printf("invalid move!\n");
		} else if(grid[k][n] == 'O'){
			printf("invalid move!\n");
		} else {
			grid[k][n] = player;
			break;
		}
	} while(grid[k][n] != ' ');
}

/* bot move */
void botplay(){
	int k, n;
	do{
		k = (rand() % 3);
		n = (rand() % 3);
		if(grid[k][n] != ' '){
		} else {
			grid[k][n] = bot;
			break;
		}
	} while(grid[k][n] != ' ');
}

/* count free spaces */
int cfree(){
	int freeSpace = 9;
	int i, j;
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			if(grid[i][j] != ' '){
				freeSpace = freeSpace - 1;
			}
		}
	}
	return freeSpace;
}

/* game logic */
char who(){
	int i;
	char a = ' ';
	for(i = 0; i < 3; i++){
		if(grid[i][0] != ' ' && grid[i][1] != ' ' && grid[i][2] != ' '){
			if(grid[i][0] == grid[i][1] && grid[i][0] == grid[i][2]){
				a = grid[i][1];
			}
		}
		if(grid[0][i] != ' ' && grid[1][i] != ' ' && grid[2][i] != ' '){
			if(grid[0][i] == grid[1][i] && grid[0][i] == grid[2][i]){
				a = grid[i][1];
			}
		}
	}
	if(grid[0][0] != ' ' && grid[1][1] != ' ' && grid[2][2] != ' '){
		if(grid[0][0] == grid[1][1] && grid[0][0] == grid[2][2]){
			a = grid[0][0];
		}
	}
	if(grid[0][2] != ' ' && grid[1][1] != ' ' && grid[2][0] != ' '){
		if(grid[0][2] == grid[1][1] && grid[0][2] == grid[2][0]){
			a = grid[0][2];
		}
	}
	return a;
}

/* fun delay */
void sokdelay(){
	printf("\nthe bot is thinking .");
	Sleep(500);
	system("cls");
	ticmap();
	printf("\nthe bot is thinking ..");
	Sleep(500);
	system("cls");
	ticmap();
	printf("\nthe bot is thinking ...");
	Sleep(500);
	system("cls");
}

/* main */
int tictactoemain(){
	srand(time(0));
	ticmap();
	Sleep(1000);
	while(winner == ' ' && cfree() != 0){
		cfree(); //checking if there's free space
		playerplay(); //player has the first turn
		ticmap(); //printing out the map
		who(); //checking for winner
		winner = who();
		if(winner != ' '){
			printf("\n\nFREEZE");
			Sleep(1000);
			break;
		}
		if(cfree() == 0){
			printf("\n\nhuh what happened");
			Sleep(1000);
			break;
		}
		cfree();
		sokdelay(); //delay animation
		botplay(); //bot has the second turn
		ticmap();
		who();
		winner = who();
		if(winner != ' '){
			printf("\n\nFREEZE");
			Sleep(1000);
			break;
		}
	}
	
	if(winner == ' ' && cfree() == 0){
		printf("\nOH\nit's a draw");
		return 0;
	}
	
	if(winner != ' '){
		system("cls");
		if(winner == player){
			printf("You actually won, I'm proud of you");
		} else if(winner == bot){
			printf("You actually lost to a random number generator.......");
		}
	}
	return 0;
}






















