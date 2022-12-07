#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char papan[3][3];
const char Player_1 = 'X';
const char Player_2 = 'O';
void ResetBoard();
void PrintBoard();
int CheckFreeSpaces();
void PlayerMove();
void PlayerMove2();
void ComputerMove();
void HardComputerMove();
void HardComputerMove1();
char CheckWinner();
void printWinner(char);
int turn_tracker();
int main(){
    int mode, diff;
    char playagain[1];
    char winner = ' ';
    ResetBoard();
    printf("TIC TAC TOE!\n");
    printf("Enter 1 to play against bot, 2 to play against other player, or 3 to see a bot vs bot match!\n");
    scanf("%d", &mode);
    if(mode == 1){
        printf("Choose the bot difficulty!\n");
        printf("1: Normal\n");
        printf("2: Impossible to win!\n");
        scanf("%d", &diff);
        if(diff == 1){
            while(winner == ' ' && CheckFreeSpaces() != 0){
            PrintBoard();
            printf("Turn %d\n", turn_tracker());
            PlayerMove();
            winner = CheckWinner();
            if(winner != ' ' || CheckFreeSpaces() == 0){
                break;
            }
            PrintBoard();
            printf("Turn %d\n", turn_tracker());
            printf("Bot's turn: \n");
            ComputerMove();
            winner = CheckWinner();
            if(winner != ' ' || CheckFreeSpaces() == 0){
            break;
                }
            }
        }
        else if (diff == 2){
            while(winner == ' ' && CheckFreeSpaces() != 0){
            PrintBoard();
            printf("Turn %d\n", turn_tracker());
            PlayerMove();
            winner = CheckWinner();
            if(winner != ' ' || CheckFreeSpaces() == 0){
                break;
            }
            PrintBoard();
            printf("Turn %d\n", turn_tracker());
            printf("Bot's turn: \n");
            HardComputerMove();
            winner = CheckWinner();
            if(winner != ' ' || CheckFreeSpaces() == 0){
            break;
                }
            }
        }
    }
    else if(mode == 2){
            while(winner == ' ' && CheckFreeSpaces() != 0){
            PrintBoard();
            printf("Turn %d\n", turn_tracker());
            PlayerMove();
            winner = CheckWinner();
            if(winner != ' ' || CheckFreeSpaces() == 0){
                break;
            }
            PrintBoard();
            printf("Turn %d\n", turn_tracker());
            PlayerMove2();
            winner = CheckWinner();
            if(winner != ' ' || CheckFreeSpaces() == 0){
            break;
                }
            }
    }
    else if(mode == 3){
            while(winner == ' ' && CheckFreeSpaces() != 0){
            PrintBoard();
            printf("Turn %d\n", turn_tracker());
            printf("Bot 1:\n");
            HardComputerMove1();
            //ComputerMove();
            winner = CheckWinner();
            if(winner != ' ' || CheckFreeSpaces() == 0){
                break;
            }
            PrintBoard();
            printf("Turn %d\n", turn_tracker());
            printf("Bot 2:\n");
            HardComputerMove();
            winner = CheckWinner();
            if(winner != ' ' || CheckFreeSpaces() == 0){
            break;
                }
            }
    }
    else{
        printf("Invalid! please enter 1, 2, or 3!\n");
        main();
    }
    PrintBoard();
    printWinner(winner);
    printf("\nGame Over! Do you want to play again?(Y/N):\n");
    scanf(" %c", &playagain[0]);
    if(playagain[0] == 'Y'){
        main();
    }
    else{
        printf("Thanks for playing!\n");
        printf("This program is made by Nehemy Davis Suryanto\n");
        return 0;
    }
}

void ResetBoard(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            papan[i][j] = ' ';
        }
    }
}

void PrintBoard(){
    printf(" %c | %c | %c ", papan[0][0], papan[0][1], papan[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", papan[1][0], papan[1][1], papan[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c \n", papan[2][0], papan[2][1], papan[2][2]);
}

int CheckFreeSpaces(){
    int freespaces = 9;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(papan[i][j] != ' '){
                freespaces--;
            }
        }
    }
    return freespaces;
}

int turn_tracker(){
    int turn = 1;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(papan[i][j] != ' '){
                turn++;
            }
        }
    }
    return turn;
}

