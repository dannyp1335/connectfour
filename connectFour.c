#include <stdio.h>

int row = 6;
int col = 7;
char player;
char aI;

/* makeBoard() is called at the start of the main method in order to fill the gameboard with '.' (meaning an empty slot) */
void makeBoard(char conBoard[6][7])
{
  for (int i = 0; i < row; i++)
  {
      for (int z = 0; z < col; z++)
      {
	conBoard[i][z] = '.';
      }
  }
  return;
}

/* printBoard() is called everytime the board is updated so that the user has a visual representation */
void printBoard(char conBoard[6][7])
{
  printf("\n");
  
  printf("  A B C D E F G");
  printf("\n");

  for (int i = 0; i < row; i++)
  {
    printf("%d",6-i);
    printf(" ");
    for (int z = 0; z < col; z++)
    {
      printf("%c ",conBoard[i][z]);
    }
    printf("\n");
  }
  printf("\n");
  return;
}

/* artificialUpdateBoard is called when it is the AI's turn, the method makes uses a scoring system to determine the best spot to place a token */
void artificialUpdateBoard(char conBoard[6][7], int position)
{
  /* Each if statement checks where the first '.' is starting from the bottom of the board */
  if (position == 0)
    {
      for(int i = 5; i >= 0; i--)
	{
	  if(conBoard[i][0] == '.')
	    {
	      conBoard[i][0] = aI;
	      break;
	    }
	}
    }
  if (position == 1)
    {
      for(int i = 5; i >= 0; i--)
	{
	  if(conBoard[i][1] == '.')
	    {
	      conBoard[i][1] = aI;
	      break;
	    }
	}
    }
  if (position == 2)
    {
      for(int i = 5; i >= 0; i--)
	{
	  if(conBoard[i][2] == '.')
	    {
	      conBoard[i][2] = aI;
	      break;
	    }
	}
    }
  if (position == 3)
    {
      for(int i = 5; i >= 0; i--)
	{
	  if(conBoard[i][3] == '.')
	    {
	      conBoard[i][3] = aI;
	      break;
	    }
	}
    }
  if (position == 4)
    {
      for(int i = 5; i >= 0; i--)
	{
	  if(conBoard[i][4] == '.')
	    {
	      conBoard[i][4] = aI;
	      break;
	    }
	}
    }
  if (position == 5)
    {
      for(int i = 5; i >= 0; i--)
	{
	  if(conBoard[i][5] == '.')
	    {
	      conBoard[i][5] = aI;
	      break;
	    }
	}
    }
  if (position == 6)
    {
      for(int i = 5; i >= 0; i--)
	{
	  if(conBoard[i][6] == '.')
	    {
	      conBoard[i][6] = aI;
	      break;
	    }
	}
    }
  printBoard(conBoard);
}

