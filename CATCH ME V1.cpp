/**************************************************************************
@Aakarshan gupta   
March, 2020.
MY FIRST PRGRAMMING PROJECT :) 
V 1.0
COMPILER GCC -std=c++11 
// a simple console game where user controlled '@' is chased by 'O'
******************************************************************************/
#include <thread>
#include <chrono>
#include <iostream>
#include <conio.h>
#include <vector>

using namespace std ;
//funtions
void initdisplay() ;
void initfood() ;
void initsnake() ;
void inputkey() ;
void updatefood() ;
void drawdisplay() ;
void updatesnake() ;
void clearscreen() ;
void checkedge() ;
void inputkeyin(char) ;

//globals
char keyin;
int AXISX = 25 ;
int AXISY = 25 ;
vector <vector <char> > grid ;
vector <int> snakeindex ;
vector <char> rowin(25);
int foodx = 0  ,foody = 0 ; 
int headx = 0, heady = 0; 
int game =1 ;
int direction = 1;// 1, 2, 3, 4 right, left, top, down 
int score =0 ;



//main
int main() {
	initdisplay() ;
	initfood() ;
	initsnake() ;
	while(game!=0) {
		if(kbhit()) {
		inputkeyin(getch());
		}
		updatesnake();
		updatefood() ;
		checkedge() ;
		clearscreen() ;
		drawdisplay() ;
		score+=100;
		
		
	}
	clearscreen() ;
	for(int i  =0 ;  i< 25 ; i++ ) {
		cout << "#########################\n" ;
		  if(i== 12) {
			  cout << "   GAME OVER SCORE=" << score << " \n" ;
		  }
	}
		
	this_thread::sleep_for(chrono::seconds(3));
	
	return 0 ; 		
}
//inputkeyin
void inputkeyin(char keyin) {
	switch (keyin) {
		case 'w' : 
			direction = 4 ;
			break;
		case 'a' :
			direction = 2 ;
			break ;
		case 'd' :
			direction = 1 ;
			break ;
		case 's' :
			direction = 3 ;
			break ;
	}
}
// initdisplay
void initdisplay() {
	
	for(int i= 0 ; i < 25; i ++ ) {
	      cout << "#########################\n" ;
		  if(i== 12) {
			  cout << "----CATCH ME GAME 1.0----\n" ;
		  }
	}
	cout << "starting in 3 seconds " ;
	this_thread::sleep_for(chrono::seconds(3));
	
	char cell = ' ' ;
	for(int i = 0 ; i < AXISX ;i ++ ) {
		rowin.push_back(cell);
	}
	for(int i = 0 ; i < AXISX ;i ++ ) {
		grid.push_back(rowin);
	}
	for(int i = 0 ; i < AXISX ;i++ ) {
		for(int j = 0 ; j < AXISY ; j++ ) {
			if(i == 0 || j == 0 || i == AXISX-1  || j == AXISY-1 ) {
				grid.at(i).at(j) = '#' ;
			}
			else {
				grid.at(i).at(j) = ' ' ; 
			}
		}
	}
}
//initfood
void initfood() {
	foodx = 20 ; foody = 20 ;
	grid.at(foodx).at(foody) = 'O' ;
}
//initsnake
void initsnake() {	
    headx = 10 ; heady = 10 ;
	grid.at(headx).at(heady) = '@' ;
}
// updatesnake
void updatesnake() {
	grid.at(headx).at(heady) = ' ' ;
	
	switch(direction) {
		
		case 1 : {
			heady+=2 ;
			break ;
		}
		case 2: {
			heady-=2 ;
			break ;
		}
		case 3: {
			headx+=2 ;
			break ;
		}
		case 4 : {
			headx-=2 ;
			break ;
		}
		
	}
	grid.at(headx).at(heady) = '@' ;
}
		
//checkedge
void checkedge() {
	
if (headx == 25 || heady == 25 || headx == 0 || heady == 0 || headx ==24 || heady == 24) {
		game=0;
}	

if (headx== foodx && heady == foody) {
	game = 0 ; 
}
}


// updatefood
void updatefood() {
	grid.at(foodx).at(foody) = ' ';
	foodx > headx ? foodx-- : foodx++ ;
	foody > heady ? foody-- : foody++ ;
	grid.at(foodx).at(foody) = 'O' ;
	//this_thread::sleep_for(chrono::microseconds(20));
}
// drawdisplay

void drawdisplay() {
	printf("-------CATCH ME!---------\n");
	for(int i = 0 ; i< AXISX ; i++ ) {
		for(int j = 0; j < AXISY; j ++ ) {
			// cout << is slow af ;
			 printf("%c",grid.at(i).at(j)) ;
		}
		printf("\n") ;
	}
	
}
// clearscreen
void clearscreen() {
	system("cls") ;
}

