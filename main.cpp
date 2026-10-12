#include <iostream>
#include <vector>
using namespace std;



bool isSafe(int board[9][9], vector<int> ij, int dig){
    // checking vertical and horizontal line at the same time
    for(int i = 0; i<9; i++){  
        if((board[i][ij[1]] == dig) || (board[ij[0]][i] == dig)) return false;
    }

    // checking the grid
    int rGrid = (ij[0]/3)*3;
    int cGrid = (ij[1]/3)*3;

    for(int i = rGrid; i <= (rGrid + 2); i++){
        for(int j = cGrid; j <= (cGrid +2); j++){
            if(board[i][j] == dig) return false;
        }
    }

    return true;
}

bool isEmpty(int board[9][9]){
    for(int i = 0; i<9; i++){
        for(int j = 0; j<9; j++){
            if(board[i][j] == 0) return true;
        }
    }
    return false;
}

vector<int> mrv(int board[9][9]){
    int candidates = 9;
    int bestI = 0;
    int bestJ = 0;
    vector<int> ans;

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            vector<int> ij = {i, j};
            int k = 9;
            for(int n = 1; n < 10; n++){
                if((board[i][j] == 0) && !isSafe(board, ij, n)){
                    k--;
                }
            }
            if (k<candidates){
                candidates = k;
                bestI = i;
                bestJ = j;
            }
        }
    }
    ans.push_back(bestI);
    ans.push_back(bestJ);
    return ans;
}

int engine(int board[9][9]){
    if (!isEmpty(board)) return true;
    vector<int> ij = mrv(board);

    if(board[ij[0]][ij[1]] != 0) return engine(board);

    for(int i = 1; i < 10; i++){
        if(isSafe(board, mrv(board), i)){
            board[ij[0]][ij[1]] = i;

            if(engine(board)) return true;
            board[ij[0]][ij[1]] = 0;

        }
    }
    return false;
}

void printBoard(int board[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << "  ";
        }
        cout << endl;
    }
}

int main(){ 
    int board[9][9];
    cout << "ENTER THE PUZZLE HERE !" << endl << endl;
    for(int i = 0;i<9;i++){
        for(int j = 0; j<9; j++){
            cin >> board[i][j];
        }
    }
    cout << endl;

    if (engine(board)) {
        cout << "SOLUTION" << endl << endl;
        printBoard(board);
    } else {
        cout << "No solution exists." << endl;
    }
    return 0;
}
