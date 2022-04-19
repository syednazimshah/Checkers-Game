#include <iostream>
using namespace std; 
class Piece {// class to  have info of each piece
  private:
    int name; // its name from 1-12
  int LocationX;// location on board
  int LocationY;
  bool IsKing; // king status of each piece

  public:

    Piece(int y = 1, int x = 1, bool king = 0, int n = 1) { // initializing with a constructor
      name = n;
      LocationX = x;
      LocationY = y;
      IsKing = false;
    }
  void setname(int n) { // setting name for each piece
    name = n;
  }
  int getx() { // getting x position of piece
    return LocationX;
  }
  int gety() {// getting y position of piece
    return LocationY;
  }
  void setx(int x) {// setting x position of piece
    LocationX = x;
  }
  void sety(int y) {// setting y position of piece
    LocationY = y;
  }
  bool kingstatus() { // getting king status of piece
    return IsKing;
  }
  void makeKing(bool king) { // making a piece king
    IsKing = king;
  }
  int getname() { // getting the name of piece
    return name;
  }
};
void Checkers(int board[][8], Piece * red, Piece * blue) { // intializing board and setting the position of each piece and setting them on board as well
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++)
      board[i][j] = 0;
  }
  int counter = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 8; j++) {
      if ((i + j) % 2 == 0) {
        board[i][j] = counter + 1;
        red[counter].makeKing(0);
        red[counter].setx(j);
        red[counter].sety(i);
        red[counter].setname(counter + 1);
        counter++;
      } else;
    }
  }
  counter = 0;
  for (int i = 7; i > 4; i--) {
    for (int j = 0; j < 8; j++) {
      if ((i + j) % 2 == 0) {
        board[i][j] = counter + 101; // adding 100 to differentiate b/w the pieces
        blue[counter].makeKing(0);
        blue[counter].setx(j);
        blue[counter].sety(i);
        blue[counter].setname(counter + 101);
        counter++;
      } else;
    }
  }
}
void DisplayBoard(int board[][8]) { // displaying board 
  for (int i = 7; i >= 0; i--) {
    cout << "\n   +---+---+---+---+---+---+---+---+\n   ";
    for (int j = 0; j <= 8; j++) {
      cout << "|";
      if ((i + j) % 2 == 0 && j < 8) {

        if (board[i][j] > 0) {
          if (board[i][j] > 0 && board[i][j] < 100)
            cout << "A" << board[i][j];
          else if (board[i][j] > 100 && board[i][j] < 120) //Displaying pieces based on the Names placed on the board positions
            cout << "B" << board[i][j] - 100;
          else;
          if ((board[i][j] < 10 && board[i][j] > 0) || (board[i][j] < 110 && board[i][j] > 100)) // displaying spaces in proper format
            cout << " "; 
          else;
        } else
          cout << "///";
      } else
        cout << "   ";
    }
  }
  cout << "\n   +---+---+---+---+---+---+---+---+\n   ";
}
Piece & TakePiece(bool player, Piece * red, Piece * blue) { // asking the user to select a piece
  int choice = 0;
  if (player == 0)
    cout << "\nPlayer A\n ";
  else
    cout << "\nPlayer B\n ";
  cout << "Please Select a Piece: ";
  cin >> choice;
  if (choice > 0 && choice <= 12) {
    if (player == 0)
      return red[choice - 1];
    else
      return blue[choice - 1];
  } else
    cout << "\nPlease Enter a Valid Value:\n";
}
int Takemove(bool playerchoice, Piece * temp) { // asking  the user to select a move
  int choice = 0;

  cout << "\n1.Move Piece Left\n2.Move Piece Right\n3.Jump Piece Left\n4.Jump Piece Right\n5.Jump King Back Left\n6.Jump King Back Right\n7.Move King Back Left\n8.Move King Back Right\n";
  cout << "\nPlease Select a Move: ";
  cin >> choice;
  if (choice > 0 && choice <= 12)
    return choice;
  else
    cout << "\nPlease Select a Valid Move: ";
}
bool ValidateMove(int choice, Piece * temp, bool player, int board[][8]) { // validating any move that a user a selects
  int x = temp->getx();
  int y = temp->gety();
  int name = temp->getname();
  bool isking = temp->kingstatus();
  switch (choice) {
  case 1: //Move Piece Left
    if (player == 1) { //checking move based on player value and wether if the required box on board has empty space or not

      if (board[y - 1][x + 1] == 0 && (y - 1 < 8 && y - 1 >= 0) && (x + 1 < 8 && x + 1 >= 0)) //checking for boundries as well so that Piece cant go outside board
        return true;
      else
        return false;
    } else {

      if (board[y + 1][x - 1] == 0 && (y + 1 < 8 && y + 1 >= 0) && (x - 1 < 8 && x - 1 >= 0))
        return true;
      else
        return false;
    }
    break;
  case 2: //Move Piece Right
    if (player == 1) {

      if (board[y - 1][x - 1] == 0 && (y - 1 < 8 && y - 1 >= 0) && (x - 1 < 8 && x - 1 >= 0))
        return true;
      else
        return false;
    } else {

      if (board[y + 1][x + 1] == 0 && (y + 1 < 8 && y + 1 >= 0) && (x + 1 < 8 && x + 1 >= 0))
        return true;
      else
        return false;
    }
    break;
  case 3://Jump Piece Left
    if (player == 1) {

      if (board[y - 2][x + 2] == 0 && (y - 2 < 8 && y - 2 >= 0) && (x + 2 < 8 && x + 2 >= 0))
        return true;
      else
        return false;
    } else {

      if (board[y + 2][x - 2] == 0 && (y + 2 < 8 && y + 2 >= 0) && (x - 2 < 8 && x - 2 >= 0))
        return true;
      else
        return false;
    }
    break;
  case 4: //Jump Piece Right
    if (player == 1) {

      if (board[y - 2][x - 2] == 0 && (y - 2 < 8 && y - 2 >= 0) && (x - 2 < 8 && x - 2 >= 0))
        return true;
      else
        return false;
    } else {

      if (board[y + 2][x + 2] == 0 && (y + 2 < 8 && y + 2 >= 0) && (x + 2 < 8 && x + 2 >= 0))
        return true;
      else
        return false;
    }
    break;
  case 5: // jump back left 
    if (player == 1) { // checking for king status to perform a backwords move
      if (isking == true && board[y - 2][x - 2] == 0 && (y - 2 < 8 && y - 2 >= 0) && (x - 2 < 8 && x - 2 >= 0))
        return true;
      else
        return false;
    } else {
      if (isking == true && board[y + 2][x + 2] == 0 && (y + 2 < 8 && y + 2 >= 0) && (x + 2 < 8 && x + 2 >= 0))
        return true;
      else
        return false;
    }
    break;
  case 6: //jump back right
    if (player == 1) {
      if (isking == true && board[y - 2][x + 2] == 0 && (y - 2 < 8 && y - 2 >= 0) && (x + 2 < 8 && x + 2 >= 0))
        return true;
      else
        return false;
    } else {
      if (isking == true && board[y + 2][x - 2] == 0 && (y + 2 < 8 && y + 2 >= 0) && (x - 2 < 8 && x - 2 >= 0))
        return true;
      else
        return false;
    }
    break;
  case 7: // move back left
    if (player == 1) {
      if (isking == true && board[y + 1][x + 1] == 0 && (y + 1 < 8 && y >= 0) && (x + 1 < 8 && x + 1 >= 0))
        return true;
      else
        return false;
    } else {
      if (isking == true && board[y - 1][x - 1] == 0 && (y - 1 < 8 && y - 1 >= 0) && (x - 1 < 8 && x - 1 >= 0))
        return true;
      else
        return false;
    }
    break;
  case 8: // move back right
    if (player == 1) {
      if (isking == true && board[y + 1][x - 1] == 0 && (y + 1 < 8 && y + 1 >= 0) && (x - 1 < 8 && x - 1 >= 0))
        return true;
      else
        return false;
    } else {
      if (isking == true && board[y - 1][x + 1] == 0 && (y - 1 < 8 && y - 1 >= 0) && (x + 1 < 8 && x + 1 >= 0))
        return true;
      else
        return false;
    }
    break;
  }
}
bool makemove(int choice, Piece * temp, bool player, int board[][8], Piece * red, Piece * blue) { // making anymove that user has selected when a move is validated
  int x = temp->getx();
  int y = temp->gety();
  int name = temp->getname();
  bool isking = temp->kingstatus();
  switch (choice) {
  case 1: // move left
    if (player == 1) { //making a move based on player value 
      if (y - 1 == 0) { // chacking and crowning king
        temp->makeKing(true);
        cout << "\nKing Crowned";
      }
      board[y - 1][x + 1] = name; //setting new position of piece on board
      board[y][x] = 0; // removing old positions
      temp->setx(x + 1); // setting new positon of piece
      temp->sety(y - 1);
      return false;
    } else {
      if (y + 1 == 7) {
        temp->makeKing(true);
        cout << "\nKing Crowned";
      }
      board[y + 1][x - 1] = name;
      board[y][x] = 0;
      temp->setx(x - 1);
      temp->sety(y + 1);
      return false;
    }
    break;
  case 2: // move right
    if (player == 1) {
      if (y - 1 == 0) {
        temp->makeKing(true);
        cout << "\nKing Crowned";
      }
      board[y - 1][x - 1] = name;
      board[y][x] = 0;
      temp->setx(x - 1);
      temp->sety(y - 1);
      return false;
    } else {
      if (y + 1 == 7) {
        temp->makeKing(true);
        cout << "\nKing Crowned";
      }
      board[y + 1][x + 1] = name;
      board[y][x] = 0;
      temp->setx(x + 1);
      temp->sety(y + 1);
      return false;
    }
    break;
  case 3: // jump left
    if (player == 1) {
      if (y - 2 == 0) {
        temp->makeKing(true);
        cout << "\nKing Crowned";
      }
      board[y - 2][x + 2] = name;
      board[y][x] = 0;
      temp->setx(x + 2);
      temp->sety(y - 2);

      for (int n = 0; n < 12; n++) {
        if (board[y - 1][x + 1] == red[n].getname()) { // checking for enemy piece while making a jump and eliminating it
          board[y - 1][x + 1] = 0; 
          red[n].setname(0);
          return true;
        } else;
      }
      return false;
    } else {
      if (y + 2 == 7) {
        temp->makeKing(true);
        cout << "\nKing Crowned";
      }
      board[y + 2][x - 2] = name;
      board[y][x] = 0;
      temp->setx(x - 2);
      temp->sety(y + 2);

      for (int n = 0; n < 12; n++) {
        if (board[y + 1][x - 1] == blue[n].getname()) {// checking for other enemy piece while making a jump and eliminating it
          board[y + 1][x - 1] = 0;
          blue[n].setname(0);
          return true;
        } else;
      }
      return false;
    }
    break;
  case 4: //jump right
    if (player == 1) {
      if (y - 2 == 0) {
        temp->makeKing(true);
        cout << "\nKing Crowned";
      }
      board[y - 2][x - 2] = name;
      board[y][x] = 0;;
      temp->setx(x - 2);
      temp->sety(y - 2);

      for (int n = 0; n < 12; n++) {
        if (board[y - 1][x - 1] == red[n].getname()) {
          board[y - 1][x - 1] = 0;
          red[n].setname(0);
          return true;
        } else;
      }
      return false;
    } else {
      if (y + 2 == 7) {
        temp->makeKing(true);
        cout << "\nKing Crowned";
      }
      board[y + 2][x + 2] = name;
      board[y][x] = 0;
      temp->setx(x + 2);
      temp->sety(y + 2);

      for (int n = 0; n < 12; n++) {
        if (board[y + 1][x + 1] == blue[n].getname()) {
          board[y + 1][x + 1] = 0;
          blue[n].setname(0);
          return true;
        } else;
      }
      return false;
    }
    break;
  case 5: // jump back left
    if (player == 1) {
      board[y - 2][x - 2] = name;
      board[y][x] = 0;
      temp->setx(x - 2);
      temp->sety(y - 2);

      for (int n = 0; n < 12; n++) {
        if (board[y - 1][x - 1] == red[n].getname()) {
          board[y - 1][x - 1] = 0;
          red[n].setname(0);
          return true;
        } else;
      }
      return false;
    } else {
      board[y + 2][x + 2] = name;
      board[y][x] = 0;
      temp->setx(x + 2);
      temp->sety(y + 2);
      for (int n = 0; n < 12; n++) {
        if (board[y + 1][x + 1] == blue[n].getname()) {
          board[y + 1][x + 1] = 0;
          blue[n].setname(0);
          return true;
        } else;
      }
      return false;
    }
    break;
  case 6: // jump back right
    if (player == 1) {
      board[y - 2][x + 2] = name;
      board[y][x] = 0;
      temp->setx(x + 2);
      temp->sety(y - 2);

      for (int n = 0; n < 12; n++) {
        if (board[y - 1][x + 1] == red[n].getname()) {
          board[y - 1][x + 1] = 0;
          red[n].setname(0);
          return true;
        } else;
      }
      return false;
    } else {
      board[y + 2][x - 2] = name;
      board[y][x] = 0;
      temp->setx(x - 2);
      temp->sety(y + 2);

      for (int n = 0; n < 12; n++) {
        if (board[y + 1][x - 1] == blue[n].getname()) {
          board[y + 1][x - 1] = 0;
          blue[n].setname(0);
          return true;
        } else;
      }
      return false;
    }
    break;
  case 7: // move back left
    if (player == 1) {
      board[y + 1][x + 1] = name;
      board[y][x] = 0;
      temp->setx(x + 1);
      temp->sety(y + 1);
      return false;
    } else {
      board[y - 1][x - 1] = name;
      board[y][x] = 0;
      temp->setx(x - 1);
      temp->sety(y - 1);
      return false;
    }
    break;
  case 8: // move back right
    if (player == 1) {
      board[y + 1][x - 1] = name;
      board[y][x] = 0;;
      temp->setx(x - 1);
      temp->sety(y + 1);
      return false;
    } else {
      board[y - 1][x + 1] = name;
      board[y][x] = 0;
      temp->setx(x + 1);
      temp->sety(y - 1);
      return false;
    }
    break;
  default:
    return false;
  }
}
void PlayGame(int alt, int board[][8], Piece * red, Piece * blue) { // function to handle other functions in specific order to play game
  DisplayBoard(board); // displaying board;
  bool x = alt % 2; // alternating values to alternate players
  Piece * temp = & TakePiece(x, red, blue); // taking piece
  int move = Takemove(x, temp); // taking move

  if (ValidateMove(move, temp, x, board) == true) { // validating move

    if (makemove(move, temp, x, board, red, blue) == true) {//making move
      system("CLS"); // clearing screen ,ofcourse
      cout << "\nEnemy goti down. "; // printing statements on condition
    } else
      system("CLS");

  } else {
    system("CLS");
    cout << "\nInvalid Move"; // if not valid move is selected
  }
}
int main() {
  int board[8][8]; // making a board
  Piece red[12]; // making twelve pieces for each player
  Piece blue[12];
  Checkers(board, red, blue); // initializing board and pieces
  int alt = 0; // alternaing between values
  while (alt >= 0) {
    int bluecounter = 0; // pieces counter for each player
    int redcounter = 0;
    for (int i = 0; i < 12; i++) {
      if (blue[i].getname() != 0) // counting pieces of each player 
        bluecounter++;
      else;
      if (red[i].getname() != 0)
        redcounter++;
      else;
    }
    cout<<"\nPlayer B: "<<bluecounter<<" Pieces Left"; // displaying remaining pieces
    cout<<"\nPlayer A: "<<redcounter<<" Pieces Left";
    PlayGame(alt, board, red, blue); // calling play function to play game
    alt++; // incrementing alternator
    if (bluecounter == 0) {
      cout << "\nPlayer B Wins"; // if remaining pieces go to zero game ends with return 0
      return 0;
    } else if (redcounter == 0) {
      cout << "\nPlayer A Wins";
      return 0;
    } else;
  }
}
