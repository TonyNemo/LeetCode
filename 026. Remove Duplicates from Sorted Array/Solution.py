class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        length = 1
        for i in range(1, len(nums)):
            if nums[i-1] != nums[i]:
                length += 1
                nums[length-1] = nums[i]
        return length