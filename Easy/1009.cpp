#include <iostream>
#include <bitset>
#include <string>

long long bitwiseComplement(int num) {

        if(num == 0){
            return 1;
        }

        std::bitset<32> bit(num);
        std::string flipstring;
        long long result = 0;

        std::string s = bit.to_string();
        s = s.substr(s.find('1'));

        for(char c : s){
            flipstring += (c == '0')?'1':'0';
        }

        int pos = flipstring.length() - 1;

        for(char c : flipstring){
            result += (c - '0') * (1 << pos);
            pos--;
        }

        return result;
    }
int main(){

    int num;

    std::cout << "Enter a number: ";
    std::cin >> num;

    std::cout << bitwiseComplement(num) << std::endl;
    
    return 0;
}