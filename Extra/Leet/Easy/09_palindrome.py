class Solution:
    def isPalindrome(self, x: int) -> bool:
        str_x= str(x)
        rev= str_x[::-1]
        return rev == str_x
    
s=Solution()
print(s.isPalindrome(121))
print(s.isPalindrome(-121))
