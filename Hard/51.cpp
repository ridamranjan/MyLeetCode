#include <iostream>
#include <vector>
using namespace std;

bool isNotUnderAttack(vector<vector<string>> &board, int row, int col, int n) {
    
    for (int i = 0; i < row; i++) {
        if (board[i][col] == "Q") return false;
    }

    
    int i = row - 1, j = col - 1;
    while (i >= 0 && j >= 0) {
        if (board[i][j] == "Q") return false;
        i--; j--;
    }

    
    i = row - 1, j = col + 1;
    while (i >= 0 && j < n) {
        if (board[i][j] == "Q") return false;
        i--; j++;
    }

    return true;
}

void nqueen(int row, int n, vector<vector<string>> &board, vector<vector<string>> &result) {
    if (row == n) {
        vector<string> temp;
        for (auto &r : board) {
            string rowStr = "";
            for (auto &cell : r) rowStr += cell;
            temp.push_back(rowStr);
        }
        result.push_back(temp);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isNotUnderAttack(board, row, col, n)) {
            board[row][col] = "Q";
            nqueen(row + 1, n, board, result);
            board[row][col] = "."; 
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    if (n == 2 || n == 3) return {};
    if (n == 1) return {{"Q"}};

    vector<vector<string>> result;
    vector<vector<string>> board(n, vector<string>(n, "."));

    nqueen(0, n, board, result);
    return result;
}

int main(){

  vector<int> testcases = {1, 2, 3, 4, 5, 6, 7, 8 ,9};

for (int test : testcases) {
    cout << "For n = " << test << " :\n";

    vector<vector<string>> result = solveNQueens(test);

    for (auto &board : result) {
        cout << "Solution:\n";
        for (auto &row : board) {
            for (char c : row)cout << (c == '.' ? "_" : "Q") << "\t";
            cout << "\n";
        }
        cout << "\n";
    }
}

  return 0;
}