# beats 21.53%
class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        maxlength = 0
        length = 0
        mymap = {}
        
        for i in range(len(s)):
            if(s[i] not in mymap):
                mymap[s[i]] = i
                length+=1
            else:
                if maxlength < length:
                    maxlength = length
                l = []
                for key in mymap.keys():
                    if mymap[key] < mymap[s[i]]:
                        l.append(key)
                for key in l:
                    mymap.pop(key)
                length = i- mymap[s[i]]
                mymap[s[i]] = i
            
        if maxlength < length:
            maxlength = length
        
        return maxlength