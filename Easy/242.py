def isAnagram(s: str, t: str) -> bool:
    if len(s) != len(t):
        return False

    hash_s = {}
    hash_t = {}

    for i in range(len(s)):
        
        if s[i] not in hash_s:
            hash_s[s[i]] = 1
        else:
            hash_s[s[i]] += 1
            
        if t[i] not in hash_t:
            hash_t[t[i]] = 1
        else:
            hash_t[t[i]] += 1

    return hash_s == hash_t

testcases = [
    ("anagram", "nagaram"),
    ("rat", "car"),
    ("aab", "abb")
]

for test in testcases:
  isa = "" if isAnagram(test[0], test[1]) else "not "
  print(f"{test[0]} & {test[1]} is {isa}a Anagram")