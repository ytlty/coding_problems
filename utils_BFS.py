'''
Graph is represented as a dictionary of adjacency list
{0 : {1, 2}, 1 : {0}, 2 : {0}} would look like 
        0 -- 1
        |
        2
Levels is just a dictionary of the depth of each node
root is 0
'''

def BFS(graph, root):
  levels = {0: 0}
  # put root in queue first
	queue = [root]
	while(len(queue)):
		node = queue.pop(0)
		nodes = list(graph[node])
		for item in nodes:
			if item not in levels:
				levels[item] = levels[node] + 1
				queue.append(item)
	return levels

graph_1 = {0 : {1, 2}, 1 : {0}, 2 : {0}}

BFS(graph_1, 0)
