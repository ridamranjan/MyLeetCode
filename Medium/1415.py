def backtracking(n: int, k: int) -> str:
    if k > (3 * 2**(n-1)):
        return ""
    
    result = []

    def back(string):
        
        if len(string) == n:
            result.append(string)
            return
        
        for ch in ['a', 'b', 'c']:
            
            if len(string) == 0 or string[-1] != ch:
                back(string + ch)
                
                
    back("")
    return result[k-1]

def subtree(n: int, k: int) -> str:
    if k > (3 * 2**(n-1)):
        return ""
    
    result = []

    def back(string):
        
        if len(string) == n:
            result.append(string)
            return
        
        for ch in ['a', 'b', 'c']:
            
            if len(string) == 0 or string[-1] != ch:
                back(string + ch)
                
                
    back("")
    return result[k-1]

if __name__ == "__main__":
    print(backtracking(1, 3))
    print(backtracking(2, 7))
    print(backtracking(3, 9))
    print(subtree(1, 3))
    print(subtree(2, 7))
    print(subtree(3, 9))