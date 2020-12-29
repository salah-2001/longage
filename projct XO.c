               //-------    _______    Game   |X|O| ______-------//

#include <stdio.h>
#include <stdlib.h>

	char board[3][3]={
	             {'1','2','3'},
				 {'4','5','6'},
				 {'7','8','9'}
	                };
	int player=1;
     char choix;
     int winner;
     int over=0  //game not over:0 || game over:1
     int movrcount=0;
 /* 
      print the board
 */
     void printboard()
     {
     	int i,j;
     		printf("------------------------\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		printf("|%c\t",board[i][j]);
		printf("|\n");
		printf("------------------------\n");
		
	}
	 }
	 
	 void play()
{
	 	  printf("player %d:choose a celle:\t",player);
     scanf(" %c",&choix);
     char valeur;
     if(player==1)
     valeur='x';
     else
     valeur='o';
    switch(choix)
     {
     	    case '1':board[0][0]=valeur;
     	break;
     		case '2':board[0][1]=valeur;
     	break;
     		case '3':board[0][2]=valeur;
     	break;
     		case '4':board[1][0]=valeur;
     	break;
     		case '5':board[1][1]=valeur;
     	break;
     		case '6':board[1][2]=valeur;
     	break;
     		case '7':board[2][0]=valeur;
     	break;
     		case '8':board[2][1]=valeur;
     	break;
     		case '9':board[2][2]=valeur;
     	break;
     
	 }
     	 movrcount++;
} 
	
  void gameover()
  {
  	// line the line
  	int i;
  	for(i=0;i<3;i++)
  	{
  		if((board[i][0]==board[i][1]) && (board[i][1]==board[i][2]))
  		{
  			 if(board[i][0]=='x')
  		    winner=1;
  		    else
  		    winner=2;
  		    
  		    over=1;
  		    return;
		  }
	  }
	  // columns
	int j;
	for(j=0;i<3;i++)
	{
		if((board[0][j]==board[1][j]) && (board[1][j]==board[2][j]))
		{
			 if(board[0][j]=='x')
  		    winner=1;
  		    else
  		    winner=2;
  		    
  		    over=1;
  		    return;
		}
	}
	// the main diametr
	if((board[0][0]==board[1][1]) && (board[1][1]==board[2][2]))
		{
			 if(board[0][0]=='x')
  		    winner=1;
  		    else
  		    winner=2;
  		    
  		    over=1;
  		    return;
		}
		// secondary dimetre
			if((board[0][2]==board[1][1]) && (board[1][1]==board[2][0]))
		{
			 if(board[0][2]=='x')
  		    winner=1;
  		    else
  		    winner=2;
  		    
  		    over=1;
  		    return;
		}
		// equality
		if(movrcount==8)
		{
				winner=0;
		        over=1;
		}
	
  }
     
int main(int argc, char *argv[]) 
{


     printboard();
     
     while (over!=1)
     {
      
        play();	
      printboard();
      gameover();
      if(player==1)
         player=2;
      else
        player=1;
       
	 }
      if( winner ==0)
        printf("no winner\n");
      else
       printf("player %d winner the  game \n",winner);
      
	getch();
	return 0;
}

