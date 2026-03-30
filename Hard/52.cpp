#include <iostream>
#include <vector>
using namespace std;

bool isNotUnderAttack(vector<vector<string>>& board, int row, int col){

    int i, j, n;
    n = board.size();
    
    for(i = 0; i < row; i++){
        if (board[i][col] == "Q"){
            return false;
        }
    }

    i = row - 1;
    j = col - 1;

    while (i >= 0 && j >= 0){
        if (board[i][j] == "Q")return false;
        i--;
        j--;
    }

    i = row - 1;
    j = col + 1;

    while (i >= 0 && j < n){
        if (board[i][j] == "Q") return false;
        i--;
        j++;
    }

    return true;
}

void nqueen(int row, vector<vector<string>>& board, vector<vector<string>>& result){
    int n = board.size();

    if (row == n){
        vector<string> temp;
        for (auto &r : board) {
            string rowStr = "";
            for (auto &cell : r) rowStr += cell;
            temp.push_back(rowStr);
        }
        result.push_back(temp);
        return;
    }

    for(int col = 0; col < n; col++){
        if (isNotUnderAttack(board, row, col)){
            board[row][col] = "Q";
            nqueen(row + 1, board, result);
            board[row][col] = ".";
        }
    }
}

int totalnqueen(int n){
        if(n == 2 || n == 3) return 0;
        if(n == 1) return 1;
        
        vector<vector<string>> result;
        vector<vector<string>> board(n, vector<string>(n, "."));

        nqueen(0, board, result);
        return result.size();
}

int main() {

    vector<int> testcases = {1, 2, 3, 4, 5, 6, 7, 8 ,9};

    for (auto& test: testcases){
        cout <<"For N = " << test;
        cout << "\nNo of result: ";
        cout << totalnqueen(test) << "\n";
    }

    return 0;
}