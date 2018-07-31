# beat 1%
class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        l = len(nums)
        for i in range(l):
            for j in range(i+1,l):
                if nums[i]+nums[j]==target:
                    return [i,j]
  
# beats 43.5%           
class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        d = {}
        l = len(nums)
        for i in range(l):
            d[nums[i]]=i
        for i in range(l):
            if target-nums[i] in d and i!=d[target-nums[i]]:
                return [i,d[target-nums[i]]]
# beats 80%
class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        d = {}
        l = len(nums)
        for i in range(l):
            c = target-nums[i]
            if c in d and i!=d[c]:
                return [d[c],i]
            d[nums[i]]=i
                    