/* C program by Dave Russillo. Made for CS1310. TicTacToe.
 *           _                      _
 *          | |                    | |
 *         / /                     \ \
 *        /  \____             ____/  \
 *   ____/   (|____)          (____|)  \____
 *  |   |   (|_____)          (_____|) |    |
 *  |   |    (|____)          (____|)  |    |
 *  |___|_____(|___)          (___|)___|____|
 *
 */

#include <stdio.h>

char ttt[3][3];
char player = 'X';
int row;
int col;
int moves = 0;



void draw_board_options(void) {
  printf("\n"
         "_1_|_2_|_3_\n"
         "_4_|_5_|_6_\n"
         " 7 | 8 | 9 \n\n");
}



void draw_board(int winstate) {
  int i;
  int wintype = winstate / 10;
  int wincoord = winstate - winstate / 10 * 10;

  for(row = 0; row < 3; row++) {  // iterate through rows
    for(i = 0; i < 5; i++) {  // iterate through character lines within the row
      for(col = 0; col < 3; col++) {  // iterate through each column
        if(ttt[row][col] == ' ') {  // based on which line it's on, draw different parts of the ascii for X
          if(i == 4 && row != 2) printf("_________");  // separator between rows: dont add if last row
          else printf("         ");
          if(col != 2) printf("|");  // dont add column separator if last column
        } else {
          switch(i) {
            case 0:  // first line in row
              if(wintype == 2 && wincoord == col) printf("    |    ");  // if win on column, add pipe
              else if(wintype == 3 && row == col) printf("\\\\       ");  // if backward win, add backslashes
              else if(wintype == 4 && row + col == 2) printf("        /");  // if backward win, add slash
              else printf("         ");  // if no win yet
              break;
            case 1:  // second line in row
              if(ttt[row][col] == 'X') {
                if(wintype == 2 && wincoord == col) printf("   X|X   ");  // if win on column, add pipe
                else if(wintype == 3 && row == col) printf("  \\X X   ");  // if backward win, add backslash
                else if(wintype == 4 && row + col == 2) printf("   X X// ");  // if forward win, add slashes
                else printf("   X X   ");  // if no win yet
              } else {
                if(wintype == 2 && wincoord == col) printf("   O|O   ");  // if win on column, add pipe
                else if(wintype == 3 && row == col) printf("  \\OOO   ");  // if backward win, add backslash
                else if(wintype == 4 && row + col == 2) printf("   OOO// ");  // if forward win, add slashes
                else printf("   OOO   ");  // if no win yet
              }
              break;
            case 2:  // third line in row
              if(ttt[row][col] == 'X') {
                if(wintype == 1 && wincoord == row) printf("========="); // if win on row, add equal signs
                else if(wintype == 2 && wincoord == col) printf("    |    ");
                else if(wintype == 3 && row == col) printf("    \\\\   ");  // if backward win, add backslashes
                else if(wintype == 4 && row + col == 2) printf("    //   ");  // if forward win, add slashes
                else printf("    X    ");  // if no win yet
              } else {
                if(wintype == 1 && wincoord == row) printf("==O===O=="); // if win on row, add equal signs
                else if(wintype == 2 && wincoord == col) printf("  O | O  ");
                else if(wintype == 3 && row == col) printf("  O \\\\O  ");  // if backward win, add backslashes
                else if(wintype == 4 && row + col == 2) printf("  O //O  ");  // if forward win, add slashes
                else printf("  O   O  ");  // if no win yet
              }
              break;
            case 3:  // fourth line in row
              if(ttt[row][col] == 'X') {
                if(wintype == 2 && wincoord == col) printf("   X|X   ");  // if win on column, add pipe
                else if(wintype == 3 && row == col) printf("   X X\\\\ ");  // if backward win, add backslashes
                else if(wintype == 4 && row + col == 2) printf("  /X X   ");  // if forward win, add slash
                else printf("   X X   ");  // if not win yet
              } else {
                if(wintype == 2 && wincoord == col) printf("   O|O   ");  // if win on column, add pipe
                else if(wintype == 3 && row == col) printf("   OOO\\\\ ");  // if backward win, add backslashes
                else if(wintype == 4 && row + col == 2) printf("  /OOO   ");  // if forward win, add slash
                else printf("   OOO   ");  // if not win yet
              }
              break;
            case 4:  // last line in row
              if(row != 2) {  // if not on last row, add separator between rows
                if(wintype == 2 && wincoord == col) printf("____|____");  // if win on column, add pipe
                else if(wintype == 3 && row == col) printf("________\\");  // if backward win, add backslash
                else if(wintype == 4 && row + col == 2) printf("//_______");  // if forward win, add slash
                else printf("_________");  // if no win yet
              } else {
                if(wintype == 2 && wincoord == col) printf("    |    ");  // if win on column, add pipe
                else if(wintype == 3 && row == col) printf("        \\");  // if backward win, add backslash
                else if(wintype == 4 && row + col == 2) printf("//       ");  // if forward win, add slash
                else printf("         ");  // if no win yet
              }
          }
          // separator between columns
          if(col != 2 && wintype == 1 && wincoord == row && i == 2) printf("=");  // if win is on row, add equal sign
          else if(wintype == 3 && row == col && i == 4) printf("\\");  // add backslash instead of pipe if it's a backward win
          else if(wintype == 4 && row + col == 2 && i == 0) printf("/");  // add slash instead of pipe if it's a backward win
          else if(col != 2) printf("|");  // dont add pipe if last column

        }
      }
      printf("\n");  // newline between each line in row
    }
  }
  if(wintype == 5) {
    printf("\nTie! \n\n");
  } else if(wintype != 0) {
    printf("\n%c won! \n\n", player);
  }
}



