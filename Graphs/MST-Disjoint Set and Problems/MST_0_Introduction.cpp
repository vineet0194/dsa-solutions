/*
Problem: Spanning Tree / Minimum Spanning Tree
Link: -
Difficulty: Easy 
Approach: ST/MST Theory
Time Complexity: -
Note:
    Spanning Tree: A spanning tree of a connected, undirected graph is a subgraph that:
                    - Includes all vertices of the graph.
                    - Is connected.
                    - Contains no cycles.
    
    Minimum Spanning Tree: A minimum spanning tree is a spanning tree whose sum of edge weights is minimum among
                            all possible spanning trees of the graph.

    ! for V nodes in a graph, a ST/MST always has (V-1) edges

    ! ST/MST concept is mainly for CONNECTED, UNDIRECTED, WEIGHTED graphs.
        Spanning trees do not exist for directed graphs in the traditional sense because
        the standard definition applies only to undirected, connected graphs.  In a
        directed graph, edges have specific directions, meaning not every vertex is
        necessarily reachable from every other vertex, which violates the connectivity
        requirement for a standard spanning tree.
    eg:
    
    Consider this weighted graph:        
        A--4--B
        |\    |
        | 5   |
        2  \  3
        |   \ |
        C--1--D

    Edges:
        A-B = 4
        A-C = 2
        A-D = 5
        B-D = 3
        C-D = 1

    ST:
        A-----B     Total weight: 4 + 2 + 1 = 7
        |
        |           => All vertices included, connected, no cycles
        C-----D     => BUT NOT the minimum cost
    
    MST
        A           Total weight: 2 + 1 + 3 = 6
        |
        2
        |
        C-----D
              |
              3     => Minimum total weight amongst all possible STs ==> MST
              |
              B
*/

/*
    Algorithms to get MST:
        1.  Prim's Algorithm
        2.  Kruskal's Algorithm
*/