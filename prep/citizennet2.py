'''
	print strings that are common to both lists
'''

def commonString(lst1, lst2):
    dict = {}
    result = []
    
    for elm in lst1:
        dict[elm] = 1
        
    for elm in lst2:
        if elm in dict:
            result.append(elm)
            
    return(result)


lst1 = ["hi", "my", "name", "name", "is", "zachary", "smith", "yoyo", "foo", "bar", ""]
lst2 = ["zachary", "yoyo", "greenday", "coocoo", "cachoo", "hi", ""]

print commonString(lst1, lst2)
# zachary yoyo hi