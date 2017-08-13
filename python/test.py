

def hello_world(word):
	print("hello world " + word)

	try:
		num = float(input("type a number: "))
	except NameError, e:
		raise ValueError("invalid input")
	
	print (num)
	return (word)


'''
	main catches assertion error, and ValueError raised in function
'''
def main():

	try:
		assert hello_world("zack") == "zack", "incorrect return"
	except (AssertionError, ValueError), e:
		print("failed test : msg = " + e.message)



if __name__ == '__main__':
	main();