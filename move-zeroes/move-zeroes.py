class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        slow, fast, ln = 0, 0, len(nums)
        while slow < ln and fast < ln:
            if nums[slow] != 0 and nums[fast] != 0:
                slow+=1
                fast+=1
            elif nums[slow] != 0 and nums[fast] == 0:
                slow+=1
                fast+=1
            elif nums[slow] == 0 and nums[fast] != 0:
                nums[slow], nums[fast] = nums[fast], nums[slow]
                slow+=1
                fast+=1
            elif nums[slow] == 0 and nums[fast] == 0:
                fast+=1
        
        return nums
        
            