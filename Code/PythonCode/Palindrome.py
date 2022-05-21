def reverse(string):
    string = string[::-1]
    return string
def isPalindrome(s):
    return s == s[::-1]

s = input("Enter a word: ")
print(reverse(s))
ans = isPalindrome(s)
 
if ans:
    print("Yes")
else:
    print("No")