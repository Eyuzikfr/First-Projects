#include <iostream>
#include <stdlib.h>
using namespace std;

int board(char*);
int player1(char*);
int player2(char*);
int winchecker(char*, int);

int main()
{
    //variable declaration
    char place[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '\0'};
    int turn_counter = 1;
    int player_choice;

    // welcome, declaration of players, and initial board shwowing place indices
    cout << "<<WELCOME TO TIC TAC TOE>>" << endl << endl;
    cout << "Player 1: X\nPlayer 2: O\n" << endl << endl;

    board(place);
    cout << endl;

    for(int i=0; i < 9; i++){
        if(turn_counter % 2 == 1){
            cout << "Player 1: " << endl;
            
            // initiating the move and checking if the move has already been made for player 1
            while(1)
            {
                player_choice = player1(place);
                if(place[player_choice] != 'X' && place[player_choice] != 'O')
                {
                    place[player_choice] = 'X';
                    cout << endl;
                    board(place);
                    cout << endl;
                    break;
                }
                else
                {
                    cout << "Spot already taken, hero." << endl;
                    cout << endl;
                }
            }

            winchecker(place, turn_counter % 2);

            ++turn_counter;
        }
        else if(turn_counter % 2 == 0){

            // initiating the move and checking if the move has already been made for player 2
            while(1)
            {
            cout << "Player 2: " << endl;
            player_choice = player2(place);
                if(place[player_choice] != 'X' && place[player_choice] != 'O')
                {
                    place[player_choice] = 'O';
                    cout << endl;
                    board(place);
                    cout << endl;
                    break;
                }
                else
                {
                    cout << "Spot already taken, hero." << endl;
                    cout << endl;
                }
            }

            winchecker(place, turn_counter % 2);

            ++turn_counter;
        }
    }

    return 0;
}

int board(char* p)
{
    cout << " " << p[0] << " | " << p[1] << " | " << p[2] << " " << endl;
    cout << "___|___|___" << endl;
    cout << " " << p[3] << " | " << p[4] << " | " << p[5] << " " << endl;
    cout << "___|___|___" << endl;
    cout << " " << p[6] << " | " << p[7] << " | " << p[8] << " " << endl;
    cout << "   |   |   " << endl;
    return 0;
}

int player1(char* p)
{
    int player1_choice;

    while(1){
        cin >> player1_choice;
        if(player1_choice > 0 && player1_choice <= 9)
        {
            break;
        }
        else
        {
            cout << "Enter a valid move, Player 1." << endl;
        }
    }

    return player1_choice-1;
}

int player2(char* p)
{
    int player2_choice;

    while(1){
        cin >> player2_choice;
        if(player2_choice > 0 && player2_choice <= 9)
        {
            break;
        }
        else
        {
            cout << "Enter a valid move, Player 1." << endl;
        }
    }
    
    return player2_choice-1;
}

int winchecker(char* p, int player)
{
    // win checking for player 1
    if(player != 0){
        
        // horizontal win
        if( (p[0] == 'X' && p[1] == 'X' && p[2] == 'X') || (p[3] == 'X' && p[4] == 'X' && p[5] == 'X') || (p[6] == 'X' && p[7] == 'X' && p[8] == 'X') )
        {
            cout << "Player 1 Wins!" << endl;
            system("pause");
            exit(0);
        }
        
        // vertical win
        else if( (p[0] == 'X' && p[3] == 'X' && p[6] == 'X') || (p[1] == 'X' && p[4] == 'X' && p[7] == 'X') || (p[2] == 'X' && p[5] == 'X' && p[8] == 'X') )
        {
            cout << "Player 1 Wins!" << endl;
            system("pause");
            exit(0);
        }

        // diagonal checking
        else if(  (p[0] == 'X' && p[4] == 'X' && p[8] == 'X') || (p[2] == 'X' && p[4] == 'X' && p[6] == 'X') )
        {
            cout << "Player 1 Wins!" << endl;
            system("pause");
            exit(0);
            
        }
    }
    // win checking for player 2
    else if(player == 0){
        
        // horizontal win
        if( (p[0] == 'O' && p[1] == 'O' && p[2] == 'O') || (p[3] == 'O' && p[4] == 'O' && p[5] == 'O') || (p[6] == 'O' && p[7] == 'O' && p[8] == 'O') )
        {
            cout << "Player 2 Wins!" << endl;
            system("pause");
            exit(0);
        }
        
        // vertical win
        else if( (p[0] == 'O' && p[3] == 'O' && p[6] == 'O') || (p[1] == 'O' && p[4] == 'O' && p[7] == 'O') || (p[2] == 'O' && p[5] == 'O' && p[8] == 'O') )
        {
            cout << "Player 2 Wins!" << endl;
            system("pause");
            exit(0);
        }

        // diagonal checking
        else if(  (p[0] == 'O' && p[4] == 'O' && p[8] == 'O') || (p[2] == 'O' && p[4] == 'O' && p[6] == 'O') )
        {
            cout << "Player 2 Wins!" << endl;
            system("pause");
            exit(0);
        }
    }

    return 0;
}
