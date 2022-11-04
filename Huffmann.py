class Node :
	def __init__(self,data=0) :
		self.data = data
		self.char = ""
		self.left = None
		self.right = None
		self.weight = None


class Huffman() :
	
	def __init__(self,) :
		self.arr = []
		
	def printLeaf(self,node,arr) :
		n = "  "
		for a in arr :
			n += str(a)
		print("  ",node.char,n)
		return
		
	def isLeaf(self,node) :
		if node.left == None and node.right == None :
			return True
		return False
		
	def printCode(self,node=None) :
		if self.isLeaf(node) :
			self.printLeaf(node,self.arr)
			self.arr.pop()
		if node.left :
			self.arr.append(node.left.weight)
			self.printCode(node.left)
		if node.right :
			self.arr.append(node.right.weight)
			self.printCode(node.right)
	
	def setCode(self,node=None) :
		if node :
			if node.left :
				node.left.weight = 0
			if node.right :
				node.right.weight = 1
			self.setCode(node=node.left)
			self.setCode(node=node.right)
			return
		return
				
	def buildTree(self,chars,freq,prev_node=None):
		if prev_node and freq:
			z = Node()
			node = Node()
			node.data = freq[0]
			node.char = chars[0]
			z.data = prev_node.data+node.data
			if prev_node.data < node.data:
				z.left = prev_node
				z.right = node
			else :
				z.right = prev_node
				z.left = node
			chars.pop(0)
			freq.pop(0)
			self.buildTree(chars,freq,prev_node=z)
			return
			
		if freq == [] :
			self.head = prev_node
			self.setCode(self.head)
			return
		z = Node()
		min1 = Node()
		min2 = Node()
		min1.data = freq[0]
		min1.char = chars[0]
		min2.data = freq[1]
		min2.char = chars[1]
		z.data = min1.data + min2.data
		z.left = min1
		z.right = min2
		
		freq.pop(0)
		freq.pop(0)
		chars.pop(0)
		chars.pop(0)
		self.buildTree(chars,freq,prev_node=z)
		return
	
	def printTree(self,node=None) :
		if node :
			print("Node :- ",node.data,"  chars :- ",node.char)
			self.printTree(node=node.left)
			self.printTree(node=node.right)
			return
		return



def SortFreq(data) :
	dict = {}
	for d in data :
		if d not in dict :
			dict[d] = 1
		else :
			dict[d] += 1
	chars = list(dict.keys())
	freq = list(dict.values())
	for i in range(len(freq)):
		has_sorted = False
		for j in range(len(freq)-1):
			if freq[j] > freq[j+1]:
				temp = chars[j]
				chars[j] = chars[j+1]
				chars[j+1] = temp
				temp = freq[j]
				freq[j] = freq[j+1]
				freq[j+1] = temp
				has_sorted = True
		if not has_sorted :
			break
	print(chars)
	print(freq)
	for ii in range(len(freq)) :
		dict[chars[ii]] = freq[ii]
	return (chars,freq)

data = 'BCAADDDCCACACAC'
chars,freq = SortFreq(data)

tree = Huffman()
tree.buildTree(chars,freq)
tree.printTree(node=tree.head)
tree.printCode(tree.head)