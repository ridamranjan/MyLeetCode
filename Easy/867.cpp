#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> transpose(vector<vector<int>>& matrix){
    vector<vector<int>> tr(matrix[0].size());
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[0].size(); j++){
            tr[j].push_back(matrix[i][j]);
        }
    }
    return tr;
}

void display(const vector<vector<int>>& matrix){
  for(auto& row : matrix){
    for(auto& ele: row){
      cout << ele << "\t";
    }
    cout << "\n";
  }
}

int main(){

  vector<vector<vector<int>>> testcases;

  testcases = {
    {{1,2,3},{4,5,6}},
    {{1,2,3},{4,5,6},{7,8,9}},
    {{1,2,3}},
    {{}}
  };

  for(auto& test: testcases){
    cout << "test case: \n";
    display(test);
    cout << "transpose: \n";
    display(transpose(test));
  }

  return 0;
}