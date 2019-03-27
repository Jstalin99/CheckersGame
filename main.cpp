/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jorda
 *
 * Created on February 20, 2018, 10:13 PM
 * 
 * Welcome to my consol checkers game made using c++
 */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

char GameBoard[8][8];
int Row = 0;
int ToRow = 0;
int Col = 0;
int ToCol = 0;
int Choice;
char PlayerPiece;
bool LeapMade = false;
int RedPieceCount = 0;
int BlackPieceCount = 0;
char Turn = 'R';


void InitBoard()
{
    BlackPieceCount = 12;
    RedPieceCount = 12;
    
    for (int Col = 0; Col < 8; Col++)//Initializes the Columns in the gameboard array
    {
        for (int Row = 0; Row < 8; Row++)//Initializes the Rows in the gameboard array
        {
            if (((Row + Col) % 2) == 0)
            {
                GameBoard[Row][Col] = '|';//Sets the non-playable spaces to the value of |
            }
            else if (((Row + Col) % 2) == 1 && Row < 3)
            {
                GameBoard[Row][Col] = 'r';//sets the value of the space to a r for red piece
            }
            else if (((Row + Col) % 2) == 1 && Row >= 5)
            {
                GameBoard[Row][Col] = 'b';//sets the value of the space to a b for red piece
            }
            else
            {
                GameBoard[Row][Col] = ' ';//if none of the above is true, the space is blank
            }
        }
    }
}
    