int artificialMove(char conBoard[6][7])
{
  /* The array that keeps the scores for each spot(scoring system expalined more in depth in the written section */
  int scores[] = {0,0,0,3,0,0,0};

  /* Checks to see if row is full */
  for(int i = 0; i < 7; i++)
  {
    if(conBoard[0][i] != '.')
    {
      scores[i] = -1;
    }
  }

  /* Main for loop, runs through every spot unless the score at that spot is equal to -1, indicating that the column is full and nothing can be placed there */
  for(int i = 0; i < 7; i++)
  {
    if(scores[i] == -1)
    {
      continue;
    }

    int vertical;
    int horizontalKeep;
    int horizontal;
    int verticalKeep;
    
    /*Finds the vertical and horizontal position of the furthest down spot in that column(where the disk would be played) */
    for(int z = 5; z >= 0; z--)
    {
      if(conBoard[z][i] == '.')
      {
        horizontal = z;
        vertical = i;
        horizontalKeep = z;
	verticalKeep = i;
        break;
      }
    }

    /*Checks Vertical Score*/
    /* Will assign points values to building up vertically and trying to block the opposing player vertically */
    int connectionVertical = 0;
    while(horizontal - horizontalKeep <= 3 && horizontal <= 5)	
    {
      if(horizontal == horizontalKeep)
      {
	horizontal++;
	continue;
      }
      
      if(aI == conBoard[horizontal][verticalKeep])
      {
	connectionVertical++;
      }
      else
      {
	break;
      }
      horizontal++;
    }
    
    if(connectionVertical == 1)
    {
      scores[i] = scores[i] + 2;
    }
    else if(connectionVertical == 2)
    {
      scores[i] = scores[i] + 5;
    }
    else if(connectionVertical == 3)
    {
      scores[i] = scores[i] + 1000;
    }
    
    horizontal = horizontalKeep;
    int blockConnectionVertical = 0;
    
    while(horizontal - horizontalKeep <=3 && horizontal <=5)
    {
      if(horizontal == horizontalKeep)
      {
	horizontal++;
	continue;
      }
      
      if(player == conBoard[horizontal][verticalKeep])
      {
	blockConnectionVertical++;
      }
      else
      {
	break;
      }
      horizontal++;
    }
    
    if(blockConnectionVertical == 2)
    {
      scores[i] = scores[i] + 4;
    }
    else if(blockConnectionVertical == 3)
    {
      scores[i] = scores[i] + 100;
    } 
    
    horizontal = horizontalKeep;
    /*End Vertical Score Check*/
    
    /* Resets all the variables */
    horizontal = horizontalKeep;
    int connectionHorizontal = 0;
    int horizontalRight = 0;
    int horizontalLeft = 0;
    
    /*Check Horizontal Score*/
    /*Check Horizontal Offensive Score(Trying to form a connection)*/
    /*Check Horizontal Right(Gets the rightmost position that is not the player and is at most three spots away(so that it can be connected by two peices in the middle)*/
    while(vertical <= 6 && horizontalRight <= 3)
    {
      if(vertical == verticalKeep)
      {
	vertical++;
	continue;
      }
      
      if(conBoard[horizontalKeep][vertical] != player  && (horizontal == 5 | conBoard[horizontal +1][vertical] != '.'))
      {
	horizontalRight++;
	vertical++;
      }
      else
      {
	break;
      }
    }
    /*End Check Horizontal Right*/
    
    vertical = verticalKeep;
    /*Check Horizontal Left*/
    while(vertical >=0 && horizontalLeft <= 3)
    {
      if(vertical == verticalKeep)
      {
	vertical--;
	continue;
      }

      if(conBoard[horizontalKeep][vertical] != player && (horizontal == 5 | conBoard[horizontal +1][vertical] != '.'))
      {
	horizontalLeft++;
	vertical--;
      }
      else
      {
	  break;
      }
    }
    /*End Check Horizontal Left*/
    vertical = verticalKeep;
    
    int rightPosition = horizontalRight + verticalKeep;
    int leftPosition = verticalKeep - horizontalLeft;

    if(rightPosition - leftPosition == 3)
    {
      /*rightPosition - leftPosition will indicate that there is exactly three other spots(to the left or right) that can be played in or already have the AI's token */
      int aIScore = 0;

      for(int q = leftPosition; q <= rightPosition; q++)
      {
	if(conBoard[horizontal][q] == aI)
	{
	  aIScore++;
	}
      }
      
      if(aIScore == 3)
      {
	scores[i] = scores[i] + 1000;
      }
      else if(aIScore == 2)
      {
	scores[i] = scores[i] + 5;
      }
      else if(aIScore == 1)
      {
	scores[i] = scores[i] + 2;
      }
    }
    else if(rightPosition - leftPosition == 4)
    {
      /*rightPosition - leftPosition == 4 will indicate that there is two different lines of four that can connect(example below)*/
      /* (Example: If spot A, B, C ,D, E are open, and D is the spot we are evaluating, the connection of ABCD or BCDE can be formed */
      int positionHold = leftPosition;
      for(int f = 0; f <= 1; f++)
      {
	int aIScore = 0;
	for(int r = 0; r <=3; r++)
        {
	  if (conBoard[horizontalKeep][positionHold] == aI)
	  {
	    aIScore++;
	  } 
	  positionHold++;
	}
	positionHold = leftPosition + 1;
	
	if(aIScore == 3)
	{
	    scores[i] = scores[i] + 1000;
	}
	else if(aIScore == 2)
	{
	    scores[i] = scores[i] + 5;
	}
	else if(aIScore == 1)
	{
	    scores[i] = scores[i] + 2;
	}	
      }
    }
    else if(rightPosition - leftPosition == 5)
    {
      /*rightPosition - leftPosition will indicate that there are three different lines of four that can connect*/
      int positionHold = leftPosition;
      int times = 1;
      int aIScore = 0;
      for(int f = 0; f <=2; f++)
      {
	for(int r = 0; r<=3; r++)
	{
	  if(conBoard[horizontalKeep][positionHold] == aI)
	  {
	    aIScore++;
	  }
	  positionHold++;
	}
	
	if(times == 1)
        {
	  positionHold = leftPosition + 1;
	} 
	if(times == 2)
	{
	  positionHold = leftPosition + 2;
	}
	times++;
	
	if(aIScore == 3)
        {
          scores[i] = scores[i] + 1000;
        }
	else if(aIScore == 2)
        {
          scores[i] = scores[i] + 5;
        }
	else if(aIScore == 1)
        {
          scores[i] = scores[i] + 2;
	}
	aIScore = 0;
      }
    }
    else if(rightPosition - leftPosition == 6)
    {
      /*rightPosition - leftPosition will indicate that there are four different lines of four that can connect(example below)*/
      int positionHold = leftPosition;
      int times = 1;
      int aIScore = 0;
      for(int f = 0; f <=3; f++)
      {
        for(int r = 0; r<=3; r++)
        {
          if(conBoard[horizontalKeep][positionHold] == aI)
	  {
            aIScore++;
	  }
          positionHold++;
	}

        if(times == 1)
	{
          positionHold = leftPosition + 1;
        }
        if(times == 2)
        {
          positionHold = leftPosition + 2;
        }
	if(times == 3)
	{
	  positionHold = leftPosition + 3;
	}
        times++;
	
	if(aIScore == 3)
	{
          scores[i] = scores[i] + 1000;
	}
	else if(aIScore == 2)
	{
          scores[i] = scores[i] + 5;
	}
	else if(aIScore == 1)
	{
	  scores[i] = scores[i] + 2;
	}
	aIScore = 0;
      }
    }
    /*End Check Horizontal Offensive Score*/
    /*Start Check Horizontal Defensive Score*/
    /* Will now check if the player has a streak of disks in a row*/
    /*Check Horizontal Right*/
    int rightHorizontal = 0;
    int leftHorizontal = 0;
    int defensiveConnection = 0;
    horizontal = horizontalKeep;
    vertical = verticalKeep;
    
    /* Gets the rightmost position stopping if it hits the AI token(AI token coverage is taken care above) or if the counter is more than three spots away */
    while(vertical <= 6 && rightHorizontal <= 3)
    {
      if(vertical == verticalKeep)
      {
        vertical++;
        continue;
      }

      if(conBoard[horizontalKeep][vertical] != aI  && (horizontal == 5 | conBoard[horizontal +1][vertical] != '.'))
      {
        rightHorizontal++;
        vertical++;
      }
      else
      {
        break;
      }
    }
    /*End Check Horizontal*/
    
    vertical = verticalKeep;

    /*Check Horizontal Left*/
    /* Gets the leftmost position stopping if it hits the AI token(AI token coverage is taken care above) or if the counter is more than three spots away */
    while(vertical >=0 && leftHorizontal <= 3)
    {
      if(vertical == verticalKeep)
      {
        vertical--;
        continue;
      }

      if(conBoard[horizontalKeep][vertical] != aI && (horizontal == 5 | conBoard[horizontal +1][vertical] != '.'))
      {
        leftHorizontal++;
        vertical--;
      }
      else
      {
        break;
      }
    }
    /*End Check Horizontal Left*/
    vertical = verticalKeep;

    int positionRight = rightHorizontal + verticalKeep;
    int positionLeft = verticalKeep - leftHorizontal;

    if(positionRight - positionLeft == 3)
    {
      /*rightPosition - leftPosition will indicate that there is exactly three other spots(to the left or right) that can be played in or already have the player's token */
      int playerScore = 0;

      for(int q = positionLeft; q <= positionRight; q++)
      {
        if(conBoard[horizontal][q] == player)
	{
          playerScore++;
	}
      }

      if(playerScore == 3)
      {
        scores[i] = scores[i] + 100;
      }
      else if(playerScore == 2)
      {
        scores[i] = scores[i] + 4;
      }
    }
    else if(positionRight - positionLeft == 4)
    {
      /*rightPosition - leftPosition == 4 will indicate that there is two different lines of four that can connect(example below)*/
      /* (Example: If spot A, B, C ,D, E are open, and D is the spot we are evaluating, the connection of ABCD or BCDE can be formed */
      int positionHold = positionLeft;
      for(int f = 0; f <= 1; f++)
      {
         int playerScore = 0;
	 for(int r = 0; r <=3; r++)
	 {
	   if (conBoard[horizontalKeep][positionHold] == player)
	   {
             playerScore++;
	   }
	   positionHold++;
	 }
	 positionHold = positionLeft + 1;

         if(playerScore == 3)
         {
	   scores[i] = scores[i] + 100;
         }
         else if(playerScore == 2)
         {
	   scores[i] = scores[i] + 4;
         }
      }
    }
    else if(positionRight - positionLeft == 5)
    {
      /*rightPosition - leftPosition == 5 will indicate that there are three different lines of four that can connect*/
      int positionHold = positionLeft;
      int times = 1;
      int playerScore = 0;
      for(int f = 0; f <=2; f++)
      {
        for(int r = 0; r<=3; r++)
	{
          if(conBoard[horizontalKeep][positionHold] == player)
	  {
            playerScore++;
	  }
	  positionHold++;
	}

	if(times == 1)
	{
	  positionHold = positionLeft + 1;
	}
        if(times == 2)
	{
      	  positionHold = positionLeft + 2;
        }
        times++;

	if(playerScore == 3)
	{
       	  scores[i] = scores[i] + 100;
        }
        else if(playerScore == 2)
	{
      	  scores[i] = scores[i] + 4;
	}
        playerScore = 0;
      }
     }
     else if(positionRight - positionLeft == 6)
     {
       /*rightPosition - leftPosition == 6 will indicate that there are four different lines of four that can connect*/
       int positionHold = positionLeft;
       int times = 1;
       int playerScore = 0;
       for(int f = 0; f <=3; f++)
       {
         for(int r = 0; r<=3; r++)
         {
	   if(conBoard[horizontalKeep][positionHold] == player)
	   {
	     playerScore++;
	   }
           positionHold++;
       }

       if(times == 1)
       {
         positionHold = positionLeft + 1;
       }
       if(times == 2)
       {
         positionHold = positionLeft + 2;
       }
       if(times == 3)
       {
         positionHold = positionLeft + 3;
       }
       times++;

       if(playerScore == 3)
       {
         scores[i] = scores[i] + 100;
       }
       else if(playerScore == 2)
       {
         scores[i] = scores[i] + 4;
       }
       playerScore = 0;
     }
    }
    /*End Check Horizontal Defensive Score*/
    /*End Horizontal Score Check*/
  }

  /* Will find the largest score in the arry and pass the position onto artificialUpdateBoard */
  int position;
  int highestScore = 0;
  for(int y = 0; y <= 6; y++)
  {
    if(highestScore <= scores[y])
    {
      highestScore = scores[y];
      position = y;
    }
  }

  artificialUpdateBoard(conBoard,position);
}


