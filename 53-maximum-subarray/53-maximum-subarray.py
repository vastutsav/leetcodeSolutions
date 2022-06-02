class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        sm, mx = 0,0;
        for i in range(1,len(nums)):
            nums[i] = max(nums[i], nums[i]+nums[i-1])
            
        return max(nums)
        