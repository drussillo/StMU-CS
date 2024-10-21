/* C program by Dave Russillo. Made for CS1310. TicTacToe */
#include <stdio.h>
#include <stdlib.h>

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
                if(wintype == 1 && wincoord == row) printf("====X===="); // if win on row, add equal signs
                else if(wintype == 3 && row == col) printf("    \\\\   ");  // if backward win, add backslashes
                else if(wintype == 4 && row + col == 2) printf("    //   ");  // if forward win, add slashes
                else printf("    X    ");  // if no win yet
              } else {
                if(wintype == 1 && wincoord == row) printf("==O===O=="); // if win on row, add equal signs
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
}



void clear_board(void) {
  for(row = 0; row < 3; row++) {
    for(col = 0; col < 3; col++) {
      ttt[row][col] = ' ';
    }
  }
}



void print_array(void) {
  for(row = 0; row < 3; row++) {
    for(col = 0; col < 3; col++) {
      printf("%c (%d, %d) , ", ttt[row][col], row, col);
    }
  }
}



void place_sign(int position) {
  int x;
  int y;

  switch(position) {
    case 1: x = 0; y = 0; break;
    case 2: x = 0; y = 1; break;
    case 3: x = 0; y = 2; break;
    case 4: x = 1; y = 0; break;
    case 5: x = 1; y = 1; break;
    case 6: x = 1; y = 2; break;
    case 7: x = 2; y = 0; break;
    case 8: x = 2; y = 1; break;
    case 9: x = 2; y = 2; break;
  }
  if(ttt[x][y] == ' ') {
    ttt[x][y] = player;
  }
}



void reassign_player(void) {
  if(player == 'X') player = 'O';
  else player = 'X';
}



int check_if_win(void) {  // returns wintype in tenths and coord number in units


  for(row = 0; row < 3; row++) {
    if(ttt[row][0] != ' ' && ttt[row][0] == ttt[row][1] && ttt[row][1] == ttt[row][2]) {
      return 10 + row;  // wintype 1 is horizontal win
    }
  }
  for(col = 0; col < 3; col++) {
    if(ttt[0][col] != ' ' && ttt[0][col] == ttt[1][col] && ttt[1][col] == ttt[2][col]) {
      return 20 + col;  // wintype 2 is vertical win
    }
  }
  if(ttt[0][0] != ' ' && ttt[0][0] == ttt[1][1] && ttt[1][1] == ttt[2][2]) {
    return 30;  // wintype 3 is backward diagonal (needs no coord)
  }
  if(ttt[0][2] != ' ' && ttt[0][2] == ttt[1][1] && ttt[1][1] == ttt[2][0]) {
    return 40;  // wintype 4 is forward diagonal (needs no coord)
  }
  return 0;
}



int main(void) { 
  int selected;

  printf("Welcome to TicTacToe! X goes first. \n\n");
  clear_board();
  while(check_if_win() == 0) {
    system("cls");
    draw_board_options();
    draw_board(0);
    printf("%c chooses next:  ", player);
    scanf(" %d", &selected);
    place_sign(selected);
    reassign_player();
  }
  system("cls");
  draw_board_options();
  draw_board(check_if_win());
  reassign_player();
  printf("%c wins! \n", player);
  int x = check_if_win();
  printf("%d, %d", x / 10, x - x / 10 * 10);

  return 0;
}