/* playerUpdateBoard() updates the board when the player enters which column they want to place their token in */
void playerUpdateBoard(char position, char conBoard[6][7])
{
  if (position == 'a' | position == 'A')
  {
    for(int i = 5; i >= 0; i--)
    {
      if(conBoard[i][0] == '.')
      {
	conBoard[i][0] = player;
        break;
      }
    }
  }
  if (position == 'b' | position == 'B')
  {
    for(int i = 5; i >= 0; i--)
      {
	if(conBoard[i][1] == '.')
	  {
	    conBoard[i][1] = player;
	    break;
	  }
      }
  }
  if (position == 'c' | position == 'C')
  {
    for(int i = 5; i >= 0; i--)
      {
	if(conBoard[i][2] == '.')
	  {
	    conBoard[i][2] = player;
	    break;
	  }
      }
  }
  if (position == 'd' | position == 'D')
  {
    for(int i = 5; i >= 0; i--)
      {
	if(conBoard[i][3] == '.')
	  {
	    conBoard[i][3] = player;
	    break;
	  }
      }
  }
  if (position == 'e' | position == 'E')
  {
    for(int i = 5; i >= 0; i--)
      {
	if(conBoard[i][4] == '.')
	  {
	    conBoard[i][4] = player;
	    break;
	  }
      }
  }
  if (position == 'f' | position == 'F') 
  {
    for(int i = 5; i >= 0; i--)
      {
	if(conBoard[i][5] == '.')
	  {
	    conBoard[i][5] = player;
	    break;
	  }
      }
  }
  if (position == 'g' | position == 'G')
  {
    for(int i = 5; i >= 0; i--)
      {
	if(conBoard[i][6] == '.')
	  {
	    conBoard[i][6] = player;
	    break;
	  }
      }
  }  
  printBoard(conBoard);
}

