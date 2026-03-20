#include <iostream>
#include <vector>

using namespace std;

int lengthOfLastWord(string s) {
        vector<string> str;
        string none = "";
        s.push_back(' ');
        for(auto& c : s){
            if(c == ' '){
                if(none.size() != 0){
                    str.push_back(none);
                    none.clear();
                }
                continue;
            }
            none.push_back(c);
        }
        return str.back().size();
}

int main(){

  vector<string> testcases = {
    "Hello World",
    "   fly me   to   the moon  ",
    "luffy is still joyboy"
  };

  for(auto& str : testcases){
    cout << "string <" << str << ">" << " returns: " << lengthOfLastWord(str) << endl;
  }

  return 0;
}
