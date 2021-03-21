"""
	Anderson Vieira's solution
	Please don't copy this
"""
class bst:
	def __init__(self, v):
		self.v = v
		self.left = None
		self.right = None
		self.traversal = []

	def insert(self, node, v):
		if node == None:
			node = bst(v)
		else:
			if v < node.v:
				node.left = self.insert(node.left, v)
			else:
				node.right = self.insert(node.right, v)
		return node

	def pre(self, node):
		if node != None:
			self.traversal.append(node.v)
			self.pre(node.left)
			self.pre(node.right)

	def ino(self, node):
		if node != None:
			self.ino(node.left)
			self.traversal.append(node.v)
			self.ino(node.right)

	def pos(self, node):
		if node != None:
			self.pos(node.left)
			self.pos(node.right)
			self.traversal.append(node.v)

	def print_traversal(self):
		for i in range(len(self.traversal)):
			if i == len(self.traversal)-1:
				print(self.traversal[i])
			else:
				print(self.traversal[i], end=" ")
		self.traversal = []


c = int(input())
for i in range(1, c+1):
	print(f"Case {i}:")
	n = int(input())
	v = input().split()
	tree = bst(int(v[0]))
	for j in range(1, n):
		tree = tree.insert(tree, int(v[j]))

	tree.pre(tree)
	print("Pre.:", end=" ")
	tree.print_traversal()
	tree.ino(tree)
	print("In..:", end=" ")
	tree.print_traversal()
	tree.pos(tree)
	print("Post:", end=" ")
	tree.print_traversal()
	print()