/* checkValid() is used to make sure a valid spot was entered by the user */
int checkValid(char spot, char conBoard[6][7])
{
  if (spot == 'a' | spot == 'A')
  {
    if(conBoard[0][0] == '.')
    {
      return 0;
    }
    else
    {
      return 1;
    }
  }
  else if (spot == 'b' | spot == 'B')
  {
    if(conBoard[0][1] == '.')
    { 
	return 0;
    }
    else
    { 
	return 1;
    }
  }
  else if (spot == 'c' | spot == 'C')
  {
    if(conBoard[0][2] == '.')
    { 
	return 0;
    }
    else
    { 
	return 1;
    }
  }
  else if (spot == 'd' | spot == 'D')
  {
    if(conBoard[0][3] == '.')
    { 
	return 0;
    }
    else
    { 
	return 1;
    }
  }
  else if (spot == 'e' | spot == 'E')
  {
    if(conBoard[0][4] == '.')
    { 
	return 0;
    }
    else
    { 
	return 1;
    }
  }
  else if (spot == 'f' | spot == 'F')
  {
    if(conBoard[0][5] == '.')
    { 
	return 0;
    }
    else
    { 
	return 1;
    }
  }
  else if (spot == 'g' | spot == 'G')
  {
    if(conBoard[0][6] == '.')
    { 
	return 0;
    }
    else
    { 
	return 1;
    }
  }
}

