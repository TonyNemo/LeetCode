# 68.5%
class Solution:
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows < 2:
            return s
        
        length = len(s)
        zigzag = []
        for r in range(numRows):
            zigzag.append([])
        down = True
        row = 0
        
        for i in range(length):
            if down:
                zigzag[row].append(s[i])
                row+=1
                if row==numRows:
                    down = False
                    row = numRows-2
            else:
                zigzag[row].append(s[i])
                row-=1
                if row==-1:
                    row = 1
                    down = True
        
        out = ''.join([''.join(l) for l in zigzag])
        return out