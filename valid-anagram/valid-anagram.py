class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        dict1 = defaultdict(int)
        
        for a in s:
            dict1[a]+=1
        
        for a in t:
            dict1[a]-=1
        
        if any(list(dict1.values())):
            return False
        
        return True