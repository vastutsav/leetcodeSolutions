class Solution:
    def isPalindrome(self, x: int) -> bool:
        orig = str(x)
        rvr = orig[::-1]
        return rvr == orig