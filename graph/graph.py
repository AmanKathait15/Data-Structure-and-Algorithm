#python program to reprsent graph in memory

class Graph :
	"""blue print for graph data structure"""
	def __init__(self,dest = 0, next = None):
		self.dest = dest
		self.next = next

def input_graph(vertices,e):

	while e>0:
		e-=1
		s,d = input().split(" ")
		s,d = int(s),int(d)

		ptr = Graph(d,vertices[s])
		vertices[s] = ptr

def display_graph(vertices):

	for ptr in vertices:

		while(ptr):
			print("[{}]-->".format(ptr.dest),end = " ")
			ptr = ptr.next
		print("NULL")

print("enter total number of vertices and edges ")

v,e = input().split(" ")
v,e = int(v),int(e)
vertices = [None] * v

input_graph(vertices,e)
display_graph(vertices)