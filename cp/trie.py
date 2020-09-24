

class trie:

	def __init__(self):
		self.data = None
		self.wordend = False
		self.child= [None]*26

def insert(root,word):

	l = len(word)
	tmp = root

	for i in range(l):

		ind = ord(word[i]) - 97

		if(root.child[ind]==None):

			ptr = trie()
			ptr.data = word[i]
			if(i==l-1):
				ptr.wordend=True
			root.child[ind] = ptr
		root = root.child[ind]

	return tmp

def search(root,word):

	l = len(word)

	for i in range(l):

		ind = ord(word[i]) - 97

		if(root.child[ind]==None):
			return False

		root = root.child[ind]

		if(i==l-1 and root.wordend==0):
			return False
	return True

root = trie()

name = input('enter your fav character names in lowercase : ')

name = list(name.split( ))

for i in name:

	insert(root,i)

while True:

	name = input()

	print(search(root,name))

