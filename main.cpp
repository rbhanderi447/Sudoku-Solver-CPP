#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

// Global variable to keep track of the total nodes (states) searched
long long nodesSearched = 0;

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
    int candidates = 10;
    int bestI = -1;
    int bestJ = -1;

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if (board[i][j] == 0) {
                vector<int> ij = {i, j};
                int k = 0;
                for(int n = 1; n <= 9; n++){
                    if(isSafe(board, ij, n)){
                        k++; // count valid candidates directly
                    }
                }
                if (k < candidates){
                    candidates = k;
                    bestI = i;
                    bestJ = j;
                }
            }
        }
    }
    return {bestI, bestJ};
}

bool engine(int board[9][9]){
    nodesSearched++; // node counter

    if (!isEmpty(board)) return true;

    vector<int> ij = mrv(board);
    
    // Safety check if no valid cell was selected
    if(ij[0] == -1 || ij[1] == -1) return false;

    for(int i = 1; i <= 9; i++){
        if(isSafe(board, ij, i)){
            board[ij[0]][ij[1]] = i;

            if(engine(board)) return true;
            board[ij[0]][ij[1]] = 0; // backtrack
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
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> board[i][j];
        }
    }
    cout << endl;

    // Start timing execution
    auto start = chrono::high_resolution_clock::now();

    bool solved = engine(board);

    // Stop timing execution
    auto stop = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = stop - start;

    if (solved) {
        cout << "SOLUTION" << endl << endl;
        printBoard(board);
    } else {
        cout << "No solution exists." << endl;
    }

    // Output performance metrics
    cout << "\n-----------------------------------" << endl;
    cout << "Nodes searched : " << nodesSearched << endl;
    cout << "Time consumed  : " << duration.count() << " seconds" << endl;
    cout << "-----------------------------------" << endl;

    return 0;
}