void PlayerMove(){
    int x, y;
    do
    {
        printf("Giliran Pemain 1:\n");
        scanf("%d %d", &x, &y);

        if(papan[x][y] != ' '){
            printf("Invalid Move\n");
        }
        else{
            papan[x][y] = Player_1;
            break;
        }
    } while(papan[x][y] != ' ');
}

void PlayerMove2(){
    int x, y;
    do
    {
        printf("Giliran Pemain 2:\n");
        scanf("%d %d", &x, &y);

        if(papan[x][y] != ' '){
            printf("Invalid Move\n");
        }
        else{
            papan[x][y] = Player_2;
            break;
        }
    } while(papan[x][y] != ' ');
}

void ComputerMove(){
    srand(time(0));
    int x, y;

    if(CheckFreeSpaces() > 0){
        do
        {
            x = rand()%3;
            y = rand()%3;
        } while(papan[x][y] != ' ');

        papan[x][y] = Player_2;
    }
    else{
        printWinner(' ');
    }
}

void HardComputerMove(){
    if(CheckFreeSpaces() > 0){
        //Bot first move always goes to middle if available 
        if(turn_tracker() == 2 && papan[1][1] == ' '){
            papan[1][1] = Player_2;
            return;
        }
        //if middle doesn't available then goes to one of the available corners
        else if(turn_tracker() == 2 && papan[1][1] != ' ' && papan[0][0] == ' '){
            papan[0][0] = Player_2;
            return;
        }
        else if(turn_tracker() == 2 && papan[1][1] != ' ' && papan[0][0] != ' ' && papan[0][2] == ' '){
            papan[0][2] = Player_2;
            return;
        }
        else if(turn_tracker() == 2 && papan[1][1] != ' ' && papan[0][0] != ' ' && papan[0][2] != ' ' && papan[2][0] == ' '){
            papan[2][0] = Player_2;
            return;
        }
        else if(turn_tracker() == 2 && papan[1][1] != ' ' && papan[0][0] != ' ' && papan[0][2] != ' ' && papan[2][0] != ' ' && papan[2][2] == ' '){
            papan[2][2] = Player_2;
            return;
        }

        //Scanning the board to see any winning move
        //check row
        for(int i=0;i<3;i++){
            if(papan[i][0] == papan[i][1] && papan[i][0] == Player_2  && papan[i][2] == ' '){
                papan[i][2] = Player_2;
                return;
            }
            else if(papan[i][0] == papan[i][2] && papan[i][0] == Player_2 && papan[i][1] == ' '){
                papan[i][1] = Player_2;
                return;
            }
            else if(papan[i][2] == papan[i][1] && papan[i][1] == Player_2 && papan[i][0] == ' '){
                papan[i][0] = Player_2;
                return;
            }
        }
        //check column
        for(int i=0;i<3;i++){
            if(papan[0][i] == papan[1][i] && papan[0][i] == Player_2 && papan[2][i] == ' '){
                papan[2][i] = Player_2;
                return;
            }
            else if(papan[0][i] == papan[2][i] && papan[0][i] == Player_2 && papan[1][i] == ' '){
                papan[1][i] = Player_2;
                return;
            }
            else if(papan[2][i] == papan[1][i] && papan[1][i] == Player_2  && papan[0][i] == ' '){
                papan[0][i] = Player_2;
                return;
            }
        }
        //check diagonal
        if(papan[0][0] == papan[1][1] && papan[0][0] == Player_2 && papan[2][2] == ' '){
            papan[2][2] = Player_2;
            return;
        }
        else if(papan[0][0] == papan[2][2] && papan[0][0] == Player_2  && papan[1][1] == ' '){
            papan[1][1] = Player_2;
            return;
        }
        else if(papan[1][1] == papan[2][2] && papan[1][1] == Player_2 && papan[0][0] == ' '){
            papan[0][0] = Player_2;
            return;
        }
        else if(papan[0][2] == papan[1][1] && papan[0][2] == Player_2 && papan[2][0] == ' '){
            papan[2][0] = Player_2;
            return;
        }
        else if(papan[0][2] == papan[2][0] && papan[0][2] == Player_2 && papan[1][1] == ' '){
            papan[1][1] = Player_2;
            return;
        }
        else if(papan[2][0] == papan[1][1] && papan[2][0] == Player_2 && papan[0][2] == ' '){
            papan[0][2] = Player_2;
            return;
        }
        //Scanning the board to block any opponent's winning move

        //check row
        for(int i=0;i<3;i++){
            if(papan[i][0] == papan[i][1] && papan[i][0] == Player_1  && papan[i][2] == ' '){
                papan[i][2] = Player_2;
                return;
            }
            else if(papan[i][0] == papan[i][2] && papan[i][0] == Player_1 && papan[i][1] == ' '){
                papan[i][1] = Player_2;
                return;
            }
            else if(papan[i][2] == papan[i][1] && papan[i][1] == Player_1 && papan[i][0] == ' '){
                papan[i][0] = Player_2;
                return;
            }
        }
        //check column
        for(int i=0;i<3;i++){
            if(papan[0][i] == papan[1][i] && papan[0][i] == Player_1 && papan[2][i] == ' '){
                papan[2][i] = Player_2;
                return;
            }
            else if(papan[0][i] == papan[2][i] && papan[0][i] == Player_1 && papan[1][i] == ' '){
                papan[1][i] = Player_2;
                return;
            }
            else if(papan[2][i] == papan[1][i] && papan[1][i] == Player_1  && papan[0][i] == ' '){
                papan[0][i] = Player_2;
                return;
            }
        }
        //check diagonal
        if(papan[0][0] == papan[1][1] && papan[0][0] == Player_1 && papan[2][2] == ' '){
            papan[2][2] = Player_2;
            return;
        }
        else if(papan[0][0] == papan[2][2] && papan[0][0] == Player_1  && papan[1][1] == ' '){
            papan[1][1] = Player_2;
            return;
        }
        else if(papan[1][1] == papan[2][2] && papan[1][1] == Player_1 && papan[0][0] == ' '){
            papan[0][0] = Player_2;
            return;
        }
        else if(papan[0][2] == papan[1][1] && papan[0][2] == Player_1 && papan[2][0] == ' '){
            papan[2][0] = Player_2;
            return;
        }
        else if(papan[0][2] == papan[2][0] && papan[0][2] == Player_1 && papan[1][1] == ' '){
            papan[1][1] = Player_2;
            return;
        }
        else if(papan[2][0] == papan[1][1] && papan[2][0] == Player_1 && papan[0][2] == ' '){
            papan[0][2] = Player_2;
            return;
        }
        //move for some dumb move which doesnt make any win or lose condition which human player can use it for tricks
        if(turn_tracker() == 4 && papan[0][1] == ' ' && ((papan[0][0] == Player_1 && papan[2][2] == Player_1) || (papan[0][2] == Player_1 && papan[2][0] == Player_1))){
            papan[0][1] = Player_2;
            return;
        }
        else if(turn_tracker() == 4 && papan[2][2] == ' ' && papan[1][2] == Player_1 && papan[2][1] == Player_1){
            papan[2][2] = Player_2;
            return;
        }
        else if(turn_tracker() == 4 && papan[2][0] == ' ' && papan[2][1] == Player_1 && papan[0][0] == Player_1){
            papan[2][0] = Player_2;
            return;
        }
        else if(turn_tracker() == 4 && papan[2][2] == ' ' && papan[2][1] == Player_1 && papan[0][2] == Player_1){
            papan[2][2] = Player_2;
            return;
        }
        else if(turn_tracker() == 4 && papan[0][2] == ' ' && papan[1][2] == Player_1 && papan[0][0] == Player_1){
            papan[0][2] = Player_2;
            return;
        }
        else if(turn_tracker() == 4 && papan[2][2] == ' ' && papan[1][2] == Player_1 && papan[2][0] == Player_1){
            papan[2][2] = Player_2;
            return;
        }
        else if(turn_tracker() == 4 && papan[0][2] == ' ' && papan[0][1] == Player_1 && papan[2][2] == Player_1){
            papan[0][2] = Player_2;
            return;
        }
        else if(turn_tracker() == 4 && papan[0][0] == ' ' && papan[0][1] == Player_1 && papan[2][0] == Player_1){
            papan[0][0] = Player_2;
            return;
        }
        else if(turn_tracker() == 4 && papan[0][0] == ' ' && papan[1][0] == Player_1 && papan[0][2] == Player_1){
            papan[0][0] = Player_2;
            return;
        }
        else if(turn_tracker() == 4 && papan[2][0] == ' ' && papan[1][0] == Player_1 && papan[2][2] == Player_1){
            papan[2][0] = Player_2;
            return;
        }
        //other meh move
        else if(papan[0][0] == ' '){
            papan[0][0] = Player_2;
            return;
        }
        else if(papan[0][0] != ' ' && papan[0][2] == ' '){
            papan[0][2] = Player_2;
            return;
        }
        else if(papan[0][0] != ' ' && papan[0][2] != ' ' && papan[2][0] == ' '){
            papan[2][0] = Player_2;
            return;
        }
        else if(papan[0][0] != ' ' && papan[0][2] != ' ' && papan[2][0] != ' ' && papan[2][2] == ' '){
            papan[2][2] = Player_2;
            return;
        }
        else if(papan[0][0] != ' ' && papan[0][2] != ' ' && papan[2][0] != ' ' && papan[0][1] == ' '){
            papan[0][1] = Player_2;
            return;
        }
        else if(papan[0][0] != ' ' && papan[0][2] != ' ' && papan[2][0] != ' ' && papan[0][1] != ' ' && papan[1][0] == ' '){
            papan[1][0] = Player_2;
            return;
        }
        else if(papan[0][0] != ' ' && papan[0][2] != ' ' && papan[2][0] != ' ' && papan[0][1] != ' ' && papan[1][0] != ' ' && papan[1][2] == ' '){
            papan[1][2] = Player_2;
            return;
        }
        else if(papan[0][0] != ' ' && papan[0][2] != ' ' && papan[2][0] != ' ' && papan[0][1] != ' ' && papan[1][0] != ' ' && papan[1][2] != ' ' && papan[2][1] == ' '){
            papan[2][1] = Player_2;
            return;
    }
    else{
        printWinner(' ');
    }
    }
}

