/*Snake and Ladder Design
An Linear Array can be used to represent the Snake and Ladder Game. Each index will tell us the 
position we have rolled dice for. say board.

and board[i]=i

Representing Snake & Ladder.
Say there is snake from which takes us from 10 to 3 then 

board[10]=3
similarly for Ladders.

Throw of Dice 

The throw of dice can be implemented by a function returning a random number between 1 and 6.

Game of Play.
we get evaluate the player position by checking the position the player has rolled for in the board 
i.e. say i am at 10 and by throw of dice returns 3 so I will check board[13] and the value will be final position.*/

#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;

vector<int>board;

void print(vi &v){
	for(auto it:v)
		cout<<it<<" ";
	cout<<endl;
}

void print(vvi &vv){
	for(auto it:vv){
		for(auto jt:it)
			cout<<jt<<" ";
		cout<<endl;
	}
}

void init(){
	board.resize(101);
	for(int i=1;i<=100;i++)board[i] = i;
	int snakes,ladders,from,to;
	cout<<"Enter #snakes and #snakes pair \n";
	cin>>snakes;
	for(int i=1;i<=snakes;i++){
		cin>>from>>to;
		board[from] = to;
	}
	cout<<"Enter #ladders and #ladders pair \n";
	cin>>ladders;
	for(int i=1;i<=ladders;i++){
		cin>>from>>to;
		board[from] = to;
	}
	return;
}

int rollDie(){
	srand (time(NULL));
	return (rand()%6)+1;
}




int main() {
	int pos1=1,pos2=1,roll;
	int iter = 0;
	init();
	while(true){
		iter++;
		cout<<"player1 chance,press enter to roll die"<<endl;
		/*fflush(stdin);
		getch();*/
		roll = rollDie();
		cout<<"Die:"<<roll<<endl;

		cout<<"old Position:"<<pos1<<endl;		
		if(pos1+roll<=100){
			pos1 += roll;
			pos1 = board[pos1];	
		}		
		cout<<"Position:"<<pos1<<endl;
		if(pos1==100){
			cout<<"Player 1 won the game"<<endl;
			break;			
		}		


		cout<<"player2 chance,press enter to roll die"<<endl;
		/*fflush(stdin);
		getch();*/
		roll = rollDie();
		cout<<"Die:"<<roll<<endl;
		cout<<"old Position:"<<pos2<<endl;		
		if(pos2+roll<=100){
			pos2 += roll;
			pos2 = board[pos2];
		}		
		cout<<"Position:"<<pos2<<endl;
		if(pos1==100){
			cout<<"Player 2 won the game"<<endl;
			break;
		}
		cout<<"---------------------------------------"<<endl;
	}
	cout<<"TOTAL NUMBER OF ITEARTION TAKEN TO COMPLETE GAME WERE "<<iter<<endl;
	return 0;
}