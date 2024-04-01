#include <iostream>

using namespace std;
bool checkWin(const char* board, char player)
{
  //  could have used if statements but this was nicer.
  return((board[1] == player && board[2] == player && board[3] == player) ||
         (board[4] == player && board[5] == player && board[6] == player) ||
         (board[7] == player && board[8] == player && board[9] == player) ||
         //  above: straight along win cases
         (board[1] == player && board[4] == player && board[7] == player) ||
         (board[2] == player && board[5] == player && board[8] == player) ||
         (board[3] == player && board[6] == player && board[9] == player) ||
         //  downward win cases
         (board[1] == player && board[5] == player && board[9] == player) ||
         (board[3] == player && board[5] == player && board[7] == player) );
         //  diagonal win cases
}

bool checkDraw(const char* board)
{
  for (int i = 1; i <= 9; ++i)
  {
    if (board[i] != 'X' && board[i] != 'O')
    {
      return false;
    }
  }
  return true;
}

void printBoard(const char* board)
{
  cout << "\n\tTic Tac Toe\n\n";
  cout << "Player 1 (X)  -  Player 2 (O)" << endl;
  cout << endl;
  cout << "     |     |     " << endl;
  cout << "  " << board[1] << "  |  " << board[2] << "  |  " << board[3] << endl;
  cout << "_____|_____|_____" << endl;
  cout << "     |     |     " << endl;
  cout << "  " << board[4] << "  |  " << board[5] << "  |  " << board[6] << endl;
  cout << "_____|_____|_____" << endl;
  cout << "     |     |     " << endl;
  cout << "  " << board[7] << "  |  " << board[8] << "  |  " << board[9] << endl;
  cout << "     |     |     " << endl << endl;
}

int main()
{
  char board[10] = {' ','1', '2', '3', '4', '5', '6', '7', '8', '9'};
  char playerState = 'X';
  bool gameOver = false;
  int moveNumber = 0;

  while (!gameOver)
  {
    printBoard(board);
    
    int space;
    
    cout << "Player " << playerState << ", enter your move (1-9): ";
    cin >> space;
    
    if (space < 1 || space > 9)
    {
      cout << "That space doesn't exist, please enter a number 1-9: \n";
      continue;
    }
    if (board[space] == 'X' || board[space] == 'O')
    {
      cout << "That space is taken, try again! \n";
      continue;
    }


    board[space] = playerState;
    moveNumber++;


    if (checkWin(board, playerState)) 
    {
      gameOver = true;
      cout << "Player " << playerState << " wins!\n";
    } 

    else if (checkDraw(board)) 
    {
      gameOver = true;
      cout << "It's a draw!\n";
    }

    else if (playerState == 'X') {
      playerState = 'O';
    } 
    else 
    {
      playerState = 'X';
    }
  }

  printBoard(board);
  
  return 0;
}