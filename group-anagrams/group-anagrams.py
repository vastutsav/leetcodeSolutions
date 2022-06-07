class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        dict = {}
        
        for s in strs:
            chars = sorted(s)
            key = "".join(chars)
            if key not in dict:
                dict[key] = []
            dict[key].append(s)
        
        
        return (list(dict.values()))