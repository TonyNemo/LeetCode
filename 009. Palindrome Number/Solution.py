# 
class Solution:
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        s = str(x)
        sl = list(s)
        sl.reverse()
        rs = ''.join(sl)
        if s==rs:
            return True
        else:
            return False