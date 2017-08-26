'''
    find the max 3 values in a key value dict
'''

# O(n) time : n = number of elements in dict


def findMin(list):
    localMin = 0
    for i in range(len(list)):
        if list[i] < list[localMin]:
            localMin = i
    return(localMin)
            
def func(dict):

    if len(dict) <= 3:
        return([dict[x] for x in dict])
    
    topV = []
        
    # itterate through dictionary, add value to array top
    for k in dict:
        if len(topV) < 3:
            topV.append(dict[k])
        elif dict[k] in topV:
            continue
        elif dict[k] > topV[lowIndex]:
            topV = [x for x in topV if x != topV[lowIndex]]
            topV.append(dict[k])
        lowIndex = findMin(topV)    
    
    return (topV)


print func({ 4: 5, 7: 9, 3: 10, 1: 11, 11: 6, 12:8, 13:10, 14: 15})
print func({ 4: 5})
