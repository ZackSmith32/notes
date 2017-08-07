times = [[9, 14], [9, 12], [11, 16], [10, 11], [16, 20]]
times2 = [[0, 0], [0, 5]] # 0 cases
times3 = [[-1, 3], [13, 100]] # out of bounds cases
times4 = [[15]] 
times5 = [['a', 99]] # bad input
times6 = [[12 , 14]]


# wrtie a function to calcualte the number of people in the building. 
# also write tests

output = {
    9: 2,
    10: 3,
    11: 3,
    12: 2,
    14: 1,
    16: 1,
    20: 0
}

# O(n) looping through all times
# O(m) looping though hours in the day
# O(n) 

# TODO : handle out of bounds input gracefully

def people_in_hotel(times):
    
    time_of_day = {}
    
    for i in range(24):
        
        for time in times:
            
            if len(time) != 2:
                raise ValueError("inproper inpur format")
            
            if i >= time[0] and i < time[1]:
                
                if i in time_of_day:
                    time_of_day[i] += 1
                else:
                    time_of_day[i] = 1
                
                
    return time_of_day


# try:
#     res = people_in_hotel(times4)
#     for key in res:
#         print key,":", res[key]
# except ValueError as err:
#     print err

ans = {12: 1, 13: 1} 
    
def unit(times):
    print 'inside function'
    print people_in_hotel(times)
    assert people_in_hotel(times) == ans
        
unit(times6)