void PrintBoard()
{
cout<<"=========================================================================================" <<endl;
cout<<"     0          1          2          3          4          5          6          7      "<<endl;
cout<<"-----------------------------------------------------------------------------------------"<<endl;                                                                      
cout<<"|          |          |          |          |          |          |          |          |"<<endl;
cout<<"|     "<<GameBoard[0][0]<<"    |     "<<GameBoard[0][1]<<"    |     "<<GameBoard[0][2]<<"    |     "<<GameBoard[0][3]<<"    |     "<<GameBoard[0][4]<<"    |     "<<GameBoard[0][5]<<"    |     "<<GameBoard[0][6]<<"    |     "<<GameBoard[0][7]<<"    |     "<< "0" <<endl;                                                                      
cout<<"|          |          |          |          |          |          |          |          |"<<endl;
cout<<"-----------------------------------------------------------------------------------------"<<endl;                                                                      
cout<<"|          |          |          |          |          |          |          |          |"<<endl;
cout<<"|     "<<GameBoard[1][0]<<"    |     "<<GameBoard[1][1]<<"    |     "<<GameBoard[1][2]<<"    |     "<<GameBoard[1][3]<<"    |     "<<GameBoard[1][4]<<"    |     "<<GameBoard[1][5]<<"    |     "<<GameBoard[1][6]<<"    |     "<<GameBoard[1][7]<<"    |     "<< "1" <<endl;                                                                      
cout<<"|          |          |          |          |          |          |          |          |"<<endl;
cout<<"-----------------------------------------------------------------------------------------"<<endl;                                                                      
cout<<"|          |          |          |          |          |          |          |          |"<<endl;
cout<<"|     "<<GameBoard[2][0]<<"    |     "<<GameBoard[2][1]<<"    |     "<<GameBoard[2][2]<<"    |     "<<GameBoard[2][3]<<"    |     "<<GameBoard[2][4]<<"    |     "<<GameBoard[2][5]<<"    |     "<<GameBoard[2][6]<<"    |     "<<GameBoard[2][7]<<"    |     "<< "2" <<endl;                                                                      
cout<<"|          |          |          |          |          |          |          |          |"<<endl;
cout<<"-----------------------------------------------------------------------------------------"<<endl;                                                                      
cout<<"|          |          |          |          |          |          |          |          |"<<endl;
cout<<"|     "<<GameBoard[3][0]<<"    |     "<<GameBoard[3][1]<<"    |     "<<GameBoard[3][2]<<"    |     "<<GameBoard[3][3]<<"    |     "<<GameBoard[3][4]<<"    |     "<<GameBoard[3][5]<<"    |     "<<GameBoard[3][6]<<"    |     "<<GameBoard[3][7]<<"    |     "<< "3" <<endl;                                                                    
cout<<"|          |          |          |          |          |          |          |          |"<<endl;
cout<<"-----------------------------------------------------------------------------------------"<<endl;                                                                      
cout<<"|          |          |          |          |          |          |          |          |"<<endl;
cout<<"|     "<<GameBoard[4][0]<<"    |     "<<GameBoard[4][1]<<"    |     "<<GameBoard[4][2]<<"    |     "<<GameBoard[4][3]<<"    |     "<<GameBoard[4][4]<<"    |     "<<GameBoard[4][5]<<"    |     "<<GameBoard[4][6]<<"    |     "<<GameBoard[4][7]<<"    |     "<< "4" <<endl;                                                                      
cout<<"|          |          |          |          |          |          |          |          |"<<endl;
cout<<"-----------------------------------------------------------------------------------------"<<endl;                                                                  
cout<<"|          |          |          |          |          |          |          |          |"<<endl;
cout<<"|     "<<GameBoard[5][0]<<"    |     "<<GameBoard[5][1]<<"    |     "<<GameBoard[5][2]<<"    |     "<<GameBoard[5][3]<<"    |     "<<GameBoard[5][4]<<"    |     "<<GameBoard[5][5]<<"    |     "<<GameBoard[5][6]<<"    |     "<<GameBoard[5][7]<<"    |     "<< "5" <<endl;                                                                      
cout<<"|          |          |          |          |          |          |          |          |"<<endl;
cout<<"-----------------------------------------------------------------------------------------"<<endl;                                                                      
cout<<"|          |          |          |          |          |          |          |          |"<<endl;
cout<<"|     "<<GameBoard[6][0]<<"    |     "<<GameBoard[6][1]<<"    |     "<<GameBoard[6][2]<<"    |     "<<GameBoard[6][3]<<"    |     "<<GameBoard[6][4]<<"    |     "<<GameBoard[6][5]<<"    |     "<<GameBoard[6][6]<<"    |     "<<GameBoard[6][7]<<"    |     "<< "6" <<endl;                                                                      
cout<<"|          |          |          |          |          |          |          |          |"<<endl;
cout<<"-----------------------------------------------------------------------------------------"<<endl;                                                                      
cout<<"|          |          |          |          |          |          |          |          |"<<endl;
cout<<"|     "<<GameBoard[7][0]<<"    |     "<<GameBoard[7][1]<<"    |     "<<GameBoard[7][2]<<"    |     "<<GameBoard[7][3]<<"    |     "<<GameBoard[7][4]<<"    |     "<<GameBoard[7][5]<<"    |     "<<GameBoard[7][6]<<"    |     "<<GameBoard[7][7]<<"    |     "<< "7" <<endl;                                                                      
cout<<"|          |          |          |          |          |          |          |          |"<<endl;
cout<<"-----------------------------------------------------------------------------------------"<<endl;
cout<<"     0          1          2          3          4          5          6          7      "<<endl;
cout<<"=========================================================================================" <<endl;
}

bool Input()
{
    string TempAns;
    
    cout<<"It is "<<Turn<<"'s turn"<<endl;        
    cout<<"What piece would you like to move?"<<endl;
    cout<<"If you would like to exit the game, type \"quit\""<<endl;
    cout<< "Row"<<endl; 
    cin>>TempAns;
    
    if("quit" == TempAns)//This takes user input and checks to make sure player is not trying to quit out of the game, if not, it returns the entered integer value
    {
        return true;
    }
    Row = atoi(TempAns.c_str());

    cout<< "Column"<<endl;
    cin>>Col;
    
    while (Row < 0 || Row > 7 || Col < 0 || Col > 7)//Makes sure specified values are within the legal limits of the array
    {
        cout<<"The specified piece is invalid."<<endl;
        cout<<"What piece would you like to move?"<<endl;
        cout<< "Row"<<endl; 
        cin>>Row;
        cout<< "Column"<<endl;
        cin>>Col;
    }
    
    cout<<"Where would you like to place your piece?"<<endl;
    cout<< "Row"<<endl; 
    cin>>ToRow;
    cout<< "Column"<<endl;
    cin>>ToCol;
    
    while (ToRow < 0 || ToRow > 7 || ToCol < 0 || ToCol > 7)//Makes sure specified values are within the legal limits of the array
    {
        cout<<"The specified space is outside of the game board."<<endl;
        cout<<"Where would you like to place your piece?"<<endl;
        cout<< "Row"<<endl; 
        cin>>ToRow;
        cout<< "Column"<<endl;
        cin>>ToCol;
    }
    return false;
}

