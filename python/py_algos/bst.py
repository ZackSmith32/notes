
class Node(object):
	
	def __init__(self, data):
		self.data = data
		self.leftChild = None
		self.rightChild = None


class BinarySearchTree(object):

	def __init__(self):
		self.root = None

	def insert(self, data):
		if not self.root:
			self.root = Node(data)
		else:
			self.insertNode(data, self.root)

	def insertNode(self, data, node):
		if data < node.data:
			if node.leftChild:
				self.insertNode(data, node.leftChild)
			else:
				node.leftChild = Node(data)
		else:
			if node.rightChild:
				self.insertNode(data, node.rightChild)
			else:
				node.rightChild = Node(data)
	
	def getPredecessor(self, node):
		if node.rightChild:
			return self.getPredecessor(node.rightChild)

		return node

	def removeNode(self, data, node):
		if not node:
			return node

		if data < node.data:
			node.leftChild = self.removeNode(data, node.leftChild)
		elif data > node.data:
			node.rightChild = self.removeNode(data, node.leftChild)
		else:
			if not node.leftChildand not node.rightChild:
				print("removing a leaf node...")
				del nodereturn None;

			if not self.leftChild:
				print("remove node with single right child")
				tempNode = node.rightChild
				return tempNode

			if not self.rightChild:
				print("remove node with single left child")
				tempNode = node.leftChild
				return tempNode

			print("removing node with 2 children")
			tempNode = self.getPredecessor(node.leftChild)
			node.data = tempNode.data
			del tempNode.data
			return

	
	def remove(self, data):
		if self.root:
			self.root = self.removeNode(data, self.root)

	def getMinValue(self):
		if self.root:
			return self.getMin(self.root)

	def getMin(self, node):
		if node.leftChild:
			return self.getMin(node.leftChild)

		return node.data

	def getMaxValue(self):
		if self.root:
			return self.getMax(self.root)

	def getMax(self, node):
		if node.rightChild:
			return self.getMax(node.rightChild)

		return node.data

	def traverse(self):
		if self.root:
			self.traverseInOrder(self.root)

	def traverseInOrder(self, node):
		if node.leftChild:
			self.traverseInOrder(node.leftChild)

		print("%s " % node.data)

		if node.rightChild:
			self.traverseInOrder(node.rightChild)


bst = BinarySearchTree()
bst.insert(10)
bst.insert(5)
bst.insert(15)
bst.insert(6)

print(bst.getMinValue())
print(bst.getMaxValue())
bst.traverse()





















