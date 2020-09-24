#python program to reprsent graph in memory

class Graph :
	"""blue print for graph data structure"""
	def __init__(self,source = 0,dest = 0,weight = 0,next = None):
		self.source = source
		self.dest = dest
		self.weight = weight
		self.next = next

def find(parent,i):

	while i!=parent[i]:
		i = parent[i]
	return i

def union(parent,s,d):

	if(find(parent,s)!=find(parent,d)):
		return True
	else:
		return False

def mst(parent,front,v):

	weight,tmp,ptr = 0,None,front
	while v:

		s,d,w = ptr.source,ptr.dest,ptr.weight

		if union(parent,s,d):		#if no cycle formed by adding this egde then add this egde to mst
			parent[d] = s
			weight += w
			v-=1
			tmp = ptr
		else:
			tmp.next = ptr.next
		ptr = ptr.next
	
	tmp.next = None
	print("minimum weight of mst is {} ".format(weight))
	return front

def input_graph(front,rear,e):

	while e>0:
		e-=1
		#print("enter source destination and weight :",end = " ")
		s,d,w = input().split(" ")
		s,d,w = int(s),int(d),int(w)

		ptr = Graph(s,d,w)

		if(rear == None):
			front  = rear = ptr
		elif(w > (rear.weight)):
			rear.next = ptr
			rear = ptr
		elif(w < (front.weight)):
			ptr.next = front
			front = ptr
		else:
			tmp = front
			while(w > (tmp.next).weight):
				tmp = tmp.next
			ptr.next = tmp.next
			tmp.next = ptr
	return front

def display_graph(ptr):

	while(ptr):
		print("[{}|{}|{}]-->".format(ptr.source,ptr.dest,ptr.weight),end = " ")
		ptr = ptr.next
	print("NULL")

print("enter total number of vertices and edges ")

v,e = input().split(" ")
v,e = int(v),int(e)
parent = [0] * v
front = rear = None

for i in range(v):
	parent[i]=i

front = input_graph(front,rear,e)
display_graph(front)
front = mst(parent,front,v-1)
display_graph(front)