void Move()
{
    
    GameBoard[ToRow][ToCol] = GameBoard[Row][Col];//Completes the actual move for the specified piece
    GameBoard[Row][Col] = ' ';
    
    if(true == LeapMade)
    {
        int TempRow;
        int TempCol;
        TempRow = (Row + ToRow) / 2;
        TempCol = (Col + ToCol) / 2;
        
        if ('r' == GameBoard[TempRow][TempCol] || 'R' == GameBoard[TempRow][TempCol])//Removes value of 1 from RedPieceCount to track how many red pieces remain
        {
            RedPieceCount = RedPieceCount - 1;
        }
        if ('b' == GameBoard[TempRow][TempCol] || 'B' == GameBoard[TempRow][TempCol])//Removes value of 1 from BlackPieceCount to track how many black pieces remain
        {
            BlackPieceCount = BlackPieceCount - 1;
        }
        
        GameBoard[TempRow][TempCol] = ' ';// leap function
        LeapMade = false;
    }

    cout<<"Total Black Pieces Remaining = "<<BlackPieceCount<<endl;
    cout<<"Total Red Pieces Remaining = "<<RedPieceCount<<endl;
}

bool CheckMove()
{
    if(GameBoard[ToRow][ToCol] != ' ')//Checks to make sure player piece is being moved to an open space
    {
        return false;
    }
    
    if(GameBoard[Row][Col] == ' ')//Checks to make sure player piece is being selected
    {
        return false;
    }
    else if(GameBoard[Row][Col] == '|')//Makes sure player is not trying to move a non-movable piece  
    {
        return false;
    }
    
    if(Turn == 'R')//Ensures only red piece is being selected during red players turn
    {
        if(GameBoard[Row][Col] == 'b' ||GameBoard[Row][Col] == 'B')
        {
            return false;
        }
    }
    else if(Turn == 'B')//Ensures only black piece is being selected during black players turn
    {
        if(GameBoard[Row][Col] == 'r' ||GameBoard[Row][Col] == 'R')
        {
            return false;
        }
    }
    
    if(ToRow > Row)//Checks to make sure piece is being moved down the game board, or positively through the array
    {
        if(GameBoard[Row][Col] == 'r' || GameBoard[Row][Col] == 'R' || GameBoard[Row][Col] == 'B' )//only allows these pieces to move in this direction
        {
            if(ToRow > Row + 1 && ToCol > Col + 1)//First leap function for red piece to leap black piece
            {
                if(GameBoard[Row + 1][Col + 1] != ' ')//Checks to make sure space being jumped contains a value
                {
                    if(GameBoard[Row + 1][Col + 1] != GameBoard[Row][Col])
                    {
                        LeapMade = true;
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            
            else if(ToRow > Row + 1 && ToCol < Col - 1)//Second leap function for red piece to leap black piece
            {   
                if(GameBoard[Row + 1][Col - 1] != ' ')//Checks to make sure space being jumped contains a value
                {
                    if(GameBoard[Row + 1][Col - 1] != GameBoard[Row][Col])
                    {
                        LeapMade = true;
                        return true;
                    }
                    else 
                    {
                        return false;
                    }
                }
            }
            else
            {
                return true;
            }
        }
        else
        {
            return false;  
        }
    }
    else if(ToRow < Row)
    {
        if(GameBoard[Row][Col] == 'b' || GameBoard[Row][Col] == 'R' || GameBoard[Row][Col] == 'B')//only allows these pieces to move in this direction
        {
            if(ToRow < Row - 1 && ToCol > Col + 1)//First leap function for black piece to leap red piece
            {   
                if(GameBoard[Row - 1][Col + 1] != ' ')//Checks to make sure space being jumped contains a value
                {
                    if(GameBoard[Row - 1][Col + 1] != GameBoard[Row][Col])
                    {
                        LeapMade = true;
                        return true;
                    }
                    else 
                    {
                        return false;
                    }
                }
            }

            else if(ToRow < Row - 1 && ToCol < Col - 1)//Second leap function for black piece to leap red piece
            {   
                if(GameBoard[Row - 1][Col - 1] != ' ')//Checks to make sure space being jumped contains a value
                {
                    if(GameBoard[Row - 1][Col - 1] != GameBoard[Row][Col])
                    {
                        LeapMade = true;
                        return true;
                    }
                }
                else 
                {
                    return false;
                }
            }
            else
            {
                return true;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

void KingPiece()
{
    for (int x = 0; x < 8; x++)//Creates a red king when piece reaches bottom of the array
    {
        if(GameBoard[7][x] == 'r')
        {
            GameBoard[7][x] = 'R';
        }
    }
    
    for(int x = 0; x < 8; x++)//Creates black king when piece reaches top of the array
    {
        if (GameBoard[0][x] == 'b')
        {
            GameBoard[0][x] = 'B';
        }
    }
}

void Rules()
{
    cout<<"1 - A player wins the game when the opponent cannot make a move. In most cases, this is because all of the opponent's pieces have been captured,"<<endl<<"    but it could also be because all of his pieces are blocked in."<<endl;
    cout<<"2 - Moves are allowed only on the squares which do not have a |, so pieces always move diagonally. Single pieces are always limited to forward moves (toward the opponent)."<<endl;
    cout<<"3 - A piece making a non-capturing move (not involving a jump) may move only one square."<<endl;
    cout<<"4 - A piece making a capturing move (a jump) leaps over one of the opponent's pieces, landing in a straight diagonal line on the other side."<<endl<< "    Only one piece may be captured in a single jump; however, multiple jumps are allowed during a single turn."<<endl;
    cout<<"5 - When a piece is captured, it is removed from the board."<<endl;
    cout<<"6 - When a piece reaches the furthest row from the player who controls that piece, it is crowned and becomes a king."<<endl<< "    The lowercase letter than becomes an uppercase letter to distinguish the king from a normal piece."<<endl;
    cout<<"7 - Kings are limited to moving diagonally but may move both forward and backward. (Remember that single pieces, i.e. non-kings, are always limited to forward moves.)"<<endl;
}
void Menu()
{
    cout<<"Welcome to my Checkers Game!"<<endl;
    cout<<"Please select from one of the following options"<<endl;
    cout<<"1 - Play Game"<<endl;
    cout<<"2 - Read Rules"<<endl;
    cout<<"3 - Exit Game"<<endl;
    cin>>Choice;
}

int main(int argc, char** argv) 
{
    Menu();
    
    while(Choice != 3)
    {
        if(Choice == 1)
        {
            InitBoard();

            while(RedPieceCount > 0 && BlackPieceCount > 0)
            {
                PrintBoard();//calls print board function to run
                
                if('R' == Turn)//if the turn is 'R', this code will run
                {
                    if(Input() == false)
                    {
                        if(CheckMove() == true)
                        {
                            Move();
                            KingPiece();
                            Turn = 'B';
                        }
                    }
                    else
                    {
                        Menu();
                        break;
                    }
                }
                else if('B' == Turn)//if the turn is 'B', this code will run
                {
                    if(Input() == false)
                    {
                        if(CheckMove() == true)
                        {
                            Move();
                            KingPiece();
                            Turn = 'R';
                        }
                    }
                    else
                    {
                        Menu();
                        break;
                    }
                }
            }
        }
        else if(Choice == 2)
        {
            int ReturnToMenu;
            
            Rules();
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<"Would you like to return to the menu?"<<endl;
            cout<<"1 - Yes"<<endl;
            cout<<"2 - No"<<endl;
            cin>>ReturnToMenu;
            
            if (ReturnToMenu == 1)
            {
                Menu();
            }
            else
            {
                Rules();
            }
        }
    }
    return 0;
}



