#adjacency list meth

class adjnode():
    def __init__(self, data):
        self.vertex = data
        self.next = None


class graph():
    def __init__(self, vertices):
        self.V = vertices
        self.graph = [None] * self.V

    
    def add_edge(self, src, dest):
        node = adjnode(dest)
        node.next = self.graph[src]
        self.graph[src] = node

        '''
        if u want graph to be undirected too...
        node = adjnode(src)
        node.next = self.graph[dest]
        self.graph[dest] = node
        '''

    def printgraph(self):
        for i in range(self.V):
            print(f"adjacency list of the vertex {i} is ", endl = "")
            temp = self.graph
            while temp:
                print(f" -> {temp.vertex}", endl = "")
                temp = temp.next
            print(" \n")