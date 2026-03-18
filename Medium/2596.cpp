#include <iostream>
#include <vector>

using namespace std;

pair<bool, pair<int, int>> isValid(vector<vector<int>> &grid, int r, int c, int next){
  vector<pair<int, int>> moves = {{2, 1}, {-2, 1}, {2, -1}, {-2, -1}, {1, 2}, {-1, 2}, {1, -2}, {-1, -2}};
  int n = grid.size();
  for (auto& move : moves){
    int nx = r + move.first;
    int ny = c + move.second;
    if (nx >= 0 && nx < n && ny >= 0 && ny < n){
      if (grid[nx][ny] == next){
        return {true, {nx, ny}};
      }
    }
  }
  return {false, {r, c}};
}

bool checkValidGrid(vector<vector<int>> &grid){
  if (grid[0][0] != 0){
    return false;
  }
  int r = 0, c = 0;
  int n = grid.size();
  for (int i = 1; i < n * n; i++){
    pair<bool, pair<int, int>> temp = isValid(grid, r, c, i);
    if (!temp.first)return false;
    r = temp.second.first;
    c = temp.second.second;
  }
  return true;
}

int main(){
  vector<vector<vector<int>>> testcases = {
      // 1. Minimum valid
      {{0}},

      // 2. Minimum invalid
      {{1}},

      // 3. 2x2 invalid
      {{0, 1},
       {2, 3}},

      // 4. Given invalid
      {{8, 3, 6},
       {5, 0, 1},
       {2, 7, 4}},

      // 5. 3x3 (always invalid)
      {{0, 3, 6},
       {5, 8, 1},
       {2, 7, 4}},

      // 6. InValid 5x5 knight tour
      {{0, 3, 16, 21, 10},
       {17, 22, 11, 4, 15},
       {12, 1, 8, 9, 20},
       {23, 18, 5, 14, 7},
       {2, 13, 24, 19, 6}},

      // 7. Invalid (0 not at start)
      {{1, 3, 16, 21, 10},
       {17, 22, 11, 4, 15},
       {12, 0, 8, 9, 20},
       {23, 18, 5, 14, 7},
       {2, 13, 24, 19, 6}},

      // 8. Duplicate value
      {{0, 1, 2},
       {3, 4, 5},
       {6, 7, 7}},

      // 9. Missing value
      {{0, 1, 2},
       {3, 4, 5},
       {6, 7, 9}},

      // 10. Slightly wrong 5x5
      {{0, 3, 16, 21, 10},
       {17, 22, 11, 4, 15},
       {12, 1, 8, 9, 20},
       {23, 18, 5, 14, 7},
       {2, 13, 19, 24, 6}},

      //11. Valid 5X5
      {{0,11,16,5,20},
      {17,4,19,10,15},
      {12,1,8,21,6},
      {3,18,23,14,9},
      {24,13,2,7,22}}
  };

  for (auto &grid : testcases){
    cout << "Grid:\n";
    for (auto &row : grid){
      for (auto &val : row){
        cout << val << " ";
      }
      cout << endl;
    }

    cout << "Returns: " << (checkValidGrid(grid) ? "true" : "false") << endl;
    cout << "----------------------\n";
  }

  return 0;
}