#include <iostream>
#include <vector>
#include <set>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
        set<pair<int,int>> zeros;
        
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(matrix[i][j] == 0)zeros.insert({{i, j}});
            }
        }
        
        for(auto& p: zeros){
            for(int i = 0; i < matrix[p.first].size(); i++ ){
                matrix[p.first][i] = 0;
            }
            for(int i = 0; i < matrix.size(); i++){
                matrix[i][p.second] = 0;
            }
            
        }
}

void display(vector<vector<int>> matrix){
  for(auto& row: matrix){
        for(auto& ele: row){
          cout << ele << "\t";
        }
        cout << endl;
      }
}

int main(){
  
  vector<vector<vector<int>>> testcase = {
    {{0,1,2,0},{3,4,5,2},{1,3,1,5}},
    {{1,1,1},{1,0,1},{1,1,1}}
  };

  for(auto& tc: testcase){
    cout << "Matrix before function: " << endl;
    display(tc);
    setZeroes(tc);
    cout << "Matrix after function: " << endl;
    display(tc);
    cout << "\n\n";
  }

  return 0;
}