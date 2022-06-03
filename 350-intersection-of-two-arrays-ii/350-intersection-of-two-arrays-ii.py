class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        dict = defaultdict(int)
        lst = []
        for n in nums1:
            dict[n]+=1
        
        for n in nums2:
            if n in dict and dict[n] > 0:
                lst.append(n)
                dict[n]-=1
        
        return lst