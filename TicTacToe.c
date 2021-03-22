//AUTHOR: FLETCHER MOORE
//DESCRIPTION: ADS COURSEWORK - WORKING TIC-TAC-TOE GAME BETWEEN TWO PEOPLE
//START DATE: 16/03/2019
//LAST EDIT: 02/04/2019


//LIBRARIES
#include <stdio.h>


//CONSTANTS
#define PLAYERONE 0
#define PLAYERTWO 1



//PROTOTYPES DECLARED
void Board(char placeNums[]);
int PossibleWinner(char placeNums[]);
void PlayerTurn(int playerPiece, char gameBoard[]);




//MAIN METHOD
int main(void)
{
	int player = 0;
	int turn = 0;
	char confirmationPW, confirmationSM;
	
	//1D ARRAY FOR THE NUMBERS FOR THE BOARD
	char boardPlaces [9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
	
	//WHILE LOOP TO RUN THE METHODS
	while (PossibleWinner(boardPlaces)==0)
	{
		//RUNS METHODS
		Board(boardPlaces);
		PlayerTurn(player, boardPlaces);
		PossibleWinner(boardPlaces);
		
		

		//END OF TURN
		player++;		//INCREASE PLAYER NUM
		turn++;			//INCREASE TURN NUM
		
		if (PossibleWinner(boardPlaces) == 1)
		{
			//DISPLAY WINNING BOARD
			Board(boardPlaces);
			
			//PRINT WINNER AND ASK FOR NEW GAME
			printf("Player %d won. Would you like to reset the game(y/n)?\n", player);
			//STORE USER ANSWER
			scanf(" %c", &confirmationPW);
			
			//VALIDATE USER INPUT
			//RESTART (Y) OR EXIT (N)
			if(confirmationPW == 'y')
			{
				main();
			}
			else if (confirmationPW == 'n')
			{
				break;
			}
			else
			{
				printf("To start again insert (y) or finish insert (n)\n");
				return;
			}
		}
		
		//RESETS PLAYER NUMBER
		if (player == 2)
		{
			player = 0;
		}
		
		//DETERMINE IF STALE MATE
		if ((turn == 9) && (PossibleWinner(boardPlaces) == 0))
		{
			//DISPLAY END GAME BOARD
			Board(boardPlaces);
			
			//PRINT MESSAGE PROMPTING USER INPUT
			printf("Stale mate: It's a draw. Would you like to reset the game(y/n)?\n");
			//SCAN ANSWER AND STORE 
			scanf(" %c", &confirmationSM);
			
			//VALIDATE THE USER INPUT
			//RESTART (Y) OR EXIT (N)
			if(confirmationSM == 'y')
			{
				main();
			}
			else if(confirmationSM == 'n')
			{
				printf("Game finished!\n");
				break;
			}				
			else
			{
				printf("To start again insert (y) or finish insert (n)\n");
				return;
			}
			
		}

	}
}





//DISPLAY THE BOARD FOR THE GAME
void Board(char placeNums[])
{
	//PRINT BOARD LAYOUT AND TEMP PLACEMENTS 
	//FOR THE FINAL BOARD PIECES TO BE PLACED INSIDE
	printf("\n\n %c | %c | %c\n", placeNums[0], placeNums[1], placeNums[2]);
	printf("---|---|---\n");
	printf(" %c | %c | %c\n", placeNums[3], placeNums[4], placeNums[5]);
	printf("---|---|---\n");
	printf(" %c | %c | %c\n", placeNums[6], placeNums[7], placeNums[8]);
}






//CHECK TO SEE IF ANYONE HAS WON THE GAME 
int PossibleWinner(char placeNums[])
{
	
	//VARIABLES
	int playerWins;
	
	
	//HORIZONTAL - TOP LINE
	if ((placeNums[0] == placeNums[1]) && (placeNums[1] == placeNums[2]))
	{
		playerWins = 1;
	}
	//HORIZONTAL - MIDDLE LINE
	else if ((placeNums[3] == placeNums[4]) && (placeNums[4] == placeNums[5]))
	{
		playerWins = 1;
	}
	//HORIZONTAL - BOTTOM LINE
	else if ((placeNums[6] == placeNums[7]) && (placeNums[7] == placeNums[8]))
	{
		playerWins = 1;
	}
	//VERTICAL - LEFT LINE
	else if ((placeNums[0] == placeNums[3]) && (placeNums[3] == placeNums[6]))
	{
		playerWins = 1;
	}
	//VERTICAL - MIDDLE LINE
	else if ((placeNums[1] == placeNums[4]) && (placeNums[4] == placeNums[7]))
	{
		playerWins = 1;
	}
	//VERTICAL - RIGHT LINE 
	else if ((placeNums[2] == placeNums[5]) && (placeNums[5] == placeNums[8]))
	{
		playerWins = 1;
	}
	//DIAGONAL - TOP LEFT TO BOTTOM RIGHT
	else if ((placeNums[0] == placeNums[4]) && (placeNums[4] == placeNums[8]))
	{
		playerWins = 1;
	}
	//DIAGONAL - TOP RIGHT TO BOTTOM LEFT
	else if ((placeNums[2] == placeNums[4]) && (placeNums[4] == placeNums[6]))
	{
		playerWins = 1;
	}
	//GAME INCOMPLETE
	else 
	{
		playerWins = 0;
	}
	
	//RETURN 1 OR 0
	return playerWins;
	
}




//DETERMINES PLAYERS TURN AND WHAT PIECE THEY HAVE
void PlayerTurn(int playerPiece, char gameBoard[])
{
	//VARIABLES
	char piece;
	int placement;
	
	
	//DETERMINE PIECE - EITHER NOUGHT OR CROSS
	//PLAYERONE PIECE IS NOUGHTS (O) 
	if (playerPiece == PLAYERONE)
	{
		piece = 'O';
	}
	//PLAYERTWO PIECE IS CROSSES (X)
	else if (playerPiece == PLAYERTWO)
	{
		piece = 'X';
	}
	
	
	//PROMPT PLAYER TO INTPUT NUMBER FOR O/X ON BOARD
	printf("\nIt's player %d turn. Please choose where you would like to place your piece. Select a number on the board: ", playerPiece + 1);
	//STORE USER INPUT
	scanf("%d", &placement);
	
	while((placement <1) || (placement > 9))
	{
		//DISPLAY ERROR
		printf("Choice is invalid. Choose again:\n");
		//STORE USER INPUT
		scanf("%d", &placement);
	}
	
	//IF X OR O IS IN PLACE DISPLAY ERROR
	while((gameBoard[placement-1] == 'X') || (gameBoard[placement-1] == 'O'))
	{
		//DISPLAY ERROR 
		printf("Placement is taken. Select another area:\n");
		//STORE USER INPUT
		scanf("%d", &placement);
	}
	
	
		gameBoard[placement-1] = piece;	
	
}





















