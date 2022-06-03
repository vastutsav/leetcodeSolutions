class Solution:
    def maxProfit(self, nums: List[int]) -> int:
        return sum([nums[i]-nums[i-1] for i in range(1, len(nums)) if nums[i]>nums[i-1]])
