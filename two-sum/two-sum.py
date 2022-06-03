class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dict = defaultdict(int)
        for i in range(len(nums)):
            need = target - nums[i]
            if need in dict:
                return [i, dict[need]]
            dict[nums[i]] = i;