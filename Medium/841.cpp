#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool canVisitAllRooms(vector<vector<int>>& rooms) {
    vector<int> keys = {0};
    set<int> visited = {0};

    while(!keys.empty()){
        int key = keys.back();
        keys.pop_back();

        for(auto& i : rooms[key]){
            if(visited.find(i) != visited.end())continue;
            visited.insert(i);
            keys.push_back(i);
        }
    }

    return visited.size() == rooms.size();
}

int main(void){

	vector<vector<vector<int>>> testcases = {
		{{1},{2},{3},{}},
		{{1,3},{3,0,1},{2},{0}},
		{{2},{},{1}}
	};

	for(auto& test : testcases){
		cout << "TestCase : \n";
		for(auto& room: test){
			if(room.empty()) cout << "NULL";
			else{
				for(auto& key: room){
					cout << key << "\t";
				}
		}
			cout << "\n";
		}
		cout << "Result : " << (canVisitAllRooms(test)?"True":"False") << "\n\n";
	}

	return 0;
}