'''
	find longest sub string
	naive solution
'''

def longestSub(s):
    
    slen = len(s)
    maxSubStr = (0, 0) # (starting index, length)
    
    
        
    # for each index in s
    for i in range(slen):
        
        # for all possible word lens
        for wordLen in range(1, slen / 2 + 1):
            if wordLen <= maxSubStr[1]:
                continue
        
            # for each possible sub string after the first
            for j in range(i + wordLen, slen - wordLen):
            
                # check if there are any matchin sub strings
                subStr1 = s[i : i + wordLen]
                subStr2 = s[j : j + wordLen]
                if subStr1 == subStr2:
                    maxSubStr = (i, wordLen)
    return (s[maxSubStr[0] : maxSubStr[0] + maxSubStr[1]])

print(longestSub("abccdebccfs"))
print(longestSub("abccbccbccdebccfs"))
print(longestSub(""))
print(longestSub("aaaaaaaaaaa"))





