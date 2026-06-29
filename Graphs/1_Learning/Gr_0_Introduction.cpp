/*
Problem: Graphs Introduction
        Building, Inserting edge
Link: NA
Difficulty: Easy
Approach: -
Time Complexity: -
Note:
    A graph class stores the number of nodes present in the graph and the adjacenecy matrix of the graph,
    which is basically a 2D matrix of max size VxV where neighbours of each node are stored in a list<int>

    basically tells what node is connected to what other node

    if it is a weighted graph => then instead of passing neighbour to a node's adj list, pass a pair {neighbour, weight},
    so if a pair exists => that edge exists => what's the weight for that edge? you have it paired the neighbour
    => vector<pair<int, int>> adjList


    alternatively, a VxV matrix can also be maintained for weighted/non-weight, directed/undirected graphs too
    where in for eg: an edge between u and v will have adjMat[u][v] = 1;
    eg:
            for the graph: 
                0 --- 1
                |     |
                |     |
                2 --- 3
            
            edges:
                (0,1)
                (0,2)
                (1,3)
                (2,3)
            
            adjMat:
                     0 1 2 3
                 -----------
                 0 | 0 1 1 0
                 1 | 1 0 0 1
                 2 | 1 0 0 1
                 3 | 0 1 1 0

*/

#include<bits/stdc++.h>
using namespace std;

// GRAPH CLASS
class Graph{
    int V;
    vector<list<int>> adjList;       // SC = O(2V)

public:
    // CONSTRUCTING
    Graph(int V){
        this->V = V;
        adjList.resize(V);
    }

    // ADDING AN EDGE (assuming an undirected unweighted graph)
    void addEdge(int u, int v){
        adjList[u].push_back(v);     // add v to u's neighbour
        adjList[v].push_back(u);     // add u to v's neighbour (not reqd if directed)
                                    // also, SC = O(V) instead of 2V for directed
    }

    // PRINT ADJACENCY LIST
    void printAdjMat(){
        for (int i=0; i<V; i++){
            cout << i << " : ";
            for (auto& neigh : adjList[i]){
                cout << neigh << " ";
            }
            cout << endl;
        }
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(2,4);

    g.printAdjMat();

    return 0;
}

/*

========================================
          CONNECTED COMPONENTS
========================================

Definition:
A connected component is a group of vertices such that every vertex
is reachable from every other vertex in that group.

Algorithm:
1. Maintain a visited array.
2. Iterate through all vertices.
3. If a vertex is unvisited:
    - Run BFS/DFS from it.
    - Mark all reachable vertices as visited.
    - Increment component count.
4. Return component count.

TC:
Adjacency Matrix:
    O(V^2)
    (For every visited node, all V neighbors are checked.)

Adjacency List:
    O(V+E)

Observation:
The count of connected components is simply the number of times
we initiate BFS/DFS from an unvisited node.

*/
// ----------------------------------------------------------------------------------------------------------------- //
/*

How to identify a graph question if you have a grid

A trick that helped many people

!   cell = node
!   movement rule = edge

    Whenever you see a grid problem ask:    What is a node?
        Usually:    a cell

    Then ask:   When are two nodes connected?
        Usually:    up/down/left/right  or  8 directions

Then you've converted the grid into a graph.

Suppose you have (foreg: Rotten Oranges)

    2 1 1
    1 1 0
    0 1 1

You see a matrix.

A graph person sees:

(0,0) -- (0,1) -- (0,2)
  |        |        |
(1,0) -- (1,1)    [wall]
           |
         (2,1) -- (2,2)

Every cell becomes a node.

Connections are determined by movement rules:   up/down/left/right

*/

// ----------------------------------------------------------------------------------------------------------------- //

/*

    ===============================================================================
GRAPH REPRESENTATION : ADJACENCY LIST vs ADJACENCY MATRIX
===============================================================================

1. ADJACENCY MATRIX
-------------------

vector<vector<int>> matrix(V, vector<int>(V, 0));

Example:

0 --- 1
|     |
2 --- 3

Matrix:

    0 1 2 3
0 [ 0 1 1 0 ]
1 [ 1 0 0 1 ]
2 [ 1 0 0 1 ]
3 [ 0 1 1 0 ]

Advantages:
- O(1) edge lookup
    matrix[u][v]

- Easy to implement

Disadvantages:
- Space: O(V²)
- DFS/BFS scans entire row even if only a few neighbors exist

Example:
V = 100000

Space needed:
100000² = 10^10 entries  ❌

When to use:
- Dense graphs
- Small V
- Frequent "is there an edge between u and v?" queries


===============================================================================

2. ADJACENCY LIST
-----------------

vector<vector<int>> adj(V);

adj[u].push_back(v);

Example:

0 --- 1
|     |
2 --- 3

Adjacency List:

0 -> {1,2}
1 -> {0,3}
2 -> {0,3}
3 -> {1,2}

Advantages:
- Space: O(V + E)
- DFS/BFS only visits actual neighbors
- Standard representation for interview questions

Disadvantages:
- Edge lookup is not O(1)

Checking if edge (u,v) exists:
Need to search adj[u]

When to use:
- Almost every graph problem
- BFS
- DFS
- Cycle Detection
- Bipartite Graph
- Topological Sort
- Dijkstra
- Prim's
- Most LeetCode / GFG graph questions


===============================================================================

COMPLEXITY COMPARISON
-------------------------------------------------------------------------------

Adjacency Matrix:
Space       : O(V²)
DFS / BFS   : O(V²)

Adjacency List:
Space       : O(V + E)
DFS / BFS   : O(V + E)


*/