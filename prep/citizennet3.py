'''
	fizz buzz problem
'''

for i in range(1, 100):
    if i % 3 == 0 and i % 5 == 0:
        continue
    elif i % 3 == 0:
        print "Foo"
    elif i % 5 == 0:
        print "Bar"
    else:
        print i