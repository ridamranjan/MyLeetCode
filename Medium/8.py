class Solution:
    def myAtoi(self, s: str) -> int:

        length = len(s)
        if length == 0:
            return 0
        
        num = 0
        i_max = 2147483647
        i_min = -2147483648
        cursor = 0
        
        while cursor < length and s[cursor] == " ":
            cursor += 1
            
        if cursor < length and s[cursor] == "+":
            sign = 1
            cursor += 1
        elif cursor < length and s[cursor] == "-":
            sign = -1
            cursor += 1
        else:
            sign = 1
        
        while cursor < length and s[cursor].isdigit():
            temp = int(s[cursor])
            if sign == 1:
                if num > i_max//10 or (num == i_max//10 and temp > 7):
                    return i_max
            else:
                if num > i_max//10 or (num == i_max//10 and temp > 8):
                    return i_min
                
            num = num*10 + temp
            cursor += 1
                
        return sign*num

if __name__ == "__main__":
    s = Solution()
    test_cases = ["42", "   -42", "4193 with words", "words and 987", "-91283472332"]
    for test in test_cases:
        print(f"Input: '{test}' -> Output: {s.myAtoi(test)}")