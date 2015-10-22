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
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;

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

class game{
private:
	vector<int>board;
public:	
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
		int roll = (rand()%6)+1;
		cout<<"Die:"<<roll<<endl;	
		return roll;
	}

	void updatePos(int& oldpos, int roll){
		cout<<"old Position:"<<oldpos<<endl;		
		if(oldpos+roll<=100){
			oldpos += roll;
			oldpos = board[oldpos];	
		}		
		cout<<"new Position:"<<oldpos<<endl;		
	}
};

int main() {
	int pos1=1,pos2=1,roll;
	int iter = 0;
	game G;
	G.init();
	while(true){
		iter++;

		cout<<"player1 chance,press enter to roll die"<<endl;/*fflush(stdin);getch();*/				
		roll = G.rollDie();
		G.updatePos(pos1,roll);		
		if(pos1==100){
			cout<<"Player 1 won the game"<<endl;
			break;			
		}		


		cout<<"player2 chance,press enter to roll die"<<endl; /*fflush(stdin);getch();*/		
		roll = G.rollDie();
		G.updatePos(pos2,roll);
		if(pos2==100){
			cout<<"Player 2 won the game"<<endl;
			break;
		}
		cout<<"---------------------------------------"<<endl;
	}
	cout<<"TOTAL NUMBER OF ITEARTION TAKEN TO COMPLETE GAME WERE "<<iter<<endl;
	return 0;
}