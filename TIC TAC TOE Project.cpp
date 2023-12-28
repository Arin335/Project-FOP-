#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

char Board[3][3];

void InitializeBoard() {
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            Board[i][j] = '-';
}
void PrintBoard() {												//Printing the board of Tic Tac Toe
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				cout<<Board[i][j]<< " ";
			}
			cout<<endl;
			}
}
bool isFull() {													//To check when the board is fully initialized 
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            if(Board[i][j] == '-')
                return false;
    return true;
}
bool Win() {
	//For Rows Win
	for(int j=0; j<3; j++){

	if(Board[0][j]== 'X' && Board[1][j]== 'X' && Board[2][j]== 'X')
	return true;
	if(Board[0][j]== 'O' && Board[1][j]== 'O' && Board[2][j]== 'O')
	return true;
}
	//For Coloumn Win
	for(int i=0; i<3; i++){
		
	if(Board[i][0]== 'X' && Board[i][1]== 'X' && Board[i][2]== 'X')
	return true;
	if(Board[i][0]== 'O' && Board[i][1]== 'O' && Board[i][2]== 'O')
	return true;
}
	
	//For Diagonal Win
	int n=0;								//Difference of Rows and Coloums
	int m=2;								//Number of Rows and Coloums (starting from 0-2)
	if(Board[n][n]== 'X' && Board[n+1][n+1]== 'X' && Board[n+2][n+2]== 'X')
	return true;
	if(Board[n][n]== 'O' && Board[n+1][n+1]== 'O' && Board[n+2][n+2]== 'O')
	return true;
	if(Board[n][m]== 'X' && Board[n+1][m-1]== 'X' && Board[n+2][m-2]== 'X')
	return true;
	if(Board[n][m]== 'O' && Board[n+1][m-1]== 'O' && Board[n+2][m-2]== 'O')
	return true;
	
	return false;
}
int main() {
	srand(time (0));
    InitializeBoard();
    while(!isFull()){
        int i = rand() % 3;
        int j = rand() % 3; 
        Win();
        if(Board[i][j] == '-')
			Board[i][j] = rand () % 2 == 0 ? 'X' : 'O';
		if(!(!Win()))
        break;
    }
	PrintBoard();
	Win();
    if(!Win())
    cout<<"The Game has been Drawn!"<<endl;
    if(!(!Win()))
    cout<<"X/O Wins!"<<endl;
    
    return 0;
}