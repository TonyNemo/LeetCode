# 80+%
class Solution:
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        l = list(str(x))
        l.reverse()
        if l[len(l)-1]=='-':
            l = ['-']+l[:-1]
        out = int(''.join(l))
        if out>pow(2,31)-1 or out<-pow(2,31):
            return 0
        return out