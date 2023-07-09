#include <iostream>
#include <vector>
using namespace std;

const char player = 'X';
const char computer = 'O';


// Function to display the Tic Tac Toe board
void displayBoard(const vector<char>& board) {
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << "---+---+---" << endl;
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << "---+---+---" << endl;
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;
}

// Function to check if a player has won
bool checkWin(const vector<char>& board, char currentPlayer) {
    // Check rows
    for (int i = 0; i <= 6; i += 3) {
        if (board[i] == currentPlayer && board[i + 1] == currentPlayer && board[i + 2] == currentPlayer)
            return true;
    }
    // Check columns
    for (int i = 0; i < 3; ++i) {
        if (board[i] == currentPlayer && board[i + 3] == currentPlayer && board[i + 6] == currentPlayer)
            return true;
    }
    // Check diagonals
    if ((board[0] == currentPlayer && board[4] == currentPlayer && board[8] == currentPlayer) ||
        (board[2] == currentPlayer && board[4] == currentPlayer && board[6] == currentPlayer))
        return true;
    return false;
}

// Function to check if the game is a draw
bool checkDraw(const vector<char>& board) {
    for (int i = 0; i < board.size(); ++i) {
        if (board[i] != player && board[i] != computer)
            return false;
    }
    return true;
}

// Function to evaluate the score of the board
int evaluateBoard(const vector<char>& board) {
    if (checkWin(board, player))
        return -1;
    else if (checkWin(board, computer))
        return 1;
    else
        return 0;
}

// Minimax algorithm function
int minimax(vector<char>& board, int depth, bool isMaximizing) {
    int score = evaluateBoard(board);

    if (score == 1 || score == -1)
        return score;

    if (checkDraw(board))
        return 0;

    if (isMaximizing) {
        int bestScore = -1000;
        for (int i = 0; i < 9; ++i) {
            if (board[i] != player && board[i] != computer) {
                char prevValue = board[i];
                board[i] = computer;
                bestScore = max(bestScore, minimax(board, depth + 1, !isMaximizing));
                board[i] = prevValue;
            }
        }
        return bestScore;
    } else {
        int bestScore = 1000;
        for (int i = 0; i < 9; ++i) {
            if (board[i] != player && board[i] != computer) {
                char prevValue = board[i];
                board[i] = player;
                bestScore = min(bestScore, minimax(board, depth + 1, !isMaximizing));
                board[i] = prevValue;
            }
        }
        return bestScore;
    }
}

// Function to find the best move for the computer
int findBestMove(vector<char>& board) {
    int bestScore = -1000;
    int bestMove = -1;
    for (int i = 0; i < 9; ++i) {
        if (board[i] != player && board[i] != computer) {
            char prevValue = board[i];
            board[i] = computer;
            int moveScore = minimax(board, 0, false);
            board[i] = prevValue;
            if (moveScore > bestScore) {
                bestScore = moveScore;
                bestMove = i;
            }
        }
    }
    return bestMove;
}

// Function for the player's turn
void playerTurn(vector<char>& board) {
    int move;
    cout << "Enter your move (0-8): ";
    cin >> move;
    while (move < 0 || move > 8 || board[move] != ' ') {
        cout << "Invalid move. Enter your move again (0-8): ";
        cin >> move;
    }
    board[move] = player;
}

// Function for the computer's turn
void computerTurn(vector<char>& board) {
    cout << "Computer's turn:" << endl;
    int bestMove = findBestMove(board);
    board[bestMove] = computer;
}

// Main game loop

void playGame_singleplayer() {
    vector<char> board(9, ' ');

    cout << "Tic Tac Toe - Single Player" << endl;
    cout << "Player: " << player << " | Computer: " << computer << endl;

    bool isPlayerTurn = true;
    bool gameEnd = false;

    while (!gameEnd) {
        displayBoard(board);

        if (isPlayerTurn) {
            playerTurn(board);
            if (checkWin(board, player)) {
                displayBoard(board);
                cout << "Congratulations! You won!" << endl;
                gameEnd = true;
            }
        } else {
            computerTurn(board);
            if (checkWin(board, computer)) {
                displayBoard(board);
                cout << "Computer wins!" << endl;
                gameEnd = true;
            }
        }

        if (checkDraw(board)) {
            displayBoard(board);
            cout << "It's a draw!" << endl;
            gameEnd = true;
        }

        isPlayerTurn = !isPlayerTurn;
    }
}













const char player1Marker = 'X';
const char player2Marker = 'O';




// Function to check if the game is a draw
bool checkDraw2(const vector<char>& board) {
    for (int i = 0; i < board.size(); ++i) {
        if (board[i] != player1Marker && board[i] != player2Marker)
            return false;
    }
    return true;
}

// Function for a player's turn
void playerTurn2(vector<char>& board, char currentPlayer) {
    int move;
    cout << "Player " << currentPlayer << "'s turn. Enter your move (0-8): ";
    cin >> move;
    while (move < 0 || move > 8 || board[move] != ' ') {
        cout << "Invalid move. Enter your move again (0-8): ";
        cin >> move;
    }
    board[move] = currentPlayer;
}

// Main game loop
void playGame_doubleplayer() {
    vector<char> board(9, ' ');

    cout << "Tic Tac Toe - Double Player Game " << endl;
    cout << "Player 1: " << player1Marker << " | Player 2: " << player2Marker << endl;

    char currentPlayer = player1Marker;
    bool Endgame = false;

    while (!Endgame) {
        displayBoard(board);

        playerTurn2(board, currentPlayer);
        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            Endgame = true;
        }

        if (checkDraw2(board)) {
            displayBoard(board);
            cout << "It's a draw!" << endl;
            Endgame = true;
        }

        currentPlayer = (currentPlayer == player1Marker) ? player2Marker : player1Marker;
    }
}

void play(){
    int b;
    cout<<"Want to play single player(press 1) or double player(press 2) :";
    cin>>b;
    cout<<endl;
    if(b==1){playGame_singleplayer();}
    else if(b==2){playGame_doubleplayer();}
    else{cout<<"Invalid input..."<<endl;
    play();}
    int c;
    cout<<"Do you want to play again: (0-'No',1-'Yes')";
    cin>>c;
    if(c==0){return;}
    else if(c==1){play();}
    else{cout<<"Invalid Input"<<endl;
    return;}
    
}


// Main function
int main() {
    int a;
    cout<<"Tic Tac Toe - Want to play(1- yes, 0- no) :";        
    cin>>a;
    cout<<endl;
    if(a==0){cout<<"see you later....";}
    else if(a==1){
        play();
        }
    
    else{cout<<"Invalid input..."<<endl;}
    return 0;
}