void clear_board(void) {
  for(row = 0; row < 3; row++) {
    for(col = 0; col < 3; col++) {
      ttt[row][col] = ' ';
    }
  }
}



void take_turn(void) {
  int position;
  int position_valid = 0;
  int x = 0;
  int y = 0;

  while(position_valid == 0) {
    printf("\nIt's %c's turn. Choose an empty field:  ", player);
    scanf("%d", &position);
    position_valid = 1;
    switch(position) {
      case 1: 
        x = 0; 
        y = 0; 
        break;
      case 2: 
        x = 0; 
        y = 1; 
        break;
      case 3: 
        x = 0; 
        y = 2; 
        break;
      case 4: 
        x = 1; 
        y = 0; 
        break;
      case 5: 
        x = 1; 
        y = 1; 
        break;
      case 6: 
        x = 1; 
        y = 2; 
        break;
      case 7: 
        x = 2; 
        y = 0; 
        break;
      case 8: 
        x = 2; 
        y = 1; 
        break;
      case 9: 
        x = 2; 
        y = 2; 
        break;
      default: 
        position_valid = 0;
        break;
    }
    if(ttt[x][y] == ' ' && position_valid == 1) {
      ttt[x][y] = player;
    } else {
      position_valid = 0;
      printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
      draw_board_options();
      draw_board(0);
      printf("Invalid input! Try again.");
    }
  }
  moves++;  // increment moves to keep track of them
}



void reassign_player(void) {
  if(player == 'X') 
    player = 'O';
  else 
    player = 'X';
}



int check_if_win(void) {  // returns wintype in tenths and coord number in units
  int i;

  for(i = 0; i < 3; i++) {
    if(ttt[i][0] != ' ' && ttt[i][0] == ttt[i][1] && ttt[i][1] == ttt[i][2]) {
      return 10 + i;  // wintype 1 is horizontal win
    } else if(ttt[0][i] != ' ' && ttt[0][i] == ttt[1][i] && ttt[1][i] == ttt[2][i]) {
      return 20 + i;  // wintype 2 is vertical win
    }
  }
  if(ttt[0][0] != ' ' && ttt[0][0] == ttt[1][1] && ttt[1][1] == ttt[2][2]) {
    return 30;  // wintype 3 is backward diagonal (needs no coord)
  } else if(ttt[0][2] != ' ' && ttt[0][2] == ttt[1][1] && ttt[1][1] == ttt[2][0]) {
    return 40;  // wintype 4 is forward diagonal (needs no coord)
  } else if(moves == 9) {
    return 50;  // wintype 5 is for ties
  }
  return 0;
}



int main(void) { 
  char input;

  printf("\nWelcome to TicTacToe! X goes first. \nPress enter to start!\n");
  scanf("%c", &input);
  clear_board();
  while(check_if_win() == 0) {
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    draw_board_options();
    draw_board(0);
    take_turn();
    reassign_player();
  }
  reassign_player();
  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
  draw_board_options();
  draw_board(check_if_win());

  return 0;
}