/* checkWinner() is used to see if the AI or the player won*/
int checkWinner(char conBoard[6][7])
{
  for(int i = 0; i < row; i++)
  {
    for(int z = 0; z < col; z++)
    {
      int horizontal = i;
      int vertical = z;
      char team = conBoard[i][z];
      
      if (team == '.')
      {
	  continue;
      }

      int count = 1;
      
      /* Checks horizontal connect four */
      while(vertical <=6)
      {
	if(vertical == z && horizontal == i)
        {
	  vertical++;
	  continue;
        }
	if(conBoard[horizontal][vertical] == team)
	{
	  count++;
        }
	else
        {
	  break;
        }
	vertical++;
      }
      
      horizontal = i;
      vertical = z;

      while(vertical  >= 0)
      {
	if(vertical == z && horizontal == i)
        {
	  vertical--;
	  continue;
        }

	if(conBoard[horizontal][vertical] == team)
	  {
	    count++;
	  }
        else
	  {
	    break;
	  }
	vertical--;
      }
      
      if (count >= 4)
      {
	  return 1;
      }
      /*End check for horizontal connect four*/

      count = 1;
      horizontal = i;
      vertical = z;

      /* Checks vertical connect four */
      while(horizontal <=5)
      {
	  if(vertical == z && horizontal == i)
	  {
	      horizontal++;
	      continue;
	  }

	  if(conBoard[horizontal][vertical] == team)
	  {
	      count++;
	  }
	  else
	  {
	      break;
	  }
	  horizontal++;
      }

      horizontal = i;
      vertical = z;
      
      while(horizontal >= 0)
      {
        if(vertical == z && horizontal == i)
        {
	  horizontal--;
	  continue;
	}

	if(conBoard[horizontal][vertical] == team)
	{
          count++;
        }
        else
        {
          break;
        }
        horizontal--;
      }

      if (count >= 4)
      {
          return 1;
      }
      /* Vertical connect four check ends here */

      count = 1;
      horizontal = i;
      vertical = z;
      
      /* Checks Right Diagonal Connect Four */
      while(vertical  <= 6 && horizontal >= 0)
      {
        if(vertical == z && horizontal == i)
        {
          horizontal--;
	  vertical++;
          continue;
        }

        if(conBoard[horizontal][vertical] == team)
        {
          count++;
        }
        else
        {
          break;
        }
        horizontal--;
	vertical++;
      }
      
      horizontal = i;
      vertical = z;
      
      while(vertical  >= 0 && horizontal <= 5)
      {
        if(vertical == z && horizontal == i)
        {
          horizontal++;
	  vertical--;
          continue;
        }

        if(conBoard[horizontal][vertical] == team)
        {
          count++;
        }
        else
        {
          break;
        }
        horizontal++;
	vertical--;
      }

      if (count >= 4)
      {
          return 1;
      }
      /*End Check Right Diagonal*/

      count = 1;
      horizontal = i;
      vertical = z;
      
      /*Checks Left Diagonal Connect Four*/
      
      while(vertical  >= 0 && horizontal >= 0)
      {
        if(vertical == z && horizontal == i)
        {
          horizontal--;
          vertical--;
          continue;
         }

        if(conBoard[horizontal][vertical] == team)
        {
          count++;
        }
        else
        {
         break;
        }
        horizontal--;
        vertical--;
      }

      horizontal = i;
      vertical = z;

      while(vertical <= 6 && horizontal <= 5)
      {
        if(vertical == z && horizontal == i)
        {
          horizontal++;
          vertical++;
          continue;
        }

        if(conBoard[horizontal][vertical] == team)
        {
          count++;
        }
        else
        {
          break;
        }
        horizontal++;
        vertical++;
      }

      if (count >= 4)
      {
        return 1;
      }
      
      /*End Check Left Diagonal*/  
    }
  }
  return 0;
}

