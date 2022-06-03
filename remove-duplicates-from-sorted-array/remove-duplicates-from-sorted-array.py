class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        slow, fast = 0, 0
        for fast in range(len(nums)):
            if nums[slow] != nums[fast]:
                nums[slow+1] = nums[fast]
                slow = slow+1
        
        return slow+1