class Node():

	def __init__(self, data):
		self.data = data
		self.right_c = None
		self.left_c = None


class BST():

	def __init__(self, node):
		self.root = node

	def insert(self, node, root):
		if not root:
			

		if (node.data > root.data):
			insert(node, root.right_c)
		if (node.data < root.data):
			insert(node, root.left_c)



def find_mid(a):
	// TODO: runner technique to find middle


def make_BST(a):
	mid = find_mid(a)


def main(void):
	i = raw_input().strip().split(" ")
	make_bst(i)

if __name__ == "__main__":
	main()