int main()
{
  /* conBoard holds the board abnd is filled with values when passed into makeBoard()*/
  char conBoard[6][7];
  int first;
  
  printf("Do you want to go first?(Enter 1 to go first, 2 to go second)\n");
  scanf(" %d",&first);

  /*Assigns the X and the O to the player and AI*/
  if(first == 1)
  {
    player = 'X';
    aI = 'O';
  }
  else
  {
    player = 'O';
    aI = 'X';
  }

  makeBoard(conBoard);
  printBoard(conBoard);

  int stop = 0;
  int winner = 0;
  int movesMade = 0;

  while(stop == 0)
  {
    if(first == 1)
    {
      /* While loop runs until there is a winner or the board is full*/
      while(winner == 0  && movesMade < 42)
      {
        char colResponse;
	printf("What column do you want to put a disk in?(Enter the letter)");
	scanf(" %c",&colResponse);
	int valid = checkValid(colResponse, conBoard);

	while (valid != 0)
        {
	  printf("Invalid response. What column do you want to put a disk in?(Enter the letter)");
	  scanf(" %c",&colResponse);
	  valid = checkValid(colResponse, conBoard);
        }

	playerUpdateBoard(colResponse, conBoard);
	movesMade++;
	winner = checkWinner(conBoard);

	if (winner == 1)
        {
	  printf("Congratualations, you have won.  Would you like to play again?(Enter 0 for yes, 1 for no)\n");
	  scanf(" %d",&stop);
	  break;
        }

	artificialMove(conBoard);
	movesMade++;
	winner = checkWinner(conBoard);
	
        if(winner == 1)
        {
	  printf("You have the lost the game.  Would you like to play again?(Enter 0 for yes, 1 for no)\n");
	  scanf(" %d",&stop);
	  break;
        }  
      }

      if(movesMade == 42)
      {
	printf("The game ended in a tie.  Would you like to play again(Enter 0 for yes, 1 for no)\n");
	scanf(" %d", &stop);
      }
    }
    else
    {
      while(winner == 0  && movesMade < 42)
      {
	artificialMove(conBoard);
	movesMade++;
	winner = checkWinner(conBoard);

	if(winner == 1)
	{
	  printf("You have the lost the game.  Would you like to play again?(Enter 0 for yes, 1 for no)\n");
	  scanf(" %d", &stop);
	  break;
	}
    
        char colResponse;
        printf("What column do you want to put a disk in?(Enter the letter)");
        scanf(" %c",&colResponse);
        int valid = checkValid(colResponse, conBoard);

	while (valid != 0)
        {
          printf("Invalid response. What column do you want to put a disk in?(Enter the letter)");
          scanf(" %c",&colResponse);
          valid = checkValid(colResponse, conBoard);
        }

        playerUpdateBoard(colResponse, conBoard);
        movesMade++;
        winner = checkWinner(conBoard);

	if (winner == 1)
	{
	  printf("Congratualations, you have won.  Would you like to play again?(Enter 0 for yes, 1 for no)\n");
	  scanf(" %d",&stop);
	  break;
        }

      }

      if(movesMade == 42)
      {
        printf("The game ended in a tie.  Would you like to play again(Enter 0 for yes, 1 for no)\n");
        scanf(" %d", &stop);
      }
    }
    /* Resets all the variables and game board if the user says they want to play again */
    if(stop == 0)
    {
      printf("Do you want to go first?(Enter 1 to go first, 2 to go second)\n");
      scanf(" %d",&first);
      
      if(first == 1)
      {
	aI = 'O';
	player = 'X';
      }
      else
      {
	player = 'O';
	aI = 'X';
      }
      winner = 0;
      movesMade = 0;
      makeBoard(conBoard);
      printBoard(conBoard);
    }
  }
}

