class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s) != len(t):
            return(False)
        dictLettersS = {}
        dictLettersT = {}
        for c in s:
            if c not in dictLettersS:
                dictLettersS[c] = 1
            else:
                dictLettersS[c] += 1
                
        for c in t:
            if c not in dictLettersT:
                dictLettersT[c] = 1
            else:
                dictLettersT[c] += 1
                
        for key in dictLettersS:
            if dictLettersS[key] == dictLettersT[key]:
                continue
            else:
                return(False)
        
        return(True)

test = Solution()
print(test.isAnagram("cat", "rat"))