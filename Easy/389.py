def findTheDifference(s: str, t: str) -> str:
    result = 0

    for i in s:
        result ^= ord(i)
    for i in t:
        result ^= ord(i)

    return chr(result)

testcases = [
    ("abcd", "abcde"),
    ("", "y"),
    ("a", "aa")
]

for i, test in enumerate(testcases):
    print(f"Test {i+1}:")
    print(f"String 1: {test[0]}")
    print(f"String 2: {test[1]}")
    print(f"Result: {findTheDifference(test[0], test[1])}")
    print("\n\n")