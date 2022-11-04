/*A directed graph is strongly connected if there is a path between all pairs of vertices. A strongly connected component (SCC) of a directed graph is a maximal strongly connected subgraph. For example, there are 3 SCCs in the following graph.

strongly connected components can be thoought as self contained cycle where every vertex can reach the other vertex in that cycle

low link value: the low link value of a node is the smallest node id reachable from that node when doing a dfs(including itself)

and all nodes with the same low link values are together but it depend on the ordering of the graph, this is where tarjan's algo works
it help in proper traversal of graph and find the low link value

new low link condition: to update u's low to v's low, there has to be path from u to v and v must be on the stack
*/