void HardComputerMove1(){
    srand(time(0));
    int x, y;

    if(CheckFreeSpaces() > 0){
        //Bot first move always goes to middle if available 
        if(turn_tracker() == 1){
            x = rand()%2 + 1;
            y = rand()%2 + 1;
            papan[x][y] = Player_1;
            return;
        }

        //Scanning the board to see any winning move
        //check row
        for(int i=0;i<3;i++){
            if(papan[i][0] == papan[i][1] && papan[i][0] == Player_1  && papan[i][2] == ' '){
                papan[i][2] = Player_1;
                return;
            }
            else if(papan[i][0] == papan[i][2] && papan[i][0] == Player_1 && papan[i][1] == ' '){
                papan[i][1] = Player_1;
                return;
            }
            else if(papan[i][2] == papan[i][1] && papan[i][1] == Player_1 && papan[i][0] == ' '){
                papan[i][0] = Player_1;
                return;
            }
        }
        //check column
        for(int i=0;i<3;i++){
            if(papan[0][i] == papan[1][i] && papan[0][i] == Player_1 && papan[2][i] == ' '){
                papan[2][i] = Player_1;
                return;
            }
            else if(papan[0][i] == papan[2][i] && papan[0][i] == Player_1 && papan[1][i] == ' '){
                papan[1][i] = Player_1;
                return;
            }
            else if(papan[2][i] == papan[1][i] && papan[1][i] == Player_1  && papan[0][i] == ' '){
                papan[0][i] = Player_1;
                return;
            }
        }
        //check diagonal
        if(papan[0][0] == papan[1][1] && papan[0][0] == Player_1 && papan[2][2] == ' '){
            papan[2][2] = Player_1;
            return;
        }
        else if(papan[0][0] == papan[2][2] && papan[0][0] == Player_1  && papan[1][1] == ' '){
            papan[1][1] = Player_1;
            return;
        }
        else if(papan[1][1] == papan[2][2] && papan[1][1] == Player_1 && papan[0][0] == ' '){
            papan[0][0] = Player_1;
            return;
        }
        else if(papan[0][2] == papan[1][1] && papan[0][2] == Player_1 && papan[2][0] == ' '){
            papan[2][0] = Player_1;
            return;
        }
        else if(papan[0][2] == papan[2][0] && papan[0][2] == Player_1 && papan[1][1] == ' '){
            papan[1][1] = Player_1;
            return;
        }
        else if(papan[2][0] == papan[1][1] && papan[2][0] == Player_1 && papan[0][2] == ' '){
            papan[0][2] = Player_1;
            return;
        }
        //Scanning the board to block any opponent's winning move

        //check row
        for(int i=0;i<3;i++){
            if(papan[i][0] == papan[i][1] && papan[i][0] == Player_2  && papan[i][2] == ' '){
                papan[i][2] = Player_1;
                return;
            }
            else if(papan[i][0] == papan[i][2] && papan[i][0] == Player_2 && papan[i][1] == ' '){
                papan[i][1] = Player_1;
                return;
            }
            else if(papan[i][2] == papan[i][1] && papan[i][1] == Player_2 && papan[i][0] == ' '){
                papan[i][0] = Player_1;
                return;
            }
        }
        //check column
        for(int i=0;i<3;i++){
            if(papan[0][i] == papan[1][i] && papan[0][i] == Player_2 && papan[2][i] == ' '){
                papan[2][i] = Player_1;
                return;
            }
            else if(papan[0][i] == papan[2][i] && papan[0][i] == Player_2 && papan[1][i] == ' '){
                papan[1][i] = Player_1;
                return;
            }
            else if(papan[2][i] == papan[1][i] && papan[1][i] == Player_2  && papan[0][i] == ' '){
                papan[0][i] = Player_1;
                return;
            }
        }
        //check diagonal
        if(papan[0][0] == papan[1][1] && papan[0][0] == Player_2 && papan[2][2] == ' '){
            papan[2][2] = Player_1;
            return;
        }
        else if(papan[0][0] == papan[2][2] && papan[0][0] == Player_2  && papan[1][1] == ' '){
            papan[1][1] = Player_1;
            return;
        }
        else if(papan[1][1] == papan[2][2] && papan[1][1] == Player_2 && papan[0][0] == ' '){
            papan[0][0] = Player_1;
            return;
        }
        else if(papan[0][2] == papan[1][1] && papan[0][2] == Player_2 && papan[2][0] == ' '){
            papan[2][0] = Player_1;
            return;
        }
        else if(papan[0][2] == papan[2][0] && papan[0][2] == Player_2 && papan[1][1] == ' '){
            papan[1][1] = Player_1;
            return;
        }
        else if(papan[2][0] == papan[1][1] && papan[2][0] == Player_2 && papan[0][2] == ' '){
            papan[0][2] = Player_1;
            return;
        }
        else if(papan[0][0] == ' '){
            papan[0][0] = Player_1;
            return;
        }
        else if(papan[0][0] != ' ' && papan[0][2] == ' '){
            papan[0][2] = Player_1;
            return;
        }
        else if(papan[0][0] != ' ' && papan[0][2] != ' ' && papan[2][0] == ' '){
            papan[2][0] = Player_1;
            return;
        }
        else if(papan[0][0] != ' ' && papan[0][2] != ' ' && papan[2][0] != ' ' && papan[2][2] == ' '){
            papan[2][2] = Player_1;
            return;
        }
        else if(papan[0][0] != ' ' && papan[0][2] != ' ' && papan[2][0] != ' ' && papan[0][1] == ' '){
            papan[0][1] = Player_1;
            return;
        }
        else if(papan[0][0] != ' ' && papan[0][2] != ' ' && papan[2][0] != ' ' && papan[0][1] != ' ' && papan[1][0] == ' '){
            papan[1][0] = Player_1;
            return;
        }
        else if(papan[0][0] != ' ' && papan[0][2] != ' ' && papan[2][0] != ' ' && papan[0][1] != ' ' && papan[1][0] != ' ' && papan[1][2] == ' '){
            papan[1][2] = Player_1;
            return;
        }
        else if(papan[0][0] != ' ' && papan[0][2] != ' ' && papan[2][0] != ' ' && papan[0][1] != ' ' && papan[1][0] != ' ' && papan[1][2] != ' ' && papan[2][1] == ' '){
            papan[2][1] = Player_1;
            return;
    }
    else{
        printWinner(' ');
    }
    }
}

char CheckWinner(){
    //check row
    for(int i=0;i<3;i++){
        if(papan[i][0] == papan[i][1] && papan[i][0] == papan[i][2]){
            return papan[i][0];
        }
    }
    //check column
    for(int i=0;i<3;i++){
        if(papan[0][i] == papan[1][i] && papan[0][i] == papan[2][i]){
            return papan[0][i];
        }
    }
    //check diagonal
    if(papan[0][0] == papan[1][1] && papan[0][0] == papan[2][2]){
        return papan[0][0];
    }
    if(papan[0][2] == papan[1][1] && papan[0][2] == papan[2][0]){
        return papan[0][2];
    }
    else{
    return ' ';
    }
}

void printWinner(char winner){
    if(winner == Player_1){
        printf("Player 1 Win!");
    }
    else if(winner == Player_2){
        printf("Player 2 Win!");
    }
    else{
        printf("Draw!");
    }